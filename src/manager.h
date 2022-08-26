#ifndef MANAGER_H
#define MANAGER_H

#include <SDL2/SDL.h>

#define PROG   "sdl2test: humble beginnings"
#define WIDTH  1280
#define HEIGHT 760
#define XSTART 100 // placeholder value
#define YSTART 100 // placeholder value
#define BKGND   "./img/grumpy-cat.bmp"
#define FLAGS  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

struct Gfx
{
	SDL_Window *win;
	SDL_Renderer *ren;
};

struct Gfx _init();
void _exit( char* msg, const char* err, SDL_Window* win, SDL_Renderer* ren );
SDL_Texture* _bmploadtex( char* path, SDL_Window* win, SDL_Renderer* ren );

#endif /* MANAGER_H */
