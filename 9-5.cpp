#include <iostream>
using namespace std;
int C,cap[105],weight[105];
int dp[105][10000];
int main(){
	
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=C;j++){
			int a=dp[i-1][j];
			int b=dp[i-1][j-cap[i]]+weight[i];
			dp[i][j]=a>b?a:b;
		}
	return 0;
}
