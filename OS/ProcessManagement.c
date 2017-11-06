/*
一定要把结构体的初始化做好
1.分配空间
2.下一个节点指向NULL

函数传参
1.若传的是地址，在函数内调用函数再次传同一个参数，则直接传，不用&
2.指针不用&

结构体调到另一个队列后，next要清空（气）

判定输入为错的时候要清除缓存
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct process{
    int pid; //进程ID
    unsigned int priority; //进程优先权
    int state; //进程状态: -1--阻塞；0--就绪；1--运行
    struct process *next;
}process;
//运行队列
typedef struct operate_queue{
    process *ohead; //队头
    process *otail; //队尾
}operate_queue;
//就绪队列
typedef struct ready_queue{
    process *rhead; //队头
    process *rtail; //队尾
}ready_queue;

//阻塞队列
typedef struct block_queue{
    process *bhead; //队头
    process *btail; //队尾
}block_queue;

//初始化运行队列
void initOperate_queue(operate_queue *_operate_queue){
    _operate_queue->ohead = NULL;
    _operate_queue->otail = NULL;
}

//初始化就绪队列
void initReady_queue(ready_queue *_ready_queue){
    _ready_queue->rhead = NULL;
    _ready_queue->rtail = NULL;
}

//初始化阻塞队列
void initBlock_queue(block_queue *_block_queue){
    _block_queue->bhead = NULL;
    _block_queue->btail = NULL;
}

//插入就绪队列
void insertReady_queue(ready_queue *_ready_queue,process *newPro){
    newPro->state = 0;
    if(_ready_queue->rhead ==NULL){ //如果就绪队列为空，则直接插入
        printf("就绪队列为空");
        _ready_queue->rhead = newPro;
        _ready_queue->rtail = newPro;
    }else{  //不为空，比较优先权
        process *midPro = _ready_queue->rhead;
        if(midPro->priority > newPro->priority){  //优先权最小，放队头
            _ready_queue->rhead = newPro;
            newPro->next = midPro;
        }else{  //插入队列中或者队尾
            while(midPro->next != NULL && midPro->next->priority <= newPro->priority){
                midPro = midPro->next;
            }
            newPro->next = midPro->next;
            midPro->next = newPro;
            if(midPro->next == NULL){ //在队尾，调整队尾指针
                _ready_queue->rtail = midPro;
            }
        }
    }
}

//插入阻塞队列
void insertBlock_queue(block_queue *_block_queue,process *newPro){
    newPro->state = -1;
    if(_block_queue->bhead == NULL){ //阻塞队列为空，直接插入
        _block_queue->bhead = newPro;
        _block_queue->btail = newPro;
    }else{
        process *midPro = _block_queue->bhead;
        if(midPro->priority > newPro->priority){  //优先权最小，放队头
            _block_queue->bhead = newPro;
            newPro->next = midPro;
        }else{  //插入队列中或者队尾
            while(midPro->next != NULL && midPro->next->priority <= newPro->priority){
                midPro = midPro->next;
            }
            newPro->next = midPro->next;
            midPro->next = newPro;
            if(midPro->next == NULL){ //在队尾，调整队尾指针
                _block_queue->btail = midPro;
            }
        }
    }
}

//进程创建：1.创建成功 2.无法分配空间
int create(operate_queue *_operate_queue,ready_queue *_ready_queue,block_queue *_block_queue){
    int _pid;
    unsigned int _priority;
    printf("请输入进程ID: ");
    while(!(scanf("%d",&_pid) == 1)){
            printf("请输入正确ID\n");
            safe_flush(stdin); //清除缓存
        }

    //判断输入
    printf("请输入进程优先权: ");
    while(!(scanf("%u",&_priority) == 1)){
            printf("请输入正确优先权\n");
            safe_flush(stdin); //清除缓存
        }
    //判断输入
    process *newPro = NULL;
    newPro = malloc(sizeof(process));
    if(newPro == NULL){
        printf("malloc fail!\n");
        return 0;
    }
    newPro->pid = _pid;
    newPro->priority = _priority;
    newPro->next = NULL;
    if(_operate_queue->ohead == NULL){   //无运行进程，直接插入运行队列
        newPro->state = 1;
        _operate_queue->ohead = newPro;
        return 1;
    }else if(newPro->priority < _operate_queue->ohead->priority){ //优先权小，抢占
        newPro->state = 1;
        insertBlock_queue(_block_queue,_operate_queue->ohead);  //阻塞运行进程，运行创建的进程
        _operate_queue->ohead = newPro;
        _operate_queue->otail = newPro;
        return 1;
    }else{  //优先权等于，插入就绪队列
        insertReady_queue(_ready_queue,newPro);
        return 1;
    }
}

//进程撤销
int revoke(int _pid,operate_queue *_operate_queue,ready_queue *_ready_queue,block_queue *_block_queue){
    process *midPro = NULL;
    if(_operate_queue->ohead != NULL && _operate_queue->ohead->pid == _pid){ //判断运行队列是否为空并查询进程ID
        midPro = _operate_queue->ohead; //不为空则撤销进程并进行调度
        _operate_queue->ohead = NULL;
        _operate_queue->otail = NULL;
        readyToOperate(_operate_queue,_ready_queue);
        free(midPro);
        return 1;
    }
    if(_ready_queue->rhead != NULL){ //判断就绪队列是否为空并查询进程ID
        process *midPro = _ready_queue->rhead;
        if(midPro->pid == _pid){    //判断头部是否为撤销进程
            _ready_queue->rhead = midPro->next;
            free(midPro);
            return 1;
        }else{
            while(midPro->next != NULL){ //遍历查询
                    if(midPro->next->pid == _pid){
                        process *revokePro = midPro->next;
                        midPro->next = revokePro->next;
                        free(revokePro);
                        return 1;
                    }
                midPro = midPro->next;
            }
        }
    }
    if(_block_queue->bhead != NULL){ //判断阻塞队列是否为空并查询进程ID
        process *midPro = _block_queue->bhead;
        if(midPro->pid == _pid){    //判断头部是否为应撤销进程
            _block_queue->bhead = midPro->next;
            free(midPro);
            return 1;
        }else{
            while(midPro->next != NULL){    //遍历查询
                    if(midPro->next->pid == _pid){
                        process *revokePro = midPro->next;
                        midPro->next = revokePro->next;
                        free(revokePro);
                        return 1;
                    }
                midPro = midPro->next;
            }
        }
    }
    //查询不到该进程
    return 0;
}

//进程阻塞：1.阻塞当前运行进程 2.阻塞队列为空，无应阻塞进程
int block(operate_queue *_operate_queue,ready_queue *_ready_queue,block_queue *_block_queue){
    //阻塞运行进程并从就绪队列调度
    process *midPro = NULL;
    if(_operate_queue->ohead != NULL){ //判断运行队列是否为空
        midPro = _operate_queue->ohead;
        _operate_queue->ohead = NULL;
        _operate_queue->otail = NULL;
        insertBlock_queue(_block_queue,midPro); //阻塞进程
        readyToOperate(_operate_queue,_ready_queue,_block_queue); //从就绪队列调度进程
        return 1;
    }
    return 0;
}

//进程唤醒:1.唤醒阻塞进程（插入就绪队列：抢占） 2.阻塞队列为空，无应唤醒进程
int wake(block_queue *_block_queue,ready_queue *_ready_queue,operate_queue *_operate_queue){
    if(_block_queue->bhead != NULL){ //判断阻塞队列是否为空
        process *midPro = _block_queue->bhead;
        _block_queue->bhead = midPro->next;
        midPro->next = NULL;    //清空next
        insertReady_queue(_ready_queue,midPro); //插入就绪队列
        readyToOperate(_operate_queue,_ready_queue,_block_queue); //从就绪队列调度进程
        return 1;
    }
    return 0;
}

//从就绪队列进入运行队列:1.进入运行队列 2.优先权低，无法运行
int readyToOperate(operate_queue *_operate_queue,ready_queue *_ready_queue,block_queue *_block_queue){
    if(_ready_queue->rhead == NULL){
        return 0;
    }else{
        if(_operate_queue->ohead == NULL){ //运行队列为空则直接调度
            if(_ready_queue->rhead == _ready_queue->rtail){ //判断就绪队列是否就一个进程
                _ready_queue->rtail = NULL;
            }
            process *midPro = _ready_queue->rhead;
            _ready_queue->rhead = midPro->next;
            midPro->next = NULL;    //清空next
            midPro->state = 1;
            _operate_queue->ohead = midPro;
            _operate_queue->otail = midPro;
            return 1;
        }else if(_operate_queue->ohead->priority > _ready_queue->rhead->priority){ //比较优先权
            if(_ready_queue->rhead == _ready_queue->rtail){ //判断就绪队列是否就一个进程
                _ready_queue->rtail = NULL;
            }
            insertBlock_queue(_block_queue,_operate_queue->ohead); //将运行进程阻塞
            process *midPro = _ready_queue->rhead;
            _ready_queue->rhead = midPro->next;
            midPro->next = NULL;    //清空next
            midPro->state = 1;
            _operate_queue->ohead = midPro;
            _operate_queue->otail = midPro;
            return 1;
        }else{  //优先权低
            return 0;
        }
    }
}


//显示id、优先权、状态
void printQueue(operate_queue *_operate_queue,ready_queue *_ready_queue,block_queue *_block_queue){
    printf("运行队列：\n");
        if(_operate_queue->ohead == NULL){
            printf("运行队列没有进程\n");
        }else{
            printf("id: %d\t优先权: %u\t进程状态: %d\n",_operate_queue->ohead->pid,_operate_queue->ohead->priority,_operate_queue->ohead->state);
        }
    printf("就绪队列:\n");
        if(_ready_queue->rhead == NULL){
            printf("就绪队列没有进程\n");
        }else{
            process *readyMidPro = _ready_queue->rhead;
            while(readyMidPro != NULL){
                printf("id: %d\t优先权: %u\t进程状态: %d\n",readyMidPro->pid,readyMidPro->priority,readyMidPro->state);
                readyMidPro = readyMidPro->next;
            }
        }
    printf("阻塞队列:\n");
        if(_block_queue->bhead == NULL){
            printf("阻塞队列没有进程\n");
        }else{
            process *blockMidPro = _block_queue->bhead;
            while(blockMidPro != NULL){
                printf("id: %d\t优先权: %u\t进程状态: %d\n",blockMidPro->pid,blockMidPro->priority,blockMidPro->state);
                blockMidPro = blockMidPro->next;
            }
        }
}

//清除缓存的函数
void safe_flush(FILE *fp)
{
    int ch;
    while( (ch = fgetc(fp)) != EOF && ch != '\n' );
}

int main()
{
    operate_queue operateQueue;
    ready_queue readyQueue;
    block_queue blockQueue;
    initOperate_queue(&operateQueue);
    initReady_queue(&readyQueue);
    initBlock_queue(&blockQueue);
    while(1){
        printf("1--创建进程\t2--撤销进程\t3--阻塞进程\t4--唤醒进程\n");
        int option;
        while(!((scanf("%d",&option) == 1) && option < 5 && option > 0)){
            printf("请输入1~4内的值\n");
            safe_flush(stdin); //清除缓存
        }
      //  system("cls");
        //判断输入
        switch(option){
        case 1:{
            int createLabel;
            createLabel = create(&operateQueue,&readyQueue,&blockQueue);
            if(createLabel){
                printf("创建成功\n");
            }else{
                printf("创建失败\n");
            }
            printQueue(&operateQueue,&readyQueue,&blockQueue);
            break;
        }
        case 2:{
            int _pid;
            int revokeLabel;
            printf("请输入要撤销的进程ID号: ");
            while(!(scanf("%d",&_pid) == 1)){
                printf("请输入正确ID\n");
                safe_flush(stdin); //清除缓存
            }
            revokeLabel = revoke(_pid,&operateQueue,&readyQueue,&blockQueue);
            if(revokeLabel){
                printf("撤销成功\n");
            }else{
                printf("撤销失败\n");
            }
            printQueue(&operateQueue,&readyQueue,&blockQueue);
            break;
        }
        case 3:{
            int blockLabel;
            blockLabel = block(&operateQueue,&readyQueue,&blockQueue);
            if(blockLabel){
                printf("阻塞成功\n");
            }else{
                printf("阻塞失败\n");
            }
            printQueue(&operateQueue,&readyQueue,&blockQueue);
            break;
        }
        case 4:{
            int wakeLabel;
            wakeLabel = wake(&blockQueue,&readyQueue,&operateQueue);
            if(wakeLabel){
                printf("成功唤醒进程\n");
            }else{
                printf("阻塞队列为空\n");
            }
            printQueue(&operateQueue,&readyQueue,&blockQueue);
            break;
        }
        }
    }
    return 0;
}
