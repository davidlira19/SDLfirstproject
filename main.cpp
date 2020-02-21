#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

int main(int argc, char** argv) {


	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	std::cout << "Resource path is: " << getResourcePath() << std::endl;

	SDL_Quit();
	return 0;
}