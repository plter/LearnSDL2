#include <SDL.h>
#include "GPoint.h"
#include "main.h"
#include <vector>
#include "constants.h"
#include <string>

std::vector<GPoint> points;

Uint32 lastTicks = 0;
uint64_t frames = 0;

int main() {
    createGPoints();

    SDL_Window *win;
    SDL_Renderer *renderer;
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Unable to init SLD: %s", SDL_GetError());
        return 1;
    }
    win = SDL_CreateWindow(
            "Hello World",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH, WINDOW_HEIGHT,
            SDL_WINDOW_OPENGL
    );
    if (win == nullptr) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(win, -1, RENDERING_MODE);
    if (renderer == nullptr) {
        SDL_Log("Can not create renderer: %s", SDL_GetError());
        return 1;
    }

    while (true) {
        Uint32 renderStartTicks = SDL_GetTicks();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        draw(renderer);
        SDL_RenderPresent(renderer);

        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }
        Uint32 renderEndTicks = SDL_GetTicks();
        int32_t delay = 16 - (renderEndTicks - renderStartTicks);
        if (delay > 0) {
            SDL_Delay(delay);
        }

        frames++;
        Uint32 current = SDL_GetTicks();
        if (frames % 30 == 0) {
            Uint32 fps = 1000 / (current - lastTicks);
            std::string fpsStr = "Rendering ";
            fpsStr += std::to_string(POINT_COUNT);
            fpsStr += " points, fps: ";
            fpsStr += std::to_string(fps);
            SDL_SetWindowTitle(win, fpsStr.c_str());
        }
        lastTicks = current;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}

void createGPoints() {
    for (int i = 0; i < POINT_COUNT; ++i) {
        GPoint p;
        points.push_back(p);
    }
}

void draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    for (int i = 0; i < POINT_COUNT; ++i) {
        auto p = &points[i];
        p->draw(renderer);
    }
}
