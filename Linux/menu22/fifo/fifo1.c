#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
int main(void)
{
int fd;
int len;
char buf[PIPE_BUF];
/*��test�ļ���Ȩ��ֻ��*/
fd = open("test",O_RDONLY);
if(fd < 0)
{
perror("open error");
exit(1);
}
/*���ļ�test�������浽buf*/
while((len = read(fd,buf,PIPE_BUF-1))>0)
printf("%s",buf);	//��ʾbuf����
close(fd);
exit(0);
}

