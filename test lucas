CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all:exec

%.o: %.c
	$(CC) -c $< -o $@

exec: $(OBJ)
	$(CC) $^ -o $@
