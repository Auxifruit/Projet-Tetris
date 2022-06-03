#include "header.h"

void input(char *c) { // input a char
	while (((*c=getchar()) == '\n'));
}

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



void init_grid(int tab[TAILLE][TAILLE]) { // initialize the grid
	for(int i = 0; i < TAILLE; i++){
		for(int j = 0; j < TAILLE; j++) {
			tab[i][j] = 0; // all the case of the tab is equal to 0
		}
	}
}

void show_grid(int tab[TAILLE][TAILLE]) { // show the grid, used to update the grid
	printf("\nThis is your grid: \n");
	for(int k = 0; k < TAILLE; k++) { // printf the letter for each column from A to J
		printf(" %c", 65 + k);
	}
	for(int a = 0; a < TAILLE; a++){
		for(int b = 0; b < TAILLE; b++){
			if(b == 0) { // allow to print the first case of each lign
				printf("\n|%c|", block(tab[a][b]));
			}
			else{ // printf the rest of the lign
				printf("%c|", block(tab[a][b]));
			}
		}
	}
	printf("\n\n");
}

int block(int p) { // transform int in char
	if(p != 1 && p != 0) { // test if the parameter is right
		printf("\nerror: p must be egal to 1 or 0\n");
		exit(1);
	}
	switch(p) {
		case 0: return(32); break; // transform the 0 in ' '
		case 1: return(64); break; // transform the 1 in '@'
		default: printf("error transformation \n"); // if there is an error
			exit(1);
	}
}

int difficulty() { // choose the level of difficulty beetween 1 and 3 from easy to hard
	int choice; // will countain the level of diffuculty choose by the user
	int sc = 0; // will be use to check the scanf
	printf("\n");
	printf("choose your difficulty: \n");
	printf("level 1 (7 seconds) / level 2 (5 seconds) / level 3 (3 seconds) \n");
	do { // do while loop to have the right value for the difficulty
		sc = scanf("%d", &choice);
		if(sc != 1) { // check if there's an error
			printf("scanf error: please enter a number \n");
			exit(2);
		}
		if(choice != 1 && choice != 2 && choice != 3) {
			printf("please choose a valid level !\n");
		}
	} while(choice != 1 && choice != 2 && choice != 3);
	switch(choice) {
		case 1: return(7);
		case 2: return(5);
		case 3: return(3);
		default: printf("error value \n");
			exit(1);
	}
}


void timer(int time_limit) { // a timer that put a time limit to choose to column and the tetromino rotation
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
		if(elapsed > time_limit) {
			break;
		}
	}
	printf("\nEND OF TIMER! \n");
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
	file = fopen("HIGH_SCORE.txt","r+"); // open the file which countain the player's score
	if(file == NULL) { // check if the file was open
		printf("opening file error \n");
		exit(1);
	}
	printf("\nenter your name: "); // allow the player to enter his name
	sc = scanf("%s", &nom);
	if(sc != 1) { // test if the scanf worked
		printf("scanf error\n");
		exit(2);
	}
	fseek(file, 0, SEEK_END); // put the cursor at the end of the file to add to player's score and name
	fprintf(file, "name: %s / score: %d",nom, score);
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
	printf("\n\nthanks for playing our game! \n");
	fclose(file); // close the file
}

void int_random(int* random) { // return a random number to choose a tetromino
	*random = rand() % 7; // random number between 0 and 6
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
			tetro->color = 33;
		
			tetro->thickness[0]= 2;
			tetro->thickness[1]= 2;
			tetro->thickness[2]= 2;
			tetro->thickness[3]= 2;
			
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
			tetro->color = 36;
		
			tetro->thickness[0]=1;
			tetro->thickness[1]=4;
			tetro->thickness[2]=1;
			tetro->thickness[3]=4;
	
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
			tetro->color = 37;
		
			tetro->thickness[0]=2;
			tetro->thickness[1]=3;
			tetro->thickness[2]=2;
			tetro->thickness[3]=3;

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


			tetro->type[3][0][0] = 1; // L block & rotation 3
			tetro->type[3][0][1] = 1;
			tetro->type[3][0][2] = 1;
			tetro->type[3][1][0] = 1;
	}
// ------------------------------------------------------------------------------

	else if(random == 3) { // J block
			tetro->color = 34;
		
			tetro->thickness[0]=2;
			tetro->thickness[1]=3;
			tetro->thickness[2]=3;
			tetro->thickness[3]=2;

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
			tetro->color = 35;
		
			tetro->thickness[0]=3;
			tetro->thickness[1]=2;
			tetro->thickness[2]=3;
			tetro->thickness[3]=2;

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
			tetro->color = 31;

			tetro->thickness[0]=3;
			tetro->thickness[1]=2;
			tetro->thickness[2]=3;
			tetro->thickness[3]=2;
		
			tetro->type[0][0][0] = 1; // Z block & rotation 0
			tetro->type[0][0][1] = 1;
			tetro->type[0][1][1] = 1;
			tetro->type[0][1][2] = 1;


			tetro->type[1][0][1] = 1; // Z block & rotation 1
			tetro->type[1][1][0] = 1;
			tetro->type[1][1][1] = 1;
			tetro->type[1][2][0] = 1;


			tetro->type[2][0][0] = 1; // Z block & rotation 2
			tetro->type[2][0][1] = 1;
			tetro->type[2][1][1] = 1;
			tetro->type[2][1][2] = 1;


			tetro->type[3][0][1] = 1; // Z block & rotation 3
			tetro->type[3][1][0] = 1;
			tetro->type[3][1][1] = 1;
			tetro->type[3][2][0] = 1;			
	}

// ------------------------------------------------------------------------------

	else if(random == 6) {// S block
			tetro->color = 32;

			tetro->thickness[0]=3;
			tetro->thickness[1]=2;
			tetro->thickness[2]=3;
			tetro->thickness[3]=2;
		
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
			printf("block error \n");
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
}*/

void show_tetro(Tetromino *tetro) { // show the tetrimoni and its rotation
	printf("This is your block with its orientation:\n");
	for(int l = 0; l < DIMENSION; l++) {
		for(int m = 0; m < DIMENSION; m++) {
			for(int n = 0; n < DIMENSION; n++) {
					printf("\033[%dm%c", tetro->color, block(tetro->type[m][l][n])); // show the first row of each tetromino before going to the next lign
			}
			printf("	"); // allow to separate each rotation
		}
	printf("\033[37m\n"); // turn back the color to white
	}
	for(int i = 1; i < DIMENSION + 1; i++){ // allow to print the number of each rotation to 1 to 4
		printf("%d.	",i);
	}
	printf("\n");
}

void memory_block(Tetromino *tetro) { // memory allocation of the tetromino
	tetro->type = malloc(ROTATION * sizeof(int)); // allocation of the first tab
	for(int i = 0 ; i < ROTATION ; i++){
		tetro->type[i] = malloc(ROTATION * sizeof(int)); // allocation of the second tab
		for(int j = 0 ; j < ROTATION; j++){
			tetro->type[i][j] = malloc(ROTATION * sizeof(int)); // allocation of the third tab
		}
	}
}

void place(int tab[TAILLE][TAILLE], Tetromino* tetro) {// place a block in the grid
	char column;
	int rotation;
	choose_column(&column);
	choose_rotation(&rotation);
	placement(tetro,rotation,(int)column,tab);
	
}

void choose_rotation(int* rotation) {
	int sc = 0; // will be use to check the scanf
	do { // do while loop to have the right value for the rotation
		printf("\nchoose the rotation between 1 and 4\n");
		sc = scanf("%d", rotation); // test if the scanf worked
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

void choose_column(char* column) {
	int sc; // will be use to check the scanf
	do { // do while loop to have the right value for the column
		printf("\nchoose the column between A and J\n");
		sc = scanf("%c", column); // test if the scanf worked
		if(sc != 1) {
			printf("error scanf\n");
			exit(1);
		}
		if(*column < 65 || *column > 74) {
			printf("please choose a letter between A and J\n");
		}
	} while(*column < 65 || *column > 74);
	*column=*column-65;
	
}
