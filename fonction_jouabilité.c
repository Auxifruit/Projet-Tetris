#include "header.h"

void logo() { // printf the classic tetris logo
printf("\033[33m _______  ____  _______  _____  _  ______\n");
printf("|__   __||  __/|__   __|| __  /|_||  ____/\n");
printf("   | |   | |__    | |   | |/ / | | \\ \\ \n");
printf("   | |   |  _/    | |   | |\\ \\ | |  \\ \\ \n");
printf("   | |   | |      | |   | | \\ \\| |   \\ \\ \n");
printf("   | |   | |____  | |   | |  \\ \\ | ___\\ \\ \n");
printf("   |_|   |______\\ |_|   |_|   \\_\\||______| \n");
printf("\033[37\nm");
}

int difficulty() { // choose the level of difficulty beetween 1 and 3 from easy to hard
	int choice; // will countain the level of diffuculty choose by the user
	printf("\n");
	printf("choose your difficulty: \n");
	printf("level 1 (10 seconds) / level 2 (7 seconds) / level 3 (5 seconds) \n");
	do { // do while loop to have the right value for the difficulty
		if(scanf("%d", &choice) == 0) { // check if there's an error
			printf("scanf error: please enter number \n");
			exit(2);
		}
		if(choice != 1 && choice != 2 && choice != 3) {
			printf("please choose a valid level between 1 and 3 !\n");
		}
	} while(choice != 1 && choice != 2 && choice != 3);
	switch(choice) {
		case 1: return(10);
		case 2: return(7);
		case 3: return(5);
		default: printf("error value \n");
			exit(1);
	}
}

void end_game(int score) { // when the game is over
	FILE* file = NULL; // will be the pointer of the file
	char nom[256]; // will contain the name of the player
	int sc = 0; // will be use to check the scanf
	int c = EOF + 1; // will be use to printf the files
	if(score < 0) { // test if the parameter is right
		printf("score error\n");
		exit(0);
	} 
	printf("\n\nGAME OVER ! \n");
	printf("BETTER LUCK NEXT TIME!\n");
	file = fopen("HIGH_SCORE.txt","r+"); // open the file which countain the player's score
	if(file == NULL) { // check if the file was open
		printf("opening file error \n");
		exit(1);
	}
	printf("\nenter your name: "); // allow the player to enter his name
	sc = scanf("%s", nom);
	if(sc != 1) { // test if the scanf worked
		printf("scanf error\n");
		exit(2);
	}
	fseek(file, 0, SEEK_END); // put the cursor at the end of the file to add to player's score and name
	fprintf(file, "\nname: %s / score: %d",nom, score);
	rewind(file); // put the cursor at the beginning of the file to print it
	while(c != EOF) {
		printf("%c",c);
		c = fgetc(file);
		if(c == EOF) { // test if we have a fgetc error
			if(feof(file)) { // if c is EOF
				break;
			}
			else{ // if we have an error
				printf("fgetc error \n");
				exit(1);
			}
		}
	}
	printf("\n\nThanks for playing our game! \n");
	fclose(file); // close the file
	exit(0);
}


void verifgameover(int tab[TAILLE][TAILLE],int score){ // verification of the first line of the tab, if there is a bloc, it's game over
	for(int i = 0; i < TAILLE;i++){
		if(tab[0][i]!=0){ // if there is a game over go to end_game
			end_game(score); 
		}
	}
}

void choose_rotation(int* rotation, int level) { // alow to choose the block's rotation
	int sc = 0; // will be use to check the scanf
	double elapsed; // allow use to have the difference between the end and the start of the timer
	time_t start, end; // will be the start and the end of the timer
	time(&start); // beginning of the timer
	printf("\nchoose the rotation between 1 and 4\n");
	sc = scanf("%d", rotation); // test if the scanf worked
	if(sc != 1) {
		printf("error scanf : please enter a number\n");
		exit(1);
	}
	if(*rotation < 1 || *rotation > 4) {
		while(*rotation < 1 || *rotation > 4) {
			printf("please choose a number between 1 and 4\n");
			sc = scanf("%d", rotation); // test if the scanf worked
			if(sc != 1) {
				printf("error scanf\n");
				exit(1);
			}
		}
	}
	time(&end); // end of the timer
	elapsed = difftime(end, start); // we calculate the difference
	if(elapsed > level) { // if the timer exceed the time limit
		printf("you took too long sorry, the rotation will be chosen randomly\n");
		*rotation = (rand() % 4) + 1;
	}
	*rotation = *rotation - 1;
}

void choose_column(char* column, int level) { // alow to choose the block's column
	int sc = 0; // will be use to check the scanf
	double elapsed; // allow use to have the difference between the end and the start of the timer
	time_t start, end; // will be the start and the end of the timer
	time(&start); // beginning of the timer
	sc = scanf("%c", column); // test if the scanf worked
	if(sc != 1) {
		printf("error scanf\n");
		exit(1);
	}
	if(*column < 65 || *column > 74) {
		while(*column < 65 || *column > 74) {
			printf("\nplease choose a letter between A and J for the column\n");
			sc = scanf("%c", column); // test if the scanf worked
			if(sc != 1) {
				printf("error scanf\n");
				exit(1);
			}
		}
	}
	time(&end);
	elapsed = difftime(end, start); // we calculate the difference
	if(elapsed > level) { // if the timer exceed the time limit
		printf("you took too long sorry, the column will be chosen randomly\n");
		*column = (rand() % 10) + 65 ;
	}
	*column = *column-65;	
}
