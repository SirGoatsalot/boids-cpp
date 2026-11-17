#include "flock.cpp"
#include<SDL3/SDL.h>

using namespace std;

int main() {
	Flock f{25};
	f.listBoids();
}
