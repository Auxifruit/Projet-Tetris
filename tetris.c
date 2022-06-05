#include "header.h"

int main() {
	int tab[TAILLE][TAILLE]; // will be the main grid of the tetri
	int score = 0; // initialization of the score to zero
	Tetromino tetro; // will countain the different tetromino
	srand(time(NULL)); // the initialisation of the random function
	logo(); // printf the classic tetris logo
	init_grid(tab); // initialize the grid
	int level = difficulty(); // choose the level of difficulty beetween 1 and 3 from easy to hard
	while(GAME == 0) { // loop that allows us to play the game
		verifgameover(tab, score); //verification for the for the first line of the tab, if there is a bloc, it's game over
		memory_block(&tetro); // memory allocation of the tetromino
		rand_tetro(&tetro); // return a random tetromino thanks to the "int_random()" function
		show_grid(tab); // show the grid in the terminal
		show_tetro(&tetro); // show the tetromino with its color and its rotation
		place(tab, &tetro, level); // place a block in the table
		score = verification(tab, score); // check if a line is complete, and if it's full it goes to the linedelete function and increment the score befor returning it
	}
	printf("\n");
	return 0;
}
