#include <curses.h>
#include <string.h>

#define StartX 20
#define StartY 2

void initial();

main(){
 int x=StartX,y=StartY,ch;
 initial();
 box(stdscr,0,0);
 attron(A_REVERSE);
 mvaddstr(0,30,"M I A O");
 attroff(A_REVERSE);
 mvaddstr(2,19,"[*] 1:Fork");
 mvaddstr(4,19,"[*] 2:Signal");
 mvaddstr(6,19,"[*] 3:Pipe");
 mvaddstr(8,19,"[*] 4:Popen");
 mvaddstr(10,19,"[*]5:fifo1");
 mvaddstr(12,19,"[*]6:fifo2");
 mvaddstr(14,19,"[*] Exit");
move(y,x);
 do{
 ch = getch();
 switch(ch){
  case KEY_UP : if(y >= 3) y = y -2; else y = 22;
  break;
  case KEY_DOWN : if(y <= 13) y = y + 2; else y = 2;
  break;
  case '\r' :
   if(y == 14) {endwin(); exit(0);}
   else if(y == 2) {endwin(); fork();}
   else if(y == 4) {endwin(); signal(); }
   else if(y == 6) {endwin(); pipe();}
   else if(y == 8) {endwin(); popenx();}
   else if(y == 10) {endwin(); fifo1();}
   else if(y == 12) {endwin(); fifo2();}
  break;
  case '\t' :
   if(y >= 2 && y <= 14) y = y + 2;
   else if(y == 14) y = 2;
  break;
  case 27 :
   endwin();
   exit();
  default:
  break;
}
move(y,x);
}while(1);
}

fork(){
int ch;
system("./fork/fork");
ch = getch();
while(ch != '\n'){
ch = getch();
}
return;
}
signal(){
int ch;
system("./signal/signal");
ch = getch();
while(ch != '\n'){
ch = getch();
}
return;
}
pipe(){
int ch;
system("./pipe/pipe");
ch = getch();
while(ch != '\n'){
ch = getch();
}
return;
}
popenx(){
int ch;
system("./popen/popen");
ch = getch();
while(ch != '\n'){
ch = getch();
}
return;
}
fifo1(){
int ch;
system("./fifo/fifo1");
ch = getch();
while(ch != '\n'){
ch = getch();
}
return;
}
fifo2(){
int ch;
system("./fifo/fifo2");
ch = getch();
while(ch != '\n'){
ch = getch();
}
return;
}
void initial(){
initscr();
cbreak();
nonl();
noecho();
intrflush(stdscr,FALSE);
keypad(stdscr,TRUE);
refresh();
}
