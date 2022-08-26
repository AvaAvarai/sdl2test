// Entry point class
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "manager.h"

int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		_exit("SDL_Init Error", SDL_GetError(), NULL, NULL);

	SDL_Window* win = SDL_CreateWindow(PROG, XSTART, YSTART, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (win == NULL)
		_exit("SDL_CreateWindow Error", SDL_GetError(), NULL, NULL);

	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, FLAGS);
	if (ren == NULL)
		_exit("SDL_CreateRenderer Error", SDL_GetError(), win, NULL); 

	SDL_Texture* tex = _bmploadtex(BKGND, win, ren);

	bool quit = false;
	SDL_Event event;

	while ( !quit )
	{
		SDL_WaitEvent(&event);
		// printf("Event received: %s\n", event);
		if ( event.type == SDL_QUIT )
		{
			quit = true;
		}
		SDL_RenderClear(ren);
		SDL_RenderCopy(ren, tex, NULL, NULL);
		SDL_RenderPresent(ren);
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return EXIT_SUCCESS;
}
