#include <curses.h>

int main(int argc, char *argv[])
{
int x=10;
int y=10;
int direction =1;
char ball='O';

initscr();
crmode();
noecho();

while(true)
{
clear();
mvaddch(y,x,ball);
refresh();

x+=direction;

if(x==COLS)
{direction=-1;x=COLS-1;beep();}
if(x<0)
{direction=1;x=0;beep();}
usleep(10000);
}
endwin();
return 0;
}
