#include <iostream>

using namespace std;

int main()
{
    int num;
    int k = 0;
    cin>>num;
    while(num != 1){
        if(num % 2 == 0){
            num /= 2;
        }
        else{
            num = (3 * num + 1) / 2;
        }
        k++;
       // cout<<num;
    }
    cout<<k;
    return 0;
}
