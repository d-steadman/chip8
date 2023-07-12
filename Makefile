CC = gcc
CFLAGS = -g -lncurses
SRC_FILES = $(wildcard *.c)

chip8: $(SRC_FILES)
	echo $(SRC_FILES)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f chip8
