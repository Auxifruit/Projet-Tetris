#include "header.h"

int main() {
	int tab[TAILLE][TAILLE];
	int score = 1000;
	Tetromino tetro;
	Tetromino all_tetro[MAXTETRO];
	tetro.type = malloc(ROTATION * sizeof(char**));
	for(int k = 0 ; k < ROTATION ; k++){
		tetro.type[k] = malloc(ROTATION * sizeof(char**));
	}
	for(int i=0 ; i < ROTATION; i++){
		for(int j=0 ; j < ROTATION; j++){
			tetro.type[i][j] = malloc(ROTATION * sizeof(char***));
		}
	}
	srand(time(NULL)); // the initialisation of the random function
	init_grid(tab);
	show_grid(tab);
	all_tetro[0] = rand_tetro();
	for(int i = 0 ; i < ROTATION; i++){
		for(int j=0 ; j < ROTATION; j++){
			printf("%d", all_tetro[0]->type[i][j]);
		}
	}
	//place(tab, all_tetro[0]);
	//show_grid(tab);
	//timer();
	//game();
	end_game(score);
	printf("\n");
	return 0;
}

