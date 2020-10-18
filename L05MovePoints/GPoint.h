//
// Created by yunp.top on 2020/10/18.
//

#ifndef L05MOVEPOINTS_GPOINT_H
#define L05MOVEPOINTS_GPOINT_H

#include <SDL.h>

class GPoint {

private:
    float x, y, speedX, speedY;

public:
    GPoint();

    void draw(SDL_Renderer *renderer);
};


#endif //L05MOVEPOINTS_GPOINT_H
