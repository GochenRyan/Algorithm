//BOSS掉落A、B、C三件装备，A、B、C的掉落几率都是1/3，但是BOSS每次只掉1件装备。为了凑齐A、B、C三件装备，期望需要打多少次？
//3*（1/3）*（2/3）+4*（1/3）*（2/3）*(1/3+2/3)+5*(1/3)*(2/3)*(1/3 * 1/3 + 1/3 * 2/3 + 2/3 * 2/3)+6*(1/3)*(2/3)*(1/3 * 1/3 * 1/3 + 1/3 * 1/3 * 2/3 + 1/3 * 2/3 * 2/3+2/3 * 2/3 * 2/3)+...
#include <iostream>
#include <cmath>

using namespace std;

double expect(int n){
    double result = (double)2/3;
    if(n < 3){
        return 0;
    }else if(n<4){
        return (double)2/3;
    }else{
        for(int i = 4;i <= n;i++){
            double result1 = 0;
            int count1 = n-3;
            for(int j = 0;j < n-2;j++){
                result1 += pow((double)1/3,count1-j)*pow((double)2/3,j);
            }
            result += n*result1;
        }
        return ((double)1/3)*((double)2/3)*result;
    }
}

int main()
{
    int n;
    cout<<"请输入n"<<endl;
    cin>>n;
    cout<<expect(n)<<endl;
    return 0;
}
