#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>

#include "Utils.h"
#include "common.h"
#include "Text.h"
#include "Character.h"
#include "Enemy.h"
#include "game.h"

using namespace std;

Character character;
Enemy enemy[MAX];
Text text;
Text Button[2];
Text FinalScore;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Texture* menu = NULL;
SDL_Texture* background = NULL;
SDL_Texture* characterTexture = NULL;
SDL_Texture* enemyTexture = NULL;
SDL_Texture* ButtonTexture[2];

SDL_Rect characterRect;

Mix_Music *Music = NULL;
Mix_Chunk *Die = NULL;

TTF_Font* fontText = NULL;
TTF_Font* fontButton = NULL;

void open();
void close();

int main (int argc, char*argv[])
{

    initSDL(window, renderer);
    open();
    Mix_PlayMusic( Music, -1 );

    SDL_Event e;
    int score = 0;
    bool GameOver = false;

    for (int i = 0; i < MAX; i++)
    {
        enemy[i].setpos(SCREEN_WIDTH - 200 + 400 * i, place[rand()%3]);
    }
    SDL_RenderCopy(renderer, menu, nullptr, nullptr);
    Button[0].content = "Play Game";
    Button[0].Color = {255,0,0};
    Button[1].content = "Quit Game";
    Button[1].Color = {255,0,0};
    for (int i = 0; i < 2; i++)
    {
        ButtonTexture[i] = Button[i].loadFromRenderedText(fontButton, renderer);
        Button[i].setpos(0, 250 + 100 * i);
        Button[i].render(renderer, ButtonTexture[i], Button[i].Rect);
    }
    SDL_RenderPresent(renderer);
    if (Selection(e, Button) == 1)
        return 0;
    while(!GameOver)
    {
        score++;
        text.content = "Score: " + to_string(score);
        SDL_Texture* textTexture = text.loadFromRenderedText(fontText, renderer);
        text.setpos(0,10);
        for(int i = 0; i < MAX; i++)
        {
            enemy[i].move(score);
            if(check(enemy[i].eRect,characterRect))
            {
                GameOver = true;
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, nullptr, nullptr);
        character.render(renderer, characterTexture, characterRect);
        for(int i = 0; i < MAX; i++)
        enemy[i].render(renderer, enemyTexture, enemy[i].eRect);
        text.render(renderer, textTexture, text.Rect);
        SDL_RenderPresent(renderer);

        if (SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        character.move(e);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture( textTexture );
        textTexture = nullptr;
    }

    Mix_PlayChannel( -1, Die, 0 );
    waitUntilKeyPressed();
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    FinalScore.content = "Your score is: " + to_string(score);
    SDL_Texture* scoreTexture = FinalScore.loadFromRenderedText(fontText, renderer);
    FinalScore.setpos(0,10);
    FinalScore.render(renderer, scoreTexture, FinalScore.Rect);
    SDL_RenderPresent(renderer);
    waitUntilKeyPressed();
    SDL_DestroyTexture( scoreTexture );
    scoreTexture = nullptr;
    close();
    return 0;
}

void open()
{
    menu = loadTexture("menu.png",renderer);
    background = loadTexture("Wallpaper.jpg", renderer);
    characterTexture = loadTexture("mon.png", renderer);
    enemyTexture = loadTexture("mouse.png", renderer);
    fontText = TTF_OpenFont( "OpenSans_Regular.ttf", 24 );
    fontButton = TTF_OpenFont( "SuperMario256.ttf", 36);
    Music = Mix_LoadMUS( "DoraemonNoUta.wav" );
	Die = Mix_LoadWAV( "doraemonsms.wav" );
}

void close()
{
    SDL_DestroyTexture( menu );
    menu = nullptr;
    SDL_DestroyTexture( background );
    background = nullptr;
    SDL_DestroyTexture( characterTexture );
    characterTexture = nullptr;
    SDL_DestroyTexture( enemyTexture );
    enemyTexture = nullptr;
    Mix_FreeChunk( Die );
    Die = nullptr;
    Mix_FreeMusic( Music );
    Music = nullptr;
    quitSDL(window, renderer);
    TTF_CloseFont( fontText );
	fontText = nullptr;
}










