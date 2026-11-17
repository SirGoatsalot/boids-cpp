/*
 * Misc. utilities for use with the Boid class.
 *
 * Author: Foster Sullivan {SirGoatsalot}
 */

#include <SDL3/SDL.h>

#include <iostream>

namespace boid_util {
	/**
	 * Log the given message to the given Boid ID.
	 *
	 * @param ID the ID of the boid logging.
	 * @param msg the message to log.
	 */
	void log_msg(int ID, std::string& msg) {
		std::cout << "Boid [" + std::to_string(ID) + "] - " << msg << "\n";
	}

	/** 
	 * Adjust the given list of vertices to form a triangle shape relative to the first point, making the firsrt
	 * point the tip of the triangle.
	 *
	 * @param veritces The list of vertices to adjust into a triangle.
	 * @param vertex_count The number of vertices in vertices.
	 * @param scale Scale to draw the triangle.
	 */
	void set_shape(SDL_Vertex* vertices, int vertex_count, float scale) {
		vertices[1].position.x = vertices[0].position.x + (1 * scale);
		vertices[1].position.y = vertices[0].position.y + (2 * scale);

		vertices[2].position.x = vertices[0].position.x - (1 * scale);
		vertices[2].position.y = vertices[0].position.y + (2 * scale);
	}
}

