#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>

#define MAX 5
using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Game";

SDL_Texture* loadTexture( string path, SDL_Renderer* renderer );
void OpenAudio ();

#endif // COMMON_H
