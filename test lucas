#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#define ligne 10
#define colonne 10
#define loose -500		// if this is  a loose condition we will use this value

typedef struct
{
  int x;
  int y;
  int thickness;

  char tab[4][4];

} pa;



void videScanf(){

int res;

char c;

do{

res = scanf("%c", &c);

} while( res == 1 && c !='\n' );

}
int
choosecc (pa piece)
{
  int c = -1;

  time_t start = time (NULL);

  while (c < 1 || c > 10 - piece.thickness + 1)
    {


      printf (" \nchoissisez  la colonne ? \n");
      scanf ("%d", &c);
videScanf;
    }
  time_t end = time (NULL);

  unsigned long secondes = (unsigned long) difftime (end, start);

  if (secondes > 10)
    {printf("\n vous avez pris trop de temps la colonne est aleatoire \n");
     c=rand()%(10-piece.thickness)+1;
      
    }

  return c;
}



int
chooseorientation ()
{
  int orientation = -1;

  time_t start = time (NULL);

  while (orientation < 0 || orientation > 4)
    {


      printf (" \nchoissisez  l'orientation   ? \n");
      scanf (" %d", &orientation);
    videScanf;
    }
  time_t end = time (NULL);

  unsigned long secondes = (unsigned long) difftime (end, start);

  if (secondes > 10)
    {
      printf ("vous avez pris trop de temps l'orientation est aléatoire  ");
      orientation=rand()%3+1;
    }

  return orientation;
}




int
randpiece ()
{
  int randpiece = rand () % 5;

  return randpiece;
}


pa
placement (int randpiece, int orientation)
{
  pa piece;
  for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
	{
	  piece.tab[i][j] = ' ';
    }}
  if (randpiece == 0)
    {
      piece.tab[0][0] = '@';
      piece.tab[0][1] = '@';
      piece.tab[1][1] = '@';
      piece.tab[1][0] = '@';
      piece.thickness = 2;

    }
  else if (randpiece == 1 && orientation == 1)
    {
      piece.tab[0][0] = '@';
      piece.tab[3][0] = '@';
      piece.tab[1][0] = '@';
      piece.tab[2][0] = '@';
      piece.thickness = 1;
    }
  else if (randpiece == 1 && orientation == 2)
    {
      piece.tab[0][1] = '@';
      piece.tab[0][0] = '@';
      piece.tab[0][2] = '@';
      piece.tab[0][3] = '@';
      piece.thickness = 4;
    }
  else if (randpiece == 1 && orientation == 3)
    {
      piece.tab[0][1] = '@';
      piece.tab[0][0] = '@';
      piece.tab[0][2] = '@';
      piece.tab[0][3] = '@';
      piece.thickness = 4;
    }
  else if (randpiece == 1 && orientation == 4)
    {
      piece.tab[0][0] = '@';
      piece.tab[3][0] = '@';
      piece.tab[1][0] = '@';
      piece.tab[2][0] = '@';
      piece.thickness = 1;
    }
  else if (randpiece == 2 && orientation == 1)
    {
      piece.tab[0][1] = '@';
      piece.tab[0][0] = '@';
      piece.tab[1][0] = '@';
      piece.tab[2][0] = '@';
     
      piece.thickness = 2;
    }
  else if (randpiece == 2 && orientation == 2)
    {
      piece.tab[0][0] = '@';
      piece.tab[1][0] = '@';
      piece.tab[0][1] = '@';
      piece.tab[0][2] = '@';
      
      piece.thickness = 4;
    }
  else if (randpiece == 2 && orientation == 3)
    {
      piece.tab[2][1] = '@';
      piece.tab[1][0] = '@';
      piece.tab[2][0] = '@';
      piece.tab[0][0] = '@';
      piece.thickness = 2;
    }
  else if (randpiece == 2 && orientation == 4)
    {

      piece.tab[1][1] = '@';
      piece.tab[1][0] = '@';
      piece.tab[1][2] = '@';
      
      piece.tab[0][2] = '@';
      piece.thickness = 4;
    }
  else if (randpiece == 3 && orientation == 1)
    {
      piece.tab[0][0] = '@';
      piece.tab[0][1] = '@';
      piece.tab[0][2] = '@';
      piece.tab[1][1] = '@';
      piece.thickness = 3;
    }

  else if (randpiece == 3 && orientation == 2)
    {
      piece.tab[0][0] = '@';
      piece.tab[1][0] = '@';
      piece.tab[2][0] = '@';
      piece.tab[1][1] = '@';
      piece.thickness = 2;
    }

  else if (randpiece == 3 && orientation == 3)
    {
      piece.tab[0][1] = '@';
      piece.tab[1][0] = '@';
      piece.tab[1][1] = '@';
      piece.tab[1][2] = '@';
      piece.thickness = 3;

    }

  else if (randpiece == 3 && orientation == 4)
    {
      piece.tab[1][0] = '@';
      piece.tab[0][1] = '@';
      piece.tab[1][1] = '@';
      piece.tab[2][1] = '@';
      piece.thickness = 2;
    }

  else if (randpiece == 4 && orientation == 1)
    {
      piece.tab[0][0] = '@';
      piece.tab[0][1] = '@';
      piece.tab[1][1] = '@';
      piece.tab[1][2] = '@';
      piece.thickness = 3;
    }

  else if (randpiece == 4 && orientation == 3)
    {
      piece.tab[0][1] = '@';
      piece.tab[0][2] = '@';
      piece.tab[1][1] = '@';
      piece.tab[1][0] = '@';
      piece.thickness = 3;
    }

  else if (randpiece == 4 && orientation == 2)
    {
      piece.tab[0][0] = '@';
      piece.tab[1][1] = '@';
      piece.tab[1][0] = '@';
      piece.tab[2][1] = '@';
      piece.thickness = 2;
    }

  else if (randpiece == 4 && orientation == 4)
    {
      piece.tab[0][1] = '@';
      piece.tab[1][0] = '@';
      piece.tab[1][1] = '@';
      piece.tab[2][0] = '@';
      piece.thickness = 2;
    }
  return piece;

}

void
printpiecerota (int randpiece)
{
  int p, i;
  pa piece;
  printf ("\n");
  printf ("  1    2     3      4\n\n");
  for (p = 1; p < 5; p++)
    {
      piece = placement (randpiece, p);
      printf (" ");
      for (int c = 0; c < 4; c++)
	{
	  printf ("%c", piece.tab[0][c]);
	}
      printf (" ");
    }
  printf ("\n");
  for (p = 1; p < 5; p++)
    {
      piece = placement (randpiece, p);
      printf (" ");
      for (i = 0; i < 4; i++)
	{
	  printf ("%c", piece.tab[1][i]);
	}
      printf (" ");
    }
  printf ("\n");
  for (p = 1; p < 5; p++)
    {
      piece = placement (randpiece, p);
      printf (" ");
      for (i = 0; i < 4; i++)
	{
	  printf ("%c", piece.tab[2][i]);
	}
      printf (" ");
    }
  printf ("\n");

  for (p = 1; p < 5; p++)
    {
      piece = placement (randpiece, p);
      printf (" ");
      for (i = 0; i < 4; i++)
	{
	  printf ("%c", piece.tab[3][i]);
	}
      printf (" ");
    }
  printf ("\n");






}


void
intialisation (char tetris[ligne + 1][colonne])
{

  for (int i = 0; i < ligne + 1; i++)
    {

      for (int j = 0; j < colonne; j++)
	{
	  tetris[i][j] = ' ';

	}

    }
}

void
affichetableau (char tetris[ligne + 1][colonne])
{
  printf ("  |1|2|3|4|5|6|7|8|9|10|");
  for (int i = 1; i < ligne + 1; i++)
    {				//we don't print the first line 
      printf ("\n");
      if (i < 10)
	{
	  printf (" %d|", i);
	}
      else
	{
	  printf ("%d|", i);
	}

      for (int j = 0; j < colonne; j++)
	{
	  printf ("%c|", tetris[i][j]);
	}

    }
  printf ("\n");
}

void
numbrpiece (int nbrtour)
{
  if (nbrtour >= 2)
    {
      printf ("\nil vous reste %d tours\n\n", nbrtour);
    }
  else
    {
      printf ("il vous reste 1 tour");
    }
  nbrtour--;
}

//we gave gave a value to all piece 


void
addurscore (FILE * SCOREBOARD, int score)
{

  char name[250];
 printf("\necrivez votre nom :");
      scanf ("%s", name);

  fprintf (SCOREBOARD, "%s %d", name , score);
}






int
verifline (char tetris[ligne + 1][colonne])
{
  int squarecounter;		// this variable will count every caracter different of in the tetris
  for (int i = 0; i < ligne; i++)
    {
      squarecounter = 0;	// reintialize of the variable for every line
      for (int j = 0; j < colonne; j++)
	{
	  if (tetris[i][j] == '@')
	    {
	      squarecounter = squarecounter + 1;

	    }
	}
      if (squarecounter == 10)
	{
	  printf ("%d", i);
	  return i;
	}
    }
  return -1;
}



int
verifloose (char tab[ligne + 1][colonne])
{
  for (int i = 0; i < colonne; i++)
    {
      if (tab[0][i] != ' ')
	{
	  return loose;
	}
    }
  return 0;


}

void
deleteline (char tetris[ligne + 1][colonne], int linetodelete)
{
  for (int i = linetodelete; i >= 0; i--)
    {
      for (int j = 0; j < colonne; j++)
	{
	  tetris[i][j] = tetris[i - 1][j];
	}

    }

  for (int k = 0; k < colonne; k++)
    {
      tetris[0][k] = ' ';
    }
}


int
choosenbrtour (int nbrtour)
{
  printf
    ("\n veuillez choisir votre nombre de tour \n Vous avez le choix entre 3 possibilite \n ");

  while (nbrtour != 30 & nbrtour != 60 & nbrtour != 90)
    {
      printf
	("\n\n  ecrivez 30 pour jouer 30 tours   ecrivez 60 pour jouer 60 tours  ecrivez 90 pour jouer 90 tours\n\n\n ");
      scanf ("%d", &nbrtour);
      videScanf;
      
    }
  return nbrtour;
}

void printhighscore(FILE * SCOREBOARD ){
    int highscore,tmp;
    char namehighscore[256];
    while(fscanf(SCOREBOARD, "%d %s" , &highscore , namehighscore )!=EOF ){
    fscanf(SCOREBOARD, "%d %s" , &highscore , namehighscore ); 
   printf("score : %d nom : %s\n", highscore , namehighscore);
        
    }
    
}

void
totalscore (FILE * SCOREBOARD, int score)
{
  addurscore (SCOREBOARD, score);
  printhighscore(SCOREBOARD);

}

int
highline (pa piece, int col)
{
  int high = 0;
  for (int i = 0; i < 4; i++)
    {

      if (piece.tab[i][col] == '@' && piece.tab[i+1][col]==' '){

	return i +1;
}
 if (piece.tab[i][col] == ' ' && piece.tab[i+1][col] == ' ' && piece.tab[i+2][col] == ' ' && piece.tab[i+3][col] == ' ' ){

    return 0;
 }
    }

  return 4;
}

int choosehightetris ( pa piece, int col, char tetris [11][10])
{
    int tab[4];
    int coll[4];
    int k, index;
    for (k=0 ; k<4;k++){
        tab[k]=highline(piece , k);
        
    }  for (k=0 ; k<4;k++){
        coll[k]=col+k-1;
        
    } 
    for(int i=0; i<4; i++){
    if (tab[i]!=0){
        index =i;
    }
    else {
       while(tab[i]==0 ){//if it's ' ' we clone the case with an index case 
           tab[i]=tab[index];
           coll[i]=coll[index];
           
           
       }
        
    }
        
    }
   
    while(tetris[tab[0]][coll[0]]==' ' && tetris[ tab[1]] [coll[1]]==' ' && tetris[ tab[2]] [coll[2]]==' ' && tetris[ tab[3]] [coll[3]]==' ') {
for ( k=0 ; k<4 ; k++){
    tab[k]=tab[k]+1;
    
    
} 
        
        
    }
  
 return tab[0]-highline(piece , 0);
 
}






// 10- si y a une piece au dessus , hauteur piece 

void printpiece(char tetris [11][10] , int col , pa piece ){
    int z ; 
    z=choosehightetris (piece , col, tetris );
     for (int i = 0; i<4; i++)
    {
       
      for (int j = 0; j < 4; j++)
	{
	  if (piece.tab[i][j]=='@'){
	      
	      tetris[z+i][j+col-1]=piece.tab[i][j];
	  }
	}

    }
}

int game ()
{
  char tetris[ligne + 1][colonne];	// we create a tab with 1 one more line than necessary because we will use line 0 
  int orientation;
  int nbrtour;
  int score = 0;
  int piece;
  int verif = 10;
  intialisation (tetris);
  pa usep;
  int col;
  int high;
  int z;
  nbrtour = choosenbrtour (nbrtour);
  while (nbrtour > 0)
    {
      piece = randpiece ();
      numbrpiece (nbrtour);
      affichetableau (tetris);
      printpiecerota (piece);
      orientation = chooseorientation ();
      usep = placement (piece, orientation);




      col = choosecc (usep);
      
printpiece(tetris , col , usep);


     



      verif = verifloose (tetris);

      if (verifloose (tetris) == loose)
	{
	  printf ("Vous avez perdu");
	  exit (loose);
	}


      verif = verifline (tetris);
      while (verif > 0)
	{
	  verif = verifline (tetris);
	  deleteline (tetris, verif);
	  score =score+100;
	  
	}
	printf(" \nvotre score est  de %d \n ", score);
      nbrtour--;
    }

  return score;
}


int
main ()
{

  printf ("          ______   ___ ______ ____  ____ _____\n");
  printf ("         |      | /  _]      |    )|    / ___/\n");
  printf ("         |      |/  [_|      |  D  )|  ||   |_\n");
  printf ("         |_|  |_|    _]_|  |_|    / |  ||__  |\n");
  printf ("           |  | |   [_  |  | |    | |  | __| |\n");
  printf ("           |  | |     | |  | |  .  ||  ||    |\n");
  printf ("           |__| |_____| |__| |__||_|____||___|\n\n\n");





FILE *SCOREBOARD =fopen("score.txt"  ,"w");

 if (SCOREBOARD == NULL){
printf("\nOuverture du fichier impossible\n");
printf("code d'erreur = %d \n", errno );
exit(1);
}



  int score = game ();
  totalscore(SCOREBOARD , score);
  fclose(SCOREBOARD);
  return 0;


}
