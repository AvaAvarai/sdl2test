// Entry point class
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "manager.h"

int main()
{
	struct Gfx handlers = _init();
	SDL_Window* win = handlers.win;
	SDL_Renderer* ren = handlers.ren;

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
