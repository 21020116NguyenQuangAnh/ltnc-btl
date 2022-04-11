#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "common.h"

using namespace std;

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();

#endif // UTILS_H
