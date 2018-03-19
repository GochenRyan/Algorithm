#include <iostream>
#include <algorithm>

using namespace std;

void checkNum(int **cal, int t, int mid){
    for(int i = 0; i < t; i++){
        if(*((int*)cal + 0 + i) == mid){
            *((int*)cal + t + i) = 1;
        }
    }
}

int cmp(const int &a, const int &b){
    return a > b; //降序排列
}

int main()
{
  //  freopen("data.txt","r",stdin);
    int t;
    cin>>t;
    int cal[t][t] = {0};
    for(int i = 0; i < t; i++){
        cin>>cal[0][i];
    }
    sort(cal[0],cal[0]+(t-1)*sizeof(int),cmp);

    //比较
    for(int i = 0; i < t; i++){
        int mid = cal[0][i];
        while(mid != 1){
            if(mid%2 == 1){
                mid = (mid * 3 + 1) / 2;
            }else{
                mid = mid / 2;
            }
            checkNum((int**)cal, t, mid);
        }
    }

    //输出
    int k = 0;
    for(int i = 0; i < t; i++){
        if(cal[1][i] == 0){
            k ++;
            if(k != 1){
                cout<<' ';
            }
            cout<<cal[0][i];
        }
    }
    return 0;
}
