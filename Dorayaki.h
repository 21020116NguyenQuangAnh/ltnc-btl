#ifndef DORAYAKI_H
#define DORAYAKI_H

#include <cstdlib>
#include <ctime>
#include "common.h"

#define DORAYAKI_WIDTH 100
#define DORAYAKI_HEIGHT 100

struct Dorayaki{
    int x;
    int y;
    SDL_Rect Rect;

    void setpos(int _x, int _y);
    void render(SDL_Renderer* renderer, SDL_Texture* dorayakiTexture, SDL_Rect &Rect);
    void move();
};

#endif // DORAYAKI_H
