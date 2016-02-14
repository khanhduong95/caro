#include<gtk/gtk.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>


int check_result(int m, int n, int a[m][n]){
  int i,j;
  //check rows
  for (i=1;i<16;i++){
    for (j=0;j<11;j++){
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
  for (j=1;j<16;j++){
    for (i=0;i<11;i++){
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

  for (j=0;j<11;j++){
    for (i=0;i<11;i++){
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

  for (j=0;j<11;j++){
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


int check_chance_four(int x,int y,int m,int a[m][m]){

  //check 4
  
  if (x<12){
    if (a[x+1][y]==a[x+2][y]&&a[x+1][y]==a[x+3][y]&&a[x+1][y]==a[x+4][y]&&a[x+1][y]!=a[x+5][y]){
      if (a[x+1][y]==0){
	if (a[x-1][y]==a[x+5][y]&&a[x-1][y]!=1) return 1;
	else if (a[x-1][y]!=a[x+5][y]&&a[x-1][y]!=0) return 1;
      }
    }
    
    if (y<12){
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+1]==a[x][y+4]&&a[x][y+1]!=a[x][y+5]){
	if (a[x][y+1]==0){
	  if (a[x][y-1]==a[x][y+5]&&a[x][y-1]!=1) return 1;
	  else if (a[x][y-1]!=a[x][y+5]&&a[x][y-1]!=0) return 1;
	}
      }
      if (a[x+1][y+1]==a[x+2][y+2]&&a[x+1][y+1]==a[x+3][y+3]&&a[x+1][y+1]==a[x+4][y+4]&&a[x+1][y+1]!=a[x+5][y+5]){
	if (a[x+1][y+1]==0){
	  if (a[x-1][y-1]==a[x+5][y+5]&&a[x-1][y-1]!=1) return 1;
	  else if (a[x-1][y-1]!=a[x+5][y+5]&&a[x-1][y-1]!=0) return 1;
	}
      }
      
    }
    
    if (y>4){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-1]==a[x][y-4]&&a[x][y-1]!=a[x][y-5]){
	if (a[x][y-1]==0){
	  if (a[x][y+1]==a[x][y-5]&&a[x][y+1]!=1) return 1;
	  else if (a[x][y+1]!=a[x][y-5]&&a[x][y+1]!=0) return 1;
	}
      }
      if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x+3][y-3]&&a[x+1][y-1]==a[x+4][y-4]&&a[x+1][y-1]!=a[x+5][y-5]){
	if (a[x+1][y-1]==0){
	  if (a[x-1][y+1]==a[x-5][y+5]&&a[x-1][y+1]!=1) return 1;
	  else if (a[x-1][y+1]!=a[x-5][y+5]&&a[x-1][y+1]!=0) return 1;
	}
      }

      
    }
    
    
  }
  
  if (x>4){
    if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x-3][y]&&a[x-1][y]==a[x-4][y]&&a[x-1][y]!=a[x-5][y]){
      if (a[x-1][y]==0){
	if (a[x+1][y]==a[x-5][y]&&a[x+1][y]!=1) return 1;
	else if (a[x+1][y]!=a[x-5][y]&&a[x+1][y]!=0) return 1;
      }
    }
    if (y<12){
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+1]==a[x][y+4]&&a[x][y+1]!=a[x][y+5]){
	if (a[x][y+1]==0){
	  if (a[x][y-1]==a[x][y+5]&&a[x][y-1]!=1) return 1;
	  else if (a[x][y-1]!=a[x][y+5]&&a[x][y-1]!=0) return 1;
	}
      }
      if (a[x-1][y+1]==a[x-2][y+2]&&a[x-1][y+1]==a[x-3][y+3]&&a[x-1][y+1]==a[x-4][y+4]&&a[x-1][y+1]!=a[x-5][y+5]){
	if (a[x-1][y+1]==0){
	  if (a[x+1][y-1]==a[x-5][y+5]&&a[x+1][y-1]!=1) return 1;
	  else if (a[x+1][y-1]!=a[x-5][y+5]&&a[x+1][y-1]!=0) return 1;
	}
      }
      
    }
    
    if (y>4){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-1]==a[x][y-4]&&a[x][y-1]!=a[x][y-5]){
	if (a[x][y-1]==0){
	  if (a[x][y+1]==a[x][y-5]&&a[x][y+1]!=1) return 1;
	  else if (a[x][y+1]!=a[x][y-5]&&a[x][y+1]!=0) return 1;
	}
      }
      if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x-3][y-3]&&a[x-1][y-1]==a[x-4][y-4]&&a[x-1][y-1]!=a[x-5][y-5]){
	if (a[x-1][y-1]==0){
	  if (a[x+1][y+1]==a[x-5][y-5]&&a[x+1][y+1]!=1) return 1;
	  else if (a[x+1][y+1]!=a[x-5][y-5]&&a[x+1][y+1]!=0) return 1;
	}
      }
      
      
    }
    
  }

  //check 1+3

  if (x>1&&x<13){
    if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x-1][y]==a[x+3][y]&&a[x-1][y]!=a[x+4][y]){
      if (a[x-1][y]==0){
	if (a[x-2][y]==a[x+4][y]&&a[x-2][y]!=1) return 1;
	else if (a[x-2][y]!=a[x+4][y]&&a[x-2][y]!=0) return 1;
      }
    }
    if (y>1&&y<13){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x][y+3]&&a[x][y-1]!=a[x][y+4]){
	if (a[x][y-1]==0){
	  if (a[x][y-2]==a[x][y+4]&&a[x][y-2]!=1) return 1;
	  else if (a[x][y-2]!=a[x][y+4]&&a[x][y-2]!=0) return 1;
	}
      }

      if (a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x-1][y-1]==a[x+3][y+3]&&a[x-1][y-1]!=a[x+4][y+4]){
	if (a[x-1][y-1]==0){
	  if (a[x-2][y-2]==a[x+4][y+4]&&a[x-2][y-2]!=1) return 1;
	  else if (a[x-2][y-2]!=a[x+4][y+4]&&a[x-2][y-2]!=0) return 1;
	}
      }
      
    }
    if (y>3&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x][y-3]&&a[x][y+1]!=a[x][y-4]){
	if (a[x][y+1]==0){
	  if (a[x][y+2]==a[x][y-4]&&a[x][y+2]!=1) return 1;
	  else if (a[x][y+2]!=a[x][y-4]&&a[x][y+2]!=0) return 1;
	}
      }

      if (a[x-1][y+1]==a[x+1][y-1]&&a[x-1][y+1]==a[x+2][y-2]&&a[x-1][y+1]==a[x+3][y-3]&&a[x-1][y+1]!=a[x+4][y-4]){
	if (a[x-1][y+1]==0){
	  if (a[x-2][y+2]==a[x+4][y-4]&&a[x-2][y+2]!=1) return 1;
	  else if (a[x-2][y+2]!=a[x+4][y-4]&&a[x-2][y+2]!=0) return 1;
	}
      }

      
    }
  }
  
  if (x>3&&x<15){
    if (a[x+1][y]==a[x-1][y]&&a[x+1][y]==a[x-2][y]&&a[x+1][y]==a[x-3][y]&&a[x+1][y]!=a[x-4][y]){
      if (a[x+1][y]==0){
	if (a[x+2][y]==a[x-4][y]&&a[x+2][y]!=1) return 1;
	else if (a[x+2][y]!=a[x-4][y]&&a[x+2][y]!=0) return 1;
      }
    }
    if (y>1&&y<13){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x][y+3]&&a[x][y-1]!=a[x][y+4]){
	if (a[x][y-1]==0){
	  if (a[x][y-2]==a[x][y+4]&&a[x][y-2]!=1) return 1;
	  else if (a[x][y-2]!=a[x][y+4]&&a[x][y-2]!=0) return 1;
	}
      }
      
      if (a[x+1][y-1]==a[x-1][y+1]&&a[x+1][y-1]==a[x-2][y+2]&&a[x+1][y-1]==a[x-3][y+3]&&a[x+1][y-1]!=a[x-4][y+4]){
	if (a[x+1][y-1]==0){
	  if (a[x+2][y-2]==a[x-4][y+4]&&a[x+2][y-2]!=1) return 1;
	  else if (a[x+2][y-2]!=a[x-4][y+4]&&a[x+2][y-2]!=0) return 1;
	  }
      }
      
    }
    if (y>3&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x][y-3]&&a[x][y+1]!=a[x][y-4]){
	if (a[x][y+1]==0){
	  if (a[x][y+2]==a[x][y-4]&&a[x][y+2]!=1) return 1;
	  else if (a[x][y+2]!=a[x][y-4]&&a[x][y+2]!=0) return 1;
	}
      }
      
      if (a[x+1][y+1]==a[x-1][y-1]&&a[x+1][y+1]==a[x-2][y-2]&&a[x+1][y+1]==a[x-3][y-3]&&a[x+1][y+1]!=a[x-4][y-4]){
	if (a[x+1][y+1]==0){
	  if (a[x+2][y+2]==a[x-4][y-4]&&a[x+2][y+2]!=1) return 1;
	  else if (a[x+2][y+2]!=a[x-4][y-4]&&a[x+2][y+2]!=0) return 1;
	  }
      }
      
      
    }  

  }

  if (x<2||x>12){
    if (y>1&&y<13){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x][y+3]&&a[x][y-1]!=a[x][y+4]){
	if (a[x][y-1]==0){
	  if (a[x][y-2]==a[x][y+4]&&a[x][y-2]!=1) return 1;
	  else if (a[x][y-2]!=a[x][y+4]&&a[x][y-2]!=0) return 1;
	}
      }
      
    }
    if (y>3&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x][y-3]&&a[x][y+1]!=a[x][y-4]){
	if (a[x][y+1]==0){
	  if (a[x][y+2]==a[x][y-4]&&a[x][y+2]!=1) return 1;
	  else if (a[x][y+2]!=a[x][y-4]&&a[x][y+2]!=0) return 1;
	}
      }
      
      
    }
  }

  if (x<4||x>14){
    if (y>1&&y<13){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x][y+3]&&a[x][y-1]!=a[x][y+4]){
	if (a[x][y-1]==0){
	  if (a[x][y-2]==a[x][y+4]&&a[x][y-2]!=1) return 1;
	  else if (a[x][y-2]!=a[x][y+4]&&a[x][y-2]!=0) return 1;
	}
      }
      
    }
    if (y>3&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x][y-3]&&a[x][y+1]!=a[x][y-4]){
	if (a[x][y+1]==0){
	  if (a[x][y+2]==a[x][y-4]&&a[x][y+2]!=1) return 1;
	  else if (a[x][y+2]!=a[x][y-4]&&a[x][y+2]!=0) return 1;
	}
      }
    }
    
    
  }  
  
  



  //check 2+2
  
  if (x>2&&x<14){
    if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x-1][y]!=a[x+3][y]){
      if (a[x-1][y]==0){
	if (a[x-3][y]==a[x+3][y]&&a[x-3][y]!=1) return 1;	  
	else if (a[x-3][y]!=a[x+3][y]&&a[x-3][y]!=0) return 1;	
      }
    }
    if (y>2&&y<14){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]!=a[x][y+3]){
	if (a[x][y-1]==0){
	  if (a[x][y-3]==a[x][y+3]&&a[x][y+3]!=1) return 1;	  
	  else if (a[x][y-3]!=a[x][y+3]&&a[x][y-3]!=0) return 1;	
	}
      }
      
      if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x-1][y-1]!=a[x+3][y+3]){
	if (a[x-1][y-1]==0){
	  if (a[x-3][y-3]==a[x+3][y+3]&&a[x+3][y+3]!=1) return 1;	  
	  else if (a[x-3][y-3]!=a[x+3][y+3]&&a[x-3][y-3]!=0) return 1;	
	}
      }
      
      if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x-1][y+1]&&a[x+1][y-1]==a[x-2][y+2]&&a[x+1][y-1]!=a[x-3][y+3]){
	if (a[x+1][y-1]==0){
	  if (a[x+3][y-3]==a[x-3][y+3]&&a[x-3][y+3]!=1) return 1;	  
	  else if (a[x+3][y-3]!=a[x-3][y+3]&&a[x+3][y-3]!=0) return 1;	
	}
      }
      
      
    }
  }
  
  
  if (x<3||x>13){
    if (y>2&&y<14){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]!=a[x][y+3]){
	if (a[x][y-1]==0){
	  if (a[x][y-3]==a[x][y+3]&&a[x][y+3]!=1) return 1;	  
	  else if (a[x][y-3]!=a[x][y+3]&&a[x][y-3]!=0) return 1;	
	}
      }
      
    }
  }
  
  
  return 0;

}

int check_threat_four_special(int x,int y,int m,int a[m][m]){
  //check 4

  if (x<11){
    if (a[x+1][y]==a[x+2][y]&&a[x+1][y]==a[x+3][y]&&a[x+1][y]==a[x+4][y]&&a[x+5][y]==2&&(a[x+6][y]==0||a[x+6][y]==1)&&a[x+6][y]!=a[x-1][y]&&a[x+1][y]==1) return 1;
    if (y<11){
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+1]==a[x][y+4]&&a[x][y+5]==2&&(a[x][y+6]==0||a[x][y+6]==1)&&a[x][y+6]!=a[x][y-1]&&a[x][y+1]==1) return 1;
      if (a[x+1][y+1]==a[x+2][y+2]&&a[x+1][y+1]==a[x+3][y+3]&&a[x+1][y+1]==a[x+4][y+4]&&a[x+5][y+5]==2&&(a[x+6][y+6]==0||a[x+6][y+6]==1)&&a[x+6][y+6]!=a[x+1][y-1]&&a[x+1][y+1]==1) return 1;
      
    }
    if (y>5){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-1]==a[x][y-4]&&a[x][y-5]==2&&(a[x][y-6]==0||a[x][y-6]==1)&&a[x][y-6]!=a[x][y+1]&&a[x][y-1]==1) return 1;
      if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x+3][y-3]&&a[x+1][y-1]==a[x+4][y-4]&&a[x+5][y-5]==2&&(a[x+6][y-6]==0||a[x+6][y-6]==1)&&a[x+6][y-6]!=a[x+1][y+1]&&a[x+1][y-1]==1) return 1;
      
    }
  }

  if (x>5){
    if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x-3][y]&&a[x-1][y]==a[x-4][y]&&a[x-5][y]==2&&(a[x-6][y]==0||a[x-6][y]==1)&&a[x-6][y]!=a[x+1][y]&&a[x-1][y]==1) return 1;
    if (y<11){
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+1]==a[x][y+4]&&a[x][y+5]==2&&(a[x][y+6]==0||a[x][y+6]==1)&&a[x][y+6]!=a[x][y-1]&&a[x][y+1]==1) return 1;
      if (a[x-1][y+1]==a[x-2][y+2]&&a[x-1][y+1]==a[x-3][y+3]&&a[x-1][y+1]==a[x-4][y+4]&&a[x-5][y+5]==2&&(a[x-6][y+6]==0||a[x-6][y+6]==1)&&a[x-6][y+6]!=a[x-1][y-1]&&a[x-1][y+1]==1) return 1;
      
    }
    if (y>5){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-1]==a[x][y-4]&&a[x][y-5]==2&&(a[x][y-6]==0||a[x][y-6]==1)&&a[x][y-6]!=a[x][y+1]&&a[x][y-1]==1) return 1;
      if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x-3][y-3]&&a[x-1][y-1]==a[x-4][y-4]&&a[x-5][y-5]==2&&(a[x-6][y-6]==0||a[x-6][y-6]==1)&&a[x-6][y-6]!=a[x-1][y+1]&&a[x-1][y-1]==1) return 1;
      
    }
  }
  
  return 0;
}


int check_threat_four(int x,int y,int m,int a[m][m]){

  //check 4
  
  if (x<12){
    if (a[x+1][y]==a[x+2][y]&&a[x+1][y]==a[x+3][y]&&a[x+1][y]==a[x+4][y]&&a[x+1][y]!=a[x+5][y]){
      if (a[x+1][y]==1){
	if (a[x-1][y]==a[x+5][y]&&a[x-1][y]!=0) return 1;
	else if (a[x-1][y]!=a[x+5][y]&&a[x-1][y]!=1) return 1;
      }
    }
    
    if (y<12){
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+1]==a[x][y+4]&&a[x][y+1]!=a[x][y+5]){
	if (a[x][y+1]==1){
	  if (a[x][y-1]==a[x][y+5]&&a[x][y-1]!=0) return 1;
	  else if (a[x][y-1]!=a[x][y+5]&&a[x][y-1]!=1) return 1;
	}
      }
      if (a[x+1][y+1]==a[x+2][y+2]&&a[x+1][y+1]==a[x+3][y+3]&&a[x+1][y+1]==a[x+4][y+4]&&a[x+1][y+1]!=a[x+5][y+5]){
	if (a[x+1][y+1]==1){
	  if (a[x-1][y-1]==a[x+5][y+5]&&a[x-1][y-1]!=0) return 1;
	  else if (a[x-1][y-1]!=a[x+5][y+5]&&a[x-1][y-1]!=1) return 1;
	}
      }
      
    }
    
    if (y>4){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-1]==a[x][y-4]&&a[x][y-1]!=a[x][y-5]){
	if (a[x][y-1]==1){
	  if (a[x][y+1]==a[x][y-5]&&a[x][y+1]!=0) return 1;
	  else if (a[x][y+1]!=a[x][y-5]&&a[x][y+1]!=1) return 1;
	}
      }
      if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x+3][y-3]&&a[x+1][y-1]==a[x+4][y-4]&&a[x+1][y-1]!=a[x+5][y-5]){
	if (a[x+1][y-1]==1){
	  if (a[x-1][y+1]==a[x-5][y+5]&&a[x-1][y+1]!=0) return 1;
	  else if (a[x-1][y+1]!=a[x-5][y+5]&&a[x-1][y+1]!=1) return 1;
	}
      }

      
    }
    
    
  }
  
  if (x>4){
    if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x-3][y]&&a[x-1][y]==a[x-4][y]&&a[x-1][y]!=a[x-5][y]){
      if (a[x-1][y]==1){
	if (a[x+1][y]==a[x-5][y]&&a[x+1][y]!=0) return 1;
	else if (a[x+1][y]!=a[x-5][y]&&a[x+1][y]!=1) return 1;
      }
    }
    if (y<12){
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+1]==a[x][y+4]&&a[x][y+1]!=a[x][y+5]){
	if (a[x][y+1]==1){
	  if (a[x][y-1]==a[x][y+5]&&a[x][y-1]!=0) return 1;
	  else if (a[x][y-1]!=a[x][y+5]&&a[x][y-1]!=1) return 1;
	}
      }
      if (a[x-1][y+1]==a[x-2][y+2]&&a[x-1][y+1]==a[x-3][y+3]&&a[x-1][y+1]==a[x-4][y+4]&&a[x-1][y+1]!=a[x-5][y+5]){
	if (a[x-1][y+1]==1){
	  if (a[x+1][y-1]==a[x-5][y+5]&&a[x+1][y-1]!=0) return 1;
	  else if (a[x+1][y-1]!=a[x-5][y+5]&&a[x+1][y-1]!=1) return 1;
	}
      }
      
    }
    
    if (y>4){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-1]==a[x][y-4]&&a[x][y-1]!=a[x][y-5]){
	if (a[x][y-1]==1){
	  if (a[x][y+1]==a[x][y-5]&&a[x][y+1]!=0) return 1;
	  else if (a[x][y+1]!=a[x][y-5]&&a[x][y+1]!=1) return 1;
	}
      }
      if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x-3][y-3]&&a[x-1][y-1]==a[x-4][y-4]&&a[x-1][y-1]!=a[x-5][y-5]){
	if (a[x-1][y-1]==1){
	  if (a[x+1][y+1]==a[x-5][y-5]&&a[x+1][y+1]!=0) return 1;
	  else if (a[x+1][y+1]!=a[x-5][y-5]&&a[x+1][y+1]!=1) return 1;
	}
      }
      
      
    }
    
  }

  //check 1+3

  if (x>1&&x<13){
    if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x-1][y]==a[x+3][y]&&a[x-1][y]!=a[x+4][y]){
      if (a[x-1][y]==1){
	if (a[x-2][y]==a[x+4][y]&&a[x-2][y]!=0) return 1;
	else if (a[x-2][y]!=a[x+4][y]&&a[x-2][y]!=1) return 1;
      }
    }
    if (y>1&&y<13){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x][y+3]&&a[x][y-1]!=a[x][y+4]){
	if (a[x][y-1]==1){
	  if (a[x][y-2]==a[x][y+4]&&a[x][y-2]!=0) return 1;
	  else if (a[x][y-2]!=a[x][y+4]&&a[x][y-2]!=1) return 1;
	}
      }

      if (a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x-1][y-1]==a[x+3][y+3]&&a[x-1][y-1]!=a[x+4][y+4]){
	if (a[x-1][y-1]==1){
	  if (a[x-2][y-2]==a[x+4][y+4]&&a[x-2][y-2]!=0) return 1;
	  else if (a[x-2][y-2]!=a[x+4][y+4]&&a[x-2][y-2]!=1) return 1;
	}
      }
      
    }
    if (y>3&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x][y-3]&&a[x][y+1]!=a[x][y-4]){
	if (a[x][y+1]==1){
	  if (a[x][y+2]==a[x][y-4]&&a[x][y+2]!=0) return 1;
	  else if (a[x][y+2]!=a[x][y-4]&&a[x][y+2]!=1) return 1;
	}
      }

      if (a[x-1][y+1]==a[x+1][y-1]&&a[x-1][y+1]==a[x+2][y-2]&&a[x-1][y+1]==a[x+3][y-3]&&a[x-1][y+1]!=a[x+4][y-4]){
	if (a[x-1][y+1]==1){
	  if (a[x-2][y+2]==a[x+4][y-4]&&a[x-2][y+2]!=0) return 1;
	  else if (a[x-2][y+2]!=a[x+4][y-4]&&a[x-2][y+2]!=1) return 1;
	}
      }

      
    }
  }
  
  if (x>3&&x<15){
    if (a[x+1][y]==a[x-1][y]&&a[x+1][y]==a[x-2][y]&&a[x+1][y]==a[x-3][y]&&a[x+1][y]!=a[x-4][y]){
      if (a[x+1][y]==1){
	if (a[x+2][y]==a[x-4][y]&&a[x+2][y]!=0) return 1;
	else if (a[x+2][y]!=a[x-4][y]&&a[x+2][y]!=1) return 1;
      }
    }
    if (y>1&&y<13){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x][y+3]&&a[x][y-1]!=a[x][y+4]){
	if (a[x][y-1]==1){
	  if (a[x][y-2]==a[x][y+4]&&a[x][y-2]!=0) return 1;
	  else if (a[x][y-2]!=a[x][y+4]&&a[x][y-2]!=1) return 1;
	}
      }
      
      if (a[x+1][y-1]==a[x-1][y+1]&&a[x+1][y-1]==a[x-2][y+2]&&a[x+1][y-1]==a[x-3][y+3]&&a[x+1][y-1]!=a[x-4][y+4]){
	if (a[x+1][y-1]==1){
	  if (a[x+2][y-2]==a[x-4][y+4]&&a[x+2][y-2]!=0) return 1;
	  else if (a[x+2][y-2]!=a[x-4][y+4]&&a[x+2][y-2]!=1) return 1;
	  }
      }
      
    }
    if (y>3&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x][y-3]&&a[x][y+1]!=a[x][y-4]){
	if (a[x][y+1]==1){
	  if (a[x][y+2]==a[x][y-4]&&a[x][y+2]!=0) return 1;
	  else if (a[x][y+2]!=a[x][y-4]&&a[x][y+2]!=1) return 1;
	}
      }
      
      if (a[x+1][y+1]==a[x-1][y-1]&&a[x+1][y+1]==a[x-2][y-2]&&a[x+1][y+1]==a[x-3][y-3]&&a[x+1][y+1]!=a[x-4][y-4]){
	if (a[x+1][y+1]==1){
	  if (a[x+2][y+2]==a[x-4][y-4]&&a[x+2][y+2]!=0) return 1;
	  else if (a[x+2][y+2]!=a[x-4][y-4]&&a[x+2][y+2]!=1) return 1;
	  }
      }
      
      
    }  

  }

  if (x<2||x>12){
    if (y>1&&y<13){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x][y+3]&&a[x][y-1]!=a[x][y+4]){
	if (a[x][y-1]==1){
	  if (a[x][y-2]==a[x][y+4]&&a[x][y-2]!=0) return 1;
	  else if (a[x][y-2]!=a[x][y+4]&&a[x][y-2]!=1) return 1;
	}
      }
      
      
    }
    if (y>3&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x][y-3]&&a[x][y+1]!=a[x][y-4]){
	if (a[x][y+1]==1){
	  if (a[x][y+2]==a[x][y-4]&&a[x][y+2]!=0) return 1;
	  else if (a[x][y+2]!=a[x][y-4]&&a[x][y+2]!=1) return 1;
	}
      }
      
    }
  }

  if (x<4||x>14){
    if (y>1&&y<13){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x][y+3]&&a[x][y-1]!=a[x][y+4]){
	if (a[x][y-1]==1){
	  if (a[x][y-2]==a[x][y+4]&&a[x][y-2]!=0) return 1;
	  else if (a[x][y-2]!=a[x][y+4]&&a[x][y-2]!=1) return 1;
	}
      }
      
      
    }
    if (y>3&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x][y-3]&&a[x][y+1]!=a[x][y-4]){
	if (a[x][y+1]==1){
	  if (a[x][y+2]==a[x][y-4]&&a[x][y+2]!=0) return 1;
	  else if (a[x][y+2]!=a[x][y-4]&&a[x][y+2]!=1) return 1;
	}
      }
      
      
    }  

  }

  
  //check 2+2

  if (x>2&&x<14){
    if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x-1][y]!=a[x+3][y]){
      if (a[x-1][y]==1){
	if (a[x-3][y]==a[x+3][y]&&a[x-3][y]!=0) return 1;	  
	else if (a[x-3][y]!=a[x+3][y]&&a[x-3][y]!=1) return 1;	
      }
    }
    if (y>2&&y<14){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]!=a[x][y+3]){
	if (a[x][y-1]==1){
	  if (a[x][y-3]==a[x][y+3]&&a[x][y+3]!=0) return 1;	  
	  else if (a[x][y-3]!=a[x][y+3]&&a[x][y-3]!=1) return 1;	
	}
      }

      if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x-1][y-1]!=a[x+3][y+3]){
	if (a[x-1][y-1]==1){
	  if (a[x-3][y-3]==a[x+3][y+3]&&a[x+3][y+3]!=0) return 1;	  
	  else if (a[x-3][y-3]!=a[x+3][y+3]&&a[x-3][y-3]!=1) return 1;	
	}
      }

      if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x-1][y+1]&&a[x+1][y-1]==a[x-2][y+2]&&a[x+1][y-1]!=a[x-3][y+3]){
	if (a[x+1][y-1]==1){
	  if (a[x+3][y-3]==a[x-3][y+3]&&a[x-3][y+3]!=0) return 1;	  
	  else if (a[x+3][y-3]!=a[x-3][y+3]&&a[x+3][y-3]!=1) return 1;	
	}
      }
      
      
    }
  }

  if (x<3||x>13){
    if (y>2&&y<14){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]!=a[x][y+3]){
	if (a[x][y-1]==1){
	  if (a[x][y-3]==a[x][y+3]&&a[x][y+3]!=0) return 1;	  
	  else if (a[x][y-3]!=a[x][y+3]&&a[x][y-3]!=1) return 1;	
	}
      }
      
    }
  }
  return 0;

}


int check_chance_three(int x,int y,int m,int a[m][m]){

  //check 3
  if (x<13){
    if (a[x+1][y]==a[x+2][y]&&a[x+1][y]==a[x+3][y]&&a[x+4][y]==2&&a[x-1][y]==2&&a[x+1][y]==0) return 1;
    if (y<13){
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+4]==2&&a[x][y-1]==2&&a[x][y+1]==0) return 1;
      else if (a[x+1][y+1]==a[x+2][y+2]&&a[x+1][y+1]==a[x+3][y+3]&&a[x+4][y+4]==2&&a[x-1][y-1]==2&&a[x+1][y+1]==0) return 1;
    }
    if (y>4){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-4]==2&&a[x][y+1]==2&&a[x][y-1]==0) return 1;
      else if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x+3][y-3]&&a[x+4][y-4]==2&&a[x-1][y+1]==2&&a[x+1][y-1]==0) return 1;
    }
    
  }

  if (x>4){
    if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x-3][y]&&a[x-4][y]==2&&a[x+1][y]==2&&a[x-1][y]==0) return 1;
    if (y<13){
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+4]==2&&a[x][y-1]==2&&a[x][y+1]==0) return 1;
      else if (a[x-1][y+1]==a[x-2][y+2]&&a[x-1][y+1]==a[x-3][y+3]&&a[x-4][y+4]==2&&a[x+1][y-1]==2&&a[x-1][y+1]==0) return 1;
    }
    if (y>4){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-4]==2&&a[x][y+1]==2&&a[x][y-1]==0) return 1;
      else if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x-3][y-3]&&a[x-4][y-4]==2&&a[x+1][y+1]==2&&a[x+1][y+1]==0) return 1;
    }
    
  }
  
  //check 1+2

  if (x>1&&x<14){
    if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x+3][y]==2&&a[x-2][y]==2&&a[x-1][y]==0) return 1;
    if (y>1&&y<14){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y+3]==2&&a[x][y-2]==2&&a[x][y-1]==0) return 1;
      else if (a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x+3][y+3]==2&&a[x-2][y-2]==2&&a[x-1][y-1]==0) return 1;
    }
    if (y>2&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y-3]==2&&a[x][y+2]==2&&a[x][y+1]==0) return 1;
      else if (a[x-1][y+1]==a[x+1][y-1]&&a[x-1][y+1]==a[x+2][y-2]&&a[x+3][y-3]==2&&a[x-2][y+2]==2&&a[x-1][y+1]==0) return 1;
    }

  }
  if (x>2&&x<15){
    if (a[x+1][y]==a[x-1][y]&&a[x+1][y]==a[x-2][y]&&a[x-3][y]==2&&a[x+2][y]==2&&a[x+1][y]==0) return 1;
    if (y>1&&y<14){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y+3]==2&&a[x][y-2]==2&&a[x][y-1]==0) return 1;
      else if (a[x+1][y-1]==a[x-1][y+1]&&a[x+1][y-1]==a[x-2][y+2]&&a[x-3][y+3]==2&&a[x+2][y-2]==2&&a[x+1][y-1]==0) return 1;
    }
    if (y>2&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y-3]==2&&a[x][y+2]==2&&a[x][y+1]==0) return 1;
      else if (a[x+1][y+1]==a[x-1][y-1]&&a[x+1][y+1]==a[x-2][y-2]&&a[x-3][y-3]==2&&a[x+2][y+2]==2&&a[x+1][y+1]==0) return 1;
    }

    
  }

  
  if (x<2||x>13){
    if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x+3][y]==2&&a[x-2][y]==2&&a[x-1][y]==0) return 1;
    if (y>1&&y<14){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y+3]==2&&a[x][y-2]==2&&a[x][y-1]==0) return 1;
      else if (a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x+3][y+3]==2&&a[x-2][y-2]==2&&a[x-1][y-1]==0) return 1;
    }
    if (y>2&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y-3]==2&&a[x][y+2]==2&&a[x][y+1]==0) return 1;
      else if (a[x-1][y+1]==a[x+1][y-1]&&a[x-1][y+1]==a[x+2][y-2]&&a[x+3][y-3]==2&&a[x-2][y+2]==2&&a[x-1][y+1]==0) return 1;
    }
    
  }
  if (x<3||x>14){
    if (y>1&&y<14){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y+3]==2&&a[x][y-2]==2&&a[x][y-1]==0) return 1;
    }
    if (y>2&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y-3]==2&&a[x][y+2]==2&&a[x][y+1]==0) return 1;
    }
  }
    
  return 0;
}


int check_threat_three(int x,int y,int m,int a[m][m]){

  //check 3
  if (x<13){
    if (a[x+1][y]==a[x+2][y]&&a[x+1][y]==a[x+3][y]&&a[x+4][y]==2&&a[x-1][y]==2&&a[x+1][y]==1) return 1;
    if (y<13){
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+4]==2&&a[x][y-1]==2&&a[x][y+1]==1) return 1;
      else if (a[x+1][y+1]==a[x+2][y+2]&&a[x+1][y+1]==a[x+3][y+3]&&a[x+4][y+4]==2&&a[x-1][y-1]==2&&a[x+1][y+1]==1) return 1;
    }
    if (y>4){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-4]==2&&a[x][y+1]==2&&a[x][y-1]==1) return 1;
      else if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x+3][y-3]&&a[x+4][y-4]==2&&a[x-1][y+1]==2&&a[x+1][y-1]==1) return 1;
    }
    
  }

  if (x>4){
    if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x-3][y]&&a[x-4][y]==2&&a[x+1][y]==2&&a[x-1][y]==1) return 1;
    if (y<13){
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+4]==2&&a[x][y-1]==2&&a[x][y+1]==1) return 1;
      else if (a[x-1][y+1]==a[x-2][y+2]&&a[x-1][y+1]==a[x-3][y+3]&&a[x-4][y+4]==2&&a[x+1][y-1]==2&&a[x-1][y+1]==1) return 1;
    }
    if (y>4){
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-4]==2&&a[x][y+1]==2&&a[x][y-1]==1) return 1;
      else if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x-3][y-3]&&a[x-4][y-4]==2&&a[x+1][y+1]==2&&a[x+1][y+1]==1) return 1;
    }
    
  }
  
  //check 1+2

  if (x>1&&x<14){
    if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x+3][y]==2&&a[x-2][y]==2&&a[x-1][y]==1) return 1;
    if (y>1&&y<14){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y+3]==2&&a[x][y-2]==2&&a[x][y-1]==1) return 1;
      else if (a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x+3][y+3]==2&&a[x-2][y-2]==2&&a[x-1][y-1]==1) return 1;
    }
    if (y>2&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y-3]==2&&a[x][y+2]==2&&a[x][y+1]==1) return 1;
      else if (a[x-1][y+1]==a[x+1][y-1]&&a[x-1][y+1]==a[x+2][y-2]&&a[x+3][y-3]==2&&a[x-2][y+2]==2&&a[x-1][y+1]==1) return 1;
    }

  }
  if (x>2&&x<15){
    if (a[x+1][y]==a[x-1][y]&&a[x+1][y]==a[x-2][y]&&a[x-3][y]==2&&a[x+2][y]==2&&a[x+1][y]==1) return 1;
    if (y>1&&y<14){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y+3]==2&&a[x][y-2]==2&&a[x][y-1]==1) return 1;
      else if (a[x+1][y-1]==a[x-1][y+1]&&a[x+1][y-1]==a[x-2][y+2]&&a[x-3][y+3]==2&&a[x+2][y-2]==2&&a[x+1][y-1]==1) return 1;
    }
    if (y>2&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y-3]==2&&a[x][y+2]==2&&a[x][y+1]==1) return 1;
      else if (a[x+1][y+1]==a[x-1][y-1]&&a[x+1][y+1]==a[x-2][y-2]&&a[x-3][y-3]==2&&a[x+2][y+2]==2&&a[x+1][y+1]==1) return 1;
    }

    
  }

  
  if (x<2||x>13){
    if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x+3][y]==2&&a[x-2][y]==2&&a[x-1][y]==1) return 1;
    if (y>1&&y<14){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y+3]==2&&a[x][y-2]==2&&a[x][y-1]==1) return 1;
      else if (a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x+3][y+3]==2&&a[x-2][y-2]==2&&a[x-1][y-1]==1) return 1;
    }
    if (y>2&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y-3]==2&&a[x][y+2]==2&&a[x][y+1]==1) return 1;
      else if (a[x-1][y+1]==a[x+1][y-1]&&a[x-1][y+1]==a[x+2][y-2]&&a[x+3][y-3]==2&&a[x-2][y+2]==2&&a[x-1][y+1]==1) return 1;
    }
    
  }
  if (x<3||x>14){
    if (y>1&&y<14){
      if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y+3]==2&&a[x][y-2]==2&&a[x][y-1]==1) return 1;
    }
    if (y>2&&y<15){
      if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y-3]==2&&a[x][y+2]==2&&a[x][y+1]==1) return 1;
    }
  }
  
  
  return 0;
}



int check_chance_double_two(int x,int y,int m,int a[m][m]){

  //check surround

  if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==2&&a[x+2][y]==2&&a[x][y-2]==2&&a[x][y+2]==2&&a[x-1][y]==0){
    if ((a[x-3][y]==2||a[x+3][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
  }
  if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==0&&a[x+2][y]==2&&a[x][y-2]==2&&a[x][y+2]==2&&a[x-1][y]==0){
    if ((a[x-3][y]==2||a[x+3][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
  }
  if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==2&&a[x+2][y]==0&&a[x][y-2]==2&&a[x][y+2]==2&&a[x-1][y]==0){
    if ((a[x-3][y]==2||a[x+3][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
  }
  if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==2&&a[x+2][y]==2&&a[x][y-2]==0&&a[x][y+2]==2&&a[x-1][y]==0){
    if ((a[x-3][y]==2||a[x+3][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
  }
  if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==2&&a[x+2][y]==2&&a[x][y-2]==2&&a[x][y+2]==0&&a[x-1][y]==0){
    if ((a[x-3][y]==2||a[x+3][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
  }

  if (a[x-1][y-1]==a[x+1][y-1]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y+1]==a[x+1][y+1]&&a[x-2][y-2]==2&&a[x+2][y-2]==2&&a[x-2][y+2]==2&&a[x+2][y+2]==2&&a[x-1][y-1]==0){
    if ((a[x-3][y-3]==2||a[x+3][y+3]==2)&&(a[x+3][y-3]==2||a[x+3][y+3]==2)) return 1;
  }
  if (a[x-1][y-1]==a[x+1][y-1]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y+1]==a[x+1][y+1]&&a[x-2][y-2]==0&&a[x+2][y-2]==2&&a[x-2][y+2]==2&&a[x+2][y+2]==2&&a[x-1][y-1]==0){
    if ((a[x-3][y-3]==2||a[x+3][y+3]==2)&&(a[x+3][y-3]==2||a[x+3][y+3]==2)) return 1;
  }
  if (a[x-1][y-1]==a[x+1][y-1]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y+1]==a[x+1][y+1]&&a[x-2][y-2]==2&&a[x+2][y-2]==0&&a[x-2][y+2]==2&&a[x+2][y+2]==2&&a[x-1][y-1]==0){
    if ((a[x-3][y-3]==2||a[x+3][y+3]==2)&&(a[x+3][y-3]==2||a[x+3][y+3]==2)) return 1;
  }
  if (a[x-1][y-1]==a[x+1][y-1]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y+1]==a[x+1][y+1]&&a[x-2][y-2]==2&&a[x+2][y-2]==2&&a[x-2][y+2]==0&&a[x+2][y+2]==2&&a[x-1][y-1]==0){
    if ((a[x-3][y-3]==2||a[x+3][y+3]==2)&&(a[x+3][y-3]==2||a[x+3][y+3]==2)) return 1;
  }
  if (a[x-1][y-1]==a[x+1][y-1]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y+1]==a[x+1][y+1]&&a[x-2][y-2]==2&&a[x+2][y-2]==2&&a[x-2][y+2]==2&&a[x+2][y+2]==0&&a[x-1][y-1]==0){
    if ((a[x-3][y-3]==2||a[x+3][y+3]==2)&&(a[x+3][y-3]==2||a[x+3][y+3]==2)) return 1;
  }

  
  if (x<13){
    if (a[x-1][y]==a[x+2][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==2&&a[x+1][y]==2&&a[x+3][y]==2&&a[x][y-2]==2&&a[x][y+2]==2&&a[x-1][y]==0){
      if ((a[x-3][y]==2||a[x+4][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
    }
    
    if (y<13){
      if (a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x-1][y]&&a[x-1][y]==a[x+1][y]&&a[x][y-2]==2&&a[x][y+1]==2&&a[x][y+3]==2&&a[x-2][y]==2&&a[x+2][y]==2&&a[x][y-1]==0){
	if ((a[x][y-3]==2||a[x][y+4]==2)&&(a[x-3][y]==2||a[x+3][y]==2)) return 1;
      }
      
      if (a[x-1][y-1]==a[x+2][y+2]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y-1]==a[x+1][y-1]&&a[x-2][y-2]==2&&a[x+1][y+1]==2&&a[x+3][y+3]==2&&a[x-2][y+2]==2&&a[x+2][y-2]==2&&a[x-1][y-1]==0){
	if ((a[x-3][y-3]==2||a[x+4][y+4]==2)&&(a[x-3][y+3]==2||a[x+3][y-3]==2)) return 1;
      }

      
    }
    
    if (y>3){
      if (a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x-1][y]&&a[x-1][y]==a[x+1][y]&&a[x][y+2]==2&&a[x][y-1]==2&&a[x][y-3]==2&&a[x-2][y]==2&&a[x+2][y]==2&&a[x][y+1]==0){
	if ((a[x][y+3]==2||a[x][y-4]==2)&&(a[x-3][y]==2||a[x+3][y]==2)) return 1;
      }
      
      if (a[x-1][y+1]==a[x+2][y-2]&&a[x-1][y+1]==a[x-1][y-1]&&a[x-1][y-1]==a[x+1][y+1]&&a[x-2][y+2]==2&&a[x+1][y-1]==2&&a[x+3][y-3]==2&&a[x-2][y-2]==2&&a[x+2][y+2]==2&&a[x-1][y+1]==0){
	if ((a[x-3][y+3]==2||a[x+4][y-4]==2)&&(a[x-3][y-3]==2||a[x+3][y+3]==2)) return 1;
      }
      
      
    }
    
  }

  if (x>3){
    if (a[x+1][y]==a[x-2][y]&&a[x+1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x+2][y]==2&&a[x-1][y]==2&&a[x-3][y]==2&&a[x][y-2]==2&&a[x][y+2]==2&&a[x+1][y]==0){
      if ((a[x+3][y]==2||a[x-4][y]==2)&&(a[x][y+3]==2||a[x][y-3]==2)) return 1;
    }
    
    if (y<13){
      if (a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x+1][y]&&a[x+1][y]==a[x-1][y]&&a[x][y-2]==2&&a[x][y+1]==2&&a[x][y+3]==2&&a[x+2][y]==2&&a[x-2][y]==2&&a[x][y-1]==0){
	if ((a[x][y-3]==2||a[x][y+4]==2)&&(a[x-3][y]==2||a[x+3][y]==2)) return 1;
      }
      
      if (a[x+1][y-1]==a[x-2][y+2]&&a[x+1][y-1]==a[x+1][y+1]&&a[x+1][y-1]==a[x-1][y-1]&&a[x+2][y-2]==2&&a[x-1][y+1]==2&&a[x-3][y+3]==2&&a[x-2][y-2]==2&&a[x+2][y+2]==2&&a[x+1][y-1]==0){
	if ((a[x+3][y-3]==2||a[x-4][y+4]==2)&&(a[x+3][y+3]==2||a[x-3][y-3]==2)) return 1;
      }

      
    }
    
    if (y>3){
      if (a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x+1][y]&&a[x+1][y]==a[x-1][y]&&a[x][y+2]==2&&a[x][y-1]==2&&a[x][y-3]==2&&a[x+2][y]==2&&a[x-2][y]==2&&a[x][y+1]==0){
	if ((a[x][y+3]==2||a[x][y-4]==2)&&(a[x-3][y]==2||a[x+3][y]==2)) return 1;
      }
      
      if (a[x+1][y+1]==a[x-2][y-2]&&a[x+1][y+1]==a[x+1][y-1]&&a[x+1][y+1]==a[x-1][y+1]&&a[x+2][y+2]==2&&a[x-1][y-1]==2&&a[x-3][y-3]==2&&a[x-2][y+2]==2&&a[x+2][y-2]==2&&a[x+1][y+1]==0){
	if ((a[x+3][y+3]==2||a[x-4][y-4]==2)&&(a[x+3][y-3]==2||a[x-3][y+3]==2)) return 1;
      }
      
      
    }
    
  }

  //check 2 lines cross

  return 0;
}


int check_threat_double_two(int x,int y,int m,int a[m][m]){

  //check surround

  if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==2&&a[x+2][y]==2&&a[x][y-2]==2&&a[x][y+2]==2&&a[x-1][y]==1){
    if ((a[x-3][y]==2||a[x+3][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
  }
  if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==1&&a[x+2][y]==2&&a[x][y-2]==2&&a[x][y+2]==2&&a[x-1][y]==1){
    if ((a[x-3][y]==2||a[x+3][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
  }
  if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==2&&a[x+2][y]==1&&a[x][y-2]==2&&a[x][y+2]==2&&a[x-1][y]==1){
    if ((a[x-3][y]==2||a[x+3][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
  }
  if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==2&&a[x+2][y]==2&&a[x][y-2]==1&&a[x][y+2]==2&&a[x-1][y]==1){
    if ((a[x-3][y]==2||a[x+3][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
  }
  if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==2&&a[x+2][y]==2&&a[x][y-2]==2&&a[x][y+2]==1&&a[x-1][y]==1){
    if ((a[x-3][y]==2||a[x+3][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
  }

  if (a[x-1][y-1]==a[x+1][y-1]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y+1]==a[x+1][y+1]&&a[x-2][y-2]==2&&a[x+2][y-2]==2&&a[x-2][y+2]==2&&a[x+2][y+2]==2&&a[x-1][y-1]==1){
    if ((a[x-3][y-3]==2||a[x+3][y+3]==2)&&(a[x+3][y-3]==2||a[x+3][y+3]==2)) return 1;
  }
  if (a[x-1][y-1]==a[x+1][y-1]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y+1]==a[x+1][y+1]&&a[x-2][y-2]==1&&a[x+2][y-2]==2&&a[x-2][y+2]==2&&a[x+2][y+2]==2&&a[x-1][y-1]==1){
    if ((a[x-3][y-3]==2||a[x+3][y+3]==2)&&(a[x+3][y-3]==2||a[x+3][y+3]==2)) return 1;
  }
  if (a[x-1][y-1]==a[x+1][y-1]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y+1]==a[x+1][y+1]&&a[x-2][y-2]==2&&a[x+2][y-2]==1&&a[x-2][y+2]==2&&a[x+2][y+2]==2&&a[x-1][y-1]==1){
    if ((a[x-3][y-3]==2||a[x+3][y+3]==2)&&(a[x+3][y-3]==2||a[x+3][y+3]==2)) return 1;
  }
  if (a[x-1][y-1]==a[x+1][y-1]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y+1]==a[x+1][y+1]&&a[x-2][y-2]==2&&a[x+2][y-2]==2&&a[x-2][y+2]==1&&a[x+2][y+2]==2&&a[x-1][y-1]==1){
    if ((a[x-3][y-3]==2||a[x+3][y+3]==2)&&(a[x+3][y-3]==2||a[x+3][y+3]==2)) return 1;
  }
  if (a[x-1][y-1]==a[x+1][y-1]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y+1]==a[x+1][y+1]&&a[x-2][y-2]==2&&a[x+2][y-2]==2&&a[x-2][y+2]==2&&a[x+2][y+2]==1&&a[x-1][y-1]==1){
    if ((a[x-3][y-3]==2||a[x+3][y+3]==2)&&(a[x+3][y-3]==2||a[x+3][y+3]==2)) return 1;
  }

  
  if (x<13){
    if (a[x-1][y]==a[x+2][y]&&a[x-1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x-2][y]==2&&a[x+1][y]==2&&a[x+3][y]==2&&a[x][y-2]==2&&a[x][y+2]==2&&a[x-1][y]==1){
      if ((a[x-3][y]==2||a[x+4][y]==2)&&(a[x][y-3]==2||a[x][y+3]==2)) return 1;
    }
    
    if (y<13){
      if (a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x-1][y]&&a[x-1][y]==a[x+1][y]&&a[x][y-2]==2&&a[x][y+1]==2&&a[x][y+3]==2&&a[x-2][y]==2&&a[x+2][y]==2&&a[x][y-1]==1){
	if ((a[x][y-3]==2||a[x][y+4]==2)&&(a[x-3][y]==2||a[x+3][y]==2)) return 1;
      }
      
      if (a[x-1][y-1]==a[x+2][y+2]&&a[x-1][y-1]==a[x-1][y+1]&&a[x-1][y-1]==a[x+1][y-1]&&a[x-2][y-2]==2&&a[x+1][y+1]==2&&a[x+3][y+3]==2&&a[x-2][y+2]==2&&a[x+2][y-2]==2&&a[x-1][y-1]==1){
	if ((a[x-3][y-3]==2||a[x+4][y+4]==2)&&(a[x-3][y+3]==2||a[x+3][y-3]==2)) return 1;
      }

      
    }
    
    if (y>3){
      if (a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x-1][y]&&a[x-1][y]==a[x+1][y]&&a[x][y+2]==2&&a[x][y-1]==2&&a[x][y-3]==2&&a[x-2][y]==2&&a[x+2][y]==2&&a[x][y+1]==1){
	if ((a[x][y+3]==2||a[x][y-4]==2)&&(a[x-3][y]==2||a[x+3][y]==2)) return 1;
      }
      
      if (a[x-1][y+1]==a[x+2][y-2]&&a[x-1][y+1]==a[x-1][y-1]&&a[x-1][y-1]==a[x+1][y+1]&&a[x-2][y+2]==2&&a[x+1][y-1]==2&&a[x+3][y-3]==2&&a[x-2][y-2]==2&&a[x+2][y+2]==2&&a[x-1][y+1]==1){
	if ((a[x-3][y+3]==2||a[x+4][y-4]==2)&&(a[x-3][y-3]==2||a[x+3][y+3]==2)) return 1;
      }
      
      
    }
    
  }

  if (x>3){
    if (a[x+1][y]==a[x-2][y]&&a[x+1][y]==a[x][y-1]&&a[x][y-1]==a[x][y+1]&&a[x+2][y]==2&&a[x-1][y]==2&&a[x-3][y]==2&&a[x][y-2]==2&&a[x][y+2]==2&&a[x+1][y]==1){
      if ((a[x+3][y]==2||a[x-4][y]==2)&&(a[x][y+3]==2||a[x][y-3]==2)) return 1;
    }
    
    if (y<13){
      if (a[x][y-1]==a[x][y+2]&&a[x][y-1]==a[x+1][y]&&a[x+1][y]==a[x-1][y]&&a[x][y-2]==2&&a[x][y+1]==2&&a[x][y+3]==2&&a[x+2][y]==2&&a[x-2][y]==2&&a[x][y-1]==1){
	if ((a[x][y-3]==2||a[x][y+4]==2)&&(a[x-3][y]==2||a[x+3][y]==2)) return 1;
      }
      
      if (a[x+1][y-1]==a[x-2][y+2]&&a[x+1][y-1]==a[x+1][y+1]&&a[x+1][y-1]==a[x-1][y-1]&&a[x+2][y-2]==2&&a[x-1][y+1]==2&&a[x-3][y+3]==2&&a[x-2][y-2]==2&&a[x+2][y+2]==2&&a[x+1][y-1]==1){
	if ((a[x+3][y-3]==2||a[x-4][y+4]==2)&&(a[x+3][y+3]==2||a[x-3][y-3]==2)) return 1;
      }

      
    }
    
    if (y>3){
      if (a[x][y+1]==a[x][y-2]&&a[x][y+1]==a[x+1][y]&&a[x+1][y]==a[x-1][y]&&a[x][y+2]==2&&a[x][y-1]==2&&a[x][y-3]==2&&a[x+2][y]==2&&a[x-2][y]==2&&a[x][y+1]==1){
	if ((a[x][y+3]==2||a[x][y-4]==2)&&(a[x-3][y]==2||a[x+3][y]==2)) return 1;
      }
      
      if (a[x+1][y+1]==a[x-2][y-2]&&a[x+1][y+1]==a[x+1][y-1]&&a[x+1][y+1]==a[x-1][y+1]&&a[x+2][y+2]==2&&a[x-1][y-1]==2&&a[x-3][y-3]==2&&a[x-2][y+2]==2&&a[x+2][y-2]==2&&a[x+1][y+1]==1){
	if ((a[x+3][y+3]==2||a[x-4][y-4]==2)&&(a[x+3][y-3]==2||a[x-3][y+3]==2)) return 1;
      }
      
      
    }
    
  }

  //check 2 lines cross

  return 0;
}
