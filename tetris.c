#include "header.h"

int main() {
	int tab[TAILLE][TAILLE];
	int score = 0;
	Tetromino tetro;
	srand(time(NULL)); // the initialisation of the random function
	logo();
	init_grid(tab);
	int level = difficulty(); // choose the level of difficulty beetween 1 and 3 from easy to hard
	while(GAME == 0) {
		verifgameover(tab, score); //verification for the for the first line of the tab, if there is a bloc, it's game over
		memory_block(&tetro);
		rand_tetro(&tetro);
		show_grid(tab);
		show_tetro(&tetro);
		place(tab, &tetro, level);
		score = verification(tab, score);
	}
	printf("\n");
	return 0;
}
