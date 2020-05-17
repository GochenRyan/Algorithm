#include <iostream>
#include <stdio.h>
#include <queue>
#include <stdio.h>
using namespace std;

struct Edge
{
    int dest;
    int cost;
    Edge *link;
    Edge() {link=NULL;}
};

struct Vertex
{
    char data;
    Edge *adj;
};

class Graphlnk
{
private:
    Vertex *NodeTable;
    int tableSize;
public:
    ~Graphlnk();
    void createGraphlnk();
    int getFirstNeighbor(int v);
    int getNextNeighbor(int v,int w);
    void Insert(int x,Edge *node);
    int getLoc(char x);
    char getValue(int n)
    {
        return NodeTable[n].data;
    }
    int getSize()
    {
        return tableSize;
    }
    void printCost();
};

Graphlnk::~Graphlnk()
{
    for(int i=0; i<tableSize; ++i)
    {
        Edge *p=NodeTable[i].adj;
        while(p!=NULL)
        {
            NodeTable[i].adj=p->link;
            delete p;
            p=NodeTable[i].adj;
        }
    }
    delete []NodeTable;
}

int Graphlnk::getLoc(char x)
{
    for(int i=0; i<tableSize; ++i)
    {
        if(NodeTable[i].data==x) return i;
    }
    return -1;
}

//插入节点
void Graphlnk::Insert(int x,Edge *node)
{
    if(NodeTable[x].adj==NULL)
    {
        NodeTable[x].adj=node;
    }
    else
    {
        Edge *p=NodeTable[x].adj;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=node;
    }
}

//构造函数
void Graphlnk::createGraphlnk()
{
    cin>>tableSize;
    NodeTable=new Vertex[tableSize];
    for(int k=0;k<tableSize;++k) NodeTable[k].adj=NULL;
    for(int i=0; i<tableSize; ++i)
    {
        cin>>NodeTable[i].data;
    }
    int edgeSize;
    cin>>edgeSize;
    for(int j=0; j<edgeSize; ++j)
    {
        int tableDest;
        cin>>tableDest;
        Edge *newEdge1=new Edge();
        cin>>newEdge1->dest;
        cin>>newEdge1->cost;
        Edge *newEdge2=new Edge();
        newEdge2->dest=tableDest;
        newEdge2->cost=newEdge1->cost;
        Insert(tableDest,newEdge1);
        Insert(newEdge1->dest,newEdge2);
    }
}

//找邻接点
int Graphlnk::getFirstNeighbor(int v)
{
    if(v!=-1)
    {
        Edge *p=NodeTable[v].adj;
        if(p!=NULL) return p->dest;
    }
    else return -1;
}

//深度优先遍历
void DFS(Graphlnk &G,const int v,bool *visited)
{
    cout<<G.getValue(v)<<' ';
    visited[v]=true;
    int w=G.getFirstNeighbor(v);
    while(w!=-1)
    {
        if(!visited[w]) DFS(G,w,visited);
        else{
            w=G.getNextNeighbor(v,w);
        }
    }
}
void DFS(Graphlnk &G,const char v)
{
    int loc;
    bool *visited=new bool[G.getSize()];
    for(int i=0; i<G.getSize(); ++i) visited[i]=false;
    loc=G.getLoc(v);
    DFS(G,loc,visited);
    delete []visited;
}

//找下一个邻接点
int Graphlnk::getNextNeighbor(int v,int w)
{
    if(v!=-1)
    {
        Edge *p=NodeTable[v].adj;
        while(p!=NULL && p->dest!=w) p=p->link;
        if(p!=NULL && p->link!=NULL){
            return p->link->dest;
        }
    }
    return -1;
}

//广度优先遍历
void BFS(Graphlnk &G,const char &v)
{
    int loc;
    bool *visited=new bool[G.getSize()];
    loc=G.getLoc(v);
    for(int i=0; i<G.getSize(); ++i) visited[i]=false;
    queue<int> Q;
    Q.push(loc);
    while(!Q.empty())
    {
        while(!Q.empty()){
            loc=Q.front();
            cout<<G.getValue(loc)<<' ';
            Q.pop();
            visited[loc]=true;
        }
        int w=G.getFirstNeighbor(loc);
        while(w!=-1)
        {
            if(!visited[w])
                Q.push(w);
            w=G.getNextNeighbor(loc,w);
        }
    }
    delete []visited;
}

//输出权值
void Graphlnk::printCost()
{
    bool *visited=new bool[tableSize];
    for(int i=0;i>tableSize;++i) visited[i]=false;
    for(int i=0; i<tableSize; ++i)
    {
        Edge *w=NodeTable[i].adj;
        while(w!=NULL)
        {
            if(!visited[w->dest]){
            cout<<NodeTable[i].data<<'-'<<NodeTable[w->dest].data<<':'<<w->cost<<endl;
            }
            w=w->link;
        }
        visited[i]=true;
    }
}

int main()
{
    Graphlnk ex;
    freopen("data.txt","r",stdin);
    ex.createGraphlnk();
    cout<<"DFS:";
    DFS(ex,'a');
    cout<<endl;
    cout<<"BFS:";
    BFS(ex,'a');
    cout<<endl;
    cout<<"edges are:"<<endl;
    ex.printCost();
}
