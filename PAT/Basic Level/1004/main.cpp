#include <iostream>

using namespace std;

struct stu{
    string name;
    string id;
    int score;
};

int main()
{
    freopen("data.txt","r",stdin);
    int t;
    cin>>t;
    stu stus[t],stuMax,stuMin;
    stuMax.score = INT_MIN;
    stuMin.score = INT_MAX;
    for(int i = 0; i < t; i++){
        cin>>stus[i].name>>stus[i].id>>stus[i].score;
        if(stus[i].score > stuMax.score){
            stuMax = stus[i];
        }
        if(stus[i].score < stuMin.score){
            stuMin = stus[i];
        }
    }
    cout<<stuMax.name<<' '<<stuMax.id<<endl;
    cout<<stuMin.name<<' '<<stuMin.id<<endl;
    return 0;
}
