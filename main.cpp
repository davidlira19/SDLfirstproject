#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

#define WINDOW_WIDTH	1280
#define WINDOW_HEIGHT	720

int main(int argc, char* args[])
{
	SDL_Window* Window;
	SDL_Renderer* Renderer;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return -1;
	}

	Window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
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

	SDL_SetRenderDrawColor(Renderer, 0, 0, 255, 0);

	SDL_RenderClear(Renderer);

	int n = 0;
	const int cx = WINDOW_WIDTH >> 1,
		cy = WINDOW_HEIGHT >> 1;
	SDL_Rect rc = { 0, 0, 30, 70 };
	float alpha;
	while (n < 360)
	{
		rc.x += 70;
		rc.y += 40;

		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 0);
		SDL_RenderFillRect(Renderer, &rc);

		SDL_Delay(100);

		SDL_RenderPresent(Renderer);

		n += 18;
	}

	SDL_Delay(100);

	SDL_Quit();

	return 0;
}