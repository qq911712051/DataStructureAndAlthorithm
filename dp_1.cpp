#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
int Map[110][110],N;
int sum[110][110];
int main(){
	memset(sum,0,sizeof(sum));
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&Map[i][j]);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			sum[i][j]=max(sum[i-1][j],sum[i-1][j-1])+Map[i][j];
		}
	}
	int max=0;
	for(int i=1;i<=N;i++)
		if(sum[N][i]>max)
			max=sum[N][i];
	cout<<max<<endl;
	return 0;
}
