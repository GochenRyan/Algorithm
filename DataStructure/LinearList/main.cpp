#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int T;
class SeqList
{
private:
T *data;
int MaxSize; //˳��������Դ�ŵ�Ԫ�ظ�����
int last; //˳������һ��Ԫ�ص��±꣬��ʼֵΪ-1��
public:
SeqList(int sz);
void Input();//��������Ԫ�صĸ�����Ȼ��˳������Ԫ�ص�ֵ��
void Output();//������Ա������Ԫ�ء�
void Insert(const T& x, int i );//�����Ա��е�i��λ�ò���ֵΪx��Ԫ�ء�
void Remove ( T & x );//�����Ա���ɾ����һ��ֵ����x��Ԫ�ء�
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
