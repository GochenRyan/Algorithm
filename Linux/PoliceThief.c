#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>
#include <curses.h>
#include <math.h>

//the chance of running
pthread_mutex_t run;
pthread_cond_t xiao,jing;

const int distance = 3;
const int maxDistance = 30;

typedef struct coordinate
{
    int x;
    int y;
} coordinate;
coordinate police_c = {0,5};
coordinate thief_c = {0,6};

void show(){
    int i,j;
    initscr();
    clear();
    move(police_c.y,police_c.x);
    printw("P");
    move(thief_c.y,thief_c.x);
    printw("T");
    move(12,19);
    printw("P.x=%d,T.x=%d",police_c.x,thief_c.x);
    refresh();
    for(i=0;i<10000;i++)
        for(j=0;j<10000;j++){}
    }

void chase(void *arg)
{
    char phi = *(char *)arg;
    for(;;)
    {
     pthread_mutex_lock(&run);
     if(police_c.x < maxDistance || thief_c.x < maxDistance)
     {
        if(phi == 'P')
        {

            while(police_c.x >= maxDistance || abs(police_c.x - thief_c.x) > distance)
            {
              pthread_cond_wait(&xiao,&run);

          }
          police_c.x++;
          show();
          pthread_cond_signal(&jing);
      }
      else if(phi == 'T')
      {
        while(thief_c.x >= maxDistance || abs(police_c.x - thief_c.x) > distance)
        {
            pthread_cond_wait(&jing,&run);
        }
        thief_c.x++;
        show();      
        pthread_cond_signal(&xiao);
    }
}
pthread_mutex_unlock(&run);
pthread_mutex_destroy(&run);
}
}

int main()
{
    pthread_t P,T;
    char a='P',b='T';
    pthread_mutex_init(&run,NULL);
    pthread_cond_init(&xiao,NULL);
    pthread_cond_init(&jing,NULL);
    pthread_create(&P,NULL,chase,&a);
    pthread_create(&T,NULL,chase,&b);

    pthread_join(P,NULL);
    pthread_join(T,NULL);
    while(1){}
        return 0;
}
