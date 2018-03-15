#include <iostream>
#include <cstring>
using namespace std;
int nflag[20];
int sushu[50];
int nsort[20],n;
int isSushu(int num){
	for(int i=2;i<num;i++)if(num%i==0)return 0;
	return 1;
}
void set_sort(int cur){
	if(cur==n){
		for(int i=1;i<=n;i++)
			if(!nflag[i]){
				if(sushu[nsort[cur-1]+i]&&sushu[nsort[1]+i]){
//					nsort[cur]=i;
//					cout<<nsort[1];
//					for(int k=2;k<=n;k++)	
//						cout<<" "<<nsort[k];
//					cout<<endl;
					;
				}
				break;
			}
	}else{
		for(int i=1;i<=n;i++)
			if(!nflag[i]){
				
				if(i!=1&&!sushu[i+nsort[cur-1]])
					continue; 
				nflag[i]=1;
				nsort[cur]=i;
				set_sort(cur+1);
				nflag[i]=0;
			}
	}
}
int main(){
	memset(nflag,0,sizeof(nflag));
	memset(nsort,0,sizeof(nsort));
	memset(sushu,0,sizeof(sushu));
	for(int i=2;i<=n*2;i++)
		if(isSushu(i))
			sushu[i]=1;
	scanf("%d",&n);
	set_sort(1);
	return 0;
}
