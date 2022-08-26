#include "manager.h"

int _exit( char* msg, const char* err, SDL_Window* win, SDL_Renderer* ren )
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

