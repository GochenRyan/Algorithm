#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
pid_t child;
int status,a;	//status表示子进程状态，a表示是否创建子进程
printf("Do you want to create a new child process?(1:yes,2:no)");
scanf("%d",&a);
if(a == 1)
  {
  child = fork();	//创建child进程
  if(child == -1)	//创建失败
    {
    perror("fork error");exit(1);
    }
  }
  if(child == 0)	//创建成功
  {
  puts("This is child process...");
  printf("child process pid = %d\n",getpid());	//显示子进程PID
  printf("child process ppid = %d\n",getppid());	//显示父进程PID
  exit(0);
  }
  else	//父进程
  {
  waitpid(child,&status,0);	//等待child进程结束
  puts("This is parent process...");
  printf("parent process pid = %d\n",getpid());	//显示子进程PID
  printf("parent process ppid = %d\n",getppid());	//显示父进程PID
  printf("child process leaving status: %d\n",WIFEXITED(status));
  exit(0);
  }
}
