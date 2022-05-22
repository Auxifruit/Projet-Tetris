#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define TAILLE 10

typedef struct {
	char** grid;
	int w;
	int h;
} Orientation;

typedef struct {
	Orientation orientation[4];
} Piece;

void init_grid(int tab[TAILLE][TAILLE]);
void show_grid(int tab[TAILLE][TAILLE]);
int bloc(int p);
int difficulty();
void timer();

int main() {
	int tab[TAILLE][TAILLE];
	srand(time(NULL));
	init_grid(tab);
	show_grid(tab);
	//timer();
	printf("\n");
	return 0;
}

void init_grid(int tab[TAILLE][TAILLE]) {
	for(int i = 0; i < TAILLE; i++){
		for(int j = 0; j < TAILLE; j++) {
			tab[i][j] = 0;
		}
	}
}

void show_grid(int tab[TAILLE][TAILLE]) {
	printf("This is your grid: \n\n");
	for(int k = 0; k < TAILLE; k++) {
		printf(" %c", 65 + k);
	}
	for(int a = 0; a < TAILLE; a++){
		for(int b = 0; b < TAILLE; b++){
			if(b == 0) {
				printf("\n|%c|", bloc(tab[a][b]));
			}
			else{
				printf("%c|", bloc(tab[a][b]));
			}
		}
	}
}

int bloc(int p) {
	switch(p) {
		case 0: return(32); break;
		case 1: return(64); break;
		default: return(69);
	}
}
int difficulty() {
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


void timer() {
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
