#include <iostream>
#include <cstring>
using namespace std;
int pupil[1005],next[1005],pre[1005];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		if(i!=n)
			next[i]=i+1;
		else
			next[i]=1;
		if(i!=1)
			pre[i]=i-1;
		else
			pre[i]=n;
	}
	int cur=1,number=1;
	while(next[cur]!=cur){
		if(number%k==0||number%10==k){
			int pre1=pre[cur];
			int net=next[cur];
			next[pre1]=net;
			pre[net]=pre1;
			
		}
		number++;
		cur=next[cur];
	}
	cout<<cur<<endl;
	return 0;
}
