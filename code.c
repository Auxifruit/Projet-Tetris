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
int verification(int tab[TAILLE][TAILLE]); //return the line in which a line is full and if no line is full, return NULL
void linedelete(int tab[TAILLE][TAILLE], int n, int score); // after the verification, useful to delete the line and replace by the line on the bottom
//void show_block

int main(){
	int tab[TAILLE][TAILLE];
	int score = 1000;
	srand(time(NULL)); // the initialisation of the random function
	init_grid(tab);
	place(tab);
	place(tab);
	place(tab);
	place(tab);
	place(tab);
	place(tab);
	place(tab);
	place(tab);
	place(tab);
	place(tab);
	show_grid(tab);
	linedelete(tab, verification(tab), 100);
	linedelete(tab, verification(tab), 100);
	linedelete(tab, verification(tab), 100);
	linedelete(tab, verification(tab), 100);
	//timer();
	//game();
	show_grid(tab);
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
		if(c<65 || c>74){
			printf("\n%c isn't a valid column. There are 10 column from A to J. Now, ", c);
		}
	} while (c < 65 || c > 74);
	for(int i = 0; i < 4; i++) {
		tab[TAILLE -1 - i][(int)(c-65)] = mat[0][i];
	}
	show_grid(tab);
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
				printf("\n|%d|", tab[a][b]);
			}
			else{
				printf("%d|", tab[a][b]);
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


int verification(int tab[TAILLE][TAILLE]){ //return a table in which there are the numbers of the full lines and if no line is full, fill it with 20
	printf("\nLa verification est en cours \n");
	int n;
        for(int i=0; i<TAILLE; i++){ //detect for every line from 0 to 10
		if(tab[i][0]==1){ // detect the first case everytime to gain time analyse the whole table
			printf("Ligne n°%d commence par un @ : \n", i+1);
			for(int j=0; j<TAILLE;j++){ 
				n = i; // begin with a hypothesis that the line is full, then change it if it is not full
				if(tab[i][j]!=1){ //detect for every case in the line if it is equal to 0 and else it goes to the next line
					n=20; // change the value of the line to 20 if it is not full
					break;
                    	        }
                   	}
                   	if(n!=20){
				printf("La ligne retourne %d\n", i);
                   		return i; //if the code detect a full line, it returns the line
                   	}
        	}  
	}
	return 20;
}

void linedelete(int tab[TAILLE][TAILLE], int n, int score){ // after the verification, useful to delete the line and replace by the line on the bottom
	printf("La fonction delete line est en cours \n");
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
	
