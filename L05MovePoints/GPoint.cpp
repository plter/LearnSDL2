//
// Created by yunp.top on 2020/10/18.
//

#include "GPoint.h"
#include "constants.h"

GPoint::GPoint() :
        speedX(((float) (random() % 10000)) / 10000 - 0.5f),
        speedY(((float) (random() % 10000)) / 10000 - 0.5f),
        x(WINDOW_WIDTH / 2),
        y(WINDOW_HEIGHT / 2) {
}

void GPoint::draw(SDL_Renderer *renderer) {
    x += speedX;
    y += speedY;
//    SDL_Log("%f,%f,%f,%f", x, y, speedX, speedY);
    if (x > WINDOW_WIDTH) {
        speedX = -abs(speedX);
    }
    if (x < 0) {
        speedX = abs(speedX);
    }
    if (y > WINDOW_HEIGHT) {
        speedY = -abs(speedY);
    }
    if (y < 0) {
        speedY = abs(speedY);
    }
    SDL_RenderDrawPointF(renderer, x, y);
}
