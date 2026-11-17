/*
 * Class representing one Boid which sees its neighbors and moves accordingly.
 *
 * Author: Foster Sullivan (SirGoatsalot)
 */

class Boid {
private:
	int ID;
	int x;
	int y;
	int fov;
	float dir;
public:
	Boid( const Boid & other ); // Copy Constructor
	Boid( Boid && other ) noexcept;      // Move Constructor
	Boid( int ID = 0 ) {}; // Default Constructor (default parameter 0)         

	void setID(int new_ID) { ID = new_ID; }
	void setPos(int new_x, int new_y) { x = new_x; y = new_y; }

	int getID() { return ID; }
};
