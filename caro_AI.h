#include "caro_check.h"

int user_count;
int choose_x=7;
int choose_y=7;

void caro_brain(int m,int a[m][m]){
  int i,j;
  for (i=1;i<m-1;i++){
    for (j=1;j<m-1;j++){
      if (a[i][j]==1) ++user_count;
      
    }
  }
  if (user_count==0) return;
  else if (user_count==1){
    int random_number_x=random()%5;
    int random_number_y=random()%5;

    for (i=1;i<16;i++){
      for (j=1;j<16;j++){
	if (a[i][j]==1){
	  choose_x=i-3+random_number_x;
	  choose_y=j-3+random_number_y;
	  return;
	}
      }
    }
    //    return;
  }
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
	  if (check_threat_four_special(i,j,17,a)==1){
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
