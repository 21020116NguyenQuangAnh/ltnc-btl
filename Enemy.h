#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>
#include <ctime>
#include "common.h"
#include "game.h"

#define ENEMY_WIDTH 130
#define ENEMY_HEIGHT 100

const int place[] = {100,300,500};

struct Enemy{
    int x;
    int y;

    SDL_Rect eRect;

    void setpos(int a, int b)
    {
        x = a;
        y = b;
    }

    void render(SDL_Renderer* renderer, SDL_Texture* enemyTexture, SDL_Rect &eRect)
    {
            eRect.x = x;
            eRect.y = y;
            eRect.w = ENEMY_WIDTH;
            eRect.h = ENEMY_HEIGHT;
            SDL_RenderCopy( renderer, enemyTexture, NULL, &eRect);
    }

    void move(int score)
    {
        x-=5 + (score/500);
                    if(x < 0)
                    {
                    int random = rand()%3;
                    y = place[random];
                    x = 1200;
                    }
    }
};
#endif // ENEMY_H
