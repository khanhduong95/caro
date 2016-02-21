/************************************************************************

 * caro_check.h

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


#include<gtk/gtk.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>


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

int check_threat_far_four(int x,int y,int m,int a[m][m]){

  //check vertical
  if (x<10&&a[x+5][y]==1&&a[x+6][y]==0&&((a[x+1][y]==1&&a[x+2][y]==1&&a[x+3][y]==1&&a[x+4][y]==2)||(a[x+1][y]==1&&a[x+2][y]==1&&a[x+4][y]==1&&a[x+3][y]==2)||(a[x+1][y]==1&&a[x+3][y]==1&&a[x+4][y]==1&&a[x+2][y]==2)||(a[x+2][y]==1&&a[x+3][y]==1&&a[x+4][y]==1&&a[x+1][y]==2))) return 1;
  if (x>6&&a[x-5][y]==1&&a[x-6][y]==0&&((a[x-1][y]==1&&a[x-2][y]==1&&a[x-3][y]==1&&a[x-4][y]==2)||(a[x-1][y]==1&&a[x-2][y]==1&&a[x-4][y]==1&&a[x-3][y]==2)||(a[x-1][y]==1&&a[x-3][y]==1&&a[x-4][y]==1&&a[x-2][y]==2)||(a[x-2][y]==1&&a[x-3][y]==1&&a[x-4][y]==1&&a[x-1][y]==2))) return 1;

  //check horizontal
  
  if (y<10&&a[x][y+5]==1&&a[x][y+6]==0&&((a[x][y+1]==1&&a[x][y+2]==1&&a[x][y+3]==1&&a[x][y+4]==2)||(a[x][y+1]==1&&a[x][y+2]==1&&a[x][y+4]==1&&a[x][y+3]==2)||(a[x][y+1]==1&&a[x][y+3]==1&&a[x][y+4]==1&&a[x][y+2]==2)||(a[x][y+2]==1&&a[x][y+3]==1&&a[x][y+4]==1&&a[x][y+1]==2))) return 1;
  if (y>6&&a[x][y-5]==1&&a[x][y-6]==0&&((a[x][y-1]==1&&a[x][y-2]==1&&a[x][y-3]==1&&a[x][y-4]==2)||(a[x][y-1]==1&&a[x][y-2]==1&&a[x][y-4]==1&&a[x][y-3]==2)||(a[x][y-1]==1&&a[x][y-3]==1&&a[x][y-4]==1&&a[x][y-2]==2)||(a[x][y-2]==1&&a[x][y-3]==1&&a[x][y-4]==1&&a[x][y-1]==2))) return 1;

  //check diagonal 1
  if (x<10&&y<10&&a[x+5][y+5]==1&&a[x+6][y+6]==0&&((a[x+1][y+1]==1&&a[x+2][y+2]==1&&a[x+3][y+3]==1&&a[x+4][y+4]==2)||(a[x+1][y+1]==1&&a[x+2][y+2]==1&&a[x+4][y+4]==1&&a[x+3][y+3]==2)||(a[x+1][y+1]==1&&a[x+3][y+3]==1&&a[x+4][y+4]==1&&a[x+2][y+2]==2)||(a[x+2][y+2]==1&&a[x+3][y+3]==1&&a[x+4][y+4]==1&&a[x+1][y+1]==2))) return 1;
  if (x>6&&y>6&&a[x-5][y-5]==1&&a[x-6][y-6]==0&&((a[x-1][y-1]==1&&a[x-2][y-2]==1&&a[x-3][y-3]==1&&a[x-4][y-4]==2)||(a[x-1][y-1]==1&&a[x-2][y-2]==1&&a[x-4][y-4]==1&&a[x-3][y-3]==2)||(a[x-1][y-1]==1&&a[x-3][y-3]==1&&a[x-4][y-4]==1&&a[x-2][y-2]==2)||(a[x-2][y-2]==1&&a[x-3][y-3]==1&&a[x-4][y-4]==1&&a[x-1][y-1]==2))) return 1;

  //check diagonal 2
  if (x>6&&y<10&&a[x-5][y+5]==1&&a[x-6][y+6]==0&&((a[x-1][y+1]==1&&a[x-2][y+2]==1&&a[x-3][y+3]==1&&a[x-4][y+4]==2)||(a[x-1][y+1]==1&&a[x-2][y+2]==1&&a[x-4][y+4]==1&&a[x-3][y+3]==2)||(a[x-1][y+1]==1&&a[x-3][y+3]==1&&a[x-4][y+4]==1&&a[x-2][y+2]==2)||(a[x-2][y+2]==1&&a[x-3][y+3]==1&&a[x-4][y+4]==1&&a[x-1][y+1]==2))) return 1;
  if (x<10&&y>6&&a[x+5][y-5]==1&&a[x+6][y-6]==0&&((a[x+1][y-1]==1&&a[x+2][y-2]==1&&a[x+3][y-3]==1&&a[x+4][y-4]==2)||(a[x+1][y-1]==1&&a[x+2][y-2]==1&&a[x+4][y-4]==1&&a[x+3][y-3]==2)||(a[x+1][y-1]==1&&a[x+3][y-3]==1&&a[x+4][y-4]==1&&a[x+2][y-2]==2)||(a[x+2][y-2]==1&&a[x+3][y-3]==1&&a[x+4][y-4]==1&&a[x+1][y-1]==2))) return 1;
  
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

int check_chance_three_vertical(int x,int y,int m,int a[m][m]){

  if (x<14){
  
    //discrete
    
    if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x-1][y]==0){
      if (x<13&&a[x+3][y]==2&&a[x+4][y]!=1&&a[x+4][y]!=0) return 1;	  
      else if (x>2&&a[x-2][y]==2&&a[x-3][y]!=1&&a[x-3][y]!=0) return 1;
      
    }

    //discrete xx--x x--xx

    if (x>2&&a[x-2][y]==0&&a[x-2][y]==a[x+2][y]&&((a[x-1][y]==0&&a[x+1][y]==2)||(a[x+1][y]==0&&a[x-1][y]==2))&&(a[x-3][y]!=1||a[x+3][y]!=1)&&a[x-3][y]!=0&&a[x+3][y]!=0) return 1;
    
    if (x<13){
      
      //continuous
      
      if (a[x+1][y]==a[x+2][y]&&a[x+1][y]==a[x+3][y]){
	if (a[x+1][y]==0){
	  if (a[x-1][y]!=1&&a[x+4][y]!=1) return 1;
	  else if (x>1&&a[x-1][y]==2&&a[x-2][y]!=1) return 1;
	  else if (x<12&&a[x+4][y]==2&&a[x+5][y]!=1) return 1;
	  
	}
      }

      //discrete x-x-x,x--xx

      if (x>1&&a[x-1][y]==a[x+3][y]&&((a[x+1][y]==0&&a[x+2][y]==2)||(a[x+2][y]==0&&a[x+1][y]==2))&&a[x-1][y]==0){
	if ((a[x-2][y]!=1||a[x+4][y]!=1)&&a[x-2][y]!=0&&a[x+4][y]!=0) return 1; 
      }
      
      if (x<12) {
	//far continuous

	if (a[x+2][y]==a[x+3][y]&&a[x+2][y]==a[x+4][y]&&a[x+1][y]==2&&a[x+2][y]==0){
	  if ((a[x-1][y]!=1||a[x+5][y]!=1)&&a[x-1][y]!=0) return 1;
	}

	//discrete
	if (a[x+1][y]==a[x+4][y]&&((a[x+1][y]==a[x+2][y]&&a[x+3][y]==2)||(a[x+1][y]==a[x+3][y]&&a[x+2][y]==2))&&a[x+1][y]==0){
	  if ((a[x-1][y]!=1||a[x+5][y]!=1)&&a[x-1][y]!=0) return 1;
	}
	
      }      
      
    }
    
  }

  if (x>2){

    //discrete
    if (a[x+1][y]==a[x-1][y]&&a[x+1][y]==a[x-2][y]&&a[x+1][y]==0){
      if (x>3&&a[x-3][y]==2&&a[x-4][y]!=1&&a[x-4][y]!=0) return 1;	  
      else if (x<14&&a[x+2][y]==2&&a[x+3][y]!=1&&a[x+3][y]!=0) return 1;
      
    }    

    // continuous
    if (x>3){
      if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x-3][y]){
	if (a[x-1][y]==0){
	  if (a[x+1][y]!=1&&a[x-4][y]!=1) return 1;
	  else if (x<15&&a[x+1][y]==2&&a[x+2][y]!=1) return 1;
	  else if (x>4&&a[x-4][y]==2&&a[x-5][y]!=1) return 1;
	  
	}
      }

      //discrete x-x-x,x--xx
      
      if (x<15&&a[x+1][y]==a[x-3][y]&&((a[x-1][y]==0&&a[x-2][y]==2)||(a[x-2][y]==0&&a[x-1][y]==2))&&a[x+1][y]==0){
	if ((a[x+2][y]!=1||a[x-4][y]!=1)&&a[x+2][y]!=0&&a[x-4][y]!=0) return 1; 
      }      
      
      if (x>4) {
	//far continuous
	if (a[x-2][y]==a[x-3][y]&&a[x-2][y]==a[x-4][y]&&a[x-1][y]==2&&a[x-2][y]==0){
	  if ((a[x+1][y]!=1||a[x-5][y]!=1)&&a[x+1][y]!=0) return 1;
	}
	
	//discrete
	if (a[x-1][y]==a[x-4][y]&&((a[x-1][y]==a[x-2][y]&&a[x-3][y]==2)||(a[x-1][y]==a[x-3][y]&&a[x-2][y]==2))&&a[x-1][y]==0){
	  if ((a[x+1][y]!=1||a[x-5][y]!=1)&&a[x+1][y]!=0) return 1;
	}
	
      }
      
    }
  }

  return 0;
}

int check_threat_three_vertical(int x,int y,int m,int a[m][m]){


  if (x<14){
    //discrete
    
    if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x-1][y]==1){
      if (x<13&&a[x+3][y]==2&&a[x+4][y]!=0&&a[x+4][y]!=1) return 1;	  
      else if (x>2&&a[x-2][y]==2&&a[x-3][y]!=0&&a[x-3][y]!=1) return 1;
      
    }

    //discrete xx--x x--xx
    
    if (x>2&&a[x-2][y]==1&&a[x-2][y]==a[x+2][y]&&((a[x-1][y]==1&&a[x+1][y]==2)||(a[x+1][y]==1&&a[x-1][y]==2))&&(a[x-3][y]!=0||a[x+3][y]!=0)&&a[x-3][y]!=1&&a[x+3][y]!=1) return 1;
    
    if (x<13){
      
      //continuous
      if (a[x+1][y]==a[x+2][y]&&a[x+1][y]==a[x+3][y]){
	if (a[x+1][y]==1){
	  if (a[x-1][y]!=0&&a[x+4][y]!=0) return 1;
	  else if (x>1&&a[x-1][y]==2&&a[x-2][y]!=0) return 1;
	  else if (x<12&&a[x+4][y]==2&&a[x+5][y]!=0) return 1;
	}
      }

      //discrete x-x-x,x--xx
      
      if (x>1&&a[x-1][y]==a[x+3][y]&&((a[x+1][y]==1&&a[x+2][y]==2)||(a[x+2][y]==1&&a[x+1][y]==2))&&a[x-1][y]==1){
	if ((a[x-2][y]!=0||a[x+4][y]!=0)&&a[x-2][y]!=1&&a[x+4][y]!=1) return 1; 
      }      
      
      if (x<12) {
	//far continuous
	if (a[x+2][y]==a[x+3][y]&&a[x+2][y]==a[x+4][y]&&a[x+1][y]==2&&a[x+2][y]==1){
	  if ((a[x-1][y]!=0||a[x+5][y]!=0)&&a[x-1][y]!=1) return 1;
	}

	//discrete
	if (a[x+1][y]==a[x+4][y]&&((a[x+1][y]==a[x+2][y]&&a[x+3][y]==2)||(a[x+1][y]==a[x+3][y]&&a[x+2][y]==2))&&a[x+1][y]==1){
	  if ((a[x-1][y]!=0||a[x+5][y]!=0)&&a[x-1][y]!=1) return 1;
	}
	
      }
      
    }
  }

  if (x>2){

    //discrete
    if (a[x+1][y]==a[x-1][y]&&a[x+1][y]==a[x-2][y]&&a[x+1][y]==1){
      if (x>3&&a[x-3][y]==2&&a[x-4][y]!=0&&a[x-4][y]!=1) return 1;	  
      else if (x<14&&a[x+2][y]==2&&a[x+3][y]!=0&&a[x+3][y]!=1) return 1;
      
    }    
    
    if (x>3){
      
      //continuous
      if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x-3][y]){
	if (a[x-1][y]==1){
	  if (a[x+1][y]!=0&&a[x-4][y]!=0) return 1;
	  else if (x<15&&a[x+1][y]==2&&a[x+2][y]!=0) return 1;
	  else if (x>4&&a[x-4][y]==2&&a[x-5][y]!=0) return 1;
	}
      }
      
      //discrete x-x-x,x--xx
      
      if (x<15&&a[x+1][y]==a[x-3][y]&&((a[x-1][y]==1&&a[x-2][y]==2)||(a[x-2][y]==1&&a[x-1][y]==2))&&a[x+1][y]==1){
	if ((a[x+2][y]!=0||a[x-4][y]!=0)&&a[x+2][y]!=1&&a[x-4][y]!=1) return 1; 
      }
      
      if (x>4) {
	//far continuous
	if (a[x-2][y]==a[x-3][y]&&a[x-2][y]==a[x-4][y]&&a[x-1][y]==2&&a[x-2][y]==1){
	  if ((a[x+1][y]!=0||a[x-5][y]!=0)&&a[x+1][y]!=1) return 1;
	}
	
	//discrete
	if (a[x-1][y]==a[x-4][y]&&((a[x-1][y]==a[x-2][y]&&a[x-3][y]==2)||(a[x-1][y]==a[x-3][y]&&a[x-2][y]==2))&&a[x-1][y]==1){
	  if ((a[x+1][y]!=0||a[x-5][y]!=0)&&a[x+1][y]!=1) return 1;
	}
	
      }      
      
    }
  }

  return 0;
}


int check_chance_three_horizontal(int x,int y,int m,int a[m][m]){

  if (y<14){
    
    //discrete    
    
    if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]==0){
      if (y<13&&a[x][y+3]==2&&a[x][y+4]!=1&&a[x][y+4]!=0) return 1;	  
      else if (y>2&&a[x][y-2]==2&&a[x][y-3]!=1&&a[x][y-3]!=0) return 1;
      
    }

    //discrete xx--x x--xx
    
    if (y>2&&a[x][y-2]==0&&a[x][y-2]==a[x][y+2]&&((a[x][y-1]==0&&a[x][y+1]==2)||(a[x][y+1]==0&&a[x][y-1]==2))&&(a[x][y-3]!=1||a[x][y+3]!=1)&&a[x][y-3]!=0&&a[x][y+3]!=0) return 1;
    
    if (y<13){
      
      //continuous
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]){
	if (a[x][y+1]==0){
	  if (a[x][y-1]!=1&&a[x][y+4]!=1) return 1;
	  else if (y>1&&a[x][y-1]==2&&a[x][y-2]!=1) return 1;
	  else if (y<12&&a[x][y+4]==2&&a[x][y+5]!=1) return 1;
	  
	}
      }

      //discrete x-x-x,x--xx
      
      if (y>1&&a[x][y-1]==a[x][y+3]&&((a[x][y+1]==0&&a[x][y+2]==2)||(a[x][y+2]==0&&a[x][y+1]==2))&&a[x][y-1]==0){
	if ((a[x][y-2]!=1||a[x][y+4]!=1)&&a[x][y-2]!=0&&a[x][y+4]!=0) return 1; 
      }      
      
      if (y<12) {
	//far continuous
	if (a[x][y+2]==a[x][y+3]&&a[x][y+2]==a[x][y+4]&&a[x][y+1]==2&&a[x][y+2]==0){
	  if ((a[x][y-1]!=1||a[x][y+5]!=1)&&a[x][y-1]!=0) return 1;
	}
	
	//discrete
	if (a[x][y+1]==a[x][y+4]&&((a[x][y+1]==a[x][y+2]&&a[x][y+3]==2)||(a[x][y+1]==a[x][y+3]&&a[x][y+2]==2))&&a[x][y+1]==0){
	  if ((a[x][y-1]!=1||a[x][y+5]!=1)&&a[x][y-1]!=0) return 1;
	}
	
      }
      
    }
    
  }
  
  if (y>2){
    
    //discrete
    if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y+1]==0){
      if (y>3&&a[x][y-3]==2&&a[x][y-4]!=1&&a[x][y-4]!=0) return 1;	  
      else if (y<14&&a[x][y+2]==2&&a[x][y+3]!=1&&a[x][y+3]!=0) return 1;
      
    }    
    
    if (y>3){
      
      //continuous
      
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]){
	if (a[x][y-1]==0){
	  if (a[x][y+1]!=1&&a[x][y-4]!=1) return 1;
	  else if (y<15&&a[x][y+1]==2&&a[x][y+2]!=1) return 1;
	  else if (y>4&&a[x][y-4]==2&&a[x][y-5]!=1) return 1;
	  
	}
      }

      //discrete x-x-x,x--xx
      
      if (y<15&&a[x][y+1]==a[x][y-3]&&((a[x][y-1]==0&&a[x][y-2]==2)||(a[x][y-2]==0&&a[x][y-1]==2))&&a[x][y+1]==0){
	if ((a[x][y+2]!=1||a[x][y-4]!=1)&&a[x][y+2]!=0&&a[x][y-4]!=0) return 1; 
      }            
      
      if (y>4) {
	//far continuous
	if (a[x][y-2]==a[x][y-3]&&a[x][y-2]==a[x][y-4]&&a[x][y-1]==2&&a[x][y-2]==0){
	  if ((a[x][y+1]!=1||a[x][y-5]!=1)&&a[x][y+1]!=0) return 1;
	}
	
	//discrete
	if (a[x][y-1]==a[x][y-4]&&((a[x][y-1]==a[x][y-2]&&a[x][y-3]==2)||(a[x][y-1]==a[x][y-3]&&a[x][y-2]==2))&&a[x][y-1]==0){
	  if ((a[x][y+1]!=1||a[x][y-5]!=1)&&a[x][y+1]!=0) return 1;
	}
	
      }
      
      
    }
  }
  
  return 0;
}

int check_threat_three_horizontal(int x,int y,int m,int a[m][m]){

  if (y<14){
    
    //discrete    
    
    if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y-1]==1){
      if (y<13&&a[x][y+3]==2&&a[x][y+4]!=0&&a[x][y+4]!=1) return 1;	  
      else if (y>2&&a[x][y-2]==2&&a[x][y-3]!=0&&a[x][y-3]!=1) return 1;
    }   

    //discrete xx--x x--xx
    
    if (y>2&&a[x][y-2]==1&&a[x][y-2]==a[x][y+2]&&((a[x][y-1]==1&&a[x][y+1]==2)||(a[x][y+1]==1&&a[x][y-1]==2))&&(a[x][y-3]!=0||a[x][y+3]!=0)&&a[x][y-3]!=1&&a[x][y+3]!=1) return 1;
    
    if (y<13){
      
      //continuous
      
      if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]){
	if (a[x][y+1]==1){
	  if (a[x][y-1]!=0&&a[x][y+4]!=0) return 1;
	  else if (y>1&&a[x][y-1]==2&&a[x][y-2]!=0) return 1;
	  else if (y<12&&a[x][y+4]==2&&a[x][y+5]!=0) return 1;
	}
      }

      //discrete x-x-x,x--xx
      
      if (y>1&&a[x][y-1]==a[x][y+3]&&((a[x][y+1]==1&&a[x][y+2]==2)||(a[x][y+2]==1&&a[x][y+1]==2))&&a[x][y-1]==1){
	if ((a[x][y-2]!=0||a[x][y+4]!=0)&&a[x][y-2]!=1&&a[x][y+4]!=1) return 1; 
      }      
      
      if (y<12) {
	//far continuous
	if (a[x][y+2]==a[x][y+3]&&a[x][y+2]==a[x][y+4]&&a[x][y+1]==2&&a[x][y+2]==1){
	  if ((a[x][y-1]!=0||a[x][y+5]!=0)&&a[x][y-1]!=1) return 1;
	}
	
	//discrete
	if (a[x][y+1]==a[x][y+4]&&((a[x][y+1]==a[x][y+2]&&a[x][y+3]==2)||(a[x][y+1]==a[x][y+3]&&a[x][y+2]==2))&&a[x][y+1]==1){
	  if ((a[x][y-1]!=0||a[x][y+5]!=0)&&a[x][y-1]!=1) return 1;
	}
	
      }      
      
    }
    
  }

  if (y>2){
    
    //discrete
    if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y+1]==1){
      if (y>3&&a[x][y-3]==2&&a[x][y-4]!=0&&a[x][y-4]!=1) return 1;	  
      else if (y<14&&a[x][y+2]==2&&a[x][y+3]!=0&&a[x][y+3]!=1) return 1;
      
    }       
    
    if (y>3){
      
      //continuous
      
      if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]){
	if (a[x][y-1]==1){
	  if (a[x][y+1]!=0&&a[x][y-4]!=0) return 1;
	  else if (y<15&&a[x][y+1]==2&&a[x][y+2]!=0) return 1;
	  else if (y>4&&a[x][y-4]==2&&a[x][y-5]!=0) return 1;
	}
      }

      //discrete x-x-x,x--xx
      
      if (y<15&&a[x][y+1]==a[x][y-3]&&((a[x][y-1]==1&&a[x][y-2]==2)||(a[x][y-2]==1&&a[x][y-1]==2))&&a[x][y+1]==1){
	if ((a[x][y+2]!=0||a[x][y-4]!=0)&&a[x][y+2]!=1&&a[x][y-4]!=1) return 1; 
      }            
      
      if (y>4) {
	//far continuous
	if (a[x][y-2]==a[x][y-3]&&a[x][y-2]==a[x][y-4]&&a[x][y-1]==2&&a[x][y-2]==1){
	  if ((a[x][y+1]!=0||a[x][y-5]!=0)&&a[x][y+1]!=1) return 1;
	}
	
	//discrete
	if (a[x][y-1]==a[x][y-4]&&((a[x][y-1]==a[x][y-2]&&a[x][y-3]==2)||(a[x][y-1]==a[x][y-3]&&a[x][y-2]==2))&&a[x][y-1]==1){
	  if ((a[x][y+1]!=0||a[x][y-5]!=0)&&a[x][y+1]!=1) return 1;
	}	
	
      }
      
    }
  }
  
  return 0;
}

int check_chance_three_diagonal1(int x,int y,int m,int a[m][m]){

  if (x<14){
    
    if (y<14){
      
      //discrete      
      
      if (a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x-1][y-1]==0){
	if (x<13&&y<13&&a[x+3][y+3]==2&&a[x+4][y+4]!=1&&a[x+4][y+4]!=0) return 1;	  
	else if (x>2&&y>2&&a[x-2][y-2]==2&&a[x-3][y-3]!=1&&a[x-3][y-3]!=0) return 1;	
      }

      //discrete xx--x x--xx
      
      if (x>2&&y>2&&a[x-2][y-2]==0&&a[x-2][y-2]==a[x+2][y+2]&&((a[x-1][y-1]==0&&a[x+1][y+1]==2)||(a[x+1][y+1]==0&&a[x-1][y-1]==2))&&(a[x-3][y-3]!=1||a[x+3][y+3]!=1)&&a[x-3][y-3]!=0&&a[x+3][y+3]!=0) return 1;
      
      if (x<13){    
	
	if (y<13){
	  
	  //continuous
	  
	  if (a[x+1][y+1]==a[x+2][y+2]&&a[x+1][y+1]==a[x+3][y+3]){
	    if (a[x+1][y+1]==0){
	      if ((a[x-1][y-1]==2||a[x+4][y+4]==2)&&a[x-1][y-1]!=1&&a[x+4][y+4]!=1) return 1;
	      else if (x>1&&y>1&&a[x-1][y-1]==2&&a[x-2][y-2]!=1) return 1;
	      else if (x<12&&y<12&&a[x+4][y+4]==2&&a[x+5][y+5]!=1) return 1;
	      
	    }
	  }

	  //discrete x-x-x,x--xx
	  
	  if (x>1&&y>1&&a[x-1][y-1]==a[x+3][y+3]&&((a[x+1][y+1]==0&&a[x+2][y+2]==2)||(a[x+2][y+2]==0&&a[x+1][y+1]==2))&&a[x-1][y-1]==0){
	    if ((a[x-2][y-2]!=1||a[x+4][y+4]!=1)&&a[x-2][y-2]!=0&&a[x+4][y+4]!=0) return 1; 
	  }      	  
	  
	  if (x<12&&y<12){
	    //far continuous
	    if (a[x+2][y+2]==a[x+3][y+3]&&a[x+2][y+2]==a[x+4][y+4]&&a[x+2][y+2]==0){
	      if (a[x+1][y+1]==2&&(a[x-1][y-1]!=1||a[x+5][y+5]!=1)&&a[x-1][y-1]!=0) return 1;
	    }
	    //discrete
	    if (a[x+1][y+1]==a[x+4][y+4]&&((a[x+1][y+1]==a[x+2][y+2]&&a[x+3][y+3]==2)||(a[x+1][y+1]==a[x+3][y+3]&&a[x+2][y+2]==2))&&a[x+1][y+1]==0){
	      if ((a[x-1][y-1]!=1||a[x+5][y+5]!=1)&&a[x-1][y-1]!=0) return 1;
	    }	    
	    
	  }
	  
	}	
    
      }
      
    }
  }

  if (x>2){
    if (y>2){
      
      //discrete
      if (a[x+1][y+1]==a[x-1][y-1]&&a[x+1][y+1]==a[x-2][y-2]&&a[x+1][y+1]==0){
	if (x>3&&y>3&&a[x-3][y-3]==2&&a[x-4][y-4]!=1&&a[x-4][y-4]!=0) return 1;	  
	else if (x<14&&y<14&&a[x+2][y+2]==2&&a[x+3][y+3]!=1&&a[x+3][y+3]!=0) return 1;
	
      }       
      
      if (x>3){
	
	if (y>3){
	  
	  //continuous
	  if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x-3][y-3]){
	    if (a[x-1][y-1]==0){
	      if ((a[x+1][y+1]==2||a[x-4][y-4]==2)&&a[x+1][y+1]!=1&&a[x-4][y-4]!=1) return 1;
	      else if (x<15&&y<15&&a[x+1][y+1]==2&&a[x+2][y+2]!=1) return 1;
	      else if (x>4&&y>4&&a[x-4][y-4]==2&&a[x-5][y-5]!=1) return 1;
	      
	    }
	  }

	  //discrete x-x-x,x--xx
	  
	  if (x<15&&y<15&&a[x+1][y+1]==a[x-3][y-3]&&((a[x-1][y-1]==0&&a[x-2][y-2]==2)||(a[x-2][y-2]==0&&a[x-1][y-1]==2))&&a[x+1][y+1]==0){
	    if ((a[x+2][y+2]!=1||a[x-4][y-4]!=1)&&a[x+2][y+2]!=0&&a[x-4][y-4]!=0) return 1; 
	  }	  
	  
	  if (x>4&&y>4){
	    //far continuous

	    if (a[x-2][y-2]==a[x-3][y-3]&&a[x-2][y-2]==a[x-4][y-4]&&a[x-2][y-2]==0){
	      if (a[x-1][y-1]==2&&(a[x+1][y+1]!=1||a[x-5][y-5]!=1)&&a[x+1][y+1]!=0) return 1;
	    }
	    //discrete
	    if (a[x-1][y-1]==a[x-4][y-4]&&((a[x-1][y-1]==a[x-2][y-2]&&a[x-3][y-3]==2)||(a[x-1][y-1]==a[x-3][y-3]&&a[x-2][y-2]==2))&&a[x-1][y-1]==0){
	      if ((a[x+1][y+1]!=1||a[x-5][y-5]!=1)&&a[x+1][y+1]!=0) return 1;
	    }
	    
	  }  
	  
	}
	
      }
    }
  }
  
  return 0;
}

int check_threat_three_diagonal1(int x,int y,int m,int a[m][m]){

  if (x<14){
    
    if (y<14){
      
      //discrete      
      
      if (a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x-1][y-1]==1){
	if (x<13&&y<13&&a[x+3][y+3]==2&&a[x+4][y+4]!=0&&a[x+4][y+4]!=1) return 1;	  
	else if (x>2&&y>2&&a[x-2][y-2]==2&&a[x-3][y-3]!=0&&a[x-3][y-3]!=1) return 1;
	
      }
      
      //discrete xx--x x--xx
      
      if (x>2&&y>2&&a[x-2][y-2]==1&&a[x-2][y-2]==a[x+2][y+2]&&((a[x-1][y-1]==1&&a[x+1][y+1]==2)||(a[x+1][y+1]==1&&a[x-1][y-1]==2))&&(a[x-3][y-3]!=0||a[x+3][y+3]!=0)&&a[x-3][y-3]!=1&&a[x+3][y+3]!=1) return 1;
      
      if (x<13){    
	
	if (y<13){
	  //continuous
	  
	  if (a[x+1][y+1]==a[x+2][y+2]&&a[x+1][y+1]==a[x+3][y+3]){
	    if (a[x+1][y+1]==1){
	      if ((a[x-1][y-1]==2||a[x+4][y+4]==2)&&a[x-1][y-1]!=0&&a[x+4][y+4]!=0) return 1;
	      else if (x>1&&y>1&&a[x-1][y-1]==2&&a[x-2][y-2]!=0) return 1;
	      else if (x<12&&y<12&&a[x+4][y+4]==2&&a[x+5][y+5]!=0) return 1;
	    }
	  }
	  
	  //discrete x-x-x,x--xx
	  
	  if (x>1&&y>1&&a[x-1][y-1]==a[x+3][y+3]&&((a[x+1][y+1]==1&&a[x+2][y+2]==2)||(a[x+2][y+2]==1&&a[x+1][y+1]==2))&&a[x-1][y-1]==1){
	    if ((a[x-2][y-2]!=0||a[x+4][y+4]!=0)&&a[x-2][y-2]!=1&&a[x+4][y+4]!=1) return 1; 
	  }      	  
	  	  
	  if (x<12&&y<12){
	    //far continuous
	    if (a[x+2][y+2]==a[x+3][y+3]&&a[x+2][y+2]==a[x+4][y+4]&&a[x+2][y+2]==1){
	      if (a[x+1][y+1]==2&&(a[x-1][y-1]!=0||a[x+5][y+5]!=0)&&a[x-1][y-1]!=1) return 1;
	    }
	    
	    //discrete
	    if (a[x+1][y+1]==a[x+4][y+4]&&((a[x+1][y+1]==a[x+2][y+2]&&a[x+3][y+3]==2)||(a[x+1][y+1]==a[x+3][y+3]&&a[x+2][y+2]==2))&&a[x+1][y+1]==1){
	      if ((a[x-1][y-1]!=0||a[x+5][y+5]!=0)&&a[x-1][y-1]!=1) return 1;
	    }	    
	    	    
	  }    
	  
	}
      }
      
    }
  }

  if (x>2){
    if (y>2){
      
      //discrete
      if (a[x+1][y+1]==a[x-1][y-1]&&a[x+1][y+1]==a[x-2][y-2]&&a[x+1][y+1]==1){
	if (x>3&&y>3&&a[x-3][y-3]==2&&a[x-4][y-4]!=0&&a[x-4][y-4]!=1) return 1;	  
	else if (x<14&&y<14&&a[x+2][y+2]==2&&a[x+3][y+3]!=0&&a[x+3][y+3]!=1) return 1;
	
      }          
      
      if (x>3){
	
	if (y>3){
	  
	  //continuous
	  if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x-3][y-3]){
	    if (a[x-1][y-1]==1){
	      if ((a[x+1][y+1]==2||a[x-4][y-4]==2)&&a[x+1][y+1]!=0&&a[x-4][y-4]!=0) return 1;
	      else if (x<15&&y<15&&a[x-1][y+1]==2&&a[x-2][y+2]!=0) return 1;
	      else if (x>4&&y>4&&a[x-4][y-4]==2&&a[x-5][y-5]!=0) return 1;
	    }
	  }

	  //discrete x-x-x,x--xx
	  
	  if (x<15&&y<15&&a[x+1][y+1]==a[x-3][y-3]&&((a[x-1][y-1]==1&&a[x-2][y-2]==2)||(a[x-2][y-2]==1&&a[x-1][y-1]==2))&&a[x+1][y+1]==1){
	    if ((a[x+2][y+2]!=0||a[x-4][y-4]!=0)&&a[x+2][y+2]!=1&&a[x-4][y-4]!=1) return 1; 
	  }	  
	  
	  if (x>4&&y>4){
	    //far continuous
	    if (a[x-2][y-2]==a[x-3][y-3]&&a[x-2][y-2]==a[x-4][y-4]&&a[x-2][y-2]==1){
	      if (a[x-1][y-1]==2&&(a[x+1][y+1]!=0||a[x-5][y-5]!=0)&&a[x+1][y+1]!=1) return 1;
	    }
	    
	    //discrete
	    if (a[x-1][y-1]==a[x-4][y-4]&&((a[x-1][y-1]==a[x-2][y-2]&&a[x-3][y-3]==2)||(a[x-1][y-1]==a[x-3][y-3]&&a[x-2][y-2]==2))&&a[x-1][y-1]==1){
	      if ((a[x+1][y+1]!=0||a[x-5][y-5]!=0)&&a[x+1][y+1]!=1) return 1;
	    }	    
	    
	  }   
	  
	}
	
      }
    }
  }
  
  return 0;
}


int check_chance_three_diagonal2(int x,int y,int m,int a[m][m]){

  if (x<14){
    
    if (y>2){
      
      //discrete      
      
      if (a[x-1][y+1]==a[x+1][y-1]&&a[x-1][y+1]==a[x+2][y-2]&&a[x-1][y+1]==0){
	if (x<13&&y>3&&a[x+3][y-3]==2&&a[x+4][y-4]!=1&&a[x+4][y-4]!=0) return 1;	  
	else if (x>2&&y<14&&a[x-2][y+2]==2&&a[x-3][y+3]!=1&&a[x-3][y+3]!=0) return 1;	
      }

      //discrete xx--x x--xx
      
      if (x>2&&y<14&&a[x-2][y+2]==0&&a[x-2][y+2]==a[x+2][y-2]&&((a[x-1][y+1]==0&&a[x+1][y-1]==2)||(a[x+1][y-1]==0&&a[x-1][y+1]==2))&&(a[x-3][y+3]!=1||a[x+3][y-3]!=1)&&a[x-3][y+3]!=0&&a[x+3][y-3]!=0) return 1;
      
      if (x<13){
        
	if (y>3){
	  //continuous
	  
	  if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x+3][y-3]){
	    if (a[x+1][y-1]==0){
	      if ((a[x-1][y+1]==2||a[x+4][y-4]==2)&&a[x-1][y+1]!=1&&a[x+4][y-4]!=1) return 1;
	      else if (x>1&&y<15&&a[x-1][y+1]==2&&a[x-2][y+2]!=1) return 1;
	      else if (x<12&&y>4&&a[x+4][y-4]==2&&a[x+5][y-5]!=1) return 1;
	      
	    }
	  }

	  //discrete x-x-x,x--xx
	  
	  if (x>1&&y<15&&a[x-1][y+1]==a[x+3][y-3]&&((a[x+1][y-1]==0&&a[x+2][y-2]==2)||(a[x+2][y-2]==0&&a[x+1][y-1]==2))&&a[x-1][y+1]==0){
	    if ((a[x-2][y+2]!=1||a[x+4][y-4]!=1)&&a[x-2][y+2]!=0&&a[x+4][y-4]!=0) return 1; 
	  }      	  
	  
	  if (x<12&&y>4){
	    //far continuous
	    if (a[x+2][y-2]==a[x+3][y-3]&&a[x+2][y-2]==a[x+4][y-4]&&a[x+2][y-2]==0){
	      if (a[x+1][y-1]==2&&(a[x-1][y+1]!=1||a[x+5][y-5]!=1)&&a[x-1][y+1]!=0) return 1;
	    }
	    
	    //discrete
	    if (a[x+1][y-1]==a[x+4][y-4]&&((a[x+1][y-1]==a[x+2][y-2]&&a[x+3][y-3]==2)||(a[x+1][y-1]==a[x+3][y-3]&&a[x+2][y-2]==2))&&a[x+1][y-1]==0){
	      if ((a[x-1][y+1]!=1||a[x+5][y-5]!=1)&&a[x-1][y+1]!=0) return 1;
	    }	    
	    
	  }
	  
	} 
	
      }
    }
  }
  
  if (x>2){
    if (y<14){
      
      //discrete
      if (a[x+1][y-1]==a[x-1][y+1]&&a[x+1][y-1]==a[x-2][y+2]&&a[x+1][y-1]==0){
	if (x>3&&y<13&&a[x-3][y+3]==2&&a[x-4][y+4]!=1&&a[x-4][y+4]!=0) return 1;	  
	else if (x<14&&y>2&&a[x+2][y-2]==2&&a[x+3][y-3]!=1&&a[x+3][y-3]!=0) return 1;
	
      }          
      
      if (x>3){
	
	if (y<13){
	  
	  //continuous
	  if (a[x-1][y+1]==a[x-2][y+2]&&a[x-1][y+1]==a[x-3][y+3]){
	    if (a[x-1][y+1]==0){
	      if ((a[x+1][y-1]==2||a[x-4][y+4]==2)&&a[x+1][y-1]!=1&&a[x-4][y+4]!=1) return 1;
	      else if (x<15&&y>1&&a[x+1][y-1]==2&&a[x+2][y-2]!=1) return 1;
	      else if (x>4&&y<12&&a[x-4][y+4]==2&&a[x-5][y+5]!=1) return 1;
	      
	    }
	  }

	  //discrete x-x-x,x--xx
	  
	  if (x<15&&y>1&&a[x+1][y-1]==a[x-3][y+3]&&((a[x-1][y+1]==0&&a[x-2][y+2]==2)||(a[x-2][y+2]==0&&a[x-1][y+1]==2))&&a[x+1][y-1]==0){
	    if ((a[x+2][y-2]!=1||a[x-4][y+4]!=1)&&a[x+2][y-2]!=0&&a[x-4][y+4]!=0) return 1; 
	  }	  
	  
	  if (x>4&&y<12){
	    //far continuous
	    if (a[x-2][y+2]==a[x-3][y+3]&&a[x-2][y+2]==a[x-4][y+4]&&a[x-2][y+2]==0){
	      if (a[x-1][y+1]==2&&(a[x+1][y-1]!=1||a[x-5][y+5]!=1)&&a[x+1][y-1]!=0) return 1;
	    }
	    
	    //discrete
	    if (a[x-1][y+1]==a[x-4][y+4]&&((a[x-1][y+1]==a[x-2][y+2]&&a[x-3][y+3]==2)||(a[x-1][y+1]==a[x-3][y+3]&&a[x-2][y+2]==2))&&a[x-1][y+1]==0){
	      if ((a[x+1][y-1]!=1||a[x-5][y+5]!=1)&&a[x+1][y-1]!=0) return 1;
	    }	    
	    
	  }  
	  
	}    
	
      }
    }
  }
  
  return 0;
}

int check_threat_three_diagonal2(int x,int y,int m,int a[m][m]){

  if (x<14){
    
    if (y>2){
      
      //discrete      
      
      if (a[x-1][y+1]==a[x+1][y-1]&&a[x-1][y+1]==a[x+2][y-2]&&a[x-1][y+1]==1){
	if (x<13&&y>3&&a[x+3][y-3]==2&&a[x+4][y-4]!=0&&a[x+4][y-4]!=1) return 1;	  
	else if (x>2&&y<14&&a[x-2][y+2]==2&&a[x-3][y+3]!=0&&a[x-3][y+3]!=1) return 1;	
      }  

      //discrete xx--x x--xx
      
      if (x>2&&y<14&&a[x-2][y+2]==1&&a[x-2][y+2]==a[x+2][y-2]&&((a[x-1][y+1]==1&&a[x+1][y-1]==2)||(a[x+1][y-1]==1&&a[x-1][y+1]==2))&&(a[x-3][y+3]!=0||a[x+3][y-3]!=0)&&a[x-3][y+3]!=1&&a[x+3][y-3]!=1) return 1;
      
      if (x<13){
        
	if (y>3){
	  
	  //continuous
	  
	  if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x+3][y-3]){
	    if (a[x+1][y-1]==1){
	      if ((a[x-1][y+1]==2||a[x+4][y-4]==2)&&a[x-1][y+1]!=0&&a[x+4][y-4]!=0) return 1;
	      else if (x>1&&y<15&&a[x-1][y+1]==2&&a[x-2][y+2]!=0) return 1;
	      else if (x<12&&y>4&&a[x+4][y-4]==2&&a[x+5][y-5]!=0) return 1;
	    }
	  }

	  //discrete x-x-x,x--xx
	  
	  if (x>1&&y<15&&a[x-1][y+1]==a[x+3][y-3]&&((a[x+1][y-1]==1&&a[x+2][y-2]==2)||(a[x+2][y-2]==1&&a[x+1][y-1]==2))&&a[x-1][y+1]==1){
	    if ((a[x-2][y+2]!=0||a[x+4][y-4]!=0)&&a[x-2][y+2]!=1&&a[x+4][y-4]!=1) return 1; 
	  }   	  
	  
	  if (x<12&&y>4){
	    //far continuous
	    if (a[x+2][y-2]==a[x+3][y-3]&&a[x+2][y-2]==a[x+4][y-4]&&a[x+2][y-2]==1){
	      if (a[x+1][y-1]==2&&(a[x-1][y+1]!=0||a[x+5][y-5]!=0)&&a[x-1][y+1]!=1) return 1;
	    }
	    
	    //discrete
	    if (a[x+1][y-1]==a[x+4][y-4]&&((a[x+1][y-1]==a[x+2][y-2]&&a[x+3][y-3]==2)||(a[x+1][y-1]==a[x+3][y-3]&&a[x+2][y-2]==2))&&a[x+1][y-1]==1){
	      if ((a[x-1][y+1]!=0||a[x+5][y-5]!=0)&&a[x-1][y+1]!=1) return 1;
	    }        	  
	    
	  }	
	  
	}
	
      }
    }
  }

  if (x>2){
    if (y<14){
      
      //discrete
      if (a[x+1][y-1]==a[x-1][y+1]&&a[x+1][y-1]==a[x-2][y+2]&&a[x+1][y-1]==1){
	if (x>3&&y<13&&a[x-3][y+3]==2&&a[x-4][y+4]!=0&&a[x-4][y+4]!=1) return 1;	  
	else if (x<14&&y>2&&a[x+2][y-2]==2&&a[x+3][y-3]!=0&&a[x+3][y-3]!=1) return 1;
	
      }      
      
      if (x>3){
	
	if (y<13){
	  
	  //continuous
	  if (a[x-1][y+1]==a[x-2][y+2]&&a[x-1][y+1]==a[x-3][y+3]){
	    if (a[x-1][y+1]==1){
	      if ((a[x+1][y-1]==2||a[x-4][y+4]==2)&&a[x+1][y-1]!=0&&a[x-4][y+4]!=0) return 1;
	      else if (x<15&&y>1&&a[x+1][y-1]==2&&a[x+2][y-2]!=0) return 1;
	      else if (x>4&&y<12&&a[x-4][y+4]==2&&a[x-5][y+5]!=0) return 1;
	    }
	  }

	  //discrete x-x-x,x--xx
	  
	  if (x<15&&y>1&&a[x+1][y-1]==a[x-3][y+3]&&((a[x-1][y+1]==1&&a[x-2][y+2]==2)||(a[x-2][y+2]==1&&a[x-1][y+1]==2))&&a[x+1][y-1]==1){
	    if ((a[x+2][y-2]!=0||a[x-4][y+4]!=0)&&a[x+2][y-2]!=1&&a[x-4][y+4]!=1) return 1; 
	  }	  
	  
	  
	  //far continuous
	  if (x>4&&y<12){
	    if (a[x-2][y+2]==a[x-3][y+3]&&a[x-2][y+2]==a[x-4][y+4]&&a[x-2][y+2]==1){
	      if (a[x-1][y+1]==2&&(a[x+1][y-1]!=0||a[x-5][y+5]!=0)&&a[x+1][y-1]!=1) return 1;
	    }

	    //discrete
	    if (a[x-1][y+1]==a[x-4][y+4]&&((a[x-1][y+1]==a[x-2][y+2]&&a[x-3][y+3]==2)||(a[x-1][y+1]==a[x-3][y+3]&&a[x-2][y+2]==2))&&a[x-1][y+1]==1){
	      if ((a[x+1][y-1]!=0||a[x-5][y+5]!=0)&&a[x+1][y-1]!=1) return 1;
	    }	    	    
	    
	  }  
	  
	}    
	
      }
    }
  }
  
  return 0;
}



int check_chance_three(int x,int y,int m,int a[m][m]){

  //check 3
  if (x>1&&x<12){
    if (a[x+1][y]==a[x+2][y]&&a[x+1][y]==a[x+3][y]&&a[x+4][y]==2&&a[x-1][y]==2&&a[x+1][y]==0&&a[x-2][y]!=1&&a[x-2][y]!=0&&a[x+5][y]!=1&&a[x+5][y]!=0) return 1;
    if (y>1&&y<12){
      if (a[x+1][y+1]==a[x+2][y+2]&&a[x+1][y+1]==a[x+3][y+3]&&a[x+4][y+4]==2&&a[x-1][y-1]==2&&a[x+1][y+1]==0&&a[x-2][y-2]!=1&&a[x-2][y-2]!=0&&a[x+5][y+5]!=1&&a[x+5][y+5]!=0) return 1;
    }
    if (y>4&&y<15){
      if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x+3][y-3]&&a[x+4][y-4]==2&&a[x-1][y+1]==2&&a[x+1][y-1]==0&&a[x-2][y+2]!=1&&a[x-2][y+2]!=0&&a[x+5][y-5]!=1&&a[x+5][y-5]!=0) return 1;
    }
    
  }

  if (x>4&&x<15){
    if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x-3][y]&&a[x-4][y]==2&&a[x+1][y]==2&&a[x-1][y]==0&&a[x+2][y]!=1&&a[x+2][y]!=0&&a[x-5][y]!=1&&a[x-5][y]!=0) return 1;
    if (y>1&&y<12){
      if (a[x-1][y+1]==a[x-2][y+2]&&a[x-1][y+1]==a[x-3][y+3]&&a[x-4][y+4]==2&&a[x+1][y-1]==2&&a[x-1][y+1]==0&&a[x+2][y-2]!=1&&a[x+2][y-2]!=0&&a[x-5][y+5]!=1&&a[x-5][y+5]!=0) return 1;
    }
    if (y>4&&y<15){
      if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x-3][y-3]&&a[x-4][y-4]==2&&a[x+1][y+1]==2&&a[x-1][y-1]==0&&a[x+2][y+2]!=1&&a[x+2][y+2]!=0&&a[x-5][y-5]!=1&&a[x-5][y-5]!=0) return 1;
    }
    
  }
  
  //check 1+2

  if (x>2&&x<13){
    if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x+3][y]==2&&a[x-2][y]==2&&a[x-1][y]==0&&a[x-3][y]!=1&&a[x-3][y]!=0&&a[x+4][y]!=1&&a[x+4][y]!=0) return 1;
    if (y>2&&y<13){
      if (a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x+3][y+3]==2&&a[x-2][y-2]==2&&a[x-1][y-1]==0&&a[x-3][y-3]!=1&&a[x-3][y-3]!=0&&a[x+4][y+4]!=1&&a[x+4][y+4]!=0) return 1;
    }
    if (y>3&&y<14){
      if (a[x-1][y+1]==a[x+1][y-1]&&a[x-1][y+1]==a[x+2][y-2]&&a[x+3][y-3]==2&&a[x-2][y+2]==2&&a[x-1][y+1]==0&&a[x-3][y+3]!=1&&a[x-3][y+3]!=0&&a[x+4][y-4]!=1&&a[x+4][y-4]!=0) return 1;
    }

  }
  if (x>3&&x<14){
    if (a[x+1][y]==a[x-1][y]&&a[x+1][y]==a[x-2][y]&&a[x-3][y]==2&&a[x+2][y]==2&&a[x+1][y]==0&&a[x+3][y]!=1&&a[x+3][y]!=0&&a[x-4][y]!=1&&a[x-4][y]!=0) return 1;
    if (y>2&&y<13){
      if (a[x+1][y-1]==a[x-1][y+1]&&a[x+1][y-1]==a[x-2][y+2]&&a[x-3][y+3]==2&&a[x+2][y-2]==2&&a[x+1][y-1]==0&&a[x+3][y-3]!=1&&a[x+3][y-3]!=0&&a[x-4][y+4]!=1&&a[x-4][y+4]!=0) return 1;
    }
    if (y>3&&y<14){
      if (a[x+1][y+1]==a[x-1][y-1]&&a[x+1][y+1]==a[x-2][y-2]&&a[x-3][y-3]==2&&a[x+2][y+2]==2&&a[x+1][y+1]==0&&a[x+3][y+3]!=1&&a[x+3][y+3]!=0&&a[x-4][y-4]!=1&&a[x-4][y-4]!=0) return 1;
    }
    
  }
  
  if (y>1&&y<12){
    //check 3
    if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+4]==2&&a[x][y-1]==2&&a[x][y+1]==0&&a[x][y-2]!=1&&a[x][y-2]!=0&&a[x][y+5]!=1&&a[x][y+5]!=0) return 1;
  }
  if (y>2&&y<13){
    //check 1+2
    if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y+3]==2&&a[x][y-2]==2&&a[x][y-1]==0&&a[x][y-3]!=1&&a[x][y-3]!=0&&a[x][y+4]!=1&&a[x][y+4]!=0) return 1;
  }
  if (y>4&&y<15){
    //check 3
    if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-4]==2&&a[x][y+1]==2&&a[x][y-1]==0&&a[x][y+1]!=1&&a[x][y+1]!=0&&a[x][y-5]!=1&&a[x][y-5]!=0) return 1;
  }
  if (y>3&&y<14){
    //check 1+2
    if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y-3]==2&&a[x][y+2]==2&&a[x][y+1]==0&&a[x][y+3]!=1&&a[x][y+3]!=0&&a[x][y-4]!=1&&a[x][y-4]!=0) return 1;
  }
  
  return 0;
}

int check_threat_far_three(int x,int y,int m,int a[m][m]){

  //check vertical
  
  if (x<11){
    if (a[x+2][y]==a[x+3][y]&&a[x+2][y]==a[x+4][y]&&a[x+1][y]==2&&a[x+5][y]==2&&a[x+2][y]==1){
      if (a[x+6][y]==2) return 1;
      else if (a[x-1][y]!=0&&a[x-1][y]!=1&&a[x+6][y]!=0&&a[x+6][y]!=1) return 1;
    }

    if (((a[x+2][y]==a[x+4][y]&&a[x+3][y]==2)||(a[x+2][y]==a[x+3][y]&&a[x+4][y]==2))&&a[x+2][y]==a[x+5][y]&&a[x+1][y]==2&&a[x+2][y]==1){
      if (x<10&&a[x+6][y]==2&&a[x+7][y]!=0&&a[x+7][y]!=1) return 1;
    }


    //check diagonal
    if (y<11){
      if (a[x+2][y+2]==a[x+3][y+3]&&a[x+2][y+2]==a[x+4][y+4]&&a[x+1][y+1]==2&&a[x+5][y+5]==2&&a[x+2][y+2]==1){
	if (a[x+6][y+6]==2) return 1;
	else if (a[x-1][y-1]!=0&&a[x-1][y-1]!=1&&a[x+6][y+6]!=0&&a[x+6][y+6]!=1) return 1;
      }
      
      if (((a[x+2][y+2]==a[x+4][y+4]&&a[x+3][y+3]==2)||(a[x+2][y+2]==a[x+3][y+3]&&a[x+4][y+4]==2))&&a[x+2][y+2]==a[x+5][y+5]&&a[x+1][y+1]==2&&a[x+2][y+2]==1){
	if (x<10&&y<10&&a[x+6][y+6]==2&&a[x+7][y+7]!=0&&a[x+7][y+7]!=1) return 1;
      }
    }
    
    if (y>5){
      if (a[x+2][y-2]==a[x+3][y-3]&&a[x+2][y-2]==a[x+4][y-4]&&a[x+1][y-1]==2&&a[x+5][y-5]==2&&a[x+2][y-2]==1){
	if (a[x+6][y-6]==2) return 1;
	else if (a[x-1][y+1]!=0&&a[x-1][y+1]!=1&&a[x+6][y-6]!=0&&a[x+6][y-6]!=1) return 1;
      }
      
      if (((a[x+2][y-2]==a[x+4][y-4]&&a[x+3][y-3]==2)||(a[x+2][y-2]==a[x+3][y-3]&&a[x+4][y-4]==2))&&a[x+2][y-2]==a[x+5][y-5]&&a[x+1][y-1]==2&&a[x+2][y-2]==1){
	if (x<10&&y>6&&a[x+6][y-6]==2&&a[x+7][y-7]!=0&&a[x+7][y-7]!=1) return 1;
      }
      
    }
    
  }
  
  if (x>5){
    if (a[x-2][y]==a[x-3][y]&&a[x-2][y]==a[x-4][y]&&a[x-1][y]==2&&a[x-5][y]==2&&a[x-2][y]==1){
      if (a[x-6][y]==2) return 1;
      else if (a[x+1][y]!=0&&a[x+1][y]!=1&&a[x-6][y]!=0&&a[x-6][y]!=1) return 1;
    }

    if (((a[x-2][y]==a[x-4][y]&&a[x-3][y]==2)||(a[x-2][y]==a[x-3][y]&&a[x-4][y]==2))&&a[x-2][y]==a[x-5][y]&&a[x-1][y]==2&&a[x-2][y]==1){
      if (x>6&&a[x-6][y]==2&&a[x-7][y]!=0&&a[x-7][y]!=1) return 1;
    }
    
    if (y<11){
      if (a[x-2][y+2]==a[x-3][y+3]&&a[x-2][y+2]==a[x-4][y+4]&&a[x-1][y+1]==2&&a[x-5][y+5]==2&&a[x-2][y+2]==1){
      if (a[x-6][y+6]==2) return 1;
      else if (a[x+1][y-1]!=0&&a[x+1][y-1]!=1&&a[x-6][y+6]!=0&&a[x-6][y+6]!=1) return 1;
      }
      
      if (((a[x-2][y+2]==a[x-4][y+4]&&a[x-3][y+3]==2)||(a[x-2][y+2]==a[x-3][y+3]&&a[x-4][y+4]==2))&&a[x-2][y+2]==a[x-5][y+5]&&a[x-1][y+1]==2&&a[x-2][y+2]==1){
	if (x>6&&y<10&&a[x-6][y+6]==2&&a[x-7][y+7]!=0&&a[x-7][y+7]!=1) return 1;
      }
    }
    
    if (y>5){
      if (a[x-2][y-2]==a[x-3][y-3]&&a[x-2][y-2]==a[x-4][y-4]&&a[x-1][y-1]==2&&a[x-5][y-5]==2&&a[x-2][y-2]==1){
	if (a[x-6][y-6]==2) return 1;
	else if (a[x+1][y+1]!=0&&a[x+1][y+1]!=1&&a[x-6][y-6]!=0&&a[x-6][y-6]!=1) return 1;
      }
      
      if (((a[x-2][y-2]==a[x-4][y-4]&&a[x-3][y-3]==2)||(a[x-2][y-2]==a[x-3][y-3]&&a[x-4][y-4]==2))&&a[x-2][y-2]==a[x-5][y-5]&&a[x-1][y-1]==2&&a[x-2][y-2]==1){
	if (x>6&&y>6&&a[x-6][y-6]==2&&a[x-7][y-7]!=0&&a[x-7][y-7]!=1) return 1;
      }
      
    }
    
  }

  //check horizontal
  
  if (y<11){
    if (a[x][y+2]==a[x][y+3]&&a[x][y+2]==a[x][y+4]&&a[x][y+1]==2&&a[x][y+5]==2&&a[x][y+2]==1){
      if (a[x][y+6]==2) return 1;
      else if (a[x][y-1]!=0&&a[x][y-1]!=1&&a[x][y+6]!=0&&a[x][y+6]!=1) return 1;
    }
    
    if (((a[x][y+2]==a[x][y+4]&&a[x][y+3]==2)||(a[x][y+2]==a[x][y+3]&&a[x][y+4]==2))&&a[x][y+2]==a[x][y+5]&&a[x][y+1]==2&&a[x][y+2]==1){
      if (y<10&&a[x][y+6]==2&&a[x][y+7]!=0&&a[x][y+7]!=1) return 1;
    }
  }

  if (y>5){
    if (a[x][y-2]==a[x][y-3]&&a[x][y-2]==a[x][y-4]&&a[x][y-1]==2&&a[x][y-5]==2&&a[x][y-2]==1){
      if (a[x][y-6]==2) return 1;
      else if (a[x][y+1]!=0&&a[x][y+1]!=1&&a[x][y-6]!=0&&a[x][y-6]!=1) return 1;
    }

    if (((a[x][y-2]==a[x][y-4]&&a[x][y-3]==2)||(a[x][y-2]==a[x][y-3]&&a[x][y-4]==2))&&a[x][y-2]==a[x][y-5]&&a[x][y-1]==2&&a[x][y-2]==1){
      if (y>6&&a[x][y-6]==2&&a[x][y-7]!=0&&a[x][y-7]!=1) return 1;
    }
    
  }

  return 0;
}

int check_threat_three(int x,int y,int m,int a[m][m]){

  //check 3
  if (x>1&&x<12){
    if (a[x+1][y]==a[x+2][y]&&a[x+1][y]==a[x+3][y]&&a[x+4][y]==2&&a[x-1][y]==2&&a[x+1][y]==1&&a[x-2][y]!=1&&a[x-2][y]!=0&&a[x+5][y]!=1&&a[x+5][y]!=0) return 1;
    if (y>1&&y<12){
      if (a[x+1][y+1]==a[x+2][y+2]&&a[x+1][y+1]==a[x+3][y+3]&&a[x+4][y+4]==2&&a[x-1][y-1]==2&&a[x+1][y+1]==1&&a[x-2][y-2]!=1&&a[x-2][y-2]!=0&&a[x+5][y+5]!=1&&a[x+5][y+5]!=0) return 1;
    }
    if (y>4&&y<15){
      if (a[x+1][y-1]==a[x+2][y-2]&&a[x+1][y-1]==a[x+3][y-3]&&a[x+4][y-4]==2&&a[x-1][y+1]==2&&a[x+1][y-1]==1&&a[x-2][y+2]!=1&&a[x-2][y+2]!=0&&a[x+5][y-5]!=1&&a[x+5][y-5]!=0) return 1;
    }
    
  }

  if (x>4&&x<15){
    if (a[x-1][y]==a[x-2][y]&&a[x-1][y]==a[x-3][y]&&a[x-4][y]==2&&a[x+1][y]==2&&a[x-1][y]==1&&a[x+2][y]!=1&&a[x+2][y]!=0&&a[x-5][y]!=1&&a[x-5][y]!=0) return 1;
    if (y>1&&y<12){
      if (a[x-1][y+1]==a[x-2][y+2]&&a[x-1][y+1]==a[x-3][y+3]&&a[x-4][y+4]==2&&a[x+1][y-1]==2&&a[x-1][y+1]==1&&a[x+2][y-2]!=1&&a[x+2][y-2]!=0&&a[x-5][y+5]!=1&&a[x-5][y+5]!=0) return 1;
    }
    if (y>4&&y<15){
      if (a[x-1][y-1]==a[x-2][y-2]&&a[x-1][y-1]==a[x-3][y-3]&&a[x-4][y-4]==2&&a[x+1][y+1]==2&&a[x-1][y-1]==1&&a[x+2][y+2]!=1&&a[x+2][y+2]!=0&&a[x-5][y-5]!=1&&a[x-5][y-5]!=0) return 1;
    }
    
  }
  
  //check 1+2

  if (x>2&&x<13){
    if (a[x-1][y]==a[x+1][y]&&a[x-1][y]==a[x+2][y]&&a[x+3][y]==2&&a[x-2][y]==2&&a[x-1][y]==1&&a[x-3][y]!=1&&a[x-3][y]!=0&&a[x+4][y]!=1&&a[x+4][y]!=0) return 1;
    if (y>2&&y<13){
      if (a[x-1][y-1]==a[x+1][y+1]&&a[x-1][y-1]==a[x+2][y+2]&&a[x+3][y+3]==2&&a[x-2][y-2]==2&&a[x-1][y-1]==1&&a[x-3][y-3]!=1&&a[x-3][y-3]!=0&&a[x+4][y+4]!=1&&a[x+4][y+4]!=0) return 1;
    }
    if (y>3&&y<14){
      if (a[x-1][y+1]==a[x+1][y-1]&&a[x-1][y+1]==a[x+2][y-2]&&a[x+3][y-3]==2&&a[x-2][y+2]==2&&a[x-1][y+1]==1&&a[x-3][y+3]!=1&&a[x-3][y+3]!=0&&a[x+4][y-4]!=1&&a[x+4][y-4]!=0) return 1;
    }

  }
  if (x>3&&x<14){
    if (a[x+1][y]==a[x-1][y]&&a[x+1][y]==a[x-2][y]&&a[x-3][y]==2&&a[x+2][y]==2&&a[x+1][y]==1&&a[x+3][y]!=1&&a[x+3][y]!=0&&a[x-4][y]!=1&&a[x-4][y]!=0) return 1;
    if (y>2&&y<13){
      if (a[x+1][y-1]==a[x-1][y+1]&&a[x+1][y-1]==a[x-2][y+2]&&a[x-3][y+3]==2&&a[x+2][y-2]==2&&a[x+1][y-1]==1&&a[x+3][y-3]!=1&&a[x+3][y-3]!=0&&a[x-4][y+4]!=1&&a[x-4][y+4]!=0) return 1;
    }
    if (y>3&&y<14){
      if (a[x+1][y+1]==a[x-1][y-1]&&a[x+1][y+1]==a[x-2][y-2]&&a[x-3][y-3]==2&&a[x+2][y+2]==2&&a[x+1][y+1]==1&&a[x+3][y+3]!=1&&a[x+3][y+3]!=0&&a[x-4][y-4]!=1&&a[x-4][y-4]!=0) return 1;
    }
    
  }
  
  if (y>1&&y<12){
    //check 3
    if (a[x][y+1]==a[x][y+2]&&a[x][y+1]==a[x][y+3]&&a[x][y+4]==2&&a[x][y-1]==2&&a[x][y+1]==1&&a[x][y-2]!=1&&a[x][y-2]!=0&&a[x][y+5]!=1&&a[x][y+5]!=0) return 1;
  }
  if (y>2&&y<13){
    //check 1+2
    if (a[x][y-1]==a[x][y+1]&&a[x][y-1]==a[x][y+2]&&a[x][y+3]==2&&a[x][y-2]==2&&a[x][y-1]==1&&a[x][y-3]!=1&&a[x][y-3]!=0&&a[x][y+4]!=1&&a[x][y+4]!=0) return 1;
  }
  if (y>4&&y<15){
    //check 3
    if (a[x][y-1]==a[x][y-2]&&a[x][y-1]==a[x][y-3]&&a[x][y-4]==2&&a[x][y+1]==2&&a[x][y-1]==1&&a[x][y+1]!=1&&a[x][y+1]!=0&&a[x][y-5]!=1&&a[x][y-5]!=0) return 1;
  }
  if (y>3&&y<14){
    //check 1+2
    if (a[x][y+1]==a[x][y-1]&&a[x][y+1]==a[x][y-2]&&a[x][y-3]==2&&a[x][y+2]==2&&a[x][y+1]==1&&a[x][y+3]!=1&&a[x][y+3]!=0&&a[x][y-4]!=1&&a[x][y-4]!=0) return 1;
  }
  
  return 0;
}

int check_chance_two_vertical(int x,int y,int m,int a[m][m]){

  if (x>1&&x<15){

    //discrete 2 side x-x
    if (a[x-1][y]==a[x+1][y]&&a[x-2][y]==2&&a[x+2][y]==2&&a[x-1][y]==0){
      if (x<13&&a[x+3][y]==2&&a[x-3][y]!=1&&a[x+4][y]!=1&&a[x-3][y]!=0&&a[x+4][y]!=0) return 1;
      else if (x>3&&a[x-3][y]==2&&a[x+3][y]!=1&&a[x-4][y]!=1&&a[x+3][y]!=0&&a[x-4][y]!=0) return 1;
    }

    if (x<13){
      
      //continuous
      if (a[x+1][y]==a[x+2][y]&&a[x-1][y]==2&&a[x+3][y]==2&&a[x+1][y]==0){
	if (x>2&&a[x-2][y]==2&&a[x-3][y]!=1&&a[x+4][y]!=1&&a[x-3][y]!=0&&a[x+4][y]!=0) return 1;
	else if (x<12&&a[x+4][y]==2&&a[x-2][y]!=1&&a[x+5][y]!=1&&a[x-2][y]!=0&&a[x+5][y]!=0) return 1;
      }
      
      //far continuous + discrete
      if (((a[x+2][y]==a[x+3][y]&&a[x+1][y]==2)||(a[x+1][y]==a[x+3][y]&&a[x+2][y]==2))&&a[x-1][y]==2&&a[x+4][y]==2&&a[x+3][y]==0){
	if (x<12&&a[x-2][y]!=1&&a[x+5][y]!=1&&a[x-2][y]!=0&&a[x+5][y]!=0) return 1;
      }

      //discrete 2 side x--x
      if (a[x-1][y]==a[x+2][y]&&a[x-2][y]==2&&a[x+1][y]==2&&a[x+3][y]==2&&a[x-1][y]==0){
	if (x>2&&a[x-3][y]!=1&&a[x+4][y]!=1&&a[x-3][y]!=0&&a[x+4][y]!=0) return 1;
      }
      
    }

    if (x>3){
      

      //continuous
      if (a[x-1][y]==a[x-2][y]&&a[x+1][y]==2&&a[x-3][y]==2&&a[x-1][y]==0){
	if (x<14&&a[x+2][y]==2&&a[x+3][y]!=1&&a[x-4][y]!=1&&a[x+3][y]!=0&&a[x-4][y]!=0) return 1;
	else if (x>4&&a[x-4][y]==2&&a[x+2][y]!=1&&a[x-5][y]!=1&&a[x+2][y]!=0&&a[x-5][y]!=0) return 1;
      }
      
      //far continuous + discrete
      if (((a[x-2][y]==a[x-3][y]&&a[x-1][y]==2)||(a[x-1][y]==a[x-3][y]&&a[x-2][y]==2))&&a[x+1][y]==2&&a[x-4][y]==2&&a[x-3][y]==0){
	if (x>4&&a[x+2][y]!=1&&a[x-5][y]!=1&&a[x+2][y]!=0&&a[x-5][y]!=0) return 1;
      }
      
      //discrete 2 side x--x
      if (a[x+1][y]==a[x-2][y]&&a[x+2][y]==2&&a[x-1][y]==2&&a[x-3][y]==2&&a[x+1][y]==0){
	if (x<14&&a[x+3][y]!=1&&a[x-4][y]!=1&&a[x+3][y]!=0&&a[x-4][y]!=0) return 1;
      }
      
    }
    
  }
  
  return 0;
}

int check_threat_two_vertical(int x,int y,int m,int a[m][m]){

  if (x>1&&x<15){

    //discrete 2 side x-x
    if (a[x-1][y]==a[x+1][y]&&a[x-2][y]==2&&a[x+2][y]==2&&a[x-1][y]==1){
      if (x<13&&a[x+3][y]==2&&a[x-3][y]!=0&&a[x+4][y]!=0&&a[x-3][y]!=1&&a[x+4][y]!=1) return 1;
      else if (x>3&&a[x-3][y]==2&&a[x+3][y]!=0&&a[x-4][y]!=0&&a[x+3][y]!=1&&a[x-4][y]!=1) return 1;
    }

    if (x<13){
      
      //continuous
      if (a[x+1][y]==a[x+2][y]&&a[x-1][y]==2&&a[x+3][y]==2&&a[x+1][y]==1){
	if (x>2&&a[x-2][y]==2&&a[x-3][y]!=0&&a[x+4][y]!=0&&a[x-3][y]!=1&&a[x+4][y]!=1) return 1;
	else if (x<12&&a[x+4][y]==2&&a[x-2][y]!=0&&a[x+5][y]!=0&&a[x-2][y]!=1&&a[x+5][y]!=1) return 1;
      }
      
      //far continuous + discrete
      if (((a[x+2][y]==a[x+3][y]&&a[x+1][y]==2)||(a[x+1][y]==a[x+3][y]&&a[x+2][y]==2))&&a[x-1][y]==2&&a[x+4][y]==2&&a[x+3][y]==1){
	if (x<12&&a[x-2][y]!=0&&a[x+5][y]!=0&&a[x-2][y]!=1&&a[x+5][y]!=1) return 1;
      }

      //discrete 2 side x--x
      if (a[x-1][y]==a[x+2][y]&&a[x-2][y]==2&&a[x+1][y]==2&&a[x+3][y]==2&&a[x-1][y]==1){
	if (x>2&&a[x-3][y]!=0&&a[x+4][y]!=0&&a[x-3][y]!=1&&a[x+4][y]!=1) return 1;
      }
      
    }

    if (x>3){
      
      //continuous
      if (a[x-1][y]==a[x-2][y]&&a[x+1][y]==2&&a[x-3][y]==2&&a[x-1][y]==1){
	if (x<14&&a[x+2][y]==2&&a[x+3][y]!=0&&a[x-4][y]!=0&&a[x+3][y]!=1&&a[x-4][y]!=1) return 1;
	else if (x>4&&a[x-4][y]==2&&a[x+2][y]!=0&&a[x-5][y]!=0&&a[x+2][y]!=1&&a[x-5][y]!=1) return 1;
      }
      
      //far continuous + discrete
      if (((a[x-2][y]==a[x-3][y]&&a[x-1][y]==2)||(a[x-1][y]==a[x-3][y]&&a[x-2][y]==2))&&a[x+1][y]==2&&a[x-4][y]==2&&a[x-3][y]==1){
	if (x>4&&a[x+2][y]!=0&&a[x-5][y]!=0&&a[x+2][y]!=1&&a[x-5][y]!=1) return 1;
      }
      
      //discrete 2 side x--x
      if (a[x+1][y]==a[x-2][y]&&a[x+2][y]==2&&a[x-1][y]==2&&a[x-3][y]==2&&a[x+1][y]==1){
	if (x<14&&a[x+3][y]!=0&&a[x-4][y]!=0&&a[x+3][y]!=1&&a[x-4][y]!=1) return 1;
      }
      
    }
    
  }
  
  return 0;
}

int check_chance_two_horizontal(int x,int y,int m,int a[m][m]){

  if (y>1&&y<15){

    //discrete 2 side x-x
    if (a[x][y-1]==a[x][y+1]&&a[x][y-2]==2&&a[x][y+2]==2&&a[x][y-1]==0){
      if (y<13&&a[x][y+3]==2&&a[x][y-3]!=1&&a[x][y+4]!=1&&a[x][y-3]!=0&&a[x][y+4]!=0) return 1;
      else if (y>3&&a[x][y-3]==2&&a[x][y+3]!=1&&a[x][y-4]!=1&&a[x][y+3]!=0&&a[x][y-4]!=0) return 1;
    }

    if (y<13){
      
      //continuous
      if (a[x][y+1]==a[x][y+2]&&a[x][y-1]==2&&a[x][y+3]==2&&a[x][y+1]==0){
	if (y>2&&a[x][y-2]==2&&a[x][y-3]!=1&&a[x][y+4]!=1&&a[x][y-3]!=0&&a[x][y+4]!=0) return 1;
	else if (y<12&&a[x][y+4]==2&&a[x][y-2]!=1&&a[x][y+5]!=1&&a[x][y-2]!=0&&a[x][y+5]!=0) return 1;
      }
      
      //far continuous + discrete
      if (((a[x][y+2]==a[x][y+3]&&a[x][y+1]==2)||(a[x][y+1]==a[x][y+3]&&a[x][y+2]==2))&&a[x][y-1]==2&&a[x][y+4]==2&&a[x][y+3]==0){
	if (y<12&&a[x][y-2]!=1&&a[x][y+5]!=1&&a[x][y-2]!=0&&a[x][y+5]!=0) return 1;
      }

      //discrete 2 side x--x
      if (a[x][y-1]==a[x][y+2]&&a[x][y-2]==2&&a[x][y+1]==2&&a[x][y+3]==2&&a[x][y-1]==0){
	if (y>2&&a[x][y-3]!=1&&a[x][y+4]!=1&&a[x][y-3]!=0&&a[x][y+4]!=0) return 1;
      }
      
    }

    if (y>3){
      
      //continuous
      if (a[x][y-1]==a[x][y-2]&&a[x][y+1]==2&&a[x][y-3]==2&&a[x][y-1]==0){
	if (y<14&&a[x][y+2]==2&&a[x][y+3]!=1&&a[x][y-4]!=1&&a[x][y+3]!=0&&a[x][y-4]!=0) return 1;
	else if (y>4&&a[x][y-4]==2&&a[x][y+2]!=1&&a[x][y-5]!=1&&a[x][y+2]!=0&&a[x][y-5]!=0) return 1;
      }
      
      //far continuous + discrete
      if (((a[x][y-2]==a[x][y-3]&&a[x][y-1]==2)||(a[x][y-1]==a[x][y-3]&&a[x][y-2]==2))&&a[x][y+1]==2&&a[x][y-4]==2&&a[x][y-3]==0){
	if (y>4&&a[x][y+2]!=1&&a[x][y-5]!=1&&a[x][y+2]!=0&&a[x][y-5]!=0) return 1;
      }
      
      //discrete 2 side x--x
      if (a[x][y+1]==a[x][y-2]&&a[x][y+2]==2&&a[x][y-1]==2&&a[x][y-3]==2&&a[x][y+1]==0){
	if (y<14&&a[x][y+3]!=1&&a[x][y-4]!=1&&a[x][y+3]!=0&&a[x][y-4]!=0) return 1;
      }
      
    }
    
  }
  
  return 0;
}

int check_threat_two_horizontal(int x,int y,int m,int a[m][m]){

  if (y>1&&y<15){

    //discrete 2 side x-x
    if (a[x][y-1]==a[x][y+1]&&a[x][y-2]==2&&a[x][y+2]==2&&a[x][y-1]==1){
      if (y<13&&a[x][y+3]==2&&a[x][y-3]!=0&&a[x][y+4]!=0&&a[x][y-3]!=1&&a[x][y+4]!=1) return 1;
      else if (y>3&&a[x][y-3]==2&&a[x][y+3]!=0&&a[x][y-4]!=0&&a[x][y+3]!=1&&a[x][y-4]!=1) return 1;
    }

    if (y<13){
      
      //continuous
      if (a[x][y+1]==a[x][y+2]&&a[x][y-1]==2&&a[x][y+3]==2&&a[x][y+1]==1){
	if (y>2&&a[x][y-2]==2&&a[x][y-3]!=0&&a[x][y+4]!=0&&a[x][y-3]!=1&&a[x][y+4]!=1) return 1;
	else if (y<12&&a[x][y+4]==2&&a[x][y-2]!=0&&a[x][y+5]!=0&&a[x][y-2]!=1&&a[x][y+5]!=1) return 1;
      }
      
      //far continuous + discrete
      if (((a[x][y+2]==a[x][y+3]&&a[x][y+1]==2)||(a[x][y+1]==a[x][y+3]&&a[x][y+2]==2))&&a[x][y-1]==2&&a[x][y+4]==2&&a[x][y+3]==1){
	if (y<12&&a[x][y-2]!=0&&a[x][y+5]!=0&&a[x][y-2]!=1&&a[x][y+5]!=1) return 1;
      }

      //discrete 2 side x--x
      if (a[x][y-1]==a[x][y+2]&&a[x][y-2]==2&&a[x][y+1]==2&&a[x][y+3]==2&&a[x][y-1]==1){
	if (y>2&&a[x][y-3]!=0&&a[x][y+4]!=0&&a[x][y-3]!=1&&a[x][y+4]!=1) return 1;
      }
      
    }

    if (y>3){
      
      //continuous
      if (a[x][y-1]==a[x][y-2]&&a[x][y+1]==2&&a[x][y-3]==2&&a[x][y-1]==1){
	if (y<14&&a[x][y+2]==2&&a[x][y+3]!=0&&a[x][y-4]!=0&&a[x][y+3]!=1&&a[x][y-4]!=1) return 1;
	else if (y>4&&a[x][y-4]==2&&a[x][y+2]!=0&&a[x][y-5]!=0&&a[x][y+2]!=1&&a[x][y-5]!=1) return 1;
      }
      
      //far continuous + discrete
      if (((a[x][y-2]==a[x][y-3]&&a[x][y-1]==2)||(a[x][y-1]==a[x][y-3]&&a[x][y-2]==2))&&a[x][y+1]==2&&a[x][y-4]==2&&a[x][y-3]==1){
	if (y>4&&a[x][y+2]!=0&&a[x][y-5]!=0&&a[x][y+2]!=1&&a[x][y-5]!=1) return 1;
      }
      
      //discrete 2 side x--x
      if (a[x][y+1]==a[x][y-2]&&a[x][y+2]==2&&a[x][y-1]==2&&a[x][y-3]==2&&a[x][y+1]==1){
	if (y<14&&a[x][y+3]!=0&&a[x][y-4]!=0&&a[x][y+3]!=1&&a[x][y-4]!=1) return 1;
      }
      
    }
    
  }
  
  return 0;
}

int check_chance_two_diagonal1(int x,int y,int m,int a[m][m]){

  if (x>1&&x<15&&y>1&&y<15){

    //discrete 2 side x-x
    if (a[x-1][y-1]==a[x+1][y+1]&&a[x-2][y-2]==2&&a[x+2][y+2]==2&&a[x-1][y-1]==0){
      if (x<13&&y<13&&a[x+3][y+3]==2&&a[x-3][y-3]!=1&&a[x+4][y+4]!=1&&a[x-3][y-3]!=0&&a[x+4][y+4]!=0) return 1;
      else if (x>3&&y>3&&a[x-3][y-3]==2&&a[x+3][y+3]!=1&&a[x-4][y-4]!=1&&a[x+3][y+3]!=0&&a[x-4][y-4]!=0) return 1;
    }

    if (x<13&&y<13){
      
      //continuous
      if (a[x+1][y+1]==a[x+2][y+2]&&a[x-1][y-1]==2&&a[x+3][y+3]==2&&a[x+1][y+1]==0){
	if (x>2&&y>2&&a[x-2][y-2]==2&&a[x-3][y-3]!=1&&a[x+4][y+4]!=1&&a[x-3][y-3]!=0&&a[x+4][y+4]!=0) return 1;
	else if (x<12&&y<12&&a[x+4][y+4]==2&&a[x-2][y-2]!=1&&a[x+5][y+5]!=1&&a[x-2][y-2]!=0&&a[x+5][y+5]!=0) return 1;
      }
      
      //far continuous + discrete
      if (((a[x+2][y+2]==a[x+3][y+3]&&a[x+1][y+1]==2)||(a[x+1][y+1]==a[x+3][y+3]&&a[x+2][y+2]==2))&&a[x-1][y-1]==2&&a[x+4][y+4]==2&&a[x+3][y+3]==0){
	if (x<12&&y<12&&a[x-2][y-2]!=1&&a[x+5][y+5]!=1&&a[x-2][y-2]!=0&&a[x+5][y+5]!=0) return 1;
      }

      //discrete 2 side x--x
      if (a[x-1][y-1]==a[x+2][y+2]&&a[x-2][y-2]==2&&a[x+1][y+1]==2&&a[x+3][y+3]==2&&a[x-1][y-1]==0){
	if (x>2&&y>2&&a[x-3][y-3]!=1&&a[x+4][y+4]!=1&&a[x-3][y-3]!=0&&a[x+4][y+4]!=0) return 1;
      }
      
    }

    if (x>3&&y>3){
      
      //continuous
      if (a[x-1][y-1]==a[x-2][y-2]&&a[x+1][y+1]==2&&a[x-3][y-3]==2&&a[x-1][y-1]==0){
	if (x<14&&y<14&&a[x+2][y+2]==2&&a[x+3][y+3]!=1&&a[x-4][y-4]!=1&&a[x+3][y+3]!=0&&a[x-4][y-4]!=0) return 1;
	else if (x>4&&y>4&&a[x-4][y-4]==2&&a[x+2][y+2]!=1&&a[x-5][y-5]!=1&&a[x+2][y+2]!=0&&a[x-5][y-5]!=0) return 1;
      }
      
      //far continuous + discrete
      if (((a[x-2][y-2]==a[x-3][y-3]&&a[x-1][y-1]==2)||(a[x-1][y-1]==a[x-3][y-3]&&a[x-2][y-2]==2))&&a[x+1][y+1]==2&&a[x-4][y-4]==2&&a[x-3][y-3]==0){
	if (x>4&&y>4&&a[x+2][y+2]!=1&&a[x-5][y-5]!=1&&a[x+2][y+2]!=0&&a[x-5][y-5]!=0) return 1;
      }
      
      //discrete 2 side x--x
      if (a[x+1][y+1]==a[x-2][y-2]&&a[x+2][y+2]==2&&a[x-1][y-1]==2&&a[x-3][y-3]==2&&a[x+1][y+1]==0){
	if (x<14&&y<14&&a[x+3][y+3]!=1&&a[x-4][y-4]!=1&&a[x+3][y+3]!=0&&a[x-4][y-4]!=0) return 1;
      }
      
    }
    
  }
  
  return 0;
}

int check_threat_two_diagonal1(int x,int y,int m,int a[m][m]){

  if (x>1&&x<15&&y>1&&y<15){

    //discrete 2 side x-x
    if (a[x-1][y-1]==a[x+1][y+1]&&a[x-2][y-2]==2&&a[x+2][y+2]==2&&a[x-1][y-1]==1){
      if (x<13&&y<13&&a[x+3][y+3]==2&&a[x-3][y-3]!=0&&a[x+4][y+4]!=0&&a[x-3][y-3]!=1&&a[x+4][y+4]!=1) return 1;
      else if (x>3&&y>3&&a[x-3][y-3]==2&&a[x+3][y+3]!=0&&a[x-4][y-4]!=0&&a[x+3][y+3]!=1&&a[x-4][y-4]!=1) return 1;
    }

    if (x<13&&y<13){
      
      //continuous
      if (a[x+1][y+1]==a[x+2][y+2]&&a[x-1][y-1]==2&&a[x+3][y+3]==2&&a[x+1][y+1]==1){
	if (x>2&&y>2&&a[x-2][y-2]==2&&a[x-3][y-3]!=0&&a[x+4][y+4]!=0&&a[x-3][y-3]!=1&&a[x+4][y+4]!=1) return 1;
	else if (x<12&&y<12&&a[x+4][y+4]==2&&a[x-2][y-2]!=0&&a[x+5][y+5]!=0&&a[x-2][y-2]!=1&&a[x+5][y+5]!=1) return 1;
      }
      
      //far continuous + discrete
      if (((a[x+2][y+2]==a[x+3][y+3]&&a[x+1][y+1]==2)||(a[x+1][y+1]==a[x+3][y+3]&&a[x+2][y+2]==2))&&a[x-1][y-1]==2&&a[x+4][y+4]==2&&a[x+3][y+3]==1){
	if (x<12&&y<12&&a[x-2][y-2]!=0&&a[x+5][y+5]!=0&&a[x-2][y-2]!=1&&a[x+5][y+5]!=1) return 1;
      }

      //discrete 2 side x--x
      if (a[x-1][y-1]==a[x+2][y+2]&&a[x-2][y-2]==2&&a[x+1][y+1]==2&&a[x+3][y+3]==2&&a[x-1][y-1]==1){
	if (x>2&&y>2&&a[x-3][y-3]!=0&&a[x+4][y+4]!=0&&a[x-3][y-3]!=1&&a[x+4][y+4]!=1) return 1;
      }
      
    }

    if (x>3&&y>3){
      
      //continuous
      if (a[x-1][y-1]==a[x-2][y-2]&&a[x+1][y+1]==2&&a[x-3][y-3]==2&&a[x-1][y-1]==1){
	if (x<14&&y<14&&a[x+2][y+2]==2&&a[x+3][y+3]!=0&&a[x-4][y-4]!=0&&a[x+3][y+3]!=1&&a[x-4][y-4]!=1) return 1;
	else if (x>4&&y>4&&a[x-4][y-4]==2&&a[x+2][y+2]!=0&&a[x-5][y-5]!=0&&a[x+2][y+2]!=1&&a[x-5][y-5]!=1) return 1;
      }
      
      //far continuous + discrete
      if (((a[x-2][y-2]==a[x-3][y-3]&&a[x-1][y-1]==2)||(a[x-1][y-1]==a[x-3][y-3]&&a[x-2][y-2]==2))&&a[x+1][y+1]==2&&a[x-4][y-4]==2&&a[x-3][y-3]==1){
	if (x>4&&y>4&&a[x+2][y+2]!=0&&a[x-5][y-5]!=0&&a[x+2][y+2]!=1&&a[x-5][y-5]!=1) return 1;
      }
      
      //discrete 2 side x--x
      if (a[x+1][y+1]==a[x-2][y-2]&&a[x+2][y+2]==2&&a[x-1][y-1]==2&&a[x-3][y-3]==2&&a[x+1][y+1]==1){
	if (x<14&&y<14&&a[x+3][y+3]!=0&&a[x-4][y-4]!=0&&a[x+3][y+3]!=1&&a[x-4][y-4]!=1) return 1;
      }
      
    }
    
  }
  
  return 0;
}

int check_chance_two_diagonal2(int x,int y,int m,int a[m][m]){

  if (x>1&&x<15&&y>1&&y<15){

    //discrete 2 side x-x
    if (a[x+1][y-1]==a[x-1][y+1]&&a[x+2][y-2]==2&&a[x-2][y+2]==2&&a[x+1][y-1]==0){
      if (x>3&&y<13&&a[x-3][y+3]==2&&a[x+3][y-3]!=1&&a[x-4][y+4]!=1&&a[x+3][y-3]!=0&&a[x-4][y+4]!=0) return 1;
      else if (x<13&&y>3&&a[x+3][y-3]==2&&a[x-3][y+3]!=1&&a[x+4][y-4]!=1&&a[x-3][y+3]!=0&&a[x+4][y-4]!=0) return 1;
    }

    if (x>3&&y<13){
      
      //continuous
      if (a[x-1][y+1]==a[x-2][y+2]&&a[x+1][y-1]==2&&a[x-3][y+3]==2&&a[x-1][y+1]==0){
	if (x<14&&y>2&&a[x+2][y-2]==2&&a[x+3][y-3]!=1&&a[x-4][y+4]!=1&&a[x+3][y-3]!=0&&a[x-4][y+4]!=0) return 1;
	else if (x>4&&y<12&&a[x-4][y+4]==2&&a[x+2][y-2]!=1&&a[x-5][y+5]!=1&&a[x+2][y-2]!=0&&a[x-5][y+5]!=0) return 1;
      }
      
      //far continuous + discrete
      if (((a[x-2][y+2]==a[x-3][y+3]&&a[x-1][y+1]==2)||(a[x-1][y+1]==a[x-3][y+3]&&a[x-2][y+2]==2))&&a[x+1][y-1]==2&&a[x-4][y+4]==2&&a[x-3][y+3]==0){
	if (x>4&&y<12&&a[x+2][y-2]!=1&&a[x-5][y+5]!=1&&a[x+2][y-2]!=0&&a[x-5][y+5]!=0) return 1;
      }

      //discrete 2 side x--x
      if (a[x+1][y-1]==a[x-2][y+2]&&a[x+2][y-2]==2&&a[x-1][y+1]==2&&a[x-3][y+3]==2&&a[x+1][y-1]==0){
	if (x<14&&y>2&&a[x+3][y-3]!=1&&a[x-4][y+4]!=1&&a[x+3][y-3]!=0&&a[x-4][y+4]!=0) return 1;
      }
      
    }

    if (x<13&&y>3){
      
      //continuous
      if (a[x+1][y-1]==a[x+2][y-2]&&a[x-1][y+1]==2&&a[x+3][y-3]==2&&a[x+1][y-1]==0){
	if (x>2&&y<14&&a[x-2][y+2]==2&&a[x-3][y+3]!=1&&a[x+4][y-4]!=1&&a[x-3][y+3]!=0&&a[x+4][y-4]!=0) return 1;
	else if (x<12&&y>4&&a[x+4][y-4]==2&&a[x-2][y+2]!=1&&a[x+5][y-5]!=1&&a[x-2][y+2]!=0&&a[x+5][y-5]!=0) return 1;
      }
      
      //far continuous + discrete
      if (((a[x+2][y-2]==a[x+3][y-3]&&a[x+1][y-1]==2)||(a[x+1][y-1]==a[x+3][y-3]&&a[x+2][y-2]==2))&&a[x-1][y+1]==2&&a[x+4][y-4]==2&&a[x+3][y-3]==0){
	if (x<12&&y>4&&a[x-2][y+2]!=1&&a[x+5][y-5]!=1&&a[x-2][y+2]!=0&&a[x+5][y-5]!=0) return 1;
      }
      
      //discrete 2 side x--x
      if (a[x-1][y+1]==a[x+2][y-2]&&a[x-2][y+2]==2&&a[x+1][y-1]==2&&a[x+3][y-3]==2&&a[x-1][y+1]==0){
	if (x>2&&y<14&&a[x-3][y+3]!=1&&a[x+4][y-4]!=1&&a[x-3][y+3]!=0&&a[x+4][y-4]!=0) return 1;
      }
      
    }
    
  }
  
  return 0;
}

int check_threat_two_diagonal2(int x,int y,int m,int a[m][m]){

  if (x>1&&x<15&&y>1&&y<15){

    //discrete 2 side x-x
    if (a[x+1][y-1]==a[x-1][y+1]&&a[x+2][y-2]==2&&a[x-2][y+2]==2&&a[x+1][y-1]==1){
      if (x>3&&y<13&&a[x-3][y+3]==2&&a[x+3][y-3]!=0&&a[x-4][y+4]!=0&&a[x+3][y-3]!=1&&a[x-4][y+4]!=1) return 1;
      else if (x<13&&y>3&&a[x+3][y-3]==2&&a[x-3][y+3]!=0&&a[x+4][y-4]!=0&&a[x-3][y+3]!=1&&a[x+4][y-4]!=1) return 1;
    }

    if (x>3&&y<13){
      
      //continuous
      if (a[x-1][y+1]==a[x-2][y+2]&&a[x+1][y-1]==2&&a[x-3][y+3]==2&&a[x-1][y+1]==1){
	if (x<14&&y>2&&a[x+2][y-2]==2&&a[x+3][y-3]!=0&&a[x-4][y+4]!=0&&a[x+3][y-3]!=1&&a[x-4][y+4]!=1) return 1;
	else if (x>4&&y<12&&a[x-4][y+4]==2&&a[x+2][y-2]!=0&&a[x-5][y+5]!=0&&a[x+2][y-2]!=1&&a[x-5][y+5]!=1) return 1;
      }
      
      //far continuous + discrete
      if (((a[x-2][y+2]==a[x-3][y+3]&&a[x-1][y+1]==2)||(a[x-1][y+1]==a[x-3][y+3]&&a[x-2][y+2]==2))&&a[x+1][y-1]==2&&a[x-4][y+4]==2&&a[x-3][y+3]==1){
	if (x>4&&y<12&&a[x+2][y-2]!=0&&a[x-5][y+5]!=0&&a[x+2][y-2]!=1&&a[x-5][y+5]!=1) return 1;
      }

      //discrete 2 side x--x
      if (a[x+1][y-1]==a[x-2][y+2]&&a[x+2][y-2]==2&&a[x-1][y+1]==2&&a[x-3][y+3]==2&&a[x+1][y-1]==1){
	if (x<14&&y>2&&a[x+3][y-3]!=0&&a[x-4][y+4]!=0&&a[x+3][y-3]!=1&&a[x-4][y+4]!=1) return 1;
      }
      
    }

    if (x<13&&y>3){
      
      //continuous
      if (a[x+1][y-1]==a[x+2][y-2]&&a[x-1][y+1]==2&&a[x+3][y-3]==2&&a[x+1][y-1]==1){
	if (x>2&&y<14&&a[x-2][y+2]==2&&a[x-3][y+3]!=0&&a[x+4][y-4]!=0&&a[x-3][y+3]!=1&&a[x+4][y-4]!=1) return 1;
	else if (x<12&&y>4&&a[x+4][y-4]==2&&a[x-2][y+2]!=0&&a[x+5][y-5]!=0&&a[x-2][y+2]!=1&&a[x+5][y-5]!=1) return 1;
      }
      
      //far continuous + discrete
      if (((a[x+2][y-2]==a[x+3][y-3]&&a[x+1][y-1]==2)||(a[x+1][y-1]==a[x+3][y-3]&&a[x+2][y-2]==2))&&a[x-1][y+1]==2&&a[x+4][y-4]==2&&a[x+3][y-3]==1){
	if (x<12&&y>4&&a[x-2][y+2]!=0&&a[x+5][y-5]!=0&&a[x-2][y+2]!=1&&a[x+5][y-5]!=1) return 1;
      }
      
      //discrete 2 side x--x
      if (a[x-1][y+1]==a[x+2][y-2]&&a[x-2][y+2]==2&&a[x+1][y-1]==2&&a[x+3][y-3]==2&&a[x-1][y+1]==1){
	if (x>2&&y<14&&a[x-3][y+3]!=0&&a[x+4][y-4]!=0&&a[x-3][y+3]!=1&&a[x+4][y-4]!=1) return 1;
      }
      
    }
    
  }
  
  return 0;
}

int check_chance_one_vertical(int x,int y,int m,int a[m][m]){

  if (x>1&&x<13){
    if (a[x+1][y]==0&&a[x+2][y]==2&&a[x-1][y]==2){
      if (x>2&&a[x-2][y]==2&&a[x+3][y]==2&&a[x-3][y]!=1&&a[x+4][y]!=1) return 1;
      else if (x<12&&a[x+3][y]==2&&a[x+4][y]==2&&a[x-2][y]!=1&&a[x+5][y]!=1) return 1;
    }
    
    else if (a[x+2][y]==0&&a[x+1][y]==2&&a[x+3][y]==2&&a[x-1][y]==2) {
      if (x>2&&a[x-2][y]==2&&a[x-3][y]!=1&&a[x+4][y]!=1) return 1;
      else if (x<12&&a[x+4][y]==2&&a[x-2][y]!=1&&a[x+5][y]!=1) return 1;
    }   
  }

  if (x>3&&x<15){
    if (a[x-1][y]==0&&a[x-2][y]==2&&a[x+1][y]==2){
      if (x<14&&a[x+2][y]==2&&a[x-3][y]==2&&a[x+3][y]!=1&&a[x-4][y]!=1) return 1;
      else if (x>4&&a[x-3][y]==2&&a[x-4][y]==2&&a[x+2][y]!=1&&a[x-5][y]!=1) return 1;
    }

    else if (a[x-2][y]==0&&a[x-1][y]==2&&a[x-3][y]==2&&a[x+1][y]==2){
      if (x<14&&a[x+2][y]==2&&a[x+3][y]!=1&&a[x-4][y]!=1) return 1;
      else if (x>4&&a[x-4][y]==2&&a[x+2][y]!=1&&a[x-5][y]!=1) return 1;
    }
  }
  
  return 0;
}

int check_threat_one_vertical(int x,int y,int m,int a[m][m]){

  if (x>1&&x<13){
    if (a[x+1][y]==1&&a[x+2][y]==2&&a[x-1][y]==2){
      if (x>2&&a[x-2][y]==2&&a[x+3][y]==2&&a[x-3][y]!=0&&a[x+4][y]!=0) return 1;
      else if (x<12&&a[x+3][y]==2&&a[x+4][y]==2&&a[x-2][y]!=0&&a[x+5][y]!=0) return 1;
    }
    
    else if (a[x+2][y]==1&&a[x+1][y]==2&&a[x+3][y]==2&&a[x-1][y]==2) {
      if (x>2&&a[x-2][y]==2&&a[x-3][y]!=0&&a[x+4][y]!=0) return 1;
      else if (x<12&&a[x+4][y]==2&&a[x-2][y]!=0&&a[x+5][y]!=0) return 1;
    }   
  }

  if (x>3&&x<15){
    if (a[x-1][y]==1&&a[x-2][y]==2&&a[x+1][y]==2){
      if (x<14&&a[x+2][y]==2&&a[x-3][y]==2&&a[x+3][y]!=0&&a[x-4][y]!=0) return 1;
      else if (x>4&&a[x-3][y]==2&&a[x-4][y]==2&&a[x+2][y]!=0&&a[x-5][y]!=0) return 1;
    }

    else if (a[x-2][y]==1&&a[x-1][y]==2&&a[x-3][y]==2&&a[x+1][y]==2){
      if (x<14&&a[x+2][y]==2&&a[x+3][y]!=0&&a[x-4][y]!=0) return 1;
      else if (x>4&&a[x-4][y]==2&&a[x+2][y]!=0&&a[x-5][y]!=0) return 1;
    }
  }
  
  return 0;
}

int check_chance_one_horizontal(int x,int y,int m,int a[m][m]){

  if (y>1&&y<13){
    if (a[x][y+1]==0&&a[x][y+2]==2&&a[x][y-1]==2){
      if (y>2&&a[x][y-2]==2&&a[x][y+3]==2&&a[x][y-3]!=1&&a[x][y+4]!=1) return 1;
      else if (y<12&&a[x][y+3]==2&&a[x][y+4]==2&&a[x][y-2]!=1&&a[x][y+5]!=1) return 1;
    }
    
    else if (a[x][y+2]==0&&a[x][y+1]==2&&a[x][y+3]==2&&a[x][y-1]==2) {
      if (y>2&&a[x][y-2]==2&&a[x][y-3]!=1&&a[x][y+4]!=1) return 1;
      else if (y<12&&a[x][y+4]==2&&a[x][y-2]!=1&&a[x][y+5]!=1) return 1;
    }   
  }

  if (y>3&&y<15){
    if (a[x][y-1]==0&&a[x][y-2]==2&&a[x][y+1]==2){
      if (y<14&&a[x][y+2]==2&&a[x][y-3]==2&&a[x][y+3]!=1&&a[x][y-4]!=1) return 1;
      else if (y>4&&a[x][y-3]==2&&a[x][y-4]==2&&a[x][y+2]!=1&&a[x][y-5]!=1) return 1;
    }

    else if (a[x][y-2]==0&&a[x][y-1]==2&&a[x][y-3]==2&&a[x][y+1]==2){
      if (y<14&&a[x][y+2]==2&&a[x][y+3]!=1&&a[x][y-4]!=1) return 1;
      else if (y>4&&a[x][y-4]==2&&a[x][y+2]!=1&&a[x][y-5]!=1) return 1;
    }
  }
  
  return 0;
}

int check_threat_one_horizontal(int x,int y,int m,int a[m][m]){

  if (y>1&&y<13){
    if (a[x][y+1]==1&&a[x][y+2]==2&&a[x][y-1]==2){
      if (y>2&&a[x][y-2]==2&&a[x][y+3]==2&&a[x][y-3]!=0&&a[x][y+4]!=0) return 1;
      else if (y<12&&a[x][y+3]==2&&a[x][y+4]==2&&a[x][y-2]!=0&&a[x][y+5]!=0) return 1;
    }
    
    else if (a[x][y+2]==1&&a[x][y+1]==2&&a[x][y+3]==2&&a[x][y-1]==2) {
      if (y>2&&a[x][y-2]==2&&a[x][y-3]!=0&&a[x][y+4]!=0) return 1;
      else if (y<12&&a[x][y+4]==2&&a[x][y-2]!=0&&a[x][y+5]!=0) return 1;
    }   
  }

  if (y>3&&y<15){
    if (a[x][y-1]==1&&a[x][y-2]==2&&a[x][y+1]==2){
      if (y<14&&a[x][y+2]==2&&a[x][y-3]==2&&a[x][y+3]!=0&&a[x][y-4]!=0) return 1;
      else if (y>4&&a[x][y-3]==2&&a[x][y-4]==2&&a[x][y+2]!=0&&a[x][y-5]!=0) return 1;
    }

    else if (a[x][y-2]==1&&a[x][y-1]==2&&a[x][y-3]==2&&a[x][y+1]==2){
      if (y<14&&a[x][y+2]==2&&a[x][y+3]!=0&&a[x][y-4]!=0) return 1;
      else if (y>4&&a[x][y-4]==2&&a[x][y+2]!=0&&a[x][y-5]!=0) return 1;
    }
  }
  
  return 0;
}

int check_chance_one_diagonal1(int x,int y,int m,int a[m][m]){

  if (x>1&&x<13&&y>1&&y<13){
    if (a[x+1][y+1]==0&&a[x+2][y+2]==2&&a[x-1][y-1]==2){
      if (x>2&&y>2&&a[x-2][y-2]==2&&a[x+3][y+3]==2&&a[x-3][y-3]!=1&&a[x+4][y+4]!=1) return 1;
      else if (x<12&&y<12&&a[x+3][y+3]==2&&a[x+4][y+4]==2&&a[x-2][y-2]!=1&&a[x+5][y+5]!=1) return 1;
    }
    
    else if (a[x+2][y+2]==0&&a[x+1][y+1]==2&&a[x+3][y+3]==2&&a[x-1][y-1]==2) {
      if (x>2&&y>2&&a[x-2][y-2]==2&&a[x-3][y-3]!=1&&a[x+4][y+4]!=1) return 1;
      else if (x<12&&y<12&&a[x+4][y+4]==2&&a[x-2][y-2]!=1&&a[x+5][y+5]!=1) return 1;
    }   
  }

  if (x>3&&x<15&&y>3&&y<15){
    if (a[x-1][y-1]==0&&a[x-2][y-2]==2&&a[x+1][y+1]==2){
      if (x<14&&y<14&&a[x+2][y+2]==2&&a[x-3][y-3]==2&&a[x+3][y+3]!=1&&a[x-4][y-4]!=1) return 1;
      else if (x>4&&y>4&&a[x-3][y-3]==2&&a[x-4][y-4]==2&&a[x+2][y+2]!=1&&a[x-5][y-5]!=1) return 1;
    }

    else if (a[x-2][y-2]==0&&a[x-1][y-1]==2&&a[x-3][y-3]==2&&a[x+1][y+1]==2){
      if (x<14&&y<14&&a[x+2][y+2]==2&&a[x+3][y+3]!=1&&a[x-4][y-4]!=1) return 1;
      else if (x>4&&y>4&&a[x-4][y-4]==2&&a[x+2][y+2]!=1&&a[x-5][y-5]!=1) return 1;
    }
  }
  
  return 0;
}

int check_threat_one_diagonal1(int x,int y,int m,int a[m][m]){

  if (x>1&&x<13&&y>1&&y<13){
    if (a[x+1][y+1]==1&&a[x+2][y+2]==2&&a[x-1][y-1]==2){
      if (x>2&&y>2&&a[x-2][y-2]==2&&a[x+3][y+3]==2&&a[x-3][y-3]!=0&&a[x+4][y+4]!=0) return 1;
      else if (x<12&&y<12&&a[x+3][y+3]==2&&a[x+4][y+4]==2&&a[x-2][y-2]!=0&&a[x+5][y+5]!=0) return 1;
    }
    
    else if (a[x+2][y+2]==1&&a[x+1][y+1]==2&&a[x+3][y+3]==2&&a[x-1][y-1]==2) {
      if (x>2&&y>2&&a[x-2][y-2]==2&&a[x-3][y-3]!=0&&a[x+4][y+4]!=0) return 1;
      else if (x<12&&y<12&&a[x+4][y+4]==2&&a[x-2][y-2]!=0&&a[x+5][y+5]!=0) return 1;
    }   
  }

  if (x>3&&x<15&&y>3&&y<15){
    if (a[x-1][y-1]==1&&a[x-2][y-2]==2&&a[x+1][y+1]==2){
      if (x<14&&y<14&&a[x+2][y+2]==2&&a[x-3][y-3]==2&&a[x+3][y+3]!=0&&a[x-4][y-4]!=0) return 1;
      else if (x>4&&y>4&&a[x-3][y-3]==2&&a[x-4][y-4]==2&&a[x+2][y+2]!=0&&a[x-5][y-5]!=0) return 1;
    }

    else if (a[x-2][y-2]==1&&a[x-1][y-1]==2&&a[x-3][y-3]==2&&a[x+1][y+1]==2){
      if (x<14&&y<14&&a[x+2][y+2]==2&&a[x+3][y+3]!=0&&a[x-4][y-4]!=0) return 1;
      else if (x>4&&y>4&&a[x-4][y-4]==2&&a[x+2][y+2]!=0&&a[x-5][y-5]!=0) return 1;
    }
  }
  
  return 0;
}

int check_chance_one_diagonal2(int x,int y,int m,int a[m][m]){

  if (x>3&&x<15&&y>1&&y<13){
    if (a[x-1][y+1]==0&&a[x-2][y+2]==2&&a[x+1][y-1]==2){
      if (x<14&&y>2&&a[x+2][y-2]==2&&a[x-3][y+3]==2&&a[x+3][y-3]!=1&&a[x-4][y+4]!=1) return 1;
      else if (x>4&&y<12&&a[x-3][y+3]==2&&a[x-4][y+4]==2&&a[x+2][y-2]!=1&&a[x-5][y+5]!=1) return 1;
    }
    
    else if (a[x-2][y+2]==0&&a[x-1][y+1]==2&&a[x-3][y+3]==2&&a[x+1][y-1]==2) {
      if (x<14&&y>2&&a[x+2][y-2]==2&&a[x+3][y-3]!=1&&a[x-4][y+4]!=1) return 1;
      else if (x>4&&y<12&&a[x-4][y+4]==2&&a[x+2][y-2]!=1&&a[x-5][y+5]!=1) return 1;
    }   
  }

  if (x>1&&x<13&&y>3&&y<15){
    if (a[x+1][y-1]==0&&a[x+2][y-2]==2&&a[x-1][y+1]==2){
      if (x>2&&y<14&&a[x-2][y+2]==2&&a[x+3][y-3]==2&&a[x-3][y+3]!=1&&a[x+4][y-4]!=1) return 1;
      else if (x<12&&y>4&&a[x+3][y-3]==2&&a[x+4][y-4]==2&&a[x-2][y+2]!=1&&a[x+5][y-5]!=1) return 1;
    }

    else if (a[x+2][y-2]==0&&a[x+1][y-1]==2&&a[x+3][y-3]==2&&a[x-1][y+1]==2){
      if (x>2&&y<14&&a[x-2][y+2]==2&&a[x-3][y+3]!=1&&a[x+4][y-4]!=1) return 1;
      else if (x<12&&y>4&&a[x+4][y-4]==2&&a[x-2][y+2]!=1&&a[x+5][y-5]!=1) return 1;
    }
  }
  
  return 0;
}

int check_threat_one_diagonal2(int x,int y,int m,int a[m][m]){

  if (x>3&&x<15&&y>1&&y<13){
    if (a[x-1][y+1]==1&&a[x-2][y+2]==2&&a[x+1][y-1]==2){
      if (x<14&&y>2&&a[x+2][y-2]==2&&a[x-3][y+3]==2&&a[x+3][y-3]!=0&&a[x-4][y+4]!=0) return 1;
      else if (x>4&&y<12&&a[x-3][y+3]==2&&a[x-4][y+4]==2&&a[x+2][y-2]!=0&&a[x-5][y+5]!=0) return 1;
    }
    
    else if (a[x-2][y+2]==1&&a[x-1][y+1]==2&&a[x-3][y+3]==2&&a[x+1][y-1]==2) {
      if (x<14&&y>2&&a[x+2][y-2]==2&&a[x+3][y-3]!=0&&a[x-4][y+4]!=0) return 1;
      else if (x>4&&y<12&&a[x-4][y+4]==2&&a[x+2][y-2]!=0&&a[x-5][y+5]!=0) return 1;
    }   
  }

  if (x>1&&x<13&&y>3&&y<15){
    if (a[x+1][y-1]==1&&a[x+2][y-2]==2&&a[x-1][y+1]==2){
      if (x>2&&y<14&&a[x-2][y+2]==2&&a[x+3][y-3]==2&&a[x-3][y+3]!=0&&a[x+4][y-4]!=0) return 1;
      else if (x<12&&y>4&&a[x+3][y-3]==2&&a[x+4][y-4]==2&&a[x-2][y+2]!=0&&a[x+5][y-5]!=0) return 1;
    }

    else if (a[x+2][y-2]==1&&a[x+1][y-1]==2&&a[x+3][y-3]==2&&a[x-1][y+1]==2){
      if (x>2&&y<14&&a[x-2][y+2]==2&&a[x-3][y+3]!=0&&a[x+4][y-4]!=0) return 1;
      else if (x<12&&y>4&&a[x+4][y-4]==2&&a[x-2][y+2]!=0&&a[x+5][y-5]!=0) return 1;
    }
  }
  
  return 0;
}
