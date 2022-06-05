CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all:tetris

%.o: %.c header.h
	$(CC) -c $< -o $@

tetris: $(OBJ)
	$(CC) $^ -o $@
