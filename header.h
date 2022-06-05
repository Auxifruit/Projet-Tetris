#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define TAILLE 10 // size of the tab width and hight
#define ROTATION 4 // number of rotation of a tetromomino
#define DIMENSION 4 // number of tetromino with each of its rotation
#define GAME 0 // alow to loop the game

typedef struct {
	int ***type; // contain the tetromino's form and its orientation
	int orientation; // orientation of the tetromino
	int color; // color of the tetromino
	int thickness[ROTATION];
} Tetromino;

// all function of fonction_grid.c 
void init_grid(int tab[TAILLE][TAILLE]); // initialize the grid
void show_grid(int tab[TAILLE][TAILLE]); // show the grid in the terminal
int block(int p); // transform int in char
int verification(int tab[TAILLE][TAILLE], int score); //return the line in which a line is full
int linedelete(int tab[TAILLE][TAILLE], int n, int score); // after the verification, useful to delete the line and replaced by the line above
void placement(Tetromino *tetro, int rotation, int column, int tab[TAILLE][TAILLE]); // place the bloc with the colisions
void place(int tab[TAILLE][TAILLE], Tetromino* tetro, int level); // place a block in the table
void calcimpression(int tab[TAILLE][TAILLE], int calc[TAILLE][TAILLE]); // add the calc to the final tab
void fall(int calc[TAILLE][TAILLE]); // make the block fall

// all function of fonction_tetro.c
void int_random(int* rand); // return a random number to choose a tretromino
void rand_tetro(Tetromino *tetro); // return a random tetromino thanks to the "int_random()" function
void show_tetro(Tetromino *tetro); // show the tetromino with its color and its rotation
void memory_block(Tetromino *tetro); // memory allocation of the tetromino

//all function of fonction_jouabilité.c
void logo(); // printf the classic tetris logo
int difficulty(); // choose the level of difficulty, it will change the time between the placement of every tetrominos
void end_game(int score); // when the game is over, it will stop the game
void verifgameover(int tab[TAILLE][TAILLE], int score); // verification of the first line of the tab, if there is a bloc, it's game over
void choose_rotation(int* rotation, int level); // alow to choose the block's rotation
void choose_column(char* column, int level); // alow to choose the block's column
