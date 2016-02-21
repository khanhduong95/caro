/************************************************************************

 * gcaro.c

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


#include "caro_AI.h"


//Declare items
GtkWidget *window;
GtkWidget *reset_button;
GtkWidget *result;
GtkWidget *stat;
GtkWidget *buttons[15][15];
GtkWidget *vbox,*grid;

//statistics
int computer=0,user=0,turn=1,state=0;
//initialize items

void gtk_init_items()
{
	//set window
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window,300,400);
	gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
	
	//set buttons
	int i,j;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
		{
			buttons[i][j]=gtk_button_new();
			gtk_widget_set_size_request(buttons[i][j],30,30);
		}
	reset_button=gtk_button_new_with_label("Reset");
	result=gtk_label_new("It's your turn to begin.");
	char text[30];
	sprintf(text,"Computer %d - %d User",computer,user);
	stat=gtk_label_new(text);
}

//pack items
void gtk_packing()
{
	vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
	grid=gtk_grid_new();

	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_box_pack_start(GTK_BOX(vbox),reset_button,0,0,10);
	gtk_box_pack_start(GTK_BOX(vbox),grid,1,1,10);
	gtk_box_pack_start(GTK_BOX(vbox),result,1,1,10);
	gtk_box_pack_start(GTK_BOX(vbox),stat,1,1,10);
	int i,j;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			gtk_grid_attach(GTK_GRID(grid),buttons[i][j],j,i,1,1);

}

//free memory and quit program
void quit()
{
	gtk_main_quit();
}
void computer_mark()
{
	int i,j;
	while(1)
	{
	  int a[17][17];
	  for (i=0;i<17;i++){
	    a[i][0]=-1;
	    a[i][16]=-1;
	  }
	  
	  for (j=0;j<17;j++){
	    a[0][j]=-1;
	    a[16][j]=-1;
	  }
	  
	  for(i=0;i<15;i++){
	    for(j=0;j<15;j++){
	      const char *text=gtk_button_get_label(GTK_BUTTON(buttons[i][j]));
	      if (text==NULL)
		a[i+1][j+1]=2;
	      else if (strcmp(text,"X")==0)
		{
		  a[i+1][j+1]=1;
		}
	      else if (strcmp(text,"O")==0)
		{
		  a[i+1][j+1]=0;
		}
	    }
	  }
	  caro_brain(17,a);
	  i=choose_x;
	  j=choose_y;
	  //i=random()%15;
	  //j=random()%15;
	  if(gtk_button_get_label(GTK_BUTTON(buttons[i][j]))==NULL)
	    {
	      gtk_button_set_label(GTK_BUTTON(buttons[i][j]),"O");
	      break;
	    }
	}	
}
	
//check whether board finished.
bool done()
{
	int count=0,i,j;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
		{
			if(gtk_button_get_label(GTK_BUTTON(buttons[i][j]))!=NULL)
				count++;
		}
	//printf("%d ",count);
	if(count==225)
		return true;
	else
		return false;
}

//reset all buttons
void reset()
{
  int i,j;
  state=0;
  for(i=0;i<15;i++)
    for(j=0;j<15;j++){
      gtk_button_set_label(GTK_BUTTON(buttons[i][j]),"");
      gtk_button_set_label(GTK_BUTTON(buttons[i][j]),NULL);
      //gtk_widget_show(buttons[i][j]);
    }
  
  
  choose_x=7;
  choose_y=7;
  if(turn)
    {
      
      computer_mark();
      gtk_label_set_text(GTK_LABEL(result),"Game in progress");
      turn=0;
	  }
  else
    {
      turn=1;
      gtk_label_set_text(GTK_LABEL(result),"It is your turn to begin");
    }
}




//show failure success tie message
void show_message(int type)
{
       	char text[25];
       	switch(type)
       	{
       		case 0:sprintf(text,"Game was tie");
       			break;
       		case 1:sprintf(text,"You won the game");
       			break;
       		case 2:sprintf(text,"Computer won the game");
       	}
       	gtk_label_set_text(GTK_LABEL(result),text);
}

//check whether success or tie
bool check()
{
  int a[17][17],i,j;
  for (i=0;i<17;i++){
    a[i][0]=-1;
    a[i][16]=-1;
  }

  for (j=0;j<17;j++){
    a[0][j]=-1;
    a[16][j]=-1;
  }
  
  for(i=0;i<15;i++){
    for(j=0;j<15;j++){
      const char *text=gtk_button_get_label(GTK_BUTTON(buttons[i][j]));
      if (text==NULL)
	a[i+1][j+1]=-1;
      else if (strcmp(text,"X")==0)
	{
	  a[i+1][j+1]=1;
	}
      else if (strcmp(text,"O")==0)
	{
	  a[i+1][j+1]=0;
	}
    }
  }

  if (check_result(17,17,a)==1){
    show_message(1);
    user++;
    state=1;
    char text[30];
    sprintf(text,"Computer %d - %d User",computer,user);
    gtk_label_set_text(GTK_LABEL(stat),text);
    return 0;
  }
  if (check_result(17,17,a)==2){
    show_message(2);
    computer++;
    state=1;
    char text[30];
    sprintf(text,"Computer %d - %d User",computer,user);
    gtk_label_set_text(GTK_LABEL(stat),text);
    return 0;
  }
  
  if (done()){
    show_message(0);
    state=1;
    turn=(turn)?0:1;
    return 0;
  }
  return 1;
  
}

		
//mark buttons if clicked
int mark(GtkWidget *button)
{
	if(state)
		return 0;
	if(gtk_button_get_label(GTK_BUTTON(button))==NULL)
	{
		gtk_button_set_label(GTK_BUTTON(button),"X");
		gtk_label_set_text(GTK_LABEL(result),"Game in progress");
	}
	else
	{
		return 0;
	}
	if(check())
	{
		computer_mark();
		check();
	}
	return 0;
}



//connect signals
void gtk_init_signals()
{
	g_signal_connect(window,"destroy",quit,NULL);
	int i,j;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			g_signal_connect(buttons[i][j],"clicked",G_CALLBACK(mark),buttons[i][j]);
	g_signal_connect(reset_button,"clicked",G_CALLBACK(reset),NULL);
} 

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);
	gtk_init_items();
	gtk_packing();
	gtk_init_signals();
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
