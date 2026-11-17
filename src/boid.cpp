/*
 * Class representing one Boid which sees its neighbors and moves accordingly.
 *
 * Author: Foster Sullivan (SirGoatsalot)
 */

class Boid {
private:
	int ID;
	int pos[2];
	int fov;
	float dir;
public:
	Boid( const Boid & other ); // Copy Constructor
	Boid( Boid && other ) noexcept;      // Move Constructor
	Boid( int ID = 0 ) {}; // Default Constructor (default parameter 0)         

	void setID(int new_ID) { ID = new_ID; }
	void setPos(int new_x, int new_y) { pos[0] = new_x; pos[1] = new_y; }

	int getID() { return ID; }
	int * getPos() { return pos; }
};
