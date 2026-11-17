/*
 * Class that manages a group of "Boids", spawning and drawing each one.
 *
 * Author: Foster Sullivan (SirGoatsalot)
 */

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <iostream>
#include "boid.cpp"

class Flock {
private:
	const int boid_count;
	Boid* boids;

	const float gradient = 300;
public:
	explicit Flock( int boid_count, SDL_Color color )
	: boid_count{ boid_count <= 0 ? 1 : boid_count } // Safety barrier if <= 0 array length is passed
	, boids{ new Boid[ boid_count ] }
	{
		for (int i = 0; i < boid_count; ++i) {
			SDL_Color adjusted_color {color};
			adjusted_color.r -= i * gradient;
			adjusted_color.g -= i * gradient;
			adjusted_color.b -= i * gradient;
			boids[i].setColor(adjusted_color);
			float x = (i * 25.0) + 50;
			float y = (i * 25.0) + 50;
			SDL_FPoint pos = SDL_FPoint{x, y};
			boids[i].setPos(pos);
		}
	};

	void listBoids() {
		for (int i = 0; i < boid_count; ++i) {
			std::cout << "Boid " << boids[i].getID();
		}
	}

	void tick() {
		for (int i = 0; i < boid_count; ++i) {
			boids[i].tick();
		}
	}

	void draw(SDL_Renderer *renderer) {
		for (int i = 0; i < boid_count; ++i) {
			boids[i].draw(renderer);
		}	
	}

};
