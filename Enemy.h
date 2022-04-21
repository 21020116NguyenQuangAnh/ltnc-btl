#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>
#include <ctime>
#include "common.h"

#define ENEMY_WIDTH 130
#define ENEMY_HEIGHT 100

const int place[] = {100,300,500};

struct Enemy{
    int x;
    int y;
    SDL_Rect eRect;

    void setpos(int _x, int _y);
    void render(SDL_Renderer* renderer, SDL_Texture* enemyTexture, SDL_Rect &eRect);
    void move(int score);
};
#endif // ENEMY_H
