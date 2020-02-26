#include <iostream>
#include <math.h>
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

#define WINDOW_WIDTH	1920
#define WINDOW_HEIGHT	1080

int main(int argc, char* argv[])
{
	SDL_Window* Window;
	SDL_Renderer* Renderer;

	int cont = 0;

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

	const int cx = WINDOW_WIDTH >> 1,
		cy = WINDOW_HEIGHT >> 1;


	SDL_Rect rectangulo = { 920, 520, 80, 80 };
	SDL_Rect bala = { 0, 0, 30, 30 };
	SDL_Event event;
	SDL_PollEvent(&event);

	while (event.key.keysym.sym != SDLK_ESCAPE)
	{
		SDL_SetRenderDrawColor(Renderer, 0, 0, 255, 255);
		SDL_RenderClear(Renderer);

		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(Renderer, &rectangulo);

		SDL_RenderPresent(Renderer);
		SDL_PollEvent(&event);

		if (event.key.keysym.sym == SDLK_DOWN) {
			rectangulo.y += 1;
			bala.x = rectangulo.x;
			bala.y = rectangulo.y;
		}
		if (event.key.keysym.sym == SDLK_LEFT) {
			rectangulo.x -= 1;
			bala.x = rectangulo.x;
			bala.y = rectangulo.y;
		}
		if (event.key.keysym.sym == SDLK_UP) {
			rectangulo.y -= 1;
			bala.x = rectangulo.x;
			bala.y = rectangulo.y;
		}
		if (event.key.keysym.sym == SDLK_RIGHT) {
			rectangulo.x += 1;
			bala.x = rectangulo.x;
			bala.y = rectangulo.y;
		}


		if (event.key.keysym.sym == SDLK_SPACE) {
			if(cont==0){
				bala.x = rectangulo.x;
				bala.y = rectangulo.y;
				cont++;
			}
			else {
				bala.x += 2;
				SDL_SetRenderDrawColor(Renderer, 0, 255, 0, 255);
				SDL_RenderFillRect(Renderer, &bala);
				SDL_RenderPresent(Renderer);
			}
		}

		if (rectangulo.x >= 1920) {
			rectangulo.x = 1;
		}
		if (rectangulo.x <= 0) {
			rectangulo.x = 1920;
		}
		if (rectangulo.y >= 1080) {
			rectangulo.y = 1;
		}
		if (rectangulo.y <= 0) {
			rectangulo.y = 1080;
		}

		SDL_Delay(1);
	}
	SDL_Quit();
	return 0;
}