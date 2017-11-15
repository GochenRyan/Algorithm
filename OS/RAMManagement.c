//内存管理模拟程序

#include <stdio.h>
#include <stdlib.h>

int usedRam[3][40];
int count[3];

typedef struct RAM{
    unsigned int staringAddr;   //起始地址
    unsigned int size;  //分区大小
    struct RAM *next;   //下一个分区
}RAM;

//分配分区
int distribution(unsigned int _size,RAM *ram){
        RAM *newRAM = ram;
        int i = 0; //标记分区
        int j = 0; //标记第几次
        while(newRAM != NULL && newRAM->size < _size){ //匹配适合的分区
            newRAM = newRAM->next;
            if(i < 3){
                i++;
            }
        }
        if(newRAM != NULL && newRAM->size >= _size){
            newRAM->size -= _size;
            newRAM->staringAddr += _size;
            count[i] += 1;
            j = count[i];
            usedRam[i][j] = _size;
            return 1;
        }else{
            printf("无法分配！\n");
        }
    return 0;
}

//释放分区
int freeRAM(int _i,int _j,RAM *ram){
    RAM *newRAM = ram;
    int i = 0;
    for(i = 0;i < _i;i++){
        newRAM = newRAM->next;
    }
    if(usedRam[_i][_j] != -1){
        newRAM->size += usedRam[_i][_j];
        newRAM->staringAddr -= usedRam[_i][_j];
        usedRam[_i][_j] = -1;
        return 1;
    }
    return 0;
}

//显示占用的分区
void printUsedRAM(){
    int i = 0; //标记分区
    int j = 0; //标记第几次
    int label = 0;
    for(i = 0;i < 3;i++){
        for(j = 0;j < 40;j++){
            if(usedRam[i][j] != -1){
                printf("%d %d :",i,j);
                printf("%d\n",usedRam[i][j]);
                label = 1;
            }
        }
    }
    if(label == 0){
        printf("无可释放分区\n");
    }
}

//显示空闲分区
void printFreeRAM(RAM *ram){
    int sign = 0;
    RAM *newRAM = ram;
    while(newRAM != NULL){
        if(newRAM->size > 0){
            printf("分区起始地址：%u \t",newRAM->staringAddr);
            printf("分区大小：%u\n",newRAM->size);
            sign = 1;
        }
        newRAM = newRAM->next;
    }
    if(sign == 0){
        printf("无空闲分区\n");
    }
}

void safe_flush(FILE *fp)
{
    int ch;
    while( (ch = fgetc(fp)) != EOF && ch != '\n' );
}

int main()
{
    //初始化内存单元
    RAM *ram1,*ram2,*ram3;
    int i = 0;
    int j = 0;
    unsigned int demandRAM;
    ram1 = malloc(sizeof(RAM));
    ram2 = malloc(sizeof(RAM));
    ram3 = malloc(sizeof(RAM));
    if(ram1 == NULL || ram2 == NULL || ram3 == NULL){
        printf("malloc error!\n");
    }
    ram1->staringAddr = 0;
    ram1->size = 30;
    ram1->next = ram2;
    ram2->staringAddr = 40;
    ram2->size = 20;
    ram2->next = ram3;
    ram3->staringAddr = 80;
    ram3->size = 40;
    ram3->next = NULL;
    //初始化二维数组
    for(i = 0;i < 3;i++){
            count[i] = -1;
        for(j = 0;j < 40;j++){
            usedRam[i][j] = -1;
        }
    }
    while(1){
        int select = 0;
        printf("当前空闲分区：\n");
        printFreeRAM(ram1);
        printf("1.分配\t 2.释放\n");
        while(!((scanf("%d",&select) == 1) && select < 3 && select > 0)){
            printf("请输入1~2内的值\n");
            safe_flush(stdin); //清除缓存
        }
        if(select == 1){
            printf("请输入要求分配的分区大小: ");
            scanf("%u",&demandRAM);
            distribution(demandRAM,ram1);
        }else{
            printf("请输入需要释放的进程:\n");
            int _i = -1;
            int _j = -1;
            printUsedRAM();
            while(!((scanf("%d",&_i) == 1) && _i < 3 && _i > -1)){
                printf("请输入0~2内的值\n");
                safe_flush(stdin); //清除缓存
            }
            while(!((scanf("%d",&_j) == 1) && _j < 40 && _j > -1)){
                printf("请输入0~39内的值\n");
                safe_flush(stdin); //清除缓存
            }
                int label = freeRAM(_i,_j,ram1);
        }
    }
    return 0;
}
