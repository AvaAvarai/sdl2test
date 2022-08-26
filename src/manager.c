#include <SDL2/SDL.h>

// constants oto be parsed in from a config file.
#define PROG   "sdl2test: humble beginnings"
#define WIDTH  1280
#define HEIGHT 760
#define XSTART 100 // placeholder value
#define YSTART 100 // placeholder value
#define BKGND  "./img/grumpy-cat.bmp"
#define FLAGS  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

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
		_exit("SDL_CreateTextureFromSurface Error", SDL_GetError(), win, ren);
	SDL_FreeSurface(bmp);
	return tex;
}

