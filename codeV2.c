#include "header.h"

int main() {
	int tab[TAILLE][TAILLE];
	int score = 1000;
	Tetromino tetro;
	srand(time(NULL)); // the initialisation of the random function
	memory_block(&tetro);
	rand_tetro(&tetro);
	init_grid(tab);
	show_grid(tab);
	show_tetro(&tetro);
	//place(tab, &tetro);
	//show_grid(tab);
	//timer();
	//game();
	//end_game(score);
	printf("\n");

	return 0;
}
