#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int T;
class SeqList
{
private:
T *data;
int MaxSize; //顺序表最多可以存放的元素个数。
int last; //顺序表最后一个元素的下标，初始值为-1。
public:
SeqList(int sz);
void Input();//首先输入元素的个数，然后顺次输入元素的值。
void Output();//输出线性表的所有元素。
void Insert(const T& x, int i );//在线性表中第i个位置插入值为x的元素。
void Remove ( T & x );//从线性表中删除第一个值等于x的元素。
};

SeqList::SeqList(int sz){
    data = new T[sz];
    MaxSize = sz;
    last = -1;
    }

void SeqList::Input(){
    int n;
    cin>>n;
    last=n-1;
    for(int i=0;i<n;++i){
        cin>>data[i];
    }
}

void SeqList::Output(){
    cout<<"The elements are:"<<endl;
    for(int i=0;i<=last;i++){
        cout<<data[i]<<endl;
    }
}

void SeqList::Insert(const T& x, int i){
    if(last>MaxSize){
        cout<<"error"<<endl;
        exit(1);
    }
    else{
        int j;
        for(j=last;j>=i;--j){
            data[j+1]=data[j];
        }
        data[j+1]=x;
        ++last;
    }
}

void SeqList::Remove(T & x){
    for(int i=0;i<=last;++i){
        if(data[i]==x){
            for(int j=i;j<=last;++j){
                data[j]=data[j+1];
            }
            --last;
            break;
        }
    }
}

int main()
{
SeqList myList(100);
myList.Input();
myList.Output ();
int i;
for( i=0;i<5;i++)
   myList.Insert(i+10,i);
myList.Output ();
for( i=10;i<15;i++)
   myList.Remove(i);
myList.Output ();

  return 0;

}
