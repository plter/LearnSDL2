#include <SDL.h> // include SDL header
#include <cairo.h>


#define FONT_SIZE 50

void draw(cairo_surface_t *cairosurf) {
    cairo_t *cr = cairo_create(cairosurf);
    cairo_select_font_face(
            cr, "Sans",
            CAIRO_FONT_SLANT_NORMAL,
            CAIRO_FONT_WEIGHT_NORMAL
    );
    cairo_set_font_size(cr, FONT_SIZE);
    cairo_move_to(cr, 0, FONT_SIZE);
    cairo_show_text(cr, "Hello Cairo");

    cairo_destroy(cr);
}

int main(int argc, char *argv[]) {
    SDL_Surface *screen; // even with SDL2, we can still bring ancient code back
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO); // init video

    // create the window like normal
    window = SDL_CreateWindow(
            "Draw on surface",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            550, 400, SDL_WINDOW_SHOWN
    );

    // but instead of creating a renderer, we can draw directly to the screen
    screen = SDL_GetWindowSurface(window);
    cairo_surface_t *cairosurf = cairo_image_surface_create_for_data(
            screen->pixels, CAIRO_FORMAT_RGB24,
            screen->w, screen->h, screen->pitch
    );

    while (1) {
        // fill background
        SDL_FillRect(screen, NULL, 0xffffffff);
        draw(cairosurf);
        SDL_UpdateWindowSurface(window);

        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }
    }

    cairo_surface_destroy(cairosurf);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
