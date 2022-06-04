#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define TAILLE 10
#define MAXTETRO 6
#define ROTATION 4
#define DIMENSION 4
#define GAME 0

typedef struct {
	int ***type; // contain the tetromino's form and its orientation
	int orientation; // orientation of the tetromino
	int color; // color of the tetromino
	int thickness[ROTATION];
} Tetromino;

void logo(); // printf the classic tetris logo
void init_grid(int tab[TAILLE][TAILLE]); // initialize the grid
void show_grid(int tab[TAILLE][TAILLE]); // show the grid in the terminal
int block(int p); // transform int in char
int difficulty(); // choose the level of difficulty, it will change the time between the placement of every tetrominos
void input(char *c); // input a char
void end_game(int score); // when the game is over, it will stop the game
void int_random(int* rand); // return a random number to choose a tretromino
void rand_tetro(Tetromino *tetro); // return a random tetromino thanks to the "int_random()" fonction
int verification(int tab[TAILLE][TAILLE], int score); //return the line in which a line is full and if no line is full, return NULL
int linedelete(int tab[TAILLE][TAILLE], int n, int score); // after the verification, useful to delete the line and replace by the line on the bottom
void show_tetro(Tetromino *tetro); // show the tetrimoni and its rotation
void memory_block(Tetromino *tetro); // memory allocation of the tetromino
void place(int tab[TAILLE][TAILLE], Tetromino* tetro, int level); // place a block in the table
void choose_rotation(int* rotation, int level); // alow to choose the block's rotation
void choose_column(char* column, int level); // alow to choose the block's column
void placement(Tetromino *tetro, int rotation, int column, int tab[TAILLE][TAILLE]); // place the bloc with the colisions
void calcimpression(int tab[TAILLE][TAILLE], int calc[TAILLE][TAILLE]); // add the calc to the final tab
void fall(int calc[TAILLE][TAILLE]); //make the block fall by one
void verifgameover(int tab[TAILLE][TAILLE], int score); //verification for the for the first line of the tab, if there is a bloc, it's game over
