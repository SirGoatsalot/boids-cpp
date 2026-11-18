/*
 * Class that manages a group of "Boids", spawning and drawing each one.
 *
 * Author: Foster Sullivan (SirGoatsalot)
 */

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

#include "boid.cpp"

class Flock {
private:
	const int boid_count;
	Boid* boids;

	const float gradient = 0.01;
public:
	explicit Flock( int boid_count, SDL_FColor color )
	: boid_count{ boid_count <= 0 ? 1 : boid_count } // Safety barrier if <= 0 array length is passed
	, boids{ new Boid[ boid_count ] }
	{
		SDL_FColor adjusted_color {color};
		for (int i = 0; i < boid_count; ++i) {
			boids[i].setID(i);
			
			adjusted_color.r -= i * gradient;
			adjusted_color.g += i * gradient;
			
			boids[i].setColor(SDL_FColor(adjusted_color));

			float x = (i * 25.0) + 50;
			float y = (i * 25.0) + 50;
			SDL_FPoint pos = SDL_FPoint{x, y};
			boids[i].setPos(pos);

			boids[i].setScale(50 - (i * 2));
		}
	};

	void tick(double deltaTime) {
		for (int i = 0; i < boid_count; ++i) {
			boids[i].tick(deltaTime);
		}
	}

	void draw(SDL_Renderer *renderer) {
		for (int i = 0; i < boid_count; ++i) {
			boids[i].draw(renderer);
		}	
	}

};
