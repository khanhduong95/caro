
#include <stdio.h>
#include <stdlib.h>
char matrix[25][25]; 
char check(void);

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
  do {
    printf("This is the Caro game\n");
    printf("Please choose the game mode:\n");
    printf("1. 1 player (vs computer)\n");
    printf("2. 2 players\n");
    scanf("%d",&choice);
  } while (choice!=1&&choice!=2);
  if (choice==1){
    printf("You will be playing against the computer.\n");
    done = ' ';
    init_matrix();
    do {
      disp_matrix();
      get_player_move();
      done = check(); /* see if winner */
      if(done!= ' ') break; /* winner!*/
      get_computer_move ();
      done = check(); /* see if winner */
    } while(done== ' ');
    if (done=='X') printf("You won!\n");
    else printf("I won!!!!\n");
    disp_matrix(); /* show final positions */
  }
  else {
    printf("2 players will be playing.\n");
    done=' ';
    init_matrix();
    do {
      disp_matrix();
      get_player_1_move();
      done = check();

      if (done!=' ') break;
      disp_matrix();
      
      get_player_2_move();
      done = check();
    } while (done== ' ');
    if (done=='X') printf("Player 1 won!\n");
    else printf("Player 2 won!\n");
    disp_matrix();
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
      printf("| %c ",matrix[t][i]);
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
  for (i=5;i<20;i++){
    for (t=5;t<20;t++){
      if (matrix[i][t]==matrix[i][t+1]&&matrix[i][t]==matrix[i][t+2]&&matrix[i][t]==matrix[i][t+3]&&matrix[i][t]==matrix[i][t+4])
	if (matrix[i][t]=='X'||matrix[i][t]=='O') return matrix[i][t];
    }
  }
  /*columns*/
  for (i=5;i<20;i++){
    for (t=5;t<20;t++){
      if (matrix[i][t]==matrix[i+1][t]&&matrix[i][t]==matrix[i+2][t]&&matrix[i][t]==matrix[i+3][t]&&matrix[i][t]==matrix[i+4][t])
	if (matrix[i][t]=='X'||matrix[i][t]=='O') return matrix[i][t];
    }
  }
  /*diagonals*/
  for (i=5;i<20;i++){
    for (t=5;t<20;t++){
      if(matrix[i][t]==matrix[i+1][t+1]&&matrix[i][t]==matrix[i+2][t+2]&&matrix[i][t]==matrix[i+3][t+3]&&matrix[i][t]==matrix[i+4][t+4])
	if (matrix[i][t]=='X'||matrix[i][t]=='O') return matrix[i][t];
    }
  }
  for (i=19;i>4;i--){
    for (t=5;t<20;t++){
      if(matrix[i][t]==matrix[i-1][t+1]&&matrix[i][t]==matrix[i-2][t+2]&&matrix[i][t]==matrix[i-3][t+3]&&matrix[i][t]==matrix[i-4][t+4])
	if (matrix[i][t]=='X'||matrix[i][t]=='O') return matrix[i][t];
    }
  }
  return ' ';
}
