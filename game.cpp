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
