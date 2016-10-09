/************************************************************************

 * caro_AI.c

 * Copyright (C) 20m-1 Dang Duong

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


#include "caro_AI.h"

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

int check_chance_three_one(int x,int y,int m,int a[m][m]){
        if (
                        (check_chance_three_vertical(x,y,m,a)==1&&check_chance_one_horizontal(x,y,m,a)==1)||
                        (check_chance_three_vertical(x,y,m,a)==1&&check_chance_one_diagonal1(x,y,m,a)==1)||
                        (check_chance_three_vertical(x,y,m,a)==1&&check_chance_one_diagonal2(x,y,m,a)==1)||
                        (check_chance_three_horizontal(x,y,m,a)==1&&check_chance_one_vertical(x,y,m,a)==1)||
                        (check_chance_three_horizontal(x,y,m,a)==1&&check_chance_one_diagonal1(x,y,m,a)==1)||
                        (check_chance_three_horizontal(x,y,m,a)==1&&check_chance_one_diagonal2(x,y,m,a)==1)||
                        (check_chance_three_diagonal1(x,y,m,a)==1&&check_chance_one_vertical(x,y,m,a)==1)||
                        (check_chance_three_diagonal1(x,y,m,a)==1&&check_chance_one_horizontal(x,y,m,a)==1)||
                        (check_chance_three_diagonal1(x,y,m,a)==1&&check_chance_one_diagonal2(x,y,m,a)==1)||
                        (check_chance_three_diagonal2(x,y,m,a)==1&&check_chance_one_vertical(x,y,m,a)==1)||
                        (check_chance_three_diagonal2(x,y,m,a)==1&&check_chance_one_horizontal(x,y,m,a)==1)||
                        (check_chance_three_diagonal2(x,y,m,a)==1&&check_chance_one_diagonal1(x,y,m,a)==1)    
           ) return 1;

        return 0;
}

int check_threat_three_one(int x,int y,int m,int a[m][m]){
        if (
                        (check_threat_three_vertical(x,y,m,a)==1&&check_threat_one_horizontal(x,y,m,a)==1)||
                        (check_threat_three_vertical(x,y,m,a)==1&&check_threat_one_diagonal1(x,y,m,a)==1)||
                        (check_threat_three_vertical(x,y,m,a)==1&&check_threat_one_diagonal2(x,y,m,a)==1)||
                        (check_threat_three_horizontal(x,y,m,a)==1&&check_threat_one_vertical(x,y,m,a)==1)||
                        (check_threat_three_horizontal(x,y,m,a)==1&&check_threat_one_diagonal1(x,y,m,a)==1)||
                        (check_threat_three_horizontal(x,y,m,a)==1&&check_threat_one_diagonal2(x,y,m,a)==1)||
                        (check_threat_three_diagonal1(x,y,m,a)==1&&check_threat_one_vertical(x,y,m,a)==1)||
                        (check_threat_three_diagonal1(x,y,m,a)==1&&check_threat_one_horizontal(x,y,m,a)==1)||
                        (check_threat_three_diagonal1(x,y,m,a)==1&&check_threat_one_diagonal2(x,y,m,a)==1)||
                        (check_threat_three_diagonal2(x,y,m,a)==1&&check_threat_one_vertical(x,y,m,a)==1)||
                        (check_threat_three_diagonal2(x,y,m,a)==1&&check_threat_one_horizontal(x,y,m,a)==1)||
                        (check_threat_three_diagonal2(x,y,m,a)==1&&check_threat_one_diagonal1(x,y,m,a)==1)    
           ) return 1;

        return 0;
}

int check_chance_two_one(int x,int y,int m,int a[m][m]){
        if (
                        (check_chance_one_vertical(x,y,m,a)==1&&check_chance_two_horizontal(x,y,m,a)==1)||
                        (check_chance_one_vertical(x,y,m,a)==1&&check_chance_two_diagonal1(x,y,m,a)==1)||
                        (check_chance_one_vertical(x,y,m,a)==1&&check_chance_two_diagonal2(x,y,m,a)==1)||
                        (check_chance_one_horizontal(x,y,m,a)==1&&check_chance_two_vertical(x,y,m,a)==1)||
                        (check_chance_one_horizontal(x,y,m,a)==1&&check_chance_two_diagonal1(x,y,m,a)==1)||
                        (check_chance_one_horizontal(x,y,m,a)==1&&check_chance_two_diagonal2(x,y,m,a)==1)||
                        (check_chance_one_diagonal1(x,y,m,a)==1&&check_chance_two_vertical(x,y,m,a)==1)||
                        (check_chance_one_diagonal1(x,y,m,a)==1&&check_chance_two_horizontal(x,y,m,a)==1)||
                        (check_chance_one_diagonal1(x,y,m,a)==1&&check_chance_two_diagonal2(x,y,m,a)==1)||
                        (check_chance_one_diagonal2(x,y,m,a)==1&&check_chance_two_vertical(x,y,m,a)==1)||
                        (check_chance_one_diagonal2(x,y,m,a)==1&&check_chance_two_horizontal(x,y,m,a)==1)||
                        (check_chance_one_diagonal2(x,y,m,a)==1&&check_chance_two_diagonal1(x,y,m,a)==1)    
           ) return 1;

        return 0;
}

int check_threat_two_one(int x,int y,int m,int a[m][m]){
        if (
                        (check_threat_one_vertical(x,y,m,a)==1&&check_threat_two_horizontal(x,y,m,a)==1)||
                        (check_threat_one_vertical(x,y,m,a)==1&&check_threat_two_diagonal1(x,y,m,a)==1)||
                        (check_threat_one_vertical(x,y,m,a)==1&&check_threat_two_diagonal2(x,y,m,a)==1)||
                        (check_threat_one_horizontal(x,y,m,a)==1&&check_threat_two_vertical(x,y,m,a)==1)||
                        (check_threat_one_horizontal(x,y,m,a)==1&&check_threat_two_diagonal1(x,y,m,a)==1)||
                        (check_threat_one_horizontal(x,y,m,a)==1&&check_threat_two_diagonal2(x,y,m,a)==1)||
                        (check_threat_one_diagonal1(x,y,m,a)==1&&check_threat_two_vertical(x,y,m,a)==1)||
                        (check_threat_one_diagonal1(x,y,m,a)==1&&check_threat_two_horizontal(x,y,m,a)==1)||
                        (check_threat_one_diagonal1(x,y,m,a)==1&&check_threat_two_diagonal2(x,y,m,a)==1)||
                        (check_threat_one_diagonal2(x,y,m,a)==1&&check_threat_two_vertical(x,y,m,a)==1)||
                        (check_threat_one_diagonal2(x,y,m,a)==1&&check_threat_two_horizontal(x,y,m,a)==1)||
                        (check_threat_one_diagonal2(x,y,m,a)==1&&check_threat_two_diagonal1(x,y,m,a)==1)    
           ) return 1;

        return 0;
}

int check_chance_double_one(int x,int y,int m,int a[m][m]){

        if (
                        (check_chance_one_vertical(x,y,m,a)==1&&check_chance_one_horizontal(x,y,m,a)==1)||
                        (check_chance_one_vertical(x,y,m,a)==1&&check_chance_one_diagonal1(x,y,m,a)==1)||
                        (check_chance_one_vertical(x,y,m,a)==1&&check_chance_one_diagonal2(x,y,m,a)==1)||
                        (check_chance_one_horizontal(x,y,m,a)==1&&check_chance_one_diagonal1(x,y,m,a)==1)||
                        (check_chance_one_horizontal(x,y,m,a)==1&&check_chance_one_diagonal2(x,y,m,a)==1)||
                        (check_chance_one_diagonal1(x,y,m,a)==1&&check_chance_one_diagonal2(x,y,m,a)==1)	    
           ) return 1;

        return 0;
}

int check_threat_double_one(int x,int y,int m,int a[m][m]){

        if (
                        (check_threat_one_vertical(x,y,m,a)==1&&check_threat_one_horizontal(x,y,m,a)==1)||
                        (check_threat_one_vertical(x,y,m,a)==1&&check_threat_one_diagonal1(x,y,m,a)==1)||
                        (check_threat_one_vertical(x,y,m,a)==1&&check_threat_one_diagonal2(x,y,m,a)==1)||
                        (check_threat_one_horizontal(x,y,m,a)==1&&check_threat_one_diagonal1(x,y,m,a)==1)||
                        (check_threat_one_horizontal(x,y,m,a)==1&&check_threat_one_diagonal2(x,y,m,a)==1)||
                        (check_threat_one_diagonal1(x,y,m,a)==1&&check_threat_one_diagonal2(x,y,m,a)==1)	    
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
                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if ((
                                                                check_chance_one_vertical(i,j,m,a)==1||
                                                                check_chance_one_horizontal(i,j,m,a)==1||
                                                                check_chance_one_diagonal1(i,j,m,a)==1||
                                                                check_chance_one_diagonal2(i,j,m,a)==1
                                            )&&(
                                                    check_threat_one_vertical(i,j,m,a)==0&&
                                                    check_threat_one_horizontal(i,j,m,a)==0&&
                                                    check_threat_one_diagonal1(i,j,m,a)==0&&
                                                    check_threat_one_diagonal2(i,j,m,a)==0

                                               )){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;  
                                        }
                                }
                        }
                }

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==1){
                                        do{
                                                int random_number_x=rand()%3;
                                                int random_number_y=rand()%3;

                                                choose_x=i-2+random_number_x;
                                                choose_y=j-2+random_number_y;
                                        } while (choose_x<0||choose_x>m-3||choose_y<0||choose_y>m-3);
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
                                        if (check_chance_four(i,j,m,a)==1){
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
                                        if (check_threat_four_special(i,j,m,a)==1){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check threat far four

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (
                                                        (check_threat_far_four(i,j,m,a)==1&&check_chance_double_three(i,j,m,a)==1)||
                                                        (check_threat_far_four(i,j,m,a)==1&&check_chance_three_two(i,j,m,a)==1)||	    
                                                        (check_threat_far_four(i,j,m,a)==1&&check_threat_double_three(i,j,m,a)==1)||
                                                        (check_threat_far_four(i,j,m,a)==1&&check_threat_three_two(i,j,m,a)==1)
                                           ){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check threat four
                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (check_threat_four(i,j,m,a)==1){
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
                                        if (check_chance_three(i,j,m,a)==1){
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
                                        if (check_chance_three_two(i,j,m,a)==1){
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
                                        if (check_threat_three_two(i,j,m,a)==1){
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
                                        if (check_chance_double_two(i,j,m,a)==1&&check_threat_far_three(i,j,m,a)==1){
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
                                        if (check_threat_double_two(i,j,m,a)==1&&check_threat_far_three(i,j,m,a)==1){
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
                                        if (check_chance_double_two(i,j,m,a)==1&&check_threat_three(i,j,m,a)==1){
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
                                        if (check_threat_double_two(i,j,m,a)==1&&check_threat_three(i,j,m,a)==1){
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
                                        if (check_chance_two_one(i,j,m,a)==1&&check_threat_three(i,j,m,a)==1){
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
                                        if (check_threat_two_one(i,j,m,a)==1&&check_threat_three(i,j,m,a)==1){
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
                                        if (check_chance_double_one(i,j,m,a)==1&&check_threat_three(i,j,m,a)==1){
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
                                        if (check_threat_double_one(i,j,m,a)==1&&check_threat_three(i,j,m,a)==1){
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
                                        if (check_threat_three(i,j,m,a)==1){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check chance double two

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (check_chance_double_two(i,j,m,a)==1){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check threat double two

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (check_threat_double_two(i,j,m,a)==1){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check chance three one

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (check_chance_three_one(i,j,m,a)==1){
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
                                        if (check_threat_three_one(i,j,m,a)==1){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check chance two one

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (check_chance_two_one(i,j,m,a)==1){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check threat two one

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (check_threat_two_one(i,j,m,a)==1){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check chance double one

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (check_chance_double_one(i,j,m,a)==1){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check threat double one

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (check_threat_double_one(i,j,m,a)==1){
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
                                        if ((
                                                                check_chance_one_vertical(i,j,m,a)==1||
                                                                check_chance_one_horizontal(i,j,m,a)==1||
                                                                check_chance_one_diagonal1(i,j,m,a)==1||
                                                                check_chance_one_diagonal2(i,j,m,a)==1
                                            )&&(
                                                    check_threat_one_vertical(i,j,m,a)==0&&
                                                    check_threat_one_horizontal(i,j,m,a)==0&&
                                                    check_threat_one_diagonal1(i,j,m,a)==0&&
                                                    check_threat_one_diagonal2(i,j,m,a)==0

                                               )){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check chance one

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (
                                                        check_chance_one_vertical(i,j,m,a)==1||
                                                        check_chance_one_horizontal(i,j,m,a)==1||
                                                        check_chance_one_diagonal1(i,j,m,a)==1||
                                                        check_chance_one_diagonal2(i,j,m,a)==1
                                           ){
                                                choose_x=i-1;
                                                choose_y=j-1;
                                                return;
                                        }
                                }
                        }
                }

                //check threat one

                for (i=1;i<m-1;i++){
                        for (j=1;j<m-1;j++){
                                if (a[i][j]==2){
                                        if (
                                                        check_threat_one_vertical(i,j,m,a)==1||
                                                        check_threat_one_horizontal(i,j,m,a)==1||
                                                        check_threat_one_diagonal1(i,j,m,a)==1||
                                                        check_threat_one_diagonal2(i,j,m,a)==1
                                           ){
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
        if (choose_x<m-3) choose_x++;  
        else choose_x=0;
        if (choose_y<m-3) choose_y++;
        else choose_y=0;

}
