#include "caro_check.h"

int choose_x=7;
int choose_y=7;

int check_chance_double_three(int x, int y,int m,int a[m][m]){
  if (
    (check_chance_three_vertical(x,y,m,a)==1&&check_chance_three_horizontal(x,y,m,a)==1)||
    (check_chance_three_vertical(x,y,m,a)==1&&check_chance_three_diagonal1(x,y,m,a)==1)||
    (check_chance_three_vertical(x,y,m,a)==1&&check_chance_three_diagonal2(x,y,m,a)==1)||
    (check_chance_three_horizontal(x,y,m,a)==1&&check_chance_three_diagonal1(x,y,m,a)==1)||
    (check_chance_three_horizontal(x,y,m,a)==1&&check_chance_three_diagonal2(x,y,m,a)==1)||
    (check_chance_three_diagonal1(x,y,m,a)==1&&check_chance_three_diagonal2(x,y,m,a)==1)	    
  ) return 1;

  return 0;
}

int check_threat_double_three(int x,int y,int m,int a[m][m]){
  if (
    (check_threat_three_vertical(x,y,m,a)==1&&check_threat_three_horizontal(x,y,m,a)==1)||
    (check_threat_three_vertical(x,y,m,a)==1&&check_threat_three_diagonal1(x,y,m,a)==1)||
    (check_threat_three_vertical(x,y,m,a)==1&&check_threat_three_diagonal2(x,y,m,a)==1)||
    (check_threat_three_horizontal(x,y,m,a)==1&&check_threat_three_diagonal1(x,y,m,a)==1)||
    (check_threat_three_horizontal(x,y,m,a)==1&&check_threat_three_diagonal2(x,y,m,a)==1)||
    (check_threat_three_diagonal1(x,y,m,a)==1&&check_threat_three_diagonal2(x,y,m,a)==1)	    
  ) return 1;
  
  return 0;
}

int check_chance_three_two(int x,int y,int m,int a[m][m]){
  if (
    (check_chance_three_vertical(x,y,m,a)==1&&check_chance_two_horizontal(x,y,m,a)==1)||
    (check_chance_three_vertical(x,y,m,a)==1&&check_chance_two_diagonal1(x,y,m,a)==1)||
    (check_chance_three_vertical(x,y,m,a)==1&&check_chance_two_diagonal2(x,y,m,a)==1)||
    (check_chance_three_horizontal(x,y,m,a)==1&&check_chance_two_vertical(x,y,m,a)==1)||
    (check_chance_three_horizontal(x,y,m,a)==1&&check_chance_two_diagonal1(x,y,m,a)==1)||
    (check_chance_three_horizontal(x,y,m,a)==1&&check_chance_two_diagonal2(x,y,m,a)==1)||
    (check_chance_three_diagonal1(x,y,m,a)==1&&check_chance_two_vertical(x,y,m,a)==1)||
    (check_chance_three_diagonal1(x,y,m,a)==1&&check_chance_two_horizontal(x,y,m,a)==1)||
    (check_chance_three_diagonal1(x,y,m,a)==1&&check_chance_two_diagonal2(x,y,m,a)==1)||
    (check_chance_three_diagonal2(x,y,m,a)==1&&check_chance_two_vertical(x,y,m,a)==1)||
    (check_chance_three_diagonal2(x,y,m,a)==1&&check_chance_two_horizontal(x,y,m,a)==1)||
    (check_chance_three_diagonal2(x,y,m,a)==1&&check_chance_two_diagonal1(x,y,m,a)==1)    
  ) return 1;

  return 0;
}

int check_threat_three_two(int x,int y,int m,int a[m][m]){
  if (
    (check_threat_three_vertical(x,y,m,a)==1&&check_threat_two_horizontal(x,y,m,a)==1)||
    (check_threat_three_vertical(x,y,m,a)==1&&check_threat_two_diagonal1(x,y,m,a)==1)||
    (check_threat_three_vertical(x,y,m,a)==1&&check_threat_two_diagonal2(x,y,m,a)==1)||
    (check_threat_three_horizontal(x,y,m,a)==1&&check_threat_two_vertical(x,y,m,a)==1)||
    (check_threat_three_horizontal(x,y,m,a)==1&&check_threat_two_diagonal1(x,y,m,a)==1)||
    (check_threat_three_horizontal(x,y,m,a)==1&&check_threat_two_diagonal2(x,y,m,a)==1)||
    (check_threat_three_diagonal1(x,y,m,a)==1&&check_threat_two_vertical(x,y,m,a)==1)||
    (check_threat_three_diagonal1(x,y,m,a)==1&&check_threat_two_horizontal(x,y,m,a)==1)||
    (check_threat_three_diagonal1(x,y,m,a)==1&&check_threat_two_diagonal2(x,y,m,a)==1)||
    (check_threat_three_diagonal2(x,y,m,a)==1&&check_threat_two_vertical(x,y,m,a)==1)||
    (check_threat_three_diagonal2(x,y,m,a)==1&&check_threat_two_horizontal(x,y,m,a)==1)||
    (check_threat_three_diagonal2(x,y,m,a)==1&&check_threat_two_diagonal1(x,y,m,a)==1)    
  ) return 1;

  return 0;
}

int check_chance_double_two(int x,int y,int m,int a[m][m]){
  if (
    (check_chance_two_vertical(x,y,m,a)==1&&check_chance_two_horizontal(x,y,m,a)==1)||
    (check_chance_two_vertical(x,y,m,a)==1&&check_chance_two_diagonal1(x,y,m,a)==1)||
    (check_chance_two_vertical(x,y,m,a)==1&&check_chance_two_diagonal2(x,y,m,a)==1)||
    (check_chance_two_horizontal(x,y,m,a)==1&&check_chance_two_diagonal1(x,y,m,a)==1)||
    (check_chance_two_horizontal(x,y,m,a)==1&&check_chance_two_diagonal2(x,y,m,a)==1)||
    (check_chance_two_diagonal1(x,y,m,a)==1&&check_chance_two_diagonal2(x,y,m,a)==1)	    
  ) return 1;

  return 0;
}

int check_threat_double_two(int x,int y,int m,int a[m][m]){
  if (
    (check_threat_two_vertical(x,y,m,a)==1&&check_threat_two_horizontal(x,y,m,a)==1)||
    (check_threat_two_vertical(x,y,m,a)==1&&check_threat_two_diagonal1(x,y,m,a)==1)||
    (check_threat_two_vertical(x,y,m,a)==1&&check_threat_two_diagonal2(x,y,m,a)==1)||
    (check_threat_two_horizontal(x,y,m,a)==1&&check_threat_two_diagonal1(x,y,m,a)==1)||
    (check_threat_two_horizontal(x,y,m,a)==1&&check_threat_two_diagonal2(x,y,m,a)==1)||
    (check_threat_two_diagonal1(x,y,m,a)==1&&check_threat_two_diagonal2(x,y,m,a)==1)	    
  ) return 1;

  return 0;
}

void caro_brain(int m,int a[m][m]){
  int i,j;
  time_t t;
  srand((unsigned) time(&t));
  int user_count;
  for (i=1;i<m-1;i++){
    for (j=1;j<m-1;j++){
      if (a[i][j]==1) ++user_count;
      
    }
  }
  if (user_count==0) return;
  else if (user_count==1){
    for (i=1;i<16;i++){
      for (j=1;j<16;j++){
	if (a[i][j]==0){
	  do{
	    int random_number_x=rand()%5;
	    int random_number_y=rand()%5;
	    
	    choose_x=i-3+random_number_x;
	    choose_y=j-3+random_number_y;
	  } while (choose_x<0||choose_x>14||choose_y<0||choose_y>14);
	  return;
	}
      }
    }

    for (i=1;i<16;i++){
      for (j=1;j<16;j++){
	if (a[i][j]==1){
	  do{
	    int random_number_x=rand()%5;
	    int random_number_y=rand()%5;
	    
	    choose_x=i-3+random_number_x;
	    choose_y=j-3+random_number_y;
	  } while (choose_x<0||choose_x>14||choose_y<0||choose_y>14);
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

    //check chance double three

    for (i=1;i<m-1;i++){
      for (j=1;j<m-1;j++){
	if (a[i][j]==2){
	  if (check_chance_double_three(i,j,m,a)==1){
	    choose_x=i-1;
	    choose_y=j-1;
	    return;
	  }
	}
      }
    }

    //check threat double three
    
    for (i=1;i<m-1;i++){
      for (j=1;j<m-1;j++){
	if (a[i][j]==2){
	  if (check_threat_double_three(i,j,m,a)==1){
	    choose_x=i-1;
	    choose_y=j-1;
	    return;
	  }
	}
      }
    }
    
    //check chance three two
    
    for (i=1;i<m-1;i++){
      for (j=1;j<m-1;j++){
	if (a[i][j]==2){
	  if (check_chance_three_two(i,j,17,a)==1){
	    choose_x=i-1;
	    choose_y=j-1;
	    return;
	  }
	}
      }
    }
    
    //check threat three two
    
    for (i=1;i<m-1;i++){
      for (j=1;j<m-1;j++){
	if (a[i][j]==2){
	  if (check_threat_three_two(i,j,17,a)==1){
	    choose_x=i-1;
	    choose_y=j-1;
	    return;
	  }
	}
      }
    }
    
    //check chance three
    
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

    

    //check threat three
    
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
    
    //check chance double two

    for (i=3;i<m-3;i++){
      for (j=2;j<m-3;j++){
	if (a[i][j]==2){
	  if (check_chance_double_two(i,j,17,a)==1){
	    choose_x=i-1;
	    choose_y=j-1;
	    return;
	  }
	}
      }
    }

    //check threat double two
    
    for (i=3;i<m-3;i++){
      for (j=3;j<m-1;j++){
	if (a[i][j]==2){
	  if (check_threat_double_two(i,j,17,a)==1){
	    choose_x=i-1;
	    choose_y=j-1;
	    return;
	  }
	}
      }
    }
    
  }
  //choose_x=rand()%15;
  //choose_y=rand()%15;
  if (choose_x<14) choose_x++;  
  else choose_x=0;
  if (choose_y<14) choose_y++;
  else choose_y=0;
  
}
