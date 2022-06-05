CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
BUILD_DIR=FICHIER_OBJET
OBJ2=$(addprefix $(BUILD_DIR)/, $(OBJ))

all: tetris

$(BUILD_DIR)/%.o: %.c header.h $(BUILD_DIR)
	$(CC) -c $< -o $@

tetris: $(OBJ2)
	$(CC) $^ -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/	
