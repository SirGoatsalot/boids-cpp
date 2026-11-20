#ifndef FLOCK_H

#define FLOCK_H

#include <SDL3/SDL.h>

#include "boid.hpp"

/*
 * Class that manages a group of "Boids", spawning and drawing each one.
 *
 * Author: Foster Sullivan (SirGoatsalot)
 *
 */
class Flock {
private:
	const int boid_count;
	Boid* boids;
	const float gradient = 0.01;
public:

	/**
	 * Constructs a new Flock of the given boid count, starting at the given color.
	 *
	 * @param[in] boid_count The number of boids to put in the flock.
	 * @param[in] color The color to start the flock.
	 */
	explicit Flock( int boid_count, SDL_FColor color );

	/**
	 * Runs one logical tick for the flock
	 *
	 * @param[in] deltaTime The time difference since the previous logic tick, in ms.
	 */
	void tick(double deltaTime); 

	/**
	 * Sends the flock vertices to the given renderer
	 *
	 * @param[in] renderer A pointer to the renderer to put the flock on.
	 */
	void draw(SDL_Renderer* renderer); 

};

#endif
