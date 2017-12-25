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
 mvaddstr(2,19,"[*] 1:Screw Matrix");
 mvaddstr(4,19,"[*] 2:Ncurse Game");
 mvaddstr(6,19,"[*] 3:Add");
 mvaddstr(8,19,"[*] 4:Delete");
 mvaddstr(10,19,"[*] 5:Process");
 mvaddstr(12,19,"[*] Exit");
move(y,x);
 do{
 ch = getch();
 switch(ch){
  case KEY_UP : if(y >= 3) y = y -2; else y = 22;
  break;
  case KEY_DOWN : if(y <= 21) y = y + 2; else y = 2;
  break;
  case '\r' :
   if(y == 12) {endwin(); exit(1);}
   else if(y == 2) {endwin(); screwmatrix();}
   else if(y == 4) {endwin(); game(); }
   else if(y == 6) {endwin(); adduser();}
   else if(y == 8) {endwin(); deluser();}
   else if(y == 10) {endwin();menu2();}
  break;
  case '\t' :
   if(y >= 2 && y <= 22) y = y + 2;
   else if(y == 24) y = 2;
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

screwmatrix(){
system("./ma");
return;
}
game(){
system("./test1");
return;
}
adduser(){
int ch;
system("./add");
system("grep class /etc/passwd");
system("grep class /etc/group");
ch = getch();
while(ch != '\n'){
ch = getch();
}
return;
}
deluser(){
int ch;
system("./del");
system("cat /etc/passwd");
system("cat /etc/group");
ch = getch();
while(ch != '\n'){
ch = getch();
}
return;
}
menu2(){
system("./menu2");
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
