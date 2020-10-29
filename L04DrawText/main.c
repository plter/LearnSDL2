#include <SDL.h>
#include <SDL_ttf.h>

#define WIDTH 550
#define HEIGHT 400

#define FONT_FILE "Arial.ttf"
#define WORDS "https://yunp.top"

SDL_Texture *text;

void draw(SDL_Renderer *renderer) {
    SDL_Rect r;
    SDL_QueryTexture(text, NULL, NULL, &r.w, &r.h);
    r.x = (WIDTH - r.w) / 2;
    r.y = (HEIGHT - r.h - 100) / 2;
    SDL_RenderCopy(renderer, text, NULL, &r);
}

struct SDL_Texture *createText(SDL_Renderer *renderer) {
    TTF_Font *font = TTF_OpenFont(FONT_FILE, 32);
    if (font == NULL) {
        SDL_Log("Can not open font");
        return NULL;
    }
    SDL_Color c = {0, 0, 0};
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font, WORDS, c);
    if (surface == NULL) {
        SDL_Log("Can not create surface for text");
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    return texture;
}

int main() {
    SDL_Window *win;
    SDL_Renderer *renderer;
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Unable to init SLD: %s", SDL_GetError());
        return 1;
    }

    if (TTF_Init()) {
        SDL_Log("Can not init ttf: %s", TTF_GetError());
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

    text = createText(renderer);
    if (text == NULL) {
        SDL_Log("Can not create text");
    }

    while (1) {
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
    }

    if (text != NULL) {
        SDL_DestroyTexture(text);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
