#include <iostream>
#include <assert.h>
#include <cstring>
#include <stdio.h>
using namespace std;

const int maxLength=100;

class LinkedStack;
class LinkNode
{
    friend class LinkedStack;
private:
    char data;
    LinkNode *link;
public:
    LinkNode(LinkNode *ptr=NULL)
    {
        link=ptr;
    }
    LinkNode(char item,LinkNode *ptr=NULL)
    {
        data=item;
        link=ptr;
    }
};

class LinkedStack
{
private:
    LinkNode *top;
public:
    LinkedStack():top(NULL) {}
    ~LinkedStack()
    {
        makeEmpty();
    }
    void push(const char &x);
    char pop();
    bool isEmpty()const
    {
        return (top==NULL)? true:false;
    }
    void makeEmpty();
    char getTop()
    {
        return top->data;
    }
};

void LinkedStack::makeEmpty()
{
    LinkNode *p;
    while(top!=NULL)
    {
        p=top;
        top=top->link;
        delete p;
    }
}

void LinkedStack::push(const char &x)
{
    top=new LinkNode(x,top);
    assert(top!=NULL);
}

char LinkedStack::pop()
{
    char x;
    if(isEmpty()) return false;
    LinkNode *p=top;
    top=top->link;
    x=p->data;
    delete p;
    return x;
}

void printMacthedPairs(char *expression)
{
    LinkedStack s;
    int length=strlen(expression);
    for(int i=1; i<=length; ++i)
    {
        if(expression[i-1]=='{' || expression[i-1]=='<' || expression[i-1]=='(' || expression[i-1]=='[')
        {
            s.push(expression[i-1]);
        }
        else if(expression[i-1]=='}')
        {
            if(!s.isEmpty())
            {
                if(s.getTop()=='{')
                {
                    s.pop();
                }
            }
            else
            {
                cout<<"The "<<i<<" character"<<" \'}\' "<<"is wrong."<<endl;
                return;
            }
        }
        else if(expression[i-1]=='>')
        {
            if(!s.isEmpty())
            {
                if(s.getTop()=='<')
                {
                    s.pop();
                }
            }
            else
            {
                cout<<"The "<<i<<" character"<<" \'>\' "<<"is wrong."<<endl;
                return;
            }
        }
        else if(expression[i-1]==']')
        {
            if(!s.isEmpty())
            {
                if(s.getTop()=='[')
                {
                    s.pop();
                }
            }
            else
            {
                cout<<"The "<<i<<" character"<<" \']\' "<<"is wrong."<<endl;
                return;
            }
        }
        else if(expression[i-1]==')')
        {
            if(!s.isEmpty())
            {
                if(s.getTop()=='(')
                {
                    s.pop();
                }
            }
            else
            {
                cout<<"The "<<i<<" character"<<" \')\' "<<"is wrong."<<endl;
                return;
            }
        }
    }
    if(s.isEmpty())
    {
        cout<<"right"<<endl;
    }
    else if(!s.isEmpty())
    {
        cout<<"loss of right character ";
        while(!s.isEmpty())
        {
            if(s.getTop()=='(')
            {
                cout<<')';
                s.pop();
            }
            else if(s.getTop()=='{')
            {
                cout<<'}';
                s.pop();
            }
            else if(s.getTop()=='[')
            {
                cout<<']';
                s.pop();
            }
            else if(s.getTop()=='<')
            {
                cout<<'>';
                s.pop();
            }
        }
        cout<<'.'<<endl;
    }
}
int main()
{
    char str[maxLength];
//    freopen("data.txt","r",stdin);
    cin>>str;
    printMacthedPairs(str);
}
