#include "caro_check.h"


//Declare items
GtkWidget *window;
GtkWidget *reset_button;
GtkWidget *result;
GtkWidget *stat;
GtkWidget *buttons[15][15];
GtkWidget *vbox,*grid;

//statistics
int user1=0,user2=0,turn=1,state=0,temp_turn=1;
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
	sprintf(text,"Player 1 %d - %d Player 2",user1,user2);
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

void change_player_turn(){
  if (temp_turn==1) temp_turn=0;
  else temp_turn=1;
  
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
		for(j=0;j<15;j++)
		{
			gtk_button_set_label(GTK_BUTTON(buttons[i][j]),"");
			gtk_button_set_label(GTK_BUTTON(buttons[i][j]),NULL);
			//gtk_widget_show(buttons[i][j]);
		}
	if(turn)
	{
	  turn=0;
	  temp_turn=turn;
	  gtk_label_set_text(GTK_LABEL(result),"Player 2's turn to begin");

	}
	else
	{
	  turn=1;
	  temp_turn=turn;
	  gtk_label_set_text(GTK_LABEL(result),"Player 1's turn to begin");
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
       		case 1:sprintf(text,"Player 1 won the game");
       			break;
       		case 2:sprintf(text,"Player 2 won the game");
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
    user1++;
    state=1;
    char text[30];
    sprintf(text,"Player 1 %d - %d Player 2",user1,user2);
    gtk_label_set_text(GTK_LABEL(stat),text);
    return 0;
  }
  if (check_result(17,17,a)==2){
    show_message(2);
    user2++;
    state=1;
    char text[30];
    sprintf(text,"Player 1 %d - %d Player 2",user1,user2);
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
	  if(temp_turn==1){
	    gtk_button_set_label(GTK_BUTTON(button),"X");
	    gtk_label_set_text(GTK_LABEL(result),"Game in progress");
	  }
	  else {
	    gtk_button_set_label(GTK_BUTTON(button),"O");
	    gtk_label_set_text(GTK_LABEL(result),"Game in progress");
	    
	  }
	}
	else
	{
		return 0;
	}
	if(check())
	{
		change_player_turn();
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
