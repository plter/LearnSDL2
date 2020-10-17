#include <SDL.h>

#define WIDTH 550
#define HEIGHT 400

void drawBackground(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect = {0, 0, WIDTH, HEIGHT};
    SDL_RenderFillRect(renderer, &rect);
}

void drawScreen(struct SDL_Renderer *renderer) {
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

void draw(SDL_Renderer *renderer) {
    drawBackground(renderer);
    drawScreen(renderer);
}

int main() {
    SDL_Window *win;
    SDL_Renderer *renderer;
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Unable to init SLD: %s", SDL_GetError());
        return 1;
    }
    win = SDL_CreateWindow(
            "Hello World",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WIDTH, HEIGHT,
            SDL_WINDOW_OPENGL
    );
    if (win == NULL) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_Log("Can not create renderer: %s", SDL_GetError());
        return 1;
    }

    while (1) {
        SDL_RenderClear(renderer);
        draw(renderer);
        SDL_RenderPresent(renderer);

        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
