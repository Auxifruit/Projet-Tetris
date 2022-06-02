#include "header.h"

void input(char *c) { // input a char
	while (((*c=getchar()) == '\n'));
}

void place(int tab[TAILLE][TAILLE], Tetromino* tetro) {// place a block in the grid
	char c;
	int sc = 0;
	do {
		printf("\non which column you want to place your tetromino ? \n");
		sc = scanf("%c", &c);
		if(sc != 1) {
			printf("scanf error\n");
			exit(2);
		}
	} while (c < 65 || c > 74);
	for(int i = 0; i < DIMENSION; i++) {
		for(int j = 0; j < DIMENSION; j++) {
			tab[8 + i][(int)(c-65) + j] = tetro->type[0][i][j];
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
	printf("\n\n");
}

int block(int p) { // transform int in char
	if( p != 1 && p != 0) {
		printf("\nerror: p must be egal to 1 or 0\n");
		exit(1);
	}
	switch(p) {
		case 0: return(32); break;
		case 1: return(64); break;
		default: return(69);
	}
}
int difficulty() { // choose the level of difficulty beetween 1 and 3 from easy to hard
	int choice;
	int sc = 0;
	printf("\n");
	printf("choose your difficulty: \n");
	printf("level 1 (7 seconds) / level 2 (5 seconds) / level 3 (3 seconds) \n");
	do {
		sc = scanf("%d", &choice);
		if(sc != 1) {
			printf("scanf error: please enter a number \n");
			exit(2);
		}
		if(choice != 1 && choice != 2 && choice != 3) {
			printf("please choose a valid level !\n");
		}
	} while(choice != 1 && choice != 2 && choice != 3);
	return choice;
}


void timer() { // the timer
	time_t start, end;
	double elapsed;
	int a;
	int sc = 0;
	int b = 0;
	time(&start);
	
	while(b == 0) {
		time(&end);
		scanf("%d", &a);
		if(sc != 1) {
			printf("scanf error: please enter a number \n");
			exit(2);
		}
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
	int sc = 0;
	if(score < 0) {
		printf("score error\n");
		exit(0);
	} 
	printf("\n\nGAME OVER ! \n");
	f = fopen("HIGH_SCORE.txt","r+");
	if(f == NULL) {
		printf("opening file error \n");
		exit(1);
	}
	printf("\nenter your name: ");
	sc = scanf("%s", &nom);
	if(sc != 1) {
		printf("scanf error\n");
		exit(2);
	}
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

void int_random(int* random) {
	*random = rand() % 7;
}
	

void rand_tetro(Tetromino *tetro) {
	int random;
	int_random(&random); // pick a random number for a random piece
	/*if(random == 0) { // 0 block
			tetro->type[0][1][1] = 1; // 0 block & rotation 0
			tetro->type[0][1][2] = 1;
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 1;


			tetro->type[1][1][1] = 1; // 0 block & rotation 1
			tetro->type[1][1][2] = 1;
			tetro->type[1][2][1] = 1;
			tetro->type[1][2][2] = 1;


			tetro->type[2][1][1] = 1; // 0 block & rotation 2
			tetro->type[2][1][2] = 1;
			tetro->type[2][2][1] = 1;
			tetro->type[2][2][2] = 1;

			tetro->type[3][1][1] = 1; // 0 block & rotation 3
			tetro->type[3][1][2] = 1;
			tetro->type[3][2][1] = 1;
			tetro->type[3][2][2] = 1;
	}

// ------------------------------------------------------------------------------

	else if(random == 1) { // I block
			tetro->type[0][0][1] = 1; // I block & rotation 0
			tetro->type[0][1][1] = 1;
			tetro->type[0][2][1] = 1;
			tetro->type[0][3][1] = 1;


			tetro->type[1][1][0] = 1; // I block & rotation 1
			tetro->type[1][1][1] = 1;
			tetro->type[1][1][2] = 1;
			tetro->type[1][1][3] = 1;

			tetro->type[2][0][1] = 1; // I block & rotation 2
			tetro->type[2][1][1] = 1;
			tetro->type[2][2][1] = 1;
			tetro->type[2][3][1] = 1;


			tetro->type[3][1][0] = 1; // I block & rotation 3
			tetro->type[3][1][1] = 1;
			tetro->type[3][1][2] = 1;
			tetro->type[3][1][3] = 1;
	}

// ------------------------------------------------------------------------------

	else if(random == 2) { // L block
			tetro->type[0][1][1] = 1; // L block & rotation 0
			tetro->type[0][2][1] = 1;
			tetro->type[0][3][1] = 1;
			tetro->type[0][3][2] = 1;


			tetro->type[1][1][3] = 1; // L block & rotation 1
			tetro->type[1][2][1] = 1;
			tetro->type[1][2][2] = 1;
			tetro->type[1][2][3] = 1;
		

			tetro->type[2][1][1] = 1; // L block & rotation 2
			tetro->type[2][1][2] = 1;
			tetro->type[2][2][2] = 1;
			tetro->type[2][3][2] = 1;


			tetro->type[3][1][1] = 1; // L block & rotation 3
			tetro->type[3][1][2] = 1;
			tetro->type[3][1][3] = 1;
			tetro->type[3][2][1] = 1;
	}
// ------------------------------------------------------------------------------

	else if(random == 3) { // J block
			tetro->type[0][1][1] = 1; // J block & rotation 0
			tetro->type[0][1][2] = 1;
			tetro->type[0][2][1] = 1;
			tetro->type[0][3][1] = 1;


			tetro->type[1][1][1] = 1; // J block & rotation 1
			tetro->type[1][2][1] = 1;
			tetro->type[1][2][2] = 1;
			tetro->type[1][2][3] = 1;


			tetro->type[2][1][0] = 1; // J block & rotation 2
			tetro->type[2][1][1] = 1;
			tetro->type[2][1][2] = 1;
			tetro->type[2][2][2] = 1;


			tetro->type[3][0][2] = 1; // J block & rotation 3
			tetro->type[3][1][2] = 1;
			tetro->type[3][2][1] = 1;
			tetro->type[3][2][2] = 1;
	}

// ------------------------------------------------------------------------------

	else if(random == 4) { // T block
			tetro->type[0][1][2] = 1; // T block & rotation 0
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 1;
			tetro->type[0][2][3] = 1;


			tetro->type[1][1][1] = 1; // T block & rotation 1
			tetro->type[1][2][1] = 1;
			tetro->type[1][2][2] = 1;
			tetro->type[1][3][1] = 1;


			tetro->type[2][1][1] = 1; // T block & rotation 2
			tetro->type[2][1][2] = 1;
			tetro->type[2][1][3] = 1;
			tetro->type[2][2][2] = 1;


			tetro->type[3][0][2] = 1; // T block & rotation 3
			tetro->type[3][1][1] = 1;
			tetro->type[3][1][2] = 1;
			tetro->type[3][2][2] = 1;
	}

// ------------------------------------------------------------------------------

	else if(random == 5) { // Z block
			tetro->type[0][2][1] = 1; // Z block & rotation 0
			tetro->type[0][2][2] = 1;
			tetro->type[0][3][2] = 1;
			tetro->type[0][3][3] = 1;


			tetro->type[1][1][2] = 1; // Z block & rotation 1
			tetro->type[1][2][1] = 1;
			tetro->type[1][2][2] = 1;
			tetro->type[1][3][1] = 1;


			tetro->type[2][2][1] = 1; // Z block & rotation 2
			tetro->type[2][2][2] = 1;
			tetro->type[2][3][2] = 1;
			tetro->type[2][3][3] = 1;


			tetro->type[3][1][2] = 1; // Z block & rotation 3
			tetro->type[3][2][1] = 1;
			tetro->type[3][2][2] = 1;
			tetro->type[3][3][1] = 1;			
	}

// ------------------------------------------------------------------------------

	else if(random == 6) {// S block
			tetro->type[0][1][2] = 1; // S block & rotation 0
			tetro->type[0][1][3] = 1;
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 1;


			tetro->type[1][1][2] = 1; // S block & rotation 1
			tetro->type[1][2][2] = 1;
			tetro->type[1][2][3] = 1;
			tetro->type[1][3][3] = 1;


			tetro->type[2][1][2] = 1; // S block & rotation 2
			tetro->type[2][1][3] = 1;
			tetro->type[2][2][1] = 1;
			tetro->type[2][2][2] = 1;


			tetro->type[3][1][2] = 1; // S block & rotation 3
			tetro->type[3][2][2] = 1;
			tetro->type[3][2][3] = 1;
			tetro->type[3][3][3] = 1;
	}*/
	if(random == 0) { // 0 block
			tetro->type[0][0][0] = 1; // 0 block & rotation 0
			tetro->type[0][0][1] = 1;
			tetro->type[0][1][0] = 1;
			tetro->type[0][1][1] = 1;


			tetro->type[1][0][0] = 1; // 0 block & rotation 1
			tetro->type[1][0][1] = 1;
			tetro->type[1][1][0] = 1;
			tetro->type[1][1][1] = 1;


			tetro->type[2][0][0] = 1; // 0 block & rotation 2
			tetro->type[2][0][1] = 1;
			tetro->type[2][1][0] = 1;
			tetro->type[2][1][1] = 1;

			tetro->type[3][0][0] = 1; // 0 block & rotation 3
			tetro->type[3][0][1] = 1;
			tetro->type[3][1][0] = 1;
			tetro->type[3][1][1] = 1;
	}

// ------------------------------------------------------------------------------

	else if(random == 1) { // I block
			tetro->type[0][0][0] = 1; // I block & rotation 0
			tetro->type[0][1][0] = 1;
			tetro->type[0][2][0] = 1;
			tetro->type[0][3][0] = 1;


			tetro->type[1][0][0] = 1; // I block & rotation 1
			tetro->type[1][0][1] = 1;
			tetro->type[1][0][2] = 1;
			tetro->type[1][0][3] = 1;

			tetro->type[2][0][0] = 1; // I block & rotation 2
			tetro->type[2][1][0] = 1;
			tetro->type[2][2][0] = 1;
			tetro->type[2][3][0] = 1;


			tetro->type[3][0][0] = 1; // I block & rotation 3
			tetro->type[3][0][1] = 1;
			tetro->type[3][0][2] = 1;
			tetro->type[3][0][3] = 1;
	}

// ------------------------------------------------------------------------------

	else if(random == 2) { // L block
			tetro->type[0][0][0] = 1; // L block & rotation 0
			tetro->type[0][1][0] = 1;
			tetro->type[0][2][0] = 1;
			tetro->type[0][2][1] = 1;


			tetro->type[1][0][2] = 1; // L block & rotation 1
			tetro->type[1][1][0] = 1;
			tetro->type[1][1][1] = 1;
			tetro->type[1][1][2] = 1;
		

			tetro->type[2][0][0] = 1; // L block & rotation 2
			tetro->type[2][0][1] = 1;
			tetro->type[2][1][1] = 1;
			tetro->type[2][2][1] = 1;


			tetro->type[3][1][1] = 1; // L block & rotation 3
			tetro->type[3][1][1] = 1;
			tetro->type[3][2][0] = 1;
			tetro->type[3][2][1] = 1;
	}
// ------------------------------------------------------------------------------

	else if(random == 3) { // J block
			tetro->type[0][0][0] = 1; // J block & rotation 0
			tetro->type[0][0][1] = 1;
			tetro->type[0][1][0] = 1;
			tetro->type[0][2][0] = 1;


			tetro->type[1][0][0] = 1; // J block & rotation 1
			tetro->type[1][1][0] = 1;
			tetro->type[1][1][1] = 1;
			tetro->type[1][1][2] = 1;


			tetro->type[2][0][0] = 1; // J block & rotation 2
			tetro->type[2][0][1] = 1;
			tetro->type[2][0][2] = 1;
			tetro->type[2][1][2] = 1;


			tetro->type[3][0][1] = 1; // J block & rotation 3
			tetro->type[3][1][1] = 1;
			tetro->type[3][2][0] = 1;
			tetro->type[3][2][1] = 1;
	}

// ------------------------------------------------------------------------------

	else if(random == 4) { // T block
			tetro->type[0][0][1] = 1; // T block & rotation 0
			tetro->type[0][1][0] = 1;
			tetro->type[0][1][1] = 1;
			tetro->type[0][1][2] = 1;


			tetro->type[1][0][0] = 1; // T block & rotation 1
			tetro->type[1][1][0] = 1;
			tetro->type[1][1][1] = 1;
			tetro->type[1][2][0] = 1;


			tetro->type[2][0][0] = 1; // T block & rotation 2
			tetro->type[2][0][1] = 1;
			tetro->type[2][0][2] = 1;
			tetro->type[2][1][1] = 1;


			tetro->type[3][0][1] = 1; // T block & rotation 3
			tetro->type[3][1][0] = 1;
			tetro->type[3][1][1] = 1;
			tetro->type[3][2][1] = 1;
	}

// ------------------------------------------------------------------------------

	else if(random == 5) { // Z block
			tetro->type[0][1][0] = 1; // Z block & rotation 0
			tetro->type[0][1][1] = 1;
			tetro->type[0][2][1] = 1;
			tetro->type[0][2][2] = 1;


			tetro->type[1][0][1] = 1; // Z block & rotation 1
			tetro->type[1][1][0] = 1;
			tetro->type[1][1][1] = 1;
			tetro->type[1][2][0] = 1;


			tetro->type[2][1][0] = 1; // Z block & rotation 2
			tetro->type[2][1][1] = 1;
			tetro->type[2][2][1] = 1;
			tetro->type[2][2][2] = 1;


			tetro->type[3][0][1] = 1; // Z block & rotation 3
			tetro->type[3][1][0] = 1;
			tetro->type[3][1][1] = 1;
			tetro->type[3][2][0] = 1;			
	}

// ------------------------------------------------------------------------------

	else if(random == 6) {// S block
			tetro->type[0][0][1] = 1; // S block & rotation 0
			tetro->type[0][0][2] = 1;
			tetro->type[0][1][0] = 1;
			tetro->type[0][1][1] = 1;


			tetro->type[1][0][0] = 1; // S block & rotation 1
			tetro->type[1][1][0] = 1;
			tetro->type[1][1][1] = 1;
			tetro->type[1][2][1] = 1;


			tetro->type[2][0][1] = 1; // S block & rotation 2
			tetro->type[2][0][2] = 1;
			tetro->type[2][1][0] = 1;
			tetro->type[2][1][1] = 1;


			tetro->type[3][0][0] = 1; // S block & rotation 3
			tetro->type[3][1][0] = 1;
			tetro->type[3][1][1] = 1;
			tetro->type[3][2][1] = 1;
	}

	else {
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

int verification(int tab[TAILLE][TAILLE]){ //return a table in which there are the numbers of the full lines and if no line is full, fill it with 20
	printf("\n the verification is loading... \n");
	int n;
        for(int i=0; i<TAILLE; i++){ //detect for every line from 0 to 10
		if(tab[i][0]==1){ // detect the first case everytime to gain time analyse the whole table
			printf("The line n°%d begin with an @ : \n", i+1);
			for(int j=0; j<TAILLE;j++){ 
				n = i; // begin with a hypothesis that the line is full, then change it if it is not full
				if(tab[i][j]!=1){ //detect for every case in the line if it is equal to 0 and else it goes to the next line
					n=20; // change the value of the line to 20 if it is not full
					break;
                    	        }
                   	}
                   	if(n!=20){
				printf("The line return %d\n", i);
                   		return i; //if the code detect a full line, it returns the line
                   	}
        	}  
	}
	return 20;
}

void linedelete(int tab[TAILLE][TAILLE], int n, int score){ // after the verification, useful to delete the line and replace by the line on the bottom
	printf("The delete line function is loading... \n");
	for(int m = 0; m<10; m++){
		if(n!=20){
			for(int j=0; j<10; j++){ 	// delete the line n with all the 1's to a line with 0's
				tab[n][j] = 0;
			}															
			for(int i=n; i>0; i--){ 	// replace the line with all the 0's to the line on the bottom                                             
				for(int k=0; k<10; k++){
					tab[i][k] = tab[i-1][k];
				}
			}
			for(int l=0;l<10; l++){ // the first line being duplicated, we have to delete it into a line with 0's
				tab[0][l] = 0;
			}
			score = score + 100;
		}
	}
}

void show_tetro(Tetromino *tetro) {
	printf("This is your block with its orientation:");
	for(int l = 0; l < DIMENSION; l++) {
		for(int m = 0; m < DIMENSION; m++) {
			for(int n = 0; n < DIMENSION; n++) {
				if(n == 0) {
					printf("\n%c", block(tetro->type[l][m][n]));
				}
				else {
					printf("%c", block(tetro->type[l][m][n]));
				}
			}
		}
		printf("\t.%d",l);
		printf("\n");
	}
}

void memory_block(Tetromino *tetro) {
	tetro->type = malloc(ROTATION * sizeof(int));
	for(int i = 0 ; i < ROTATION ; i++){
		tetro->type[i] = malloc(ROTATION * sizeof(int));
		for(int j = 0 ; j < ROTATION; j++){
			tetro->type[i][j] = malloc(ROTATION * sizeof(int));
			for(int k = 0 ; k < ROTATION; k++){
				tetro->type[i][j][k] = 0;
			}
		}
	}
}

void choose_rotation(int* rotation) {
	int sc = 0;
	do {
		printf("\nchoose the rotation between 1 and 4\n");
		sc = scanf("%d", rotation);
		if(sc != 1) {
			printf("error scanf\n");
			exit(1);
		}
		if(*rotation != 1 && *rotation != 2 && *rotation != 3 && *rotation != 4) {
			printf("please choose a number between 1 and 4\n");
		}
	} while(*rotation != 1 && *rotation != 2 && *rotation != 3 && *rotation != 4);
	*rotation = *rotation - 1;
}
