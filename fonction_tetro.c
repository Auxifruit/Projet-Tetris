#include "header.h"

void int_random(int* random) { // return a random number to choose a tetromino
	*random = rand() % 7; // random number between 0 and 6
}
	

void rand_tetro(Tetromino *tetro) {
	int random;
	for(int i=0; i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				tetro->type[i][j][k]=0;
			}
		}
	}
	int_random(&random); // pick a random number for a random piece
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
	
			tetro->type[0][0][0] = 2; // I block & rotation 0
			tetro->type[0][1][0] = 2;
			tetro->type[0][2][0] = 2;
			tetro->type[0][3][0] = 2;


			tetro->type[1][0][0] = 2; // I block & rotation 1
			tetro->type[1][0][1] = 2;
			tetro->type[1][0][2] = 2;
			tetro->type[1][0][3] = 2;

			tetro->type[2][0][0] = 2; // I block & rotation 2
			tetro->type[2][1][0] = 2;
			tetro->type[2][2][0] = 2;
			tetro->type[2][3][0] = 2;


			tetro->type[3][0][0] = 2; // I block & rotation 3
			tetro->type[3][0][1] = 2;
			tetro->type[3][0][2] = 2;
			tetro->type[3][0][3] = 2;
			
	}

// ------------------------------------------------------------------------------

	else if(random == 2) { // L block
			tetro->color = 37;
		
			tetro->thickness[0]=2;
			tetro->thickness[1]=3;
			tetro->thickness[2]=2;
			tetro->thickness[3]=3;

			tetro->type[0][0][0] = 3; // L block & rotation 0
			tetro->type[0][1][0] = 3;
			tetro->type[0][2][0] = 3;
			tetro->type[0][2][1] = 3;


			tetro->type[1][0][2] = 3; // L block & rotation 1
			tetro->type[1][1][0] = 3;
			tetro->type[1][1][1] = 3;
			tetro->type[1][1][2] = 3;
		

			tetro->type[2][0][0] = 3; // L block & rotation 2
			tetro->type[2][0][1] = 3;
			tetro->type[2][1][1] = 3;
			tetro->type[2][2][1] = 3;


			tetro->type[3][0][0] = 3; // L block & rotation 3
			tetro->type[3][0][1] = 3;
			tetro->type[3][0][2] = 3;
			tetro->type[3][1][0] = 3;
	}
// ------------------------------------------------------------------------------

	else if(random == 3) { // J block
			tetro->color = 34;
		
			tetro->thickness[0]=2;
			tetro->thickness[1]=3;
			tetro->thickness[2]=3;
			tetro->thickness[3]=2;

			tetro->type[0][0][0] = 4; // J block & rotation 0
			tetro->type[0][0][1] = 4;
			tetro->type[0][1][0] = 4;
			tetro->type[0][2][0] = 4;


			tetro->type[1][0][0] = 4; // J block & rotation 1
			tetro->type[1][1][0] = 4;
			tetro->type[1][1][1] = 4;
			tetro->type[1][1][2] = 4;


			tetro->type[2][0][0] = 4; // J block & rotation 2
			tetro->type[2][0][1] = 4;
			tetro->type[2][0][2] = 4;
			tetro->type[2][1][2] = 4;


			tetro->type[3][0][1] = 4; // J block & rotation 3
			tetro->type[3][1][1] = 4;
			tetro->type[3][2][0] = 4;
			tetro->type[3][2][1] = 4;
	}

// ------------------------------------------------------------------------------

	else if(random == 4) { // T block
			tetro->color = 35;
		
			tetro->thickness[0]=3;
			tetro->thickness[1]=2;
			tetro->thickness[2]=3;
			tetro->thickness[3]=2;

			tetro->type[0][0][1] = 5; // T block & rotation 0
			tetro->type[0][1][0] = 5;
			tetro->type[0][1][1] = 5;
			tetro->type[0][1][2] = 5;


			tetro->type[1][0][0] = 5; // T block & rotation 1
			tetro->type[1][1][0] = 5;
			tetro->type[1][1][1] = 5;
			tetro->type[1][2][0] = 5;


			tetro->type[2][0][0] = 5; // T block & rotation 2
			tetro->type[2][0][1] = 5;
			tetro->type[2][0][2] = 5;
			tetro->type[2][1][1] = 5;


			tetro->type[3][0][1] = 5; // T block & rotation 3
			tetro->type[3][1][0] = 5;
			tetro->type[3][1][1] = 5;
			tetro->type[3][2][1] = 5;
	}

// ------------------------------------------------------------------------------

	else if(random == 5) { // Z block
			tetro->color = 31;

			tetro->thickness[0]=3;
			tetro->thickness[1]=2;
			tetro->thickness[2]=3;
			tetro->thickness[3]=2;
		
			tetro->type[0][0][0] = 6; // Z block & rotation 0
			tetro->type[0][0][1] = 6;
			tetro->type[0][1][1] = 6;
			tetro->type[0][1][2] = 6;


			tetro->type[1][0][1] = 6; // Z block & rotation 1
			tetro->type[1][1][0] = 6;
			tetro->type[1][1][1] = 6;
			tetro->type[1][2][0] = 6;


			tetro->type[2][0][0] = 6; // Z block & rotation 2
			tetro->type[2][0][1] = 6;
			tetro->type[2][1][1] = 6;
			tetro->type[2][1][2] = 6;


			tetro->type[3][0][1] = 6; // Z block & rotation 3
			tetro->type[3][1][0] = 6;
			tetro->type[3][1][1] = 6;
			tetro->type[3][2][0] = 6;			
	}

// ------------------------------------------------------------------------------

	else if(random == 6) {// S block
			tetro->color = 32;

			tetro->thickness[0]=3;
			tetro->thickness[1]=2;
			tetro->thickness[2]=3;
			tetro->thickness[3]=2;
		
			tetro->type[0][0][1] = 7; // S block & rotation 0
			tetro->type[0][0][2] = 7;
			tetro->type[0][1][0] = 7;
			tetro->type[0][1][1] = 7;


			tetro->type[1][0][0] = 7; // S block & rotation 1
			tetro->type[1][1][0] = 7;
			tetro->type[1][1][1] = 7;
			tetro->type[1][2][1] = 7;


			tetro->type[2][0][1] = 7; // S block & rotation 2
			tetro->type[2][0][2] = 7;
			tetro->type[2][1][0] = 7;
			tetro->type[2][1][1] = 7;


			tetro->type[3][0][0] = 7; // S block & rotation 3
			tetro->type[3][1][0] = 7;
			tetro->type[3][1][1] = 7;
			tetro->type[3][2][1] = 7;
	}

	else {
			printf("block error \n");
			exit(1);
	}
}

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
