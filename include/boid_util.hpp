
#ifndef BOIDUTILS_H

#define BOIDUTILS_H

#include <string>
#include <SDL3/SDL.h>

/**
 * Group of utility functions for use with boids.
 *
 * Author: Foster Sullivan {SirGoatsalot}
 */
namespace boid_util {

	/**
	 * Log the given message to the given Boid ID.
	 *
	 * @param ID the ID of the boid logging.
	 * @param msg the message to log.
	 */
	void log_msg(int ID, std::string& msg); 

	/** 
	 * Adjust the given list of vertices to form a triangle shape relative to the first point, making the firsrt
	 * point the tip of the triangle.
	 *
	 * @param veritces The list of vertices to adjust into a triangle.
	 * @param vertex_count The number of vertices in vertices.
	 * @param scale Scale to draw the triangle.
	 */
	void set_shape(SDL_Vertex* vertices, int vertex_count, float scale, float dir); 

	/**
	 * Rotates the given point about the given center.
	 *
	 * @param center The center to rotate about.
	 * @param a The point to rotate.
	 * @param theta The angle to rotate the point by.
	 */
	void rotate_point(SDL_Vertex* center, SDL_Vertex& a, float theta); 

	/**
	 * Moves the given points by a vector of magnitude speed and direction dir
	 *
	 * @param[in/out] vertices
	 * @param[in] vertex_count
	 * @param[in] dir
	 * @param[in] speed
	 */
	void move_points(SDL_Vertex* vertices, int vertex_count, float dir, float speed);
}

#endif
