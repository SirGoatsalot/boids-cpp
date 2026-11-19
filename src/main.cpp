#include <SDL3/SDL.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>

#include "flock.cpp"

using namespace std;

struct SDL_State {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

void cleanup(SDL_State &state);

int main() {
    SDL_State state;

	// Check if SDL initialized correctly
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error Initializing SDL3", nullptr);
		return 1;
	}

    int width = 800;
    int height = 800;
    state.window = SDL_CreateWindow("Boids", width, height, 0);

	// Check if SDL Window initialized correctly
    if (!state.window) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating window", state.window);
        cleanup(state);
        return 1;
    }

    state.renderer = SDL_CreateRenderer(state.window, nullptr);

	// Check if SDL Renderer intialized correctly
    if (!state.renderer) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating renderer", state.window);
        cleanup(state);
        return 1;
    }

	// Setup variables for delta-time calculation
	// 		Used for Boid movement so machine performance doesn't impact the speed of the visualizer
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	// Setup variable for framerate cap calculation?
	// #TODO Kinda janky solution, see if there is a better one someone smarter than me came up with
	float deltaTick = 0.0;
	const int framerate = 120; // framerate in frames / Second
	const float msPerFrame = (1.0 / framerate) * 1000; // Convert into ms / frame

	SDL_FColor color = SDL_FColor{0.5, 0, 0.5, 1};
	Flock flock{ 10, color };

    bool running = true;
    while (running) {
        SDL_Event event{0};
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: {
                    running = false;
                    break;
                }
            }
        }
		
		// Finalize calculations for delta-time
	    LAST = NOW;
	    NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );

		flock.tick(deltaTime);

		// TODO second part of Janky framerate solution (see line 53) 
		deltaTick += deltaTime;
		if (deltaTick > msPerFrame) { 	
			deltaTick = 0;

        	SDL_SetRenderDrawColor(state.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        	SDL_RenderClear(state.renderer);
			SDL_SetRenderDrawColor(state.renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

			flock.draw(state.renderer);

        	SDL_RenderPresent(state.renderer);

		}
    }

    cleanup(state);
	return 0;
}

void cleanup(SDL_State &state) {
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
    SDL_Quit();
}
