#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#define MAX 5

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Game";

const int place[] = {100,300,500};

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* background,
    SDL_Texture* character, SDL_Texture* object[], SDL_Rect& characterRect, SDL_Rect objectRect[]);

SDL_Texture* loadTexture( string path, SDL_Renderer* renderer );

bool check (SDL_Rect object1Rect, SDL_Rect& characterRect);





int main (int argc, char*argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    SDL_Texture* background = loadTexture("Wallpaper.jpg", renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Texture* character = loadTexture("mon.png", renderer);
    SDL_Rect characterRect;
    SDL_QueryTexture(character, nullptr, nullptr, &characterRect.w, &characterRect.h);
    characterRect.x = 0;
    characterRect.y = 400;
    characterRect.w = characterRect.w/4.0;
    characterRect.h = characterRect.h/4.0;
    SDL_RenderCopy( renderer, character, NULL, &characterRect );
    SDL_RenderPresent( renderer );

    SDL_Texture* object[MAX];
    SDL_Rect objectRect[MAX];

    for (int i = 0; i < MAX; i++)
    {
        object[i] = loadTexture("mouse.png", renderer);
        SDL_QueryTexture(object[i], nullptr, nullptr, &objectRect[i].w, &objectRect[i].h);
        objectRect[i].x = SCREEN_WIDTH - 200 + i * 400;
        objectRect[i].y = SCREEN_HEIGHT - 100;
        objectRect[i].w = objectRect[i].w/6.0;
        objectRect[i].h = objectRect[i].h/6.0;
        SDL_RenderCopy( renderer, object[i], NULL, &objectRect[i] );
        SDL_RenderPresent( renderer );
    }

    SDL_Event e;
    int step=200;

    srand(time(0));

    while(true)
    {
        for(int i = 0; i < MAX; i++)
        {
            SDL_Delay(5);
            objectRect[i].x-=10;
                    if(objectRect[i].x < 10)
                    {
                    int random = rand()%3;
                    objectRect[i].y = place[random];
                    objectRect[i].x = 1200;
                    }
            if(check(objectRect[i],characterRect))
            {
               SDL_DestroyTexture( background );
    background = nullptr;
    SDL_DestroyTexture( character );
    character = nullptr;
    for ( int i = 0; i < MAX; i++ )
    {
    SDL_DestroyTexture( object[i] );
    object[i] = nullptr;
    }

    quitSDL(window, renderer);

            }
        }


        refreshScreen(window, renderer, background, character, object, characterRect, objectRect);
        if (SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break;
        		case SDLK_LEFT: characterRect.x = (characterRect.x + SCREEN_WIDTH - step) % SCREEN_WIDTH;
        			break;
            	case SDLK_RIGHT: characterRect.x = (characterRect.x + step) % SCREEN_WIDTH;
            		break;
            	case SDLK_DOWN: characterRect.y = (characterRect.y + step) % SCREEN_HEIGHT;
					break;
            	case SDLK_UP: characterRect.y = (characterRect.y + SCREEN_HEIGHT - step) % SCREEN_HEIGHT;
            	    break;
                default: break;
			}
        }


        }


    SDL_DestroyTexture( background );
    background = nullptr;
    SDL_DestroyTexture( character );
    character = nullptr;
    for ( int i = 0; i < MAX; i++ )
    {
    SDL_DestroyTexture( object[i] );
    object[i] = nullptr;
    }

    quitSDL(window, renderer);

    return 0;
}

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Texture* loadTexture( string path, SDL_Renderer* renderer )
{
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if ( loadedSurface == nullptr )
        cout << "Unable to load image " << path << " SDL_image Error: "
             << IMG_GetError() << endl;
    else {
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == nullptr )
            cout << "Unable to create texture from " << path << " SDL Error: "
                 << SDL_GetError() << endl;
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* background,
    SDL_Texture* character, SDL_Texture* object[], SDL_Rect& characterRect, SDL_Rect objectRect[])
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_RenderCopy( renderer, character, NULL, &characterRect );
    for (int i = 0; i < MAX; i++)
    {
      SDL_RenderCopy( renderer, object[i], NULL, &objectRect[i] );
    }

    SDL_RenderPresent(renderer);
}

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

    if (left2 < right1 && right2 - 75 > right1 )
    {
        if (top2 < bot1 && bot2 > bot1)
            return true;
        else if (top2 < top1 && bot2 > top1)
            return true;
    }
    if (left2 < left1 && right2 - 75 > left1)
    {
        if (top2 < bot1 && bot2 > bot1)
            return true;
        else if (top2 < top1 && bot2 > top1)
            return true;
    }
    return false;
}



