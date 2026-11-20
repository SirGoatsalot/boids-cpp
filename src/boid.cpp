#include <SDL3/SDL.h>
#include <SDL3/SDL_stdinc.h>

#include "boid_util.cpp"

class Boid {
private:
	float fov = 45;
	float dir = 90;
	float view_dist;
	float scale = 25;
	bool dbg = true;
	int vertex_count = 3;
	float speed = 0.001;

	int ID;
	SDL_Vertex* vertices;
	SDL_Renderer* renderer;
public:
	Boid( int ID = 0, SDL_FPoint pos = SDL_FPoint{0.0, 0.0}, SDL_Color color = SDL_Color{255, 255, 255, 255} ) 
	: ID{ ID }
	, vertices{ new SDL_Vertex[vertex_count] }
	{
		setPos(pos);
	};

	void setID(int ID) { this->ID = ID; } 
	void setScale(float scale) { this->scale = scale; }
	void setDir(float dir) { this->dir = dir; }
	void setPos(SDL_FPoint pos) { 
		vertices[0].position = pos; 
		boid_util::set_shape(vertices, vertex_count, scale, dir);
	} 
	void setColor(SDL_FColor color) { 
		for (int i = 0; i < vertex_count; ++i) {
			vertices[i].color.r = color.r;
			vertices[i].color.g = color.g;
			vertices[i].color.b = color.b;
			vertices[i].color.a = color.a;
		}
	}

	int getID() { return ID; }
	SDL_Vertex getPos() { return *vertices; }

	void tick(double deltaTime) {
		dir += 0.1 * deltaTime;
		boid_util::move_head(vertices, vertex_count, dir, speed);
		boid_util::set_shape(vertices, vertex_count, scale, dir);
	};

	void draw(SDL_Renderer* renderer) {
		if (!SDL_RenderGeometry(renderer, nullptr, vertices, 3, nullptr, 0)) {
			std::string msg = SDL_GetError();
			boid_util::log_msg(ID, msg);
		}
	};
};
