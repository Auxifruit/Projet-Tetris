#include "header.h"

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
			if(b == 0) { // allow to print the first case of each line
				switch(tab[a][b]){
					case 0:
						printf("\n|\033[37m%c\033[37m|", block(tab[a][b])); // printf the first case with its own color
						break;
					case 1:
						printf("\n|\033[33m%c\033[37m|", block(tab[a][b])); // printf the first case with its own color
						break;
					case 2:
						printf("\n|\033[36m%c\033[37m|", block(tab[a][b])); // printf the first case with its own color
						break;
					case 3:
						printf("\n|\033[37m%c\033[37m|", block(tab[a][b])); // printf the first case with its own color
						break;
					case 4:
						printf("\n|\033[34m%c\033[37m|", block(tab[a][b])); // printf the first case with its own color
						break;
					case 5:
						printf("\n|\033[35m%c\033[37m|", block(tab[a][b])); // printf the first case with its own color
						break;
					case 6:
						printf("\n|\033[31m%c\033[37m|", block(tab[a][b])); // printf the first case with its own color
						break;
					case 7:
						printf("\n|\033[32m%c\033[37m|", block(tab[a][b])); // printf the first case with its own color
						break;
					default:
						printf("\nvalue error to print\n"); // error if we have no valid value
						exit(0);
				}
			}
			else{ // printf the rest of the line
				switch(tab[a][b]){
					case 0:
						printf("\033[37m%c\033[37m|", block(tab[a][b])); // printf the rest of the line case with its own color
						break;
					case 1:
						printf("\033[33m%c\033[37m|", block(tab[a][b])); // printf the rest of the line case with its own color
						break;
					case 2:
						printf("\033[36m%c\033[37m|", block(tab[a][b])); // printf the rest of the line case with its own color
						break;
					case 3:
						printf("\033[37m%c\033[37m|", block(tab[a][b])); // printf the rest of the line case with its own color
						break;
					case 4:
						printf("\033[34m%c\033[37m|", block(tab[a][b])); // printf the rest of the line case with its own color
						break;
					case 5:
						printf("\033[35m%c\033[37m|", block(tab[a][b])); // printf the rest of the line case with its own color
						break;
					case 6:
						printf("\033[31m%c\033[37m|", block(tab[a][b])); // printf the rest of the line case with its own color
						break;
					case 7:
						printf("\033[32m%c\033[37m|", block(tab[a][b])); // printf the rest of the line case with its own color
						break;
					default:
						printf("\nErreur d'affichage\n"); // error if we have no valid value
						exit(0);
				}
			}
		}
	}
	printf("\n\n");
}

int block(int p) { // transform int in char
	if(p > 7 || p < 0) { // test if the parameter is right
		printf("\nerror: p must be between 0 or 7\n");
		exit(1);
	}
	switch(p) {
		case 0: return(32); // transform the 0 in ' '
		case 1: return(64); // transform the 1 in '@'
		case 2: return(64); // transform the 1 in '@'
		case 3: return(64); // transform the 1 in '@'
		case 4: return(64); // transform the 1 in '@'
		case 5: return(64); // transform the 1 in '@'
		case 6: return(64); // transform the 1 in '@'
		case 7: return(64); // transform the 1 in '@'
		default: printf("error transformation \n"); // if there is an error
			exit(1);
	}
}

int verification(int tab[TAILLE][TAILLE], int score){ // chech if a line is complete, and if it's full it goes to the linedelete function and increment the score before returning it
	int count = 0; // count that will increment if there is not a 0 in a line
	for(int i = 0; i < TAILLE; i++){ // check all line of the grid
		for(int j = 0; j < TAILLE; j++) {
			if(tab[i][j] != 0) { 
				count++; // we don't have a 0 so this means that the case is occupied so we increment the value of count
				if(count == 10) { // it means that the line is full so we delete it
					 score = linedelete(tab, i, score); // delete the line
				}
			}	
		}
	count = 0; // reset the counter to 0 because we go to an other line
	}
	printf("\nyour score = %d", score); // print the score to keep an eye on it
	return score;
}

int linedelete(int tab[TAILLE][TAILLE], int n, int score){ // after the verification, useful to delete the line and replaced by the line above
	for(int j = 0; j < TAILLE; j++){ // delete the line n with all the 1's to a line with 0's
		tab[n][j] = 0;
	}
	for(int k = n; k > 0; k--) { // replace the line with the line above
		for(int l = 0; l < TAILLE; l++) {
			tab[k][l] = tab[k - 1][l];
		} 												
	}
	score = score + 100; // increment the score by 100
	return score;
}

void place(int tab[TAILLE][TAILLE], Tetromino* tetro, int level) {// place a block in the grid
	char column; // will countain the column of the tetromino
	int rotation; // will countain the column of the tetromino
	choose_rotation(&rotation, level); // allow us to choose the rotation
	choose_column(&column, level); // allow us to choose the rotation
	placement(tetro,rotation,(int)column,tab); // place the tetromino in the grid
}

void placement(Tetromino *tetro, int rotation, int column, int tab[TAILLE][TAILLE]){
	int calc[TAILLE][TAILLE];
	int right_gap= 4-tetro->thickness[rotation];
	int constraint=0; // act like a boolean
	int blocked =0;
	int thickness = tetro->thickness[rotation];
	for(int z=0;z<TAILLE;z++){
		for(int y=0;y<TAILLE;y++){
			calc[z][y]=0;
		}
	}
	for(int l=0;l<4;l++){ // fais chacune des lignes 
		for(int m=0;m<4;m++){//chacune des cases
			if(column>9-tetro->thickness[rotation]-right_gap+1){ 
				calc[l][6+m]=tetro->type[rotation][l][m];	
				constraint = 1;  				
			}							
											
			else{
				calc[l][column+m]=tetro->type[rotation][l][m];
			}	
		}			
	}
	if(constraint==1){  	
		if(thickness==4){
			for(int i=0;i<TAILLE;i++){
				for(int j=9;j>-1;j--){
					if(calc[i][j]!=0){
						calc[i][j]=calc[i][j];
					}
					
				}
			}
		}
		else if(thickness==3){
			for(int i=0;i<TAILLE;i++){
				for(int j=9;j>-1;j--){
					if(column == 6){
						if(calc[i][j] != 0){
							calc[i][j]=calc[i][j];
						}
					}
					else if(column == 7 || column == 8 || column == 9){
						if(calc[i][j]!=0){
							calc[i][j+1]=calc[i][j];
							calc[i][j]=0;
						}
					}
					else{
						printf("\nBlock error\n");
						exit(1);
					}
				}
			}
		}
		else if(thickness == 2){
			for(int i = 0; i < TAILLE; i++){
				for(int j = 9 ; j > 0; j--){
					if(column == 6){
						if(calc[i][j] !=0){
							calc[i][j] = calc[i][j];
						}
					}
					else if(column == 7){
						if(calc[i][j] != 0){
							calc[i][j+1] = calc[i][j];
							calc[i][j] = 0;
						}
					}
					else if(column == 8 || column == 9){
						if(calc[i][j] != 0){
							calc[i][j+2] = calc[i][j];
							calc[i][j] = 0;
						}
					}
					else{
						printf("\nBlock error\n");
						exit(1);
					}
				}
			}
		}
		else if(thickness == 1){
			for(int i = 0; i < TAILLE; i++){
				for(int j = 9; j > -1; j--){
					if(column == 6){
						if(calc[i][j] != 0){
							calc[i][j] = calc[i][j];
						}
					}
					else if(column == 7){
						if(calc[i][j] !=0){
							calc[i][j+1] = calc[i][j];
							calc[i][j] = 0;
						}
					}
					else if(column == 8){
						if(calc[i][j] != 0){
							calc[i][j+2] = calc[i][j];
							calc[i][j] = 0;
						}
					}
					else if(column == 9){
						if(calc[i][j] != 0){
							calc[i][j+3] = calc[i][j];
							calc[i][j] = 0;
						}
					}
					else{
						printf("\nBlock error\n");
						exit(1);
					}
				}
			}
		}
		else{ 
			printf("\nPlacement block error\n");
			exit(1);
		}
	}
	while(blocked != 1){
		for(int b = 0; b < TAILLE; b++){
			for(int c = 0; c < TAILLE; c++){
				if((calc[b][c] !=0 && tab[b+1][c]!=0) /*|| (calc[b-1][c] != 0 && tab[b][c] != 0) || ((calc[b+1][c] != 0 && tab[b][c] !=0 ))*/){
					printf("lololo\n");
					calcimpression(tab,calc);
					return;
				}
				else if(calc[b][c] != 0 && b == 8){
					fall(calc);
					calcimpression(tab,calc);
					return;
				}
			}
		}
		fall(calc);
	}
	calcimpression(tab,calc);
}



void calcimpression(int tab[TAILLE][TAILLE], int calc[TAILLE][TAILLE]){
	for(int g = 0;g < TAILLE; g++){
		for(int h = 0;h < TAILLE; h++){
			if(calc[g][h]!=0){
				tab[g][h]=calc[g][h]; //place the bloc at the bottom of the real tab
			}
		}
	}
}

void fall(int calc[TAILLE][TAILLE]){
	printf("lalala\n");
	for(int i = 9; i >= 0; i--){
		for(int j = 0; j < TAILLE; j++){
			if(calc[i][j] != 0){
				calc[1+i][j] = calc[i][j];
				calc[i][j] = 0;
			}
		}
	}
}
