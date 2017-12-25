#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
int M_SIZE;
void showbuf(char *buf,int n,int m);


int main()
{
int fd;
int i,n,m;
char buf[100];
char *p;

while(1){
scanf("%d%d",&n,&m);
buf[0]=n;
buf[1]=m;
M_SIZE=n*m;
fd=open("/dev/evan",O_RDWR);
if(fd<0)
{
printf("######demodriver drivers open failed!!######\n");
return(-1);
}
printf("######demodriver drivers open success!!######\n");

printf("write data to /dev/evan \n");

write(fd,buf,M_SIZE);

printf("Read bytes data from /dev/evan \n");
printf("准备从evan中read\n");
read(fd,buf,M_SIZE);
printf("从evan中读完，准备打印读出的数组\n");
showbuf(buf,n,M_SIZE);

ioctl(fd,1,NULL);
close(fd);
}
return 0;
}

void showbuf(char *buf,int n,int m)
{
int i,j=0;
for(i=0;i<m;i++)
{
if(i%n==0) printf("\n");
printf("%c ",buf[i]);
}
printf("\n*********************************\n");
}
