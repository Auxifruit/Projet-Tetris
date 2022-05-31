#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define TAILLE 10
#define MAXTETRO 6
#define ROTATION 4
#define DIMENSION 4

typedef struct {
	int ***type;
	int orientation;
} Tetromino;

void init_grid(int tab[TAILLE][TAILLE]); // initialize the grid
void show_grid(int tab[TAILLE][TAILLE]); // show the grid in the terminal
int block(int p); // transform int in char
int difficulty(); // choose the level of difficulty, it will change the time between the placement of every tetrominos
void timer(); // a timer that will be useful to the change of diffculty and time to change block position 
void place(int tab[TAILLE][TAILLE], Tetromino* tetro); // place a block in the table
void input(char *c); // input a char
void end_game(int score); // when the game is over, it will stop the game
void rand_tetro(Tetromino *tetro);
//void game(); // allow to start the game
//int verification(int tab[][]); //return the line in which a line is full and if no line is full, return NULL
//void linedelete(int tab[][], int n); // after the verification, useful to delete the line and replace by the line on the bottom
int verification(int tab[TAILLE][TAILLE]); //return the line in which a line is full and if no line is full, return NULL
void linedelete(int tab[TAILLE][TAILLE], int n, int score); // after the verification, useful to delete the line and replace by the line on the bottom
//void show_block
void show_tetro(Tetromino *tetro); // show the tetrimoni and its rotation
void memory_block(Tetromino *tetro); // memory allocation of the tetromino
