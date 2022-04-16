#include "Enemy.h"

using namespace std;

void Enemy::setpos(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Enemy::render(SDL_Renderer* renderer, SDL_Texture* enemyTexture, SDL_Rect &eRect)
{
    eRect.x = x;
    eRect.y = y;
    eRect.w = ENEMY_WIDTH;
    eRect.h = ENEMY_HEIGHT;
    SDL_RenderCopy( renderer, enemyTexture, NULL, &eRect);
}

void Enemy::move(int score)
{
     x-=5 + (score/500);
        if(x < 0)
        {
            int random = rand()%3;
            y = place[random];
            x = 1200;
        }
}

