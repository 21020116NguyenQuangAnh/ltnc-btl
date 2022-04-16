#include "Character.h"

using namespace std;

void Character::render(SDL_Renderer* renderer, SDL_Texture* characterTexture, SDL_Rect &characterRect)
{
    characterRect.x = x;
    characterRect.y = y;
    characterRect.w = CHARACTER_WIDTH;
    characterRect.h = CHARACTER_HEIGHT;
    SDL_RenderCopy( renderer, characterTexture, NULL, &characterRect );
}

void Character::move(SDL_Event &e)
{
        if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE: break;
                    case SDLK_LEFT: x = (x + SCREEN_WIDTH - step) % SCREEN_WIDTH;
                        break;
                    case SDLK_RIGHT: x = (x + step) % SCREEN_WIDTH;
                        break;
                    case SDLK_DOWN: y = (y + step) % SCREEN_HEIGHT;
                        break;
                    case SDLK_UP: y = (y + SCREEN_HEIGHT - step) % SCREEN_HEIGHT;
                        break;
                    default: break;
                }
            }
}



