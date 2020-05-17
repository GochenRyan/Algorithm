#include <iostream>

using namespace std;

static int vis[3][15]={0};
static int gEightQueen[8]={0};
static int tot=0;

//Êä³ö
void print(){
    int outer;
    int inner;
    for (outer=0;outer<8;outer++){
        for(inner=0;inner<gEightQueen[outer];inner++)
            cout<<"* ";
    cout<<"# ";
    for(inner=gEightQueen[outer]+1;inner<8;inner++)
        cout<<"* ";
    cout<<endl;
    }
    cout<<"====================================="<<endl;
}

void search(int cur){
    if(cur==8){
        print();
        tot++;
        cout<<tot<<endl;
    }
    else for(int i=0;i<8;i++){
        if(!vis[0][i] && !vis[1][cur+i] && !vis[2][7-i+cur]){
            gEightQueen[cur]=i;
            vis[0][i]=vis[1][cur+i]=vis[2][7-i+cur]=1;
            search(cur+1);
            vis[0][i]=vis[1][cur+i]=vis[2][7-i+cur]=0;
        }
    }
}

int main(){
    search(0);
    cout<<"total="<<tot<<endl;
    return 0;
}
