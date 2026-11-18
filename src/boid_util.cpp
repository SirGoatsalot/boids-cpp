#include <SDL3/SDL.h>
#include <iostream>
#include <cmath>
#include <math.h>

#include "boid_util.h"

namespace boid_util {

	void log_msg(int ID, std::string& msg) {
		std::cout << "Boid [" + std::to_string(ID) + "] - " << msg << "\n";
	}

	void set_shape(SDL_Vertex* vertices, int vertex_count, float scale, float dir) {
		const int width = 1;
		const int height = 2;

		vertices[1].position.x = vertices[0].position.x + (width * scale);
		vertices[1].position.y = vertices[0].position.y + (height * scale);

		vertices[2].position.x = vertices[0].position.x - (width * scale);
		vertices[2].position.y = vertices[0].position.y + (height * scale);
		
		float angle_offset = 180 - 2 * (std::atan(height / width) * (180 / M_PI));

		rotate_point(&vertices[0], vertices[1], dir);
		rotate_point(&vertices[0], vertices[2], dir + angle_offset);
	}

	void rotate_point(SDL_Vertex* center, SDL_Vertex& a, float theta) {
		float r = std::sqrt(std::pow(center->position.x - a.position.x, 2) + std::pow(center->position.y - a.position.y, 2));
		a.position.x = center->position.x + (r * std::cos(theta * (M_PI / 180)));
		a.position.y = center->position.y + (r * std::sin(theta * (M_PI / 180)));
	}
}

