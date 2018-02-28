#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
using namespace std;

int dpA[100005][12];
int drop[100005][12];
int main(){
	int n,MaxT;
	cin>>n;
	while(n!=0){
		int x,T;
		MaxT=0;
		memset(dpA,0,sizeof(dpA));
		memset(drop,0,sizeof(drop));
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x,&T);
			if(T>MaxT)MaxT=T;
			drop[T][x]+=1;
		}
		dpA[1][4]=drop[1][4];dpA[1][5]=drop[1][5];dpA[1][6]=drop[1][6];
		for(int i=2;i<=MaxT;i++)
			for(int j=0;j<=10;j++){
				int a=0,b=0,c=0;
				if(j==0){
					dpA[i][j]=max(dpA[i-1][j],dpA[i-1][j+1])+drop[i][j];
				}else if(j==10){
					dpA[i][j]=max(dpA[i-1][j],dpA[i-1][j-1])+drop[i][j];
				}else{
					int a=dpA[i-1][j-1];
					int b=dpA[i-1][j];
					int c=dpA[i-1][j+1];
					int hehe=a<b?b:a;
					int hehe1=hehe<c?c:hehe;
					dpA[i][j]=hehe1+drop[i][j];					
				}
			}
		int res=0;
		for(int i=0;i<=10;i++)
			if(dpA[MaxT][i]>res)
				res=dpA[MaxT][i];
		cout<<res<<endl;	
		cin>>n;
	}
	return 0;
}
