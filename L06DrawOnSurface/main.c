#include <SDL.h> // include SDL header

void draw(struct SDL_Surface *surface) {
    SDL_Rect rect = {0, 0, 100, 100};
    SDL_FillRect(surface, &rect, 0xffff0000);
}

int main(int argc, char *argv[]) {
    SDL_Surface *screen; // even with SDL2, we can still bring ancient code back
    SDL_Window *window;
    SDL_Surface *image;

    SDL_Init(SDL_INIT_VIDEO); // init video

    // create the window like normal
    window = SDL_CreateWindow(
            "Draw on surface",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            550, 400, 0
    );

    // but instead of creating a renderer, we can draw directly to the screen
    screen = SDL_GetWindowSurface(window);

    while (1) {
        // fill background
        SDL_FillRect(screen, NULL, 0xffffffff);
        draw(screen);
        SDL_UpdateWindowSurface(window);

        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
