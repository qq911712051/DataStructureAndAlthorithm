#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int n,cont[1005];
int dp[1005][1005];
int sum[1005][1005];
const int INF=0xfffffff;
int findDp(int i,int j){
	if(i==j)return 0;
	if(dp[i][j]!=INF)
		return dp[i][j];
	int Min=INF,now;
	for(int k=i;k<j;k++){
		now=findDp(i,k)+findDp(k+1,j);
		if(now<Min){
			Min=now; 
		}
	}
	dp[i][j]=Min+sum[i][j];
	return dp[i][j];
	
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&cont[i]);
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j)dp[i][j]=0;
			else dp[i][j]=INF;
			if(j==i)sum[i][j]=cont[i];
			else{
				sum[i][j]=sum[i][j-1]+cont[j];
			}
		}
	}
	int res=findDp(1,n);
	cout<<res<<endl;
}
