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
	int ID;
	int fov = 45;
	float dir = 0;
	float scale = 50;
	bool dbg = true;

	int vertex_count = 3;
	SDL_Vertex* vertices;
	SDL_Color color;
	SDL_Renderer* renderer;
public:
	Boid( const Boid & other ); // Copy Constructor
	Boid( Boid && other ) noexcept;      // Move Constructor

	Boid( int ID = 0, SDL_FPoint pos = SDL_FPoint{0.0, 0.0}, SDL_Color color = SDL_Color{255, 255, 255, 255} ) 
	: ID{ ID }
	, color{ color }
	, vertices{ new SDL_Vertex[vertex_count] }
	{
		setPos(pos);
	};

	void setID(int ID) { this->ID = ID; } 
	void setScale(float scale) { this->scale = scale; }

	void setPos(SDL_FPoint point) { 
		if (dbg) {
			std::cout << log_msg() << "Position to " << point.x << ", " << point.y << "\n";
		}
		vertices[0].position = point;

		vertices[1].position.x = point.x + (1 * scale);
		vertices[1].position.y = point.y + (2 * scale);

		vertices[2].position.x = point.x - (1 * scale);
		vertices[2].position.y = point.y + (2 * scale);
	}

	void setColor(SDL_Color color) { 
		if (dbg) {
			std::cout << log_msg() << "Color to "; 
			std::cout << std::to_string(color.r) << ", ";
			std::cout << std::to_string(color.g) << ", ";
			std::cout << std::to_string(color.b) << "\n";
		}
		this->color = SDL_Color{color}; 
		for (int i = 0; i < vertex_count; ++i) {
			vertices[i].color.r = this->color.r;
			vertices[i].color.g = this->color.g;
			vertices[i].color.b = this->color.b;
			vertices[i].color.a = this->color.a;
		}
	}


	int getID() { return ID; }

	void tick() {

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
