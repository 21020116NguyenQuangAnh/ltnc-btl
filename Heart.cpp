#include "Heart.h"

using namespace std;

void Heart::setpos(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Heart::render(SDL_Renderer* renderer, SDL_Texture* heartTexture, SDL_Rect &Rect)
{
    Rect.x = x;
    Rect.y = y;
    Rect.w = HEART_WIDTH;
    Rect.h = HEART_HEIGHT;
    SDL_RenderCopy( renderer, heartTexture, NULL, &Rect);
}
