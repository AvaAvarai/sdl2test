CC=egcc
ENTRY=main.c
FILES=manager.c
SRC=src/
PROG=sdl2test
CFLAGS=-std=c99

.PHONY: compile clean

compile: $(SRC)$(ENTRY)
	@echo "Compiling"
	$(CC) $(SRC)$(ENTRY) $(SRC)$(FILES) $(CFLAGS) `sdl2-config --cflags --libs` -o $(PROG)

clean:
	@echo "Cleaning"
	rm -rf $(PROG)
	rm -rf *.core
