#include <iostream>

using namespace std;

int main()
{
    string intStr;
    cin>>intStr;
    for(int i = 0; i < intStr.length(); i++){
        int k = intStr[i] - '0';
        int _i = i;
        if(intStr.length() == 2){
            _i = i + 1;
        }else if(intStr.length() == 1){
            _i = i + 2;
        }
        switch(_i){
            case 0:{
                while(k--){
                    cout<<'B';
                }
                break;
            }
            case 1:{
                while(k--){
                    cout<<'S';
                }
                break;
            }
            case 2:{
                if(k == 0) break;
                int kcount = 1;
                while(kcount != k + 1){
                    cout<<kcount++;
                }
                break;
            }
        }
    }
    return 0;
}
