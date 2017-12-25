#include <stdio.h>
#include <string.h>
int main()
{
FILE *fp;
char buf[501];
int ch;

/*step1:��ls��������ͨ�����ܵ�д��buf*/
memset(buf,'\0',sizeof(buf));	//buf��ʼ��
printf("read pipe...\n");
/*//����һ��fp��ʹ������ls -l��ʹ�ö��ܵ�*/
fp = popen("ls -l","r");	
if(fp!=NULL)
{
/*��fp����д��buf*/
ch = fread(buf,sizeof(char),500,fp);
if(ch > 0)
{
printf("\nThe file list is: \n");
printf("%s\n",buf);	//��ʾbuf����
}
pclose(fp);
}
else
{
printf("cann't execut popen.\n");
return 1;
}

/*step2:��buf����д��test.bin*/
printf("\nwrite into binary file...\n");
/*�����ļ�test.bin��Ȩ�޶����ƿ�д*/
fp = fopen("test.bin","wb");
if(fp == NULL)
{
printf("cann't open file.\n");
return 1;
}
/*��buf����д��test.bin*/
fwrite(buf,sizeof(char),500,fp);
fclose(fp);

/*step3:��test.bin���ݶ�����д��buf*/
printf("\n read binary file.\n");
memset(buf,'\0',sizeof(buf));	//buf��ʼ��
//��test.bin��Ȩ�޶�����ֻ��
fp = fopen("test.bin","rb");
if(fp == NULL)
{
printf("cann't open file.\n");
return 1;
}
/*��fp���ݶ���buf*/
fread(buf,sizeof(char),500,fp);
fclose(fp);

/*��buf����ͨ��д��д�ܵ���ʾ*/
printf("\n write into pipe...\n");
/*����д�ܵ�*/
fp = popen("ls -l|grep popen","w");
/*��bufд��ܵ���ʹ��grep������ʾpopen�����Ϣ*/
fwrite(buf,sizeof(char),500,fp);
pclose(fp);
return 0;
}

