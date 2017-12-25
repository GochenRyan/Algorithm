#include <stdio.h>
#include <string.h>
int main()
{
FILE *fp;
char buf[501];
int ch;

/*step1:将ls命令内容通过读管道写入buf*/
memset(buf,'\0',sizeof(buf));	//buf初始化
printf("read pipe...\n");
/*//创建一个fp，使用命令ls -l，使用读管道*/
fp = popen("ls -l","r");	
if(fp!=NULL)
{
/*将fp内容写入buf*/
ch = fread(buf,sizeof(char),500,fp);
if(ch > 0)
{
printf("\nThe file list is: \n");
printf("%s\n",buf);	//显示buf内容
}
pclose(fp);
}
else
{
printf("cann't execut popen.\n");
return 1;
}

/*step2:将buf内容写入test.bin*/
printf("\nwrite into binary file...\n");
/*创建文件test.bin，权限二进制可写*/
fp = fopen("test.bin","wb");
if(fp == NULL)
{
printf("cann't open file.\n");
return 1;
}
/*将buf内容写入test.bin*/
fwrite(buf,sizeof(char),500,fp);
fclose(fp);

/*step3:将test.bin内容读出，写入buf*/
printf("\n read binary file.\n");
memset(buf,'\0',sizeof(buf));	//buf初始化
//打开test.bin，权限二进制只读
fp = fopen("test.bin","rb");
if(fp == NULL)
{
printf("cann't open file.\n");
return 1;
}
/*将fp内容读入buf*/
fread(buf,sizeof(char),500,fp);
fclose(fp);

/*将buf内容通过写入写管道显示*/
printf("\n write into pipe...\n");
/*创建写管道*/
fp = popen("ls -l|grep popen","w");
/*将buf写入管道，使用grep命令显示popen相关信息*/
fwrite(buf,sizeof(char),500,fp);
pclose(fp);
return 0;
}

