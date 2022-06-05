CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
BUILD_DIR=FICHIER_OBJET_EXE
OBJ2=$(addprefix $(BUILD_DIR)/, $(OBJ))

all: $(BUILD_DIR)/tetris

$(BUILD_DIR)/%.o: %.c header.h $(BUILD_DIR)
	$(CC) -c $< -o $@

$(BUILD_DIR)/tetris: $(OBJ2)
	$(CC) $^ -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/	
