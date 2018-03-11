#include <iostream>
#include <string>
//#include <stdio.h>

using namespace std;

int main()
{
//    freopen("data.txt","r",stdin);
    string label[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string bNum,fNumToStr;
    int fNum = 0;
    cin>>bNum;
    for(int k = bNum.length() - 1; k >= 0; k--){
        fNum = fNum + (bNum[k] - '0');
    }
    cout<<fNum<<endl;
    fNumToStr = std::to_string(fNum);
    for(int i = 0; i < fNumToStr.length(); i++){
        cout<<label[fNumToStr[i] - '0'];
        if(i < fNumToStr.length() - 1){
            cout<<' ';
        }
    }
    return 0;
}
