#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static int flag = 0; 

void alarmessage(int sig)
  {
  printf("This is alarm message.\n\r");
  printf("Wait for 3 seconds.\n\r");
  sleep(3);flag = 1;
  }

int main()
  {
  pid_t pid;	//定义新进程
  pid = fork();	//创建新进程pid
  switch(pid)
    {
    case -1: 
      perror("fork error");
      exit(1);
    case 0:  	//进程创建成功，等待3秒
      sleep(3);//给父进程传送指定的SIGALRM信号
      kill(getppid(),SIGALRM);
      exit(0);
    }
  printf("wait alarm signal for 3 seconds....\n");//发送SIGALRM信号，即转移到指定函数alarmessage
  (void) signal(SIGALRM,alarmessage);//发送信号之后，该进程暂停，直到收到flag信号
  pause();
  if(flag)
  printf("System receive alarm signal\n");
  exit(0);
  }
