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

void Enemy::move(int time)
{
    int speed = 5 + (time/1000);
    const int max_speed = 20;
        if (speed > max_speed)
        {
            speed = max_speed;
        }
    x-=speed;
        if(x < 0)
        {
            int random = rand()%3;
            y = place[random];
            x = 1200;
        }
}

