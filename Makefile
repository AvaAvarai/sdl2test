CC=egcc
OBJS=main.c
PROG=sdl2test

all: $(OBJS)
	$(CC) $(OBJS) `sdl2-config --cflags --libs` -o $(PROG)
