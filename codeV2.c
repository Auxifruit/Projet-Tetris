#include "header.h"

int main() {
	int tab[TAILLE][TAILLE];
	int score = 1000;
	Tetromino tetro;
	srand(time(NULL)); // the initialisation of the random function
	logo();
	memory_block(&tetro);
	rand_tetro(&tetro);
	init_grid(tab);
	//show_grid(tab);
	//show_tetro(&tetro);
	//show_grid(tab);
	//timer(diff);
	//end_game(score);
	//int diff = difficulty(); //difficulty of the game
	free(tetro.type);
	printf("\n");
	return 0;
}
