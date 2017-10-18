#include <stdio.h>
#include <stdlib.h>

//n++并判断是否重新赋值
void initN(char *n){
    (*n)++;
    if(*n > 'Z'){
        *n = 'A';
    }
}

//打印矩阵
void printA(char a[][101],int n,int m){
    int i,j;
    for(i = 0;i < n;i++){
        for(j = 0;j < m;j++){
            printf("%c ",a[i][j]);
        }
        printf("\n");
    }
}

//实现n行m列的顺时针螺旋矩阵
void rectSnakeArray(char a[][101],int n,int m){
    int i,j;
    char al = 'A';
    int count = 0;//元素的总数
    int rCount = 0;//总循环次数
    while(1){
        //右循环
        for(i = rCount,j = rCount;j < m;j++){
            if(a[i][j] <= 'Z' && a[i][j] >='A'){
                break;
            }
            a[i][j] = al;
            count++;
            initN(&al);
        }
        //下循环
        for(i = rCount + 1,j = m-1-rCount;i < n;i++){
            if(a[i][j] <= 'Z' && a[i][j] >='A'){
                break;
            }
            a[i][j] = al;
            count++;
            initN(&al);
        }
        for(i = n-1-rCount,j = m-2-rCount;j >= 0;j--){
            if(a[i][j] <= 'Z' && a[i][j] >='A'){
                break;
            }
            a[i][j] = al;
            count++;
            initN(&al);
        }
        for(i = n-2-rCount,j = rCount;i >= 0;i--){
            if(a[i][j] <= 'Z' && a[i][j] >='A'){
                break;
            }
            a[i][j] = al;
            count++;
            initN(&al);
        }
        if(count == n*m){
            break;
        }
        rCount++;
    }
}

int main()
{
    char a[101][101];
    int i,j;
    for(i = 0;i < 101;i++){
        for(j = 0;j < 101;j++){
            a[i][j]= '0';
        }
    }
    int  n,m;//螺旋矩阵的行和列
    printf("please input the rows: ");
    scanf("%d",&n);
    printf("\n");
    printf("please input the columns: ");
    scanf("%d",&m);
    printf("\n");
    rectSnakeArray(a,n,m);
    printA(a,n,m);
    return 0;
}
