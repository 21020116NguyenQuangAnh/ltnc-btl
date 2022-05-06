#ifndef HEART_H
#define HEART_H

#include "common.h"

#define HEART_WIDTH 50;
#define HEART_HEIGHT 50;

struct Heart{
    int x;
    int y;
    SDL_Rect Rect;

    void setpos(int _x, int _y);
    void render(SDL_Renderer* renderer, SDL_Texture* heartTexture, SDL_Rect &Rect);
};
#endif // HEART_H
