CC=egcc
OBJS=main.c
SRCFOLDER=src/
PROG=sdl2test
CFLAGS=-std=c99

all: $(SRCFOLDER)$(OBJS)
	$(CC) $(SRCFOLDER)$(OBJS) $(CFLAGS) `sdl2-config --cflags --libs` -o $(PROG)
