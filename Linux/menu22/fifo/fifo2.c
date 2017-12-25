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
//权限为666
mode_t mode =0666;	
/*删除test文件*/
unlink("test");
/*建立test的FIFO文件*/
if((mkfifo("test",mode))<0)
{
perror("mkfifo error");
exit(1);
}
printf("fifo2 executing...\n");
/*打开test文件*/
fd = open("test",O_WRONLY);
if(fd < 0)
{
perror("open error");
exit(1);
}
while(1)
{
/*读出当前时间*/
time(&tp);
len = sprintf(buf,"fifo2 return current time is: %s",ctime(&tp));
/*将当前时间写入到FIFO文件之中*/
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
