#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
__int64 res[30][30];
int main(){
	int T;
	memset(res,0,sizeof(res));
	res[1][1]=1;
	for(int i=2;i<=25;i++)
		for(int j=1;j<=i;j++){
			res[i][j]=res[i-1][j-1]+res[i-1][j]*j;
		}
	
	cin>>T;
	for(int t=0;t<T;t++){
		int n;
		cin>>n;
		__int64 sum=0;
		for(int k=1;k<=n;k++)
			sum+=res[n][k];
		cout<<sum<<endl;
	}
	return 0;
}
