#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PROG   "sdl2test: humble beginings"
#define WIDTH  1280
#define HEIGHT 760
#define XSTART 100
#define YSTART 100

#define BKGND  "./img/grumpy-cat.bmp"

int _exit( char* msg, const char* err, SDL_Window* win, SDL_Renderer* ren )
{
	fprintf(stderr, msg, err);
	if (win != NULL)
		SDL_DestroyWindow(win);
	if (ren != NULL)
		SDL_DestroyRenderer(ren);
	return EXIT_FAILURE;
}

SDL_Texture* _bmploadtex( char* path, SDL_Window* win, SDL_Renderer* ren )
{
	SDL_Surface* bmp = SDL_LoadBMP(path);
	if (bmp == NULL)
		_exit("SDL_LoadBMP Error", SDL_GetError(), win, ren);

	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, bmp);
	if (tex == NULL)
		_exit("SDL_CreateTextureFromScratch Error", SDL_GetError(), win, ren);

	SDL_FreeSurface(bmp);
	return tex;
}

int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		_exit("SDL_Init Error", SDL_GetError(), NULL, NULL);

	SDL_Window* win = SDL_CreateWindow(PROG, XSTART, YSTART, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (win == NULL)
		_exit("SDL_CreateWindow Error", SDL_GetError(), NULL, NULL);

	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL)
		_exit("SDL_CreateRenderer Error", SDL_GetError(), win, NULL); 

	SDL_Texture* tex = _bmploadtex(BKGND, win, ren);

	bool quit = false;
	SDL_Event event;

	while ( !quit )
	{
		SDL_WaitEvent(&event);
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
