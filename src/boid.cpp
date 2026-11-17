/*
 * Class representing one Boid which sees its neighbors and moves accordingly.
 *
 * Author: Foster Sullivan (SirGoatsalot)
 *
 */

#include <SDL3/SDL.h>
#include <SDL3/SDL_stdinc.h>
#include <iostream>

class Boid {
private:
	int fov = 45;
	float dir = 0;
	float scale = 25;
	bool dbg = true;
	int vertex_count = 3;
	float speed[2] = {0.1, 0.1};

	int ID;
	SDL_Vertex* vertices;
	SDL_Renderer* renderer;
public:
	Boid( const Boid & other ); // Copy Constructor
	Boid( Boid && other ) noexcept;      // Move Constructor

	Boid( int ID = 0, SDL_FPoint pos = SDL_FPoint{0.0, 0.0}, SDL_Color color = SDL_Color{255, 255, 255, 255} ) 
	: ID{ ID }
	, vertices{ new SDL_Vertex[vertex_count] }
	{
		setPos(pos);
	};

	void setID(int ID) { this->ID = ID; } 
	void setScale(float scale) { this->scale = scale; }

	void setPos(SDL_FPoint point) { 
		if (dbg) {
			// std::cout << log_msg() << "Position to " << point.x << ", " << point.y << "\n";
		}
		vertices[0].position = point;

		vertices[1].position.x = point.x + (1 * scale);
		vertices[1].position.y = point.y + (2 * scale);

		vertices[2].position.x = point.x - (1 * scale);
		vertices[2].position.y = point.y + (2 * scale);
	}

	void setColor(SDL_FColor color) { 
		if (dbg) {
			std::cout << log_msg() << "Color to "; 
			std::cout << std::to_string(color.r) << ", ";
			std::cout << std::to_string(color.g) << ", ";
			std::cout << std::to_string(color.b) << "\n";
		}
		
		for (int i = 0; i < vertex_count; ++i) {
			vertices[i].color.r = color.r;
			vertices[i].color.g = color.g;
			vertices[i].color.b = color.b;
			vertices[i].color.a = color.a;
		}
	}


	int getID() { return ID; }

	void tick(double deltaTime) {
		
		float x = vertices[0].position.x + (speed[0] * deltaTime);
		float y = vertices[0].position.x + (speed[1] * deltaTime);
		setPos(SDL_FPoint{x, y});

	};

	void draw(SDL_Renderer* renderer) {
		if (!SDL_RenderGeometry(renderer, nullptr, vertices, 3, nullptr, 0)) {
			std::cout << log_msg() << SDL_GetError() << "\n";
		}
	};

	std::string log_msg() {
		return "Boid [" + std::to_string(ID) + "] - ";
	}
};
