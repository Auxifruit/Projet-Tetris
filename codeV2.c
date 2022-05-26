#include "header.h"

int main() {
	int tab[TAILLE][TAILLE];
	int score = 1000;
	Tetromino tetro;
	Tetromino all_tetro[MAXTETRO];
	srand(time(NULL)); // the initialisation of the random function
	tetro.type = malloc(ROTATION * sizeof(int));
	for(int i = 0 ; i < ROTATION ; i++){
		tetro.type[i] = malloc(ROTATION * sizeof(int));
		for(int j = 0 ; j < ROTATION; j++){
			tetro.type[i][j] = malloc(ROTATION * sizeof(int));
			for(int k = 0 ; k < ROTATION; k++){
			tetro.type[i][j][k] = 0;
			}
		}
	}
	rand_tetro(&tetro);
	for(int l = 0; l < DIMENSION; l++) {
		for(int m = 0; m < DIMENSION; m++) {
			for(int n = 0; n < DIMENSION; n++) {
				if(n == 0) {
					printf("\n%c", block(tetro.type[l][m][n]));
				}
				else {
					printf("%c", block(tetro.type[l][m][n]));
				}
			}
		}
		printf("\n");
	}
	free(tetro.type);
/*	init_grid(tab);
	show_grid(tab);
	all_tetro[0] = rand_tetro();
	for(int i = 0 ; i < ROTATION; i++){
		for(int j=0 ; j < ROTATION; j++){
			printf("%d", all_tetro[0]);
		}
	}
	//place(tab, all_tetro[0]);
	//show_grid(tab);
	//timer();
	//game();
	end_game(score);
	printf("\n");*/

	return 0;
}
