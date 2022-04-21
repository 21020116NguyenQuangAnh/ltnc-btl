#include "Text.h"

using namespace std;

SDL_Texture* Text::loadFromRenderedText( TTF_Font* fontText, SDL_Renderer* renderer )
{
        SDL_Texture* newTexture = NULL;
        SDL_Surface* textSurface = TTF_RenderText_Solid( fontText , content.c_str(), Color );
        if( textSurface == NULL )
        {
            cout<< "Unable to render text surface! SDL_ttf Error:" <<endl;
            TTF_GetError();
        }
        else
        {
            newTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
            if( newTexture == NULL )
            {
                cout<< "Unable to create texture from rendered text! SDL Error:" <<endl;
                SDL_GetError();
            }
            SDL_FreeSurface( textSurface );
        }
        return newTexture;
}

void Text::setpos(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Text::render (SDL_Renderer* renderer, SDL_Texture* textTexture, SDL_Rect &Rect)
{
        SDL_QueryTexture(textTexture, nullptr, nullptr, &Rect.w, &Rect.h);
        Rect.x = (SCREEN_WIDTH - Rect.w) / 2;
        Rect.y = y;
        Rect.w = Rect.w;
        Rect.h = Rect.h;
        SDL_RenderCopy (renderer, textTexture, NULL, &Rect);
}
