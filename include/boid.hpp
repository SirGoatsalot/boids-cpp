#ifndef BOID_H

#define BOID_H

#include <SDL3/SDL.h>

#include "boid_util.hpp"

/**
 * A class representing one triangular "boid", intended to be used within a "flock" of boids.
 *
 * @author Foster Sullivan (SirGoatsalot)
 *
 */
class Boid {
private:
	float fov = 45;
	float dir = 90;
	float view_dist;
	float scale = 25;
	bool dbg = true;
	int vertex_count = 3;
	float speed[2] = {0, 0};

	int ID;
	SDL_Vertex* vertices;
	SDL_Renderer* renderer;

public:
	/**
	 * Makes a new Boid
	 *
	 * @param[in] ID The ID of the new boid 
	 * @param[in] pos Where to place the new boid
	 * @param[in] color New boid's color
	 */
	Boid( int ID = 0, SDL_FPoint pos = SDL_FPoint{0.0, 0.0}, SDL_Color color = SDL_Color{255, 255, 255, 255} ); 

	void setID(int ID);
	void setScale(float scale); 
	void setColor(SDL_FColor color);  

	/**
	 * Sets the position of a boid, and rotates its other points to match the
	 * direction it is facing.
	 *
	 * @param[in] point The new head position of the boid.
	 */
	void setPos(SDL_FPoint point); 

	int getID(); 
	SDL_Vertex getPos();

	/**
	 * Runs one logical tick for the Boid
	 *
	 * @param[in] deltaTime The time difference since the previous logic tick, in ms.
	 */
	void tick(double deltaTime); 

	/**
	 * Sends the boids vertices to the given renderer
	 *
	 * @param[in] renderer A pointer to the renderer to put the boid on.
	 */
	void draw(SDL_Renderer* renderer); 

};

#endif
