/************************************************************************

 * caro_AI.h

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


#include "caro_check.h"

extern int choose_x;
extern int choose_y;

int check_chance_double_three(int x, int y,int m,int a[m][m]);

int check_threat_double_three(int x,int y,int m,int a[m][m]);

int check_chance_three_two(int x,int y,int m,int a[m][m]);

int check_threat_three_two(int x,int y,int m,int a[m][m]);

int check_chance_double_two(int x,int y,int m,int a[m][m]);

int check_threat_double_two(int x,int y,int m,int a[m][m]);

int check_chance_three_one(int x,int y,int m,int a[m][m]);

int check_threat_three_one(int x,int y,int m,int a[m][m]);

int check_chance_two_one(int x,int y,int m,int a[m][m]);

int check_threat_two_one(int x,int y,int m,int a[m][m]);

int check_chance_double_one(int x,int y,int m,int a[m][m]);

int check_threat_double_one(int x,int y,int m,int a[m][m]);

void caro_brain(int m,int a[m][m]);
