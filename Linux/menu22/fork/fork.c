#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
pid_t child;
int status,a;	//status��ʾ�ӽ���״̬��a��ʾ�Ƿ񴴽��ӽ���
printf("Do you want to create a new child process?(1:yes,2:no)");
scanf("%d",&a);
if(a == 1)
  {
  child = fork();	//����child����
  if(child == -1)	//����ʧ��
    {
    perror("fork error");exit(1);
    }
  }
  if(child == 0)	//�����ɹ�
  {
  puts("This is child process...");
  printf("child process pid = %d\n",getpid());	//��ʾ�ӽ���PID
  printf("child process ppid = %d\n",getppid());	//��ʾ������PID
  exit(0);
  }
  else	//������
  {
  waitpid(child,&status,0);	//�ȴ�child���̽���
  puts("This is parent process...");
  printf("parent process pid = %d\n",getpid());	//��ʾ�ӽ���PID
  printf("parent process ppid = %d\n",getppid());	//��ʾ������PID
  printf("child process leaving status: %d\n",WIFEXITED(status));
  exit(0);
  }
}
