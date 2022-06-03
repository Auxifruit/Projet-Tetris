#include "header.h"
		
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
					if(calc[i][j]==1){
						calc[i][j]=calc[i][j];
					}
					
				}
			}
		}
		else if(thickness==3){
			for(int i=0;i<TAILLE;i++){
				for(int j=9;j>-1;j--){
					if(column==6){
						if(calc[i][j]==1){
							calc[i][j]=calc[i][j];
						}
					}
					else if(column ==7||column==8||column==9){
						if(calc[i][j]==1){
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
		else if(thickness==2){
			for(int i=0;i<TAILLE;i++){
				for(int j=9;j>0;j--){
					if(column==6){
						if(calc[i][j]==1){
							calc[i][j]=calc[i][j];
						}
					}
					else if(column==7){
						if(calc[i][j]==1){
							calc[i][j+1]=calc[i][j];
							calc[i][j]=0;
						}
					}
					else if(column==8||column==9){
						if(calc[i][j]==1){
							calc[i][j+2]=calc[i][j];
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
		else if(thickness==1){
			for(int i=0;i<TAILLE;i++){
				for(int j=9;j>-1;j--){
					if(column==6){
						if(calc[i][j]==1){
							calc[i][j]=calc[i][j];
						}
					}
					else if(column==7){
						if(calc[i][j]==1){
							calc[i][j+1]=calc[i][j];
							calc[i][j]=0;
						}
					}
					else if(column==8){
						if(calc[i][j]==1){
							calc[i][j+2]=calc[i][j];
							calc[i][j]=0;
						}
					}
					else if(column == 9){
						if(calc[i][j]==1){
							calc[i][j+3]=calc[i][j];
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
		else{ 
			printf("\nPlacement block error\n");
			exit(1);
		}
	}
	while(blocked!=1){
		for(int b=9;b>=0;b--){
			for(int c=0;c<TAILLE;c++){
				if((calc[b][c]==1 && tab[b+1][c]==1)||(calc[b][c+1]==1 && tab[b+1][c+1]==1)||(calc[b][c+2]==1 && tab[b+1][c+2]==1)||(calc[b][c+3]==1 && tab[b+1][c+3]==1)||(calc[b-1][c]==1 && tab[b][c]==1)||(calc[b-1][c+1]==1 && tab[b][c+1]==1)||(calc[b-1][c+2]==1 && tab[b][c+2]==1)||(calc[b-1][c+3]==1 && tab[b][c+3]==1)){
				
					calcimpression(tab,calc);
					return;
				}
				else if(calc[b][c]==1 && b==8){
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
	for(int g=0;g<TAILLE;g++){
		for(int h = 0;h<TAILLE;h++){
			if(calc[g][h]==1){
				tab[g][h]=calc[g][h]; //place the bloc at the bottom of the real tab
			}
		}
	}
}


void fall(int calc[TAILLE][TAILLE]){
	for(int i=9; i>=0;i--){
		for(int j=0;j<TAILLE;j++){
			if(calc[i][j]==1){
				calc[1+i][j]=1;
				calc[i][j]=0;
			}
		}
	}
}
	
