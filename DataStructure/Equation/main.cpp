#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>

using namespace std;

class List;
class LinkNode{
    friend class List;
//private:
public:
    int coefficient;
    int exponent;
    LinkNode *link;
    LinkNode(LinkNode *ptr=NULL){
        link=ptr;
    }
    LinkNode(const int &item1,const int &item2,LinkNode *ptr=NULL){
        coefficient=item1;
        exponent=item2;
        link=ptr;
    }
    ~LinkNode(){};
};

class List{
private:
    LinkNode *first;
    int maxSize;
    int maxExponent;
public:
    List(){first=new LinkNode();}
    ~List(){};
    void input();
    void output();
    friend List operator+(List &A,List &B);
    friend List operator-(List &A,List &B);
    friend List operator*(List &A,List &B);
    List derivation();
    float calculate(float x);
    int getMax();
};

// 输入
void List::input(){
    LinkNode *newNode;
    LinkNode *p=first;
    maxSize=0;
    int val1,val2;
    while((cin>>val1)&&val1!=0){
        cin>>val2;
        if(val2==0){
            newNode=new LinkNode(val1,0);
            p->link=newNode;
            p=p->link;
            ++maxSize;
        }
        else{
        newNode=new LinkNode(val1,val2);
        p->link=newNode;
        p=p->link;
        ++maxSize;
        }
    }
}

// 输出
void List::output(){
    LinkNode *p=first->link;
    cout<<"C(x)=";
        if(p->exponent==0){
            cout<<p->coefficient;
        }
        else if(p->coefficient==1){
            cout<<"x";
        }
        else{
            cout<<p->coefficient<<"x";
        }
        if(p->exponent!=1 && p->exponent!=0){
                cout<<"^"<<p->exponent;
        }
        while(p->link!=NULL){
            p=p->link;
            if(p->coefficient==1){
                cout<<"+x";
            }
            else if(p->coefficient>1){

                cout<<"+"<<p->coefficient<<"x";
            }
            else if(p->coefficient<0){
                cout<<p->coefficient<<"x";
            }
            if(p->exponent!=1){
                cout<<"^"<<p->exponent;
            }
        }
        cout<<'\n';

}

// 重载“+”
List operator+(List &A,List &B){
    List C;
    C.maxSize=0;
    LinkNode *pa,*pb,*pc,*p;
    pa=A.first->link;
    pb=B.first->link;
    pc=C.first;
    while(pa!=NULL && pb!=NULL){
        if(pa->exponent==(pb->exponent)){
            if((pa->coefficient)+(pb->coefficient)==0){
                    pa=pa->link;
                    pb=pb->link;
            }
        else{
            LinkNode *newNode=new LinkNode((pa->coefficient)+(pb->coefficient),pa->exponent);
            pc->link=newNode;
            pc=pc->link;
            pa=pa->link;
            pb=pb->link;
            ++C.maxSize;
            }
        }
        else if(pa->exponent<(pb->exponent)){
            LinkNode *newNode=new LinkNode(pa->coefficient,pa->exponent);
            pc->link=newNode;
            pc=pc->link;
            pa=pa->link;
            ++C.maxSize;
        }
        else if(pa->exponent>(pb->exponent)){
            LinkNode *newNode=new LinkNode(pb->coefficient,pb->exponent);
            pc->link=newNode;
            pc=pc->link;
            pb=pb->link;
            ++C.maxSize;
        }
    }

    if(pa!=NULL) p=pa;
    else p=pb;
    while(p!=NULL){
        LinkNode *newNode=new LinkNode(p->coefficient,p->exponent);
        pc->link=newNode;
        pc=pc->link;
        p=p->link;
        ++C.maxSize;
    }
    return C;
}

// 重载“-”
List operator-(List &A,List &B){
    List C;
    LinkNode *pa,*pb,*pc;
    pa=A.first->link;
    pb=B.first->link;
    pc=C.first;
    while(pa!=NULL && pb!=NULL){
        if(pa->exponent==(pb->exponent)){
                if(pa->coefficient!=(pb->coefficient)){
                    LinkNode *newNode=new LinkNode((pa->coefficient)-(pb->coefficient),pa->exponent);
                    pc->link=newNode;
                    pc=pc->link;
                    pa=pa->link;
                    pb=pb->link;
                    ++C.maxSize;
                }
                else{
                    pa=pa->link;
                    pb=pb->link;
                }
        }
        else if(pa->exponent<(pb->exponent)){
            LinkNode *newNode=new LinkNode(pa->coefficient,pa->exponent);
            pc->link=newNode;
            pc=pc->link;
            pa=pa->link;
            ++C.maxSize;
        }
        else if(pa->exponent>(pb->exponent)){
            LinkNode *newNode=new LinkNode(-(pb->coefficient),pb->exponent);
            pc->link=newNode;
            pc=pc->link;
            pb=pb->link;
            ++C.maxSize;
        }
    }
    while(pa!=NULL){
        LinkNode *newNode=new LinkNode(pa->coefficient,pa->exponent);
        pc->link=newNode;
        pc=pc->link;
        pa=pa->link;
        ++C.maxSize;
    }
    while(pb!=NULL){
        LinkNode *newNode=new LinkNode(-(pb->coefficient),pb->exponent);
        pc->link=newNode;
        pc=pc->link;
        pb=pb->link;
        ++C.maxSize;
    }
    return C;
}

// 重载"*"
List operator*(List &A,List &B){
    List C;
    int m,temp;
    m=A.getMax()+B.getMax();
    int *result=new int[m+1];
    LinkNode *pa,*pb,*pc;
    C.maxSize=0;
    for(int i=0;i<=m;++i) result[i]=0;
    pa=A.first->link;
    pc=C.first;
    while(pa!=NULL){
        pb=B.first->link;
        while(pb!=NULL){
            temp=pa->exponent+pb->exponent;
            result[temp]+=(pa->coefficient)*(pb->coefficient);
            pb=pb->link;
        }
        pa=pa->link;
    }
    for(int i=0;i<=m;++i){
        if(result[i]!=0){
            LinkNode *newNode=new LinkNode(result[i],i);
            pc->link=newNode;
            pc=pc->link;
            ++C.maxSize;
        }
    }
    return C;
}

// 求导
List List::derivation(){
    List C;
    LinkNode *pc=C.first;
    LinkNode *newNode;
    LinkNode *p=first->link;
    while(p!=NULL){
        if(p->exponent!=0){
             newNode=new LinkNode(((p->coefficient)*(p->exponent)),((p->exponent)-1));
             pc->link=newNode;
             pc=pc->link;
        }
        p=p->link;
    }
    return C;
}

// 代数计算
float List::calculate(float x){
    LinkNode *p=first->link;
    float result=0;
    while(p!=NULL){
        result+=(p->coefficient)*pow(x,(p->exponent));
        p=p->link;
    }
    return result;

}

// 最大指数
int List::getMax(){
    LinkNode *p=first->link;
    while(p!=NULL){
        if(p->link==NULL){
            return p->exponent;
        }
        p=p->link;
    }

}
int main()
{
        char str;
        List equation1,equation2;
 //       freopen("in3.txt","r",stdin);
        while(cin>>str){
            switch(str){
            case 'C':
            {
                equation1.input();
                equation2.input();
                break;
                }
            case 'P':
                (equation1+equation2).output();
                break;
            case 'S':
                (equation1-equation2).output();
                break;
            case 'M':
                (equation1*equation2).output();
                break;
            case 'D':
                (equation1.derivation()).output();
                break;
            case 'V':
            {
                float num;
                cin>>num;
                printf("%.2f\n",equation1.calculate(num));
                break;
                }
            case 'X':
                return 0;
                break;
            }
        }

}
