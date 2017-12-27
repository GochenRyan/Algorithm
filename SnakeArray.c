//A到Z循环的螺旋矩阵
//浪费时间：for 循环结束后i,j多加了一次。
//解决方法：i,j直接初始化。

#include <stdio.h>
#include <stdlib.h>
const int LENGTH = 5;

//n++并判断是否重新赋值
void initN(char *n){
    (*n)++;
    if(*n > 'Z'){
        *n = 'A';
    }
}
//打印矩阵
void printA(char a[][LENGTH]){
    int i,j;
    for(i = 0;i < LENGTH;i++){
        for(j = 0;j <LENGTH;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
//螺旋矩阵
void snakeArray(char a[][LENGTH]){
//临界点为（LENGTH/2,(LENGTH+1)/2-1）
    int i = 0;
    int j = 0;
    int m = LENGTH;
    char n = 'A';
    int label = 0;
    while(1){
        for(j = LENGTH - m,i = LENGTH - m;j < m ;j++){
            a[i][j] = n;
            initN(&n);
            label = ((i == LENGTH/2) && (j == (LENGTH+1)/2 - 1));
        }
        if(label) break;
        for(i = LENGTH - m + 1,j = m - 1;i < m;i++){
            a[i][j] = n;
            initN(&n);
            label = ((i == LENGTH/2) && (j == (LENGTH+1)/2 - 1));
        }
        if(label) break;
        for(j = m - 2,i = m - 1;j >= LENGTH - m ;j--){
            a[i][j] = n;
            initN(&n);
            label = ((i == LENGTH/2) && (j == (LENGTH+1)/2 - 1));
        }
        if(label) break;
        for(i = m - 2,j = LENGTH - m;i > LENGTH - m ;i--){
            a[i][j] = n;
            initN(&n);
            label = ((i == LENGTH/2) && (j == (LENGTH+1)/2 - 1));
        }
        if(label) break;
        m--;
    }
}

int main()
{
    char a[LENGTH][LENGTH];
    snakeArray(a);
    printA(a);
    return 0;
}
