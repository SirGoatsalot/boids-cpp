/*
 * Class that manages a group of "Boids", spawning and drawing each one.
 *
 * Author: Foster Sullivan (SirGoatsalot)
 */

#include <iostream>
#include "boid.cpp"

class Flock {
private:
	const int boid_count;
	Boid * boids;
public:
	Flock(int boid_count) 
	: boid_count{ boid_count <= 0 ? 1 : boid_count } // Safety barrier if <= 0 array length is passed
	, boids{ new Boid[ boid_count ] } // 
	{
		for (int i = 0; i < boid_count; ++i) {
			boids[i].setPos(i, i);
			boids[i].setID(i);
		}
	};

	void listBoids() {
		for (int i = 0; i < boid_count; ++i) {
			int * pos = boids[i].getPos();
			std::cout << "Boid " << boids[i].getID();
			std::cout << " -- (" << pos[0] << ", " << pos[1] << ")\n";
		}
	}
};
