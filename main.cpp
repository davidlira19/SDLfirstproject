#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

#define WINDOW_WIDTH	1920
#define WINDOW_HEIGHT	1080

int main(int argc, char* args[])
{
	SDL_Window* Window;
	SDL_Renderer* Renderer;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return -1;
	}

	Window = SDL_CreateWindow("SDL CUADRADO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (Window == NULL)
	{
		SDL_Log("Unable to create window: %s", SDL_GetError());
		return -1;
	}

	Renderer = SDL_CreateRenderer(Window, -1, 0);
	if (Renderer == NULL)
	{
		SDL_Log("Unable to create rendering context: %s", SDL_GetError());
		return -1;
	}

	int n = 0;
	const int cx = WINDOW_WIDTH >> 1,
		cy = WINDOW_HEIGHT >> 1;
	SDL_Rect rc = { 960, 540, 80, 80 };

	SDL_Event event;
	SDL_PollEvent(&event);

	while (event.key.keysym.sym != SDLK_x)
	{

		SDL_SetRenderDrawColor(Renderer, 0, 0, 225, 0);
		SDL_RenderClear(Renderer);

		if (event.key.keysym.sym == SDLK_w) {
			rc.y += 5;
		}
		if (event.key.keysym.sym == SDLK_a) {
			rc.x -= 5;
		}
		if (event.key.keysym.sym == SDLK_s) {
			rc.y -= 5;
		}
		if (event.key.keysym.sym == SDLK_d) {
			rc.x += 5;
		}

		SDL_SetRenderDrawColor(Renderer, 0, 0, 225, 0);
		SDL_RenderClear(Renderer);
		SDL_SetRenderDrawColor(Renderer, 225, 0, 0, 0);
		SDL_RenderFillRect(Renderer, &rc);

		SDL_Delay(500);

		SDL_RenderPresent(Renderer);

		n += 15;
	}

	SDL_Quit();

	return 0;
}