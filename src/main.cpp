#include "flock.cpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_render.h>

using namespace std;

struct SDL_State {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

void cleanup(SDL_State &state);

int main() {
    SDL_State state;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error Initializing SDL3", nullptr);
		return 1;
	}

    int width = 800;
    int height = 800;
    state.window = SDL_CreateWindow("Boids", width, height, 0);

    if (!state.window) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating window", state.window);
        cleanup(state);
        return 1;
    }

    state.renderer = SDL_CreateRenderer(state.window, nullptr);

    if (!state.renderer) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating renderer", state.window);
        cleanup(state);
        return 1;
    }

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

        SDL_SetRenderDrawColor(state.renderer, 255, 255, 255, 255);
        SDL_RenderClear(state.renderer);

        SDL_RenderPresent(state.renderer);
    }

    cleanup(state);
	return 0;
}

void cleanup(SDL_State &state) {
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
    SDL_Quit();
}
