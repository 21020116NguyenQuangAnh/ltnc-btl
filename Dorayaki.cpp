#include "Dorayaki.h"

using namespace std;

void Dorayaki::setpos(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Dorayaki::render(SDL_Renderer* renderer, SDL_Texture* dorayakiTexture, SDL_Rect &Rect)
{
    Rect.x = x;
    Rect.y = y;
    Rect.w = DORAYAKI_WIDTH;
    Rect.h = DORAYAKI_HEIGHT;
    SDL_RenderCopy( renderer, dorayakiTexture, NULL, &Rect);
}

void Dorayaki::move()
{
    y+=3;
        if(y > SCREEN_HEIGHT)
        {
            y = 0;
            x = rand()%1000;
        }
}
