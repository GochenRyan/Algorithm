#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define ONE_K (1024)
#define MAX_MEMORY (30)
int main()
{
char *some_memory;
int size_to_allocate=ONE_K;
int megs_obtained=0;
int ks_obtained=0;
for( ks_obtained=0; ks_obtained<MAX_MEMORY; ks_obtained++)
{
some_memory=(char *)malloc(size_to_allocate);
if(some_memory==NULL) exit(EXIT_FAILURE);
sprintf(some_memory,"Hello World!");
sleep(0.5);
megs_obtained++;
printf("%s - now allocate %d KB/n",some_memory,megs_obtained);
 
some_memory=(char *)realloc(some_memory,size_to_allocate*2);
if(some_memory==NULL) exit(EXIT_FAILURE);
sprintf(some_memory+strlen(some_memory)," Hello Fedora13!");
//some_memory += "Hello Fedora13!";
//printf("%d/n",strlen(some_memory));
sleep(0.5);
megs_obtained += 2;
printf("%s - now allocate %d KB/n",some_memory,megs_obtained);
}
exit(EXIT_SUCCESS);
}
