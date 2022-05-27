#include "header.h"

char input() { // input a char
	char c;
	while (((c=getchar()) == '\n'));
	return c;
}

void place(int tab[TAILLE][TAILLE], Tetromino* tetro) {// place a block in the grid
	char c;
	do {
		printf("\non which column you want to place your tetromino ? \n");
		c = input();
	} while (c < 65 || c > 74);
	for(int i = 0; i < DIMENSION; i++) {
		for(int j = 0; j < DIMENSION; j++) {
			tab[TAILLE - i -1][(int)(c-65) + j] = tetro->type[0][i][j];
		}
	}
}
	
void init_grid(int tab[TAILLE][TAILLE]) { // initialize the grid
	for(int i = 0; i < TAILLE; i++){
		for(int j = 0; j < TAILLE; j++) {
			tab[i][j] = 0;
		}
	}
}

void show_grid(int tab[TAILLE][TAILLE]) { // show the grid, used to update the grid
	printf("\nThis is your grid: \n");
	for(int k = 0; k < TAILLE; k++) {
		printf(" %c", 65 + k);
	}
	for(int a = 0; a < TAILLE; a++){
		for(int b = 0; b < TAILLE; b++){
			if(b == 0) {
				printf("\n|%c|", block(tab[a][b]));
			}
			else{
				printf("%c|", block(tab[a][b]));
			}
		}
	}
}

int block(int p) { // transform int in char
	switch(p) {
		case 0: return(32); break;
		case 1: return(64); break;
		default: return(69);
	}
}
int difficulty() { // choose the level of difficulty beetween 1 and 3 from easy to hard
	int *choice;
	printf("\n");
	printf("choose your difficulty: \n");
	printf("level 1 (7 seconds) / level 2 (5 seconds) / level 3 (3 seconds) \n");
	do {
		scanf("%d", &choice);
		if(*choice != 1 && *choice != 2 && *choice != 3) {
			printf("please choose a valid level !\n");
		}
	} while(*choice != 1 && *choice != 2 && *choice != 3);
	return *choice;
}


void timer() { // the timer
	time_t start, end;
	double elapsed;
	int a;
	int b=0;
	time(&start);
	
	while(b ==0) {
		time(&end);
		scanf("%d", &a);
		elapsed = difftime(end, start);
		//printf("time elapsed: %f \n", elapsed);
		if(elapsed > 5) {
			break;
		}
	}
	printf("\nEND OF TIMER! \n");
}

void end_game(int score) { // when the game is over
	FILE* f = NULL;
	char nom[256];
	printf("\n\nGAME OVER ! \n");
	f = fopen("HIGH_SCORE.txt","r+");
	if(f == NULL) {
		printf("opening file error \n");
		exit(1);
	}
	printf("\nenter your name: ");
	scanf("%s", &nom);
	fseek(f, 0, SEEK_END);
	fprintf(f, "\nname: %s / score: %d",nom, score);
	rewind(f);
	int c = EOF + 1;
	while(c != EOF) {
		printf("%c",c);
		c = fgetc(f);
	}
	printf("\n\nthanks for playing our game! \n");
	fclose(f);
}

void rand_tetro(Tetromino *tetro) {
	int random;
	random = rand() % 7; // pick a random number for a random piece
	if(random == 0) { // 0 block
			tetro->type[0][0][0] = 0; // 0 block
			tetro->type[0][0][1] = 0;
			tetro->type[0][0][2] = 0;
			tetro->type[0][0][3] = 0;
		
			tetro->type[0][1][0] = 0;
			tetro->type[0][1][1] = 1;
			tetro->type[0][1][2] = 1;
			tetro->type[0][1][3] = 0;
		
			tetro->type[0][2][0] = 0;
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 1;
			tetro->type[0][2][3] = 0;
		
			tetro->type[0][3][0] = 0;
			tetro->type[0][3][1] = 0;
			tetro->type[0][3][2] = 0;
			tetro->type[0][3][3] = 0;


			tetro->type[1][0][0] = 0; // 0 block
			tetro->type[1][0][1] = 0;
			tetro->type[1][0][2] = 0;
			tetro->type[1][0][3] = 0;
		
			tetro->type[1][1][0] = 0;
			tetro->type[1][1][1] = 1;
			tetro->type[1][1][2] = 1;
			tetro->type[1][1][3] = 0;
		
			tetro->type[1][2][0] = 0;
			tetro->type[1][2][1] = 1;
			tetro->type[1][2][2] = 1;
			tetro->type[1][2][3] = 0;
		
			tetro->type[1][3][0] = 0;
			tetro->type[1][3][1] = 0;
			tetro->type[1][3][2] = 0;
			tetro->type[1][3][3] = 0;


			tetro->type[2][0][0] = 0; // 0 block
			tetro->type[2][0][1] = 0;
			tetro->type[2][0][2] = 0;
			tetro->type[2][0][3] = 0;
		
			tetro->type[2][1][0] = 0;
			tetro->type[2][1][1] = 1;
			tetro->type[2][1][2] = 1;
			tetro->type[2][1][3] = 0;
		
			tetro->type[2][2][0] = 0;
			tetro->type[2][2][1] = 1;
			tetro->type[2][2][2] = 1;
			tetro->type[2][2][3] = 0;
		
			tetro->type[2][3][0] = 0;
			tetro->type[2][3][1] = 0;
			tetro->type[2][3][2] = 0;
			tetro->type[2][3][3] = 0;


			tetro->type[3][0][0] = 0; // 0 block
			tetro->type[3][0][1] = 0;
			tetro->type[3][0][2] = 0;
			tetro->type[3][0][3] = 0;
		
			tetro->type[3][1][0] = 0;
			tetro->type[3][1][1] = 1;
			tetro->type[3][1][2] = 1;
			tetro->type[3][1][3] = 0;
		
			tetro->type[3][2][0] = 0;
			tetro->type[3][2][1] = 1;
			tetro->type[3][2][2] = 1;
			tetro->type[3][2][3] = 0;
		
			tetro->type[3][3][0] = 0;
			tetro->type[3][3][1] = 0;
			tetro->type[3][3][2] = 0;
			tetro->type[3][3][3] = 0;
	}
// ------------------------------------------------------------------------------

	else if(random == 1) { // I block
			tetro->type[0][0][0] = 0; // I block & rotation 0
			tetro->type[0][0][1] = 1;
			tetro->type[0][0][2] = 0;
			tetro->type[0][0][3] = 0;
		
			tetro->type[0][1][0] = 0;
			tetro->type[0][1][1] = 1;
			tetro->type[0][1][2] = 0;
			tetro->type[0][1][3] = 0;
		
			tetro->type[0][2][0] = 0;
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 0;
			tetro->type[0][2][3] = 0;
		
			tetro->type[0][3][0] = 0;
			tetro->type[0][3][1] = 1;
			tetro->type[0][3][2] = 0;
			tetro->type[0][3][3] = 0;


			tetro->type[1][0][0] = 0; // I block & rotation 1
			tetro->type[1][0][1] = 0;
			tetro->type[1][0][2] = 0;
			tetro->type[1][0][3] = 0;
		
			tetro->type[1][1][0] = 1;
			tetro->type[1][1][1] = 1;
			tetro->type[1][1][2] = 1;
			tetro->type[1][1][3] = 1;
		
			tetro->type[1][2][0] = 0;
			tetro->type[1][2][1] = 0;
			tetro->type[1][2][2] = 0;
			tetro->type[1][2][3] = 0;
		
			tetro->type[1][3][0] = 0;
			tetro->type[1][3][1] = 0;
			tetro->type[1][3][2] = 0;
			tetro->type[1][3][3] = 0;


			tetro->type[2][0][0] = 0; // I block & rotation 1
			tetro->type[2][0][1] = 0;
			tetro->type[2][0][2] = 1;
			tetro->type[2][0][3] = 0;
		
			tetro->type[2][1][0] = 0;
			tetro->type[2][1][1] = 0;
			tetro->type[2][1][2] = 1;
			tetro->type[2][1][3] = 0;
		
			tetro->type[2][2][0] = 0;
			tetro->type[2][2][1] = 0;
			tetro->type[2][2][2] = 1;
			tetro->type[2][2][3] = 0;
		
			tetro->type[2][3][0] = 0;
			tetro->type[2][3][1] = 0;
			tetro->type[2][3][2] = 1;
			tetro->type[2][3][3] = 0;


			tetro->type[3][0][0] = 0; // I block & rotation 1
			tetro->type[3][0][1] = 0;
			tetro->type[3][0][2] = 0;
			tetro->type[3][0][3] = 0;
		
			tetro->type[3][1][0] = 0;
			tetro->type[3][1][1] = 0;
			tetro->type[3][1][2] = 0;
			tetro->type[3][1][3] = 0;
		
			tetro->type[3][2][0] = 1;
			tetro->type[3][2][1] = 1;
			tetro->type[3][2][2] = 1;
			tetro->type[3][2][3] = 1;
		
			tetro->type[3][3][0] = 0;
			tetro->type[3][3][1] = 0;
			tetro->type[3][3][2] = 0;
			tetro->type[3][3][3] = 0;
	}
// ------------------------------------------------------------------------------

	else if(random == 2) { // L block
			tetro->type[0][0][0] = 0; // L block & rotation 0
			tetro->type[0][0][1] = 0;
			tetro->type[0][0][2] = 0;
			tetro->type[0][0][3] = 0;
		
			tetro->type[0][1][0] = 0;
			tetro->type[0][1][1] = 1;
			tetro->type[0][1][2] = 0;
			tetro->type[0][1][3] = 0;
		
			tetro->type[0][2][0] = 0;
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 0;
			tetro->type[0][2][3] = 0;
		
			tetro->type[0][3][0] = 0; 
			tetro->type[0][3][1] = 1;
			tetro->type[0][3][2] = 1;
			tetro->type[0][3][3] = 0;


			tetro->type[1][0][0] = 0; // L block & rotation 1
			tetro->type[1][0][1] = 0;
			tetro->type[1][0][2] = 0;
			tetro->type[1][0][3] = 0;
		
			tetro->type[1][1][0] = 0;
			tetro->type[1][1][1] = 0;
			tetro->type[1][1][2] = 0;
			tetro->type[1][1][3] = 1;
		
			tetro->type[1][2][0] = 0;
			tetro->type[1][2][1] = 1;
			tetro->type[1][2][2] = 1;
			tetro->type[1][2][3] = 1;
		
			tetro->type[1][3][0] = 0;
			tetro->type[1][3][1] = 0;
			tetro->type[1][3][2] = 0;
			tetro->type[1][3][3] = 0;


			tetro->type[2][0][0] = 0; // L block & rotation 2
			tetro->type[2][0][1] = 0;
			tetro->type[2][0][2] = 0;
			tetro->type[2][0][3] = 0;
		
			tetro->type[2][1][0] = 0;
			tetro->type[2][1][1] = 1;
			tetro->type[2][1][2] = 1;
			tetro->type[2][1][3] = 0;
		
			tetro->type[2][2][0] = 0;
			tetro->type[2][2][1] = 0;
			tetro->type[2][2][2] = 1;
			tetro->type[2][2][3] = 0;
		
			tetro->type[2][3][0] = 0;
			tetro->type[2][3][1] = 0;
			tetro->type[2][3][2] = 1;
			tetro->type[2][3][3] = 0;


			tetro->type[3][0][0] = 0; // L block & rotation 3
			tetro->type[3][0][1] = 0;
			tetro->type[3][0][2] = 0;
			tetro->type[3][0][3] = 0;
		
			tetro->type[3][1][0] = 0;
			tetro->type[3][1][1] = 1;
			tetro->type[3][1][2] = 1;
			tetro->type[3][1][3] = 1;
		
			tetro->type[3][2][0] = 0;
			tetro->type[3][2][1] = 1;
			tetro->type[3][2][2] = 0;
			tetro->type[3][2][3] = 0;
		
			tetro->type[3][3][0] = 0;
			tetro->type[3][3][1] = 0;
			tetro->type[3][3][2] = 0;
			tetro->type[3][3][3] = 0;
	}
// ------------------------------------------------------------------------------

	else if(random == 3) { // J block
			tetro->type[0][0][0] = 0; // J block & rotation 0
			tetro->type[0][0][1] = 0;
			tetro->type[0][0][2] = 0;
			tetro->type[0][0][3] = 0;
		
			tetro->type[0][1][0] = 0;
			tetro->type[0][1][1] = 1;
			tetro->type[0][1][2] = 1;
			tetro->type[0][1][3] = 0;
		
			tetro->type[0][2][0] = 0;
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 0;
			tetro->type[0][2][3] = 0;
		
			tetro->type[0][3][0] = 0; 
			tetro->type[0][3][1] = 1;
			tetro->type[0][3][2] = 0;
			tetro->type[0][3][3] = 0;


			tetro->type[1][0][0] = 0; // J block & rotation 1
			tetro->type[1][0][1] = 0;
			tetro->type[1][0][2] = 0;
			tetro->type[1][0][3] = 0;
		
			tetro->type[1][1][0] = 0;
			tetro->type[1][1][1] = 1;
			tetro->type[1][1][2] = 0;
			tetro->type[1][1][3] = 0;
		
			tetro->type[1][2][0] = 0;
			tetro->type[1][2][1] = 1;
			tetro->type[1][2][2] = 1;
			tetro->type[1][2][3] = 1;
		
			tetro->type[1][3][0] = 0;
			tetro->type[1][3][1] = 0;
			tetro->type[1][3][2] = 0;
			tetro->type[1][3][3] = 0;


			tetro->type[2][0][0] = 0; // J block & rotation 2
			tetro->type[2][0][1] = 0;
			tetro->type[2][0][2] = 0;
			tetro->type[2][0][3] = 0;
		
			tetro->type[2][1][0] = 1;
			tetro->type[2][1][1] = 1;
			tetro->type[2][1][2] = 1;
			tetro->type[2][1][3] = 0;
		
			tetro->type[2][2][0] = 0;
			tetro->type[2][2][1] = 0;
			tetro->type[2][2][2] = 1;
			tetro->type[2][2][3] = 0;
		
			tetro->type[2][3][0] = 0;
			tetro->type[2][3][1] = 0;
			tetro->type[2][3][2] = 0;
			tetro->type[2][3][3] = 0;


			tetro->type[3][0][0] = 0; // J block & rotation 3
			tetro->type[3][0][1] = 0;
			tetro->type[3][0][2] = 1;
			tetro->type[3][0][3] = 0;
		
			tetro->type[3][1][0] = 0;
			tetro->type[3][1][1] = 0;
			tetro->type[3][1][2] = 1;
			tetro->type[3][1][3] = 0;
		
			tetro->type[3][2][0] = 0;
			tetro->type[3][2][1] = 1;
			tetro->type[3][2][2] = 1;
			tetro->type[3][2][3] = 0;
		
			tetro->type[3][3][0] = 0;
			tetro->type[3][3][1] = 0;
			tetro->type[3][3][2] = 0;
			tetro->type[3][3][3] = 0;
	}
// ------------------------------------------------------------------------------

	else if(random == 4) { // T block
			tetro->type[0][0][0] = 0; // T block & rotation 0
			tetro->type[0][0][1] = 0;
			tetro->type[0][0][2] = 0;
			tetro->type[0][0][3] = 0;
		
			tetro->type[0][1][0] = 0;
			tetro->type[0][1][1] = 0;
			tetro->type[0][1][2] = 1;
			tetro->type[0][1][3] = 0;
		
			tetro->type[0][2][0] = 0;
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 1;
			tetro->type[0][2][3] = 1;
		
			tetro->type[0][3][0] = 0; 
			tetro->type[0][3][1] = 0;
			tetro->type[0][3][2] = 0;
			tetro->type[0][3][3] = 0;


			tetro->type[1][0][0] = 0; // T block & rotation 1
			tetro->type[1][0][1] = 0;
			tetro->type[1][0][2] = 0;
			tetro->type[1][0][3] = 0;
		
			tetro->type[1][1][0] = 0;
			tetro->type[1][1][1] = 1;
			tetro->type[1][1][2] = 0;
			tetro->type[1][1][3] = 0;
		
			tetro->type[1][2][0] = 0;
			tetro->type[1][2][1] = 1;
			tetro->type[1][2][2] = 1;
			tetro->type[1][2][3] = 0;
		
			tetro->type[1][3][0] = 0;
			tetro->type[1][3][1] = 1;
			tetro->type[1][3][2] = 0;
			tetro->type[1][3][3] = 0;


			tetro->type[2][0][0] = 0; // T block & rotation 2
			tetro->type[2][0][1] = 0;
			tetro->type[2][0][2] = 0;
			tetro->type[2][0][3] = 0;
		
			tetro->type[2][1][0] = 0;
			tetro->type[2][1][1] = 1;
			tetro->type[2][1][2] = 1;
			tetro->type[2][1][3] = 1;
		
			tetro->type[2][2][0] = 0;
			tetro->type[2][2][1] = 0;
			tetro->type[2][2][2] = 1;
			tetro->type[2][2][3] = 0;
		
			tetro->type[2][3][0] = 0;
			tetro->type[2][3][1] = 0;
			tetro->type[2][3][2] = 0;
			tetro->type[2][3][3] = 0;


			tetro->type[3][0][0] = 0; // T block & rotation 3
			tetro->type[3][0][1] = 0;
			tetro->type[3][0][2] = 1;
			tetro->type[3][0][3] = 0;
		
			tetro->type[3][1][0] = 0;
			tetro->type[3][1][1] = 1;
			tetro->type[3][1][2] = 1;
			tetro->type[3][1][3] = 0;
		
			tetro->type[3][2][0] = 0;
			tetro->type[3][2][1] = 0;
			tetro->type[3][2][2] = 1;
			tetro->type[3][2][3] = 0;
		
			tetro->type[3][3][0] = 0;
			tetro->type[3][3][1] = 0;
			tetro->type[3][3][2] = 0;
			tetro->type[3][3][3] = 0;
	}
// ------------------------------------------------------------------------------

	else if(random == 5) { // Z block
			tetro->type[0][0][0] = 0; // Z block & rotation 0
			tetro->type[0][0][1] = 0;
			tetro->type[0][0][2] = 0;
			tetro->type[0][0][3] = 0;
		
			tetro->type[0][1][0] = 0;
			tetro->type[0][1][1] = 0;
			tetro->type[0][1][2] = 0;
			tetro->type[0][1][3] = 0;
		
			tetro->type[0][2][0] = 0;
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 1;
			tetro->type[0][2][3] = 0;
		
			tetro->type[0][3][0] = 0; 
			tetro->type[0][3][1] = 0;
			tetro->type[0][3][2] = 1;
			tetro->type[0][3][3] = 1;


			tetro->type[1][0][0] = 0; // Z block & rotation 1
			tetro->type[1][0][1] = 0;
			tetro->type[1][0][2] = 0;
			tetro->type[1][0][3] = 0;
		
			tetro->type[1][1][0] = 0;
			tetro->type[1][1][1] = 0;
			tetro->type[1][1][2] = 1;
			tetro->type[1][1][3] = 0;
		
			tetro->type[1][2][0] = 0;
			tetro->type[1][2][1] = 1;
			tetro->type[1][2][2] = 1;
			tetro->type[1][2][3] = 0;
		
			tetro->type[1][3][0] = 0;
			tetro->type[1][3][1] = 1;
			tetro->type[1][3][2] = 0;
			tetro->type[1][3][3] = 0;


			tetro->type[2][0][0] = 0; // Z block & rotation 2
			tetro->type[2][0][1] = 0;
			tetro->type[2][0][2] = 0;
			tetro->type[2][0][3] = 0;
		
			tetro->type[2][1][0] = 0;
			tetro->type[2][1][1] = 0;
			tetro->type[2][1][2] = 0;
			tetro->type[2][1][3] = 0;
		
			tetro->type[2][2][0] = 0;
			tetro->type[2][2][1] = 1;
			tetro->type[2][2][2] = 1;
			tetro->type[2][2][3] = 0;
		
			tetro->type[2][3][0] = 0;
			tetro->type[2][3][1] = 0;
			tetro->type[2][3][2] = 1;
			tetro->type[2][3][3] = 1;


			tetro->type[3][0][0] = 0; // Z block & rotation 3
			tetro->type[3][0][1] = 0;
			tetro->type[3][0][2] = 0;
			tetro->type[3][0][3] = 0;
		
			tetro->type[3][1][0] = 0;
			tetro->type[3][1][1] = 0;
			tetro->type[3][1][2] = 1;
			tetro->type[3][1][3] = 0;
		
			tetro->type[3][2][0] = 0;
			tetro->type[3][2][1] = 1;
			tetro->type[3][2][2] = 1;
			tetro->type[3][2][3] = 0;
		
			tetro->type[3][3][0] = 0;
			tetro->type[3][3][1] = 1;
			tetro->type[3][3][2] = 0;
			tetro->type[3][3][3] = 0;			

// ------------------------------------------------------------------------------
	}
	else if(random == 6) {// S block
			tetro->type[0][0][0] = 0; // S block & rotation 0
			tetro->type[0][0][1] = 0;
			tetro->type[0][0][2] = 0;
			tetro->type[0][0][3] = 0;
		
			tetro->type[0][1][0] = 0;
			tetro->type[0][1][1] = 0;
			tetro->type[0][1][2] = 1;
			tetro->type[0][1][3] = 1;
		
			tetro->type[0][2][0] = 0;
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 1;
			tetro->type[0][2][3] = 0;
		
			tetro->type[0][3][0] = 0; 
			tetro->type[0][3][1] = 0;
			tetro->type[0][3][2] = 0;
			tetro->type[0][3][3] = 0;


			tetro->type[1][0][0] = 0; // S block & rotation 1
			tetro->type[1][0][1] = 0;
			tetro->type[1][0][2] = 0;
			tetro->type[1][0][3] = 0;
		
			tetro->type[1][1][0] = 0;
			tetro->type[1][1][1] = 0;
			tetro->type[1][1][2] = 1;
			tetro->type[1][1][3] = 0;
		
			tetro->type[1][2][0] = 0;
			tetro->type[1][2][1] = 0;
			tetro->type[1][2][2] = 1;
			tetro->type[1][2][3] = 1;
		
			tetro->type[1][3][0] = 0;
			tetro->type[1][3][1] = 0;
			tetro->type[1][3][2] = 0;
			tetro->type[1][3][3] = 1;


			tetro->type[2][0][0] = 0; // S block & rotation 2
			tetro->type[2][0][1] = 0;
			tetro->type[2][0][2] = 0;
			tetro->type[2][0][3] = 0;
		
			tetro->type[2][1][0] = 0;
			tetro->type[2][1][1] = 0;
			tetro->type[2][1][2] = 0;
			tetro->type[2][1][3] = 0;
		
			tetro->type[2][2][0] = 0;
			tetro->type[2][2][1] = 0;
			tetro->type[2][2][2] = 1;
			tetro->type[2][2][3] = 1;
		
			tetro->type[2][3][0] = 0;
			tetro->type[2][3][1] = 1;
			tetro->type[2][3][2] = 1;
			tetro->type[2][3][3] = 0;


			tetro->type[3][0][0] = 0; // S block & rotation 3
			tetro->type[3][0][1] = 0;
			tetro->type[3][0][2] = 0;
			tetro->type[3][0][3] = 0;
		
			tetro->type[3][1][0] = 0;
			tetro->type[3][1][1] = 1;
			tetro->type[3][1][2] = 0;
			tetro->type[3][1][3] = 0;
		
			tetro->type[3][2][0] = 0;
			tetro->type[3][2][1] = 1;
			tetro->type[3][2][2] = 1;
			tetro->type[3][2][3] = 0;
		
			tetro->type[3][3][0] = 0;
			tetro->type[3][3][1] = 0;
			tetro->type[3][3][2] = 1;
			tetro->type[3][3][3] = 0;
	}
	else{
			printf("erreur block \n");
			exit(1);
	}
}

/*
void game() { // allow to play the game
	bool gameover = false;
	while(gameover != false;) {
		places(tab);
		show_grid(tab);
		score = score + linedelete(); // voir si une ligne est complète
	}
	end_game(int score);
}
*/

/*
int verification(int tab[][]){ //return the line in which a line is full and if no line is full, return NULL
        for(int i=0; i<10; i++){ //detect for every line from 0 to 10
                if(tab[i][0]==1){ // detect the first case everytime to gain time analyse the whole table
                        for(int j=0; i<10;j++){ //detect for every case in the line if it is equal to 0 and else it goes to the next line
                                if(tab[i][j]!=1){
                                        j=10;
                                }
                        }
                        return i;
                }
        }
        return 20; //if there is no line completed by the '1' value, it return NULL 
}

void linedelete(int tab[][], int n){ // after the verification, useful to delete the line and replace by the line on the bottom
	for(int j=0; j<10; j++){ // delete the line with all the 1's
		tab[n][j] = 0;
	}	
	for(int i=n; i>0; i--){ // replace the line with all the 0's to the line on the bottom
		for(int k=0; k<10; k++){
			tab[i][k] = tab[i-1][k];
		}
	}
	for(int l=0;l<10; l++){ // the first line being duplicated, we have to delete it into a line with 0's
		tab[0][l] = 0;
	}
}
*/
