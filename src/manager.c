#include "manager.h"

struct Gfx _init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		_exit("SDL_Init Error", SDL_GetError(), NULL, NULL);

	SDL_Window *win = SDL_CreateWindow(PROG, XSTART, YSTART, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (win == NULL)
		_exit("SDL_CreateWindow Error", SDL_GetError(), NULL, NULL);

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, FLAGS);
	if (ren == NULL)
		_exit("SDL_CreateRenderer Error", SDL_GetError(), win, NULL);

	struct Gfx out = {win, ren};
	return out;
}

void _exit( char* msg, const char* err, SDL_Window* win, SDL_Renderer* ren )
{
	fprintf(stderr, err);
	printf("%n");
	if (win != NULL)
		SDL_DestroyWindow(win);
	if (ren != NULL)
		SDL_DestroyRenderer(ren);
	exit(EXIT_FAILURE);
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

