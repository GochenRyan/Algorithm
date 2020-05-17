#include <iostream>
int sum,ans[8];
int solve(int n, long long mark, int *ans){
	for (int i=n>8?++sum&0:0; n>8&&i<8; i!=7?std::cout << ans[i++] << " " : std::cout << ans[i++] << std::endl);
	for (int i=0; i<8; !(mark>>i&1)&&!(mark>>(n+i+7)&1)&&!(mark>>(n-i+30)&1)?solve(n+(ans[n-1]=i+1)-i, mark|1ll<<i|1ll<<(n+i+7)|1ll<<(n-i+30), ans):0,i++);
	return sum;
}
int main(){
	std::cout << solve(1, 0, ans) << std::endl;
}
