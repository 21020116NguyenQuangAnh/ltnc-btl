#include "Character.h"

using namespace std;

void Character::setpos(int _x, int _y)
{
    x = _x;
    y = _y;
}

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
        switch (e.type)
        {
            case SDL_KEYDOWN:
            {
                    switch (e.key.keysym.sym) {
                        case SDLK_LEFT:
                        {
                            x = (x - step);
                            if (x < 0)
                                    x = SCREEN_WIDTH - CHARACTER_WIDTH;
                        }
                            break;
                        case SDLK_RIGHT:
                        {
                            x = (x + step);
                            if (x > SCREEN_WIDTH - CHARACTER_WIDTH)
                                x = 0;
                        }
                            break;
                        case SDLK_DOWN:
                        {
                            y = (y + step);
                            if (y > SCREEN_HEIGHT - CHARACTER_HEIGHT)
                                y = 0;
                        }
                            break;
                        case SDLK_UP:
                         {
                            y = (y - step);
                            if (y < 0)
                                y = SCREEN_HEIGHT - CHARACTER_HEIGHT;
                         }
                            break;
                        default: break;
                    }
            }
            break;
            case SDL_MOUSEMOTION:
            {
                int x_dir = x - e.motion.x;
                int y_dir = y - e.motion.y;
                double distance = sqrt(x_dir * x_dir + y_dir * y_dir);
                if (distance >= 25)
                {
                x -= 50 * x_dir/distance;
                y -= 50 * y_dir/distance;
                }
            }
            break;
            case SDL_MOUSEBUTTONDOWN:
            {
                switch (e.button.button)
                {
                    case SDL_BUTTON_LEFT:
                    {
                         x = e.button.x;
                         y = e.button.y;
                    }
                    break;
                    case SDL_BUTTON_RIGHT:
                    {
                         x = 0;
                         y = SCREEN_HEIGHT - CHARACTER_HEIGHT;
                    }

                }

            }
            break;
            default: break;
        }
}






