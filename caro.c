/************************************************************************

 * caro.c

 * Copyright (C) 2016 Dang Duong

 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.

************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char matrix[25][25]; 
char check(void);
int score1;
int score2;
void init_matrix(void);
void get_player_move(void);
void get_player_1_move(void);
void get_player_2_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main(void)
{
  char done;
  int choice;
  char cont[]=" ";
  do {
    printf("This is the Caro game\n");
    printf("Please choose the game mode:\n");
    printf("1. 1 player (vs computer)\n");
    printf("2. 2 players\n");
    scanf("%d",&choice);
  } while (choice!=1&&choice!=2);
  if (choice==1){
    printf("You will be playing against the computer.\n");

    do {
      done = ' ';
      init_matrix();
      do {
	printf("Player %d-%d Computer\n",score1,score2);
	disp_matrix();
	get_player_move();
	done = check(); /* see if winner */
	if(done!= ' ') break; /* winner!*/
	printf("Player %d-%d Computer\n",score1,score2);
	get_computer_move ();
	done = check(); /* see if winner */
      } while(done== ' ');
      if (done=='X'){
	printf("You won!\n");
	++score1;
      }
      else {
	printf("I won!!!!\n");
	++score2;
      }
      printf("Player %d-%d Computer\n",score1,score2);
      disp_matrix(); /* show final positions */
      
      printf("\nContinue? [Enter N to stop]\n");
      scanf("%s",&cont);
    } while (strcmp(cont,"N")!=0&&strcmp(cont,"n")!=0);
  }
  else {
    char playerone[]=" ";
    char playertwo[]=" ";
    do {
      printf("Enter player 1's name: \n");
      scanf("%s",&playerone);
    
      printf("Enter player 2's name: \n");
      scanf("%s",&playertwo);
    } while (strcmp(playerone,playertwo)==0||strcmp(playerone," ")==0||strcmp(playertwo," ")==0);
    printf("2 players will be playing.\n");

    do {
      done=' ';
      init_matrix();
      do {
	printf("\n%s %d-%d %s\n",playerone,score1,score2,playertwo);
	disp_matrix();
	get_player_1_move();
	done = check();
	
	if (done!=' ') break;
	printf("\n%s %d-%d %s\n",playerone,score1,score2,playertwo);
	disp_matrix();
	
	get_player_2_move();
	done = check();
      } while (done== ' ');
      if (done=='X') {
	printf("%s won!\n",playerone);
	++score1;
      }
      else {
	printf("%s won!\n",playertwo);
	++score2;
      }
      printf("\n%s %d-%d %s\n",playerone,score1,score2,playertwo);
      disp_matrix();
      
      printf("\nContinue?[Enter N to stop]\n");
      scanf("%s",&cont);
    } while (strcmp(cont,"N")!=0&&strcmp(cont,"n")!=0);
  }
  return 0;
}
/* Initialize the matrix. */
void init_matrix(void)
{
int i, j;
for(i=5; i<20; i++)
for(j=5; j<20; j++) matrix[i][j] = ' ';
}

/* Get a player's move. */
void get_player_move (void)
{
int x, y;
printf("Enter X,Y coordinates for your move: ");
scanf("%d%*c%d", &x, &y);
x--; y--;
if(matrix[x+5][y+5]!= ' '){
printf("Invalid move, try again.\n");
get_player_move();
}
else matrix[x+5][y+5] = 'X';
}

void get_player_1_move (void)
{
int x, y;
printf("Enter X,Y coordinates for Player 1's move: ");
scanf("%d%*c%d", &x, &y);
x--; y--;
if(matrix[x+5][y+5]!= ' '){
printf("Invalid move, try again.\n");
get_player_1_move();
}
else matrix[x+5][y+5] = 'X';
}
 
void get_player_2_move (void)
{
int x, y;
printf("Enter X,Y coordinates for Player 2's move: ");
scanf("%d%*c%d", &x, &y);
x--; y--;
if(matrix[x+5][y+5]!= ' '){
printf("Invalid move, try again.\n");
get_player_2_move();
}
else matrix[x+5][y+5] = 'O';
}
/* Get a move from the computer. */
void get_computer_move(void)
{
int i, j;
for(i=5; i<20; i++){
for(j=5; j<20; j++)
if(matrix[i][j]==' ') break;
if(matrix[i][j]==' ') break;
}
if(i*j==400) {
printf("draw\n");
exit(0);
}
else
matrix[i][j] = 'O';
}

void disp_matrix(void){
  int i,t;
  for (i=5;i<20;i++){
    printf("|---");
  }
  printf("|\n");
  for (t=5;t<20;t++){
    for (i=5;i<20;i++){
      printf("| %c ",matrix[i][t]);
    }
    printf("|\n");
    for (i=5;i<20;i++){
      printf("|---");
    }
    printf("|\n");
  }
}

char check(void){
  int i,t;
  /*rows*/
  for (i=4;i<16;i++){
    for (t=4;t<16;t++){
      if (matrix[i][t+1]==matrix[i][t+2]&&matrix[i][t+1]==matrix[i][t+3]&&matrix[i][t+1]==matrix[i][t+4]&&matrix[i][t+1]==matrix[i][t+5]){
	if (matrix[i][t]!=matrix[i][t+1]){
	  if (matrix[i][t]==' '){
	    if (matrix[i][t+6]!=matrix[i][t+1]) {
	      if (matrix[i][t+1]=='X'||matrix[i][t+1]=='O') return matrix[i][t+1];
	    }
	  }
	  else {
	    if (matrix[i][t+6]!=matrix[i][t+1]&&matrix[i][t+6]!=matrix[i][t]){
	      if (matrix[i][t+1]=='X'||matrix[i][t+1]=='O') return matrix[i][t+1];
	    }
	  }
	}
      }
    }
  }
  /*columns*/
  for (i=4;i<16;i++){
    for (t=4;t<16;t++){
      if (matrix[i+1][t]==matrix[i+2][t]&&matrix[i+1][t]==matrix[i+3][t]&&matrix[i+1][t]==matrix[i+4][t]&&matrix[i+1][t]==matrix[i+5][t]){
	if (matrix[i][t]!=matrix[i+1][t]){
	  if (matrix[i][t]==' '){
	    if (matrix[i+6][t]!=matrix[i+1][t]){
	      if (matrix[i+1][t]=='X'||matrix[i+1][t]=='O') return matrix[i+1][t];
	    }
	  }
	  else {
	    if (matrix[i+6][t]!=matrix[i+1][t]&&matrix[i+6][t]!=matrix[i][t]){
	      if (matrix[i+1][t]=='X'||matrix[i+1][t]=='O') return matrix[i+1][t];
	    }
	  }
	}
      }
	      
    }
  }
  /*diagonals*/
  for (i=4;i<16;i++){
    for (t=4;t<16;t++){
      if(matrix[i+1][t+1]==matrix[i+2][t+2]&&matrix[i+1][t+1]==matrix[i+3][t+3]&&matrix[i+1][t+1]==matrix[i+4][t+4]&&matrix[i+1][t+1]==matrix[i+5][t+5]){
	if (matrix[i][t]!=matrix[i+1][t+1]){
	  if (matrix[i][t]==' '){
	    if (matrix[i+6][t+6]!=matrix[i+1][t+1]){
	      if (matrix[i+1][t+1]=='X'||matrix[i+1][t+1]=='O') return matrix[i+1][t+1];
	    }
	  }
	  else {
	    if (matrix[i+6][t+6]!=matrix[i+1][t+1]){
	      if (matrix[i][t]=='X'||matrix[i][t]=='O'){
		if (matrix[i+6][t+6]!=matrix[i][t]){
		  if (matrix[i+1][t+1]=='X'||matrix[i+1][t+1]=='O') return matrix[i+1][t+1];
		}
	      }
	      else {
		if (matrix[i+1][t+1]=='X'||matrix[i+1][t+1]=='O') return matrix[i+1][t+1];
	      }
	    }
	  }
	}
      }
    }
  }
  for (i=15;i>3;i--){
    for (t=4;t<16;t++){
      if(matrix[i-1][t+1]==matrix[i-2][t+2]&&matrix[i-1][t+1]==matrix[i-3][t+3]&&matrix[i-1][t+1]==matrix[i-4][t+4]&&matrix[i-1][t+1]==matrix[i-5][t+5]){
	if (matrix[i][t]!=matrix[i-1][t+1]){
	  if (matrix[i][t]==' '){
	    if (matrix[i-6][t+6]!=matrix[i-1][t+1]){
	      if (matrix[i-1][t+1]=='X'||matrix[i-1][t+1]=='O') return matrix[i-1][t+1];
	    }
	  }
	  else {
	    if (matrix[i-6][t+6]!=matrix[i-1][t+1]){
	      if (matrix[i][t]=='X'||matrix[i][t]=='O'){
		if (matrix[i-6][t+6]!=matrix[i][t]){
		  if (matrix[i-1][t+1]=='X'||matrix[i-1][t+1]=='O') return matrix[i-1][t+1];
		}
	      }
	      else {
		if (matrix[i-1][t+1]=='X'||matrix[i-1][t+1]=='O') return matrix[i-1][t+1];
	      }
	    }
	  }
	}
      }
    }
  }
  return ' ';
}
