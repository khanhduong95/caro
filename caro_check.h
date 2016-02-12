#include<gtk/gtk.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>


int check_result(int m, int n, int a[m][n]){
  int i,j;
  //check rows
  for (i=0;i<12;i++){
    for (j=0;j<12;j++){
      if (a[i][j+1]==a[i][j+2]&&a[i][j+1]==a[i][j+3]&&a[i][j+1]==a[i][j+4]&&a[i][j+1]==a[i][j+5]&&a[i][j+6]!=a[i][j+1]){
	if (a[i][j]!=a[i][j+1]){
	  if (a[i][j]==-1){
	    if (a[i][j+1]==1) return 1;
	    if (a[i][j+1]==0) return 2;
	  }
	  else {
	    if (a[i][j+6]!=a[i][j]){
	      if (a[i][j+1]==1)	return 1;
	      if (a[i][j+1]==0)	return 2;
	    
	    }
	  }
	}
      }
    }
  }
  
  
  //check columns
  for (j=0;j<12;j++){
    for (i=0;i<12;i++){
      if (a[i+1][j]==a[i+2][j]&&a[i+1][j]==a[i+3][j]&&a[i+1][j]==a[i+4][j]&&a[i+1][j]==a[i+5][j]&&a[i+6][j]!=a[i+1][j]){
	if (a[i][j]!=a[i+1][j]){
	  if (a[i][j]==-1){
	    if (a[i+1][j]==1) return 1;
	    
	    if (a[i+1][j]==0) return 2;
	    
	  }
	  else {
	    if (a[i+6][j]!=a[i][j]){
	      if (a[i+1][j]==1) return 1;
	      
	      if (a[i+1][j]==0) return 2;
	      
	    }
	  }
	}
      }
    }
  }
  
  //check diagonals 1

  for (j=0;j<12;j++){
    for (i=0;i<12;i++){
      if (a[i+1][j+1]==a[i+2][j+2]&&a[i+1][j+1]==a[i+3][j+3]&&a[i+1][j+1]==a[i+4][j+4]&&a[i+1][j+1]==a[i+5][j+5]&&a[i+1][j+1]!=a[i+6][j+6]){
	if (a[i][j]!=a[i+1][j+1]){
	  if (a[i][j]==-1){
	    if (a[i+1][j+1]==1) return 1;
	    
	    if (a[i+1][j+1]==0) return 2;
	    
	  }
	  else {
	    if (a[i+6][j+6]!=a[i][j]){
	      if (a[i+1][j+1]==1) return 1;
	      
	      if (a[i+1][j+1]==0) return 2;
	      
	    }
	  }
	}
      }
    }
  }

  //check diagonals 2

  for (j=0;j<12;j++){
    for (i=16;i>5;i--){
      if (a[i-1][j+1]==a[i-2][j+2]&&a[i-1][j+1]==a[i-3][j+3]&&a[i-1][j+1]==a[i-4][j+4]&&a[i-1][j+1]==a[i-5][j+5]&&a[i-6][j+6]!=a[i-1][j+1]){
	if (a[i][j]!=a[i-1][j+1]){
	  if (a[i][j]==-1){
	    if (a[i-1][j+1]==1) return 1;
	    
	    if (a[i-1][j+1]==0) return 2;
	    
	  }
	  else {
	    if (a[i-6][j+6]!=a[i][j]){
	      if (a[i-1][j+1]==1) return 1;
	      
	      if (a[i-1][j+1]==0) return 2;
	      
	    }
	  }
	}
      }
    }
  }
  
  return 0;
}

