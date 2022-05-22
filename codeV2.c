#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define TAILLE 10

void init_grid(int tab[TAILLE][TAILLE]); // initialize the grid
void show_grid(int tab[TAILLE][TAILLE]); // show the grid in the terminal
int block(int p); // transform int in char
int difficulty(); // choose the level of difficulty, it will change the time between the placement of every tetriminos
void timer(); // a timer that will be useful to the change of diffculty and time to change block position 
void place(int tab[TAILLE][TAILLE]); // place a block in the table
char input(); // input a char
void end_game(int score); // when the game is over, it will stop the game
//void game(); // allow to start the game
int verification(int tab[][]); //return the line in which a line is full and if no line is full, return NULL



int main() {
	int tab[TAILLE][TAILLE];
	int score = 1000;
	srand(time(NULL)); // the initialisation of the random function
	init_grid(tab);
	place(tab);
	show_grid(tab);
	//timer();
	//game();
	end_game(score);
	printf("\n");
	return 0;
}

char input() { // input a char
	char c;
	while (((c=getchar()) == '\n'));
	return c;
}

void place(int tab[TAILLE][TAILLE]) { // place a block
	char c;
	int mat[1][4] = 
	{1,
	1,
	1,
	1};
	do {
		printf("on which column you want to place your tetromino ? \n");
		c = input();
	} while (c < 65 || c > 74);
	for(int i = 0; i < 4; i++) {
		printf("%d \n", mat[0][i]);
		tab[TAILLE -1 - i][(int)(c-65)] = mat[0][i];
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
	printf("This is your grid: \n\n");
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


/*
void game() { // allow to play the game
	bool gameover = false;
	while(gameover != false;) {
		places(tab);
		show_grid(tab);
		verification(); // voir si une ligne est complète
	}
	end_game(int score);
}
*/


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
        return NULL; //if there is no line completed by the '1' value, it return NULL 
}
