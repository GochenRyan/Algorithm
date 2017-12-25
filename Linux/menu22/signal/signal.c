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
  pid_t pid;	//�����½���
  pid = fork();	//�����½���pid
  switch(pid)
    {
    case -1: 
      perror("fork error");
      exit(1);
    case 0:  	//���̴����ɹ����ȴ�3��
      sleep(3);//�������̴���ָ����SIGALRM�ź�
      kill(getppid(),SIGALRM);
      exit(0);
    }
  printf("wait alarm signal for 3 seconds....\n");//����SIGALRM�źţ���ת�Ƶ�ָ������alarmessage
  (void) signal(SIGALRM,alarmessage);//�����ź�֮�󣬸ý�����ͣ��ֱ���յ�flag�ź�
  pause();
  if(flag)
  printf("System receive alarm signal\n");
  exit(0);
  }
