#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>
int main()
{
int fd,len;
char buf[PIPE_BUF];
time_t tp;
//Ȩ��Ϊ666
mode_t mode =0666;	
/*ɾ��test�ļ�*/
unlink("test");
/*����test��FIFO�ļ�*/
if((mkfifo("test",mode))<0)
{
perror("mkfifo error");
exit(1);
}
printf("fifo2 executing...\n");
/*��test�ļ�*/
fd = open("test",O_WRONLY);
if(fd < 0)
{
perror("open error");
exit(1);
}
while(1)
{
/*������ǰʱ��*/
time(&tp);
len = sprintf(buf,"fifo2 return current time is: %s",ctime(&tp));
/*����ǰʱ��д�뵽FIFO�ļ�֮��*/
if((write(fd,buf,len+1))<0)
{
perror("write error");
close(fd);
exit(1);
}
}
close(fd);
exit(0);
}
