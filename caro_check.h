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


int check_result(int m, int a[m][m]);


int check_chance_four(int x,int y,int m,int a[m][m]);

int check_threat_four_special(int x,int y,int m,int a[m][m]);

int check_threat_far_four(int x,int y,int m,int a[m][m]);

int check_threat_four(int x,int y,int m,int a[m][m]);

int check_chance_three_vertical(int x,int y,int m,int a[m][m]);

int check_threat_three_vertical(int x,int y,int m,int a[m][m]);

int check_chance_three_horizontal(int x,int y,int m,int a[m][m]);

int check_threat_three_horizontal(int x,int y,int m,int a[m][m]);

int check_chance_three_diagonal1(int x,int y,int m,int a[m][m]);

int check_threat_three_diagonal1(int x,int y,int m,int a[m][m]);

int check_chance_three_diagonal2(int x,int y,int m,int a[m][m]);

int check_threat_three_diagonal2(int x,int y,int m,int a[m][m]);

int check_chance_three(int x,int y,int m,int a[m][m]);

int check_threat_far_three(int x,int y,int m,int a[m][m]);

int check_threat_three(int x,int y,int m,int a[m][m]);

int check_chance_two_vertical(int x,int y,int m,int a[m][m]);

int check_threat_two_vertical(int x,int y,int m,int a[m][m]);

int check_chance_two_horizontal(int x,int y,int m,int a[m][m]);

int check_threat_two_horizontal(int x,int y,int m,int a[m][m]);

int check_chance_two_diagonal1(int x,int y,int m,int a[m][m]);

int check_threat_two_diagonal1(int x,int y,int m,int a[m][m]);

int check_chance_two_diagonal2(int x,int y,int m,int a[m][m]);

int check_threat_two_diagonal2(int x,int y,int m,int a[m][m]);

int check_chance_one_vertical(int x,int y,int m,int a[m][m]);

int check_threat_one_vertical(int x,int y,int m,int a[m][m]);

int check_chance_one_horizontal(int x,int y,int m,int a[m][m]);

int check_threat_one_horizontal(int x,int y,int m,int a[m][m]);

int check_chance_one_diagonal1(int x,int y,int m,int a[m][m]);

int check_threat_one_diagonal1(int x,int y,int m,int a[m][m]);

int check_chance_one_diagonal2(int x,int y,int m,int a[m][m]);

int check_threat_one_diagonal2(int x,int y,int m,int a[m][m]);
