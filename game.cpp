#include "game.h"

using namespace std;

bool check (SDL_Rect object1Rect, SDL_Rect& characterRect)
{
    int left1 = object1Rect.x;
    int right1 = object1Rect.x + object1Rect.w;
    int top1 = object1Rect.y;
    int bot1 = object1Rect.y + object1Rect.h;

    int left2 = characterRect.x;
    int right2 = characterRect.x + characterRect.w;
    int top2 = characterRect.y;
    int bot2 = characterRect.y + characterRect.h;

    if (left2 + 60 < right1 && right2 - 60 > right1 )
    {
        if (top2 < bot1 && bot2 > bot1)
            return true;
        else if (top2 < top1 && bot2 > top1)
            return true;
    }
    if (left2 + 60 < left1 && right2 - 60 > left1)
    {
        if (top2 < bot1 && bot2 > bot1)
            return true;
        else if (top2 < top1 && bot2 > top1)
            return true;
    }
    return false;
}

bool CheckInside (int &x, int &y, SDL_Rect& rect)
{
    if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
        return true;
    return false;
}

int Selection(SDL_Event &e, Text Button[])
{
    while (true)
    {
        if (SDL_PollEvent(&e)!=0)
        {
            switch (e.type)
            {
                case SDL_QUIT:
                    return 1;
                case SDL_MOUSEBUTTONDOWN:
                {
                     for (int i = 0; i < 2; i++)
                     {
                         if (CheckInside(e.button.x, e.button.y, Button[i].Rect))
                            return i;
                     }
                }
                break;
                default: break;
            }
        }
    }
}
