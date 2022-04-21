#ifndef TEXT_H
#define TEXT_H

#include "common.h"

struct Text{
    int x;
    int y;
    SDL_Rect Rect;
    SDL_Color Color = {255, 255, 255};
    string content;

    SDL_Texture* loadFromRenderedText( TTF_Font* fontText, SDL_Renderer* renderer );
    void setpos(int _x, int _y);
    void render(SDL_Renderer* renderer, SDL_Texture* textTexture, SDL_Rect &Rect);
};
#endif // TEXT_H
