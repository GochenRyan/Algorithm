#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

int main()
{
int fd[2];	//定义两个文件描述符
int fdin;	//文件指针
char buf[PIPE_BUF];	//缓冲区
int pid,len;
if(pipe(fd)<0)	//定义管道
  {
  perror("pipe error");
  exit(1);
  }
pid=fork();
if(pid<0)
  {
  perror("fork error");
  exit(1);
  }
if(pid==0)
  {
  close(fd[1]);	//对于子进程，关闭写管道
  printf("Child process ");
  //信息从fd[0]中读出到buf之中，长度为len
  while((len=read(fd[0],buf,PIPE_BUF))>0)
    {
    buf[len]='\0';	//最后一个字符标识终止
    printf("read %d bytes...\n",len);
    printf("%s\n",buf);	//显示缓冲区内容
    }
  close(fd[0]);	//关闭读管道
  }
  if(pid>0)	//父进程
  {
  close(fd[0]);	//关闭读管道
  printf("Parent start...\n");
  //使用只读方式打开文件hello
  fdin=open("hello",O_RDONLY);
  if(fdin<0)
    {
    perror("open hello file error\n");
    exit(1);
    }
  //信息从文件fdin读入buf，长度为len
  while((len=read(fdin,buf,PIPE_BUF))>0)
  write(fd[1],buf,len); //信息从buf写入fd[1]中
  close(fdin);	//关闭文件指针
  printf("Parent over...\n");
  close(fd[1]);	//关闭写管道
  }
  waitpid(pid,NULL,0);	//等待子进程结束
  exit(0);
}
