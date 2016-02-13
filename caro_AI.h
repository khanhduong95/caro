#include "caro_check.h"

int user_count,computer_count;
int choose_x=7;
int choose_y=7;
int user_x=7;
int user_y=7;
int computer_x=7;
int computer_y=7;

void caro_brain(int m,int a[m][m]){
  int i,j;
  for (i=1;i<m-1;i++){
    for (j=1;j<m-1;j++){
      if (a[i][j]==1) ++user_count;
      //else if (a[i][j]==0) ++computer_count;
    }
  }
  if (user_count==0) return;
  else {
    for (i=1;i<m-1;i++){
      for (j=1;j<m-1;j++){
	if (a[i][j]==2){
	  if (check_chance_four(i,j,17,a)==1){
	    choose_x=i-1;
	    choose_y=j-1;
	    return;
	  }
	}
      }
    }
    
    for (i=1;i<m-1;i++){
      for (j=1;j<m-1;j++){
	if (a[i][j]==2){
	  if (check_threat_four(i,j,17,a)==1){
	    choose_x=i-1;
	    choose_y=j-1;
	    return;
	  }
	}
      }
    }

    for (i=1;i<m-1;i++){
      for (j=1;j<m-1;j++){
	if (a[i][j]==2){
	  if (check_chance_three(i,j,17,a)==1){
	    choose_x=i-1;
	    choose_y=j-1;
	    return;
	  }
	}
      }
    }
    
    for (i=1;i<m-1;i++){
      for (j=1;j<m-1;j++){
	if (a[i][j]==2){
	  if (check_threat_three(i,j,17,a)==1){
	    choose_x=i-1;
	    choose_y=j-1;
	    return;
	  }
	}
      }
    }


    choose_x=random()%15;
    choose_y=random()%15;
    
  }
}
