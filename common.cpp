#include "common.h"

using namespace std;

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

 void PauseGame (SDL_Event &e)
 {
             if (e.type == SDL_KEYDOWN)
             {
                 if (e.key.keysym.sym == SDLK_SPACE)
                    waitUntilKeyPressed();
             }
}

void PauseMusic (SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN)
    {
        if (e.key.keysym.sym == SDLK_m)
        {
            if(Mix_PausedMusic() == 1)
            {
                Mix_ResumeMusic();
            }
            else
            {
                Mix_PauseMusic();
            }
        }
    }
}

int GetHighScore (string path)
{
    int high;
    ifstream file (path);
    file >> high;
    return high;
}

void UpdateHighScore (string path, int score, int highscore)
{
    ofstream file (path);
    if (score > highscore)
        highscore = score;
    file << highscore;
}


