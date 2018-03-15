#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=10005; 
vector<int> G[MAXN*2];
int deep[2*MAXN];
int n,m;
bool cmp(const int a,const int b){
	return a>b;
}
int findDeep(int u){
	if(deep[u]!=0)
		return deep[u];
	int Max=-1;
	for(int i=0;i<G[u].size();i++){
		int a=findDeep(G[u][i]);
		if(Max<a)
			Max=a;
	}
	deep[u]=Max+1;
	return deep[u];
}
long long find(int u){
	if(G[u].size()==0){
		return 0;
	}
	int Max=-1;
	int maxDep=-1;
	vector<int> dept;
	for(int i=0;i<G[u].size();i++){
		int now=find(G[u][i]);
		Max=Max>now?Max:now;
		int hehe=findDeep(G[u][i]);
		if(hehe+1>maxDep)
			maxDep=hehe+1;
		dept.push_back(hehe+1);
	} 
	sort(dept.begin(),dept.end(),cmp);
	deep[u]=maxDep;
	if(G[u].size()==1){
		return maxDep>Max?maxDep:Max;
	}else{
		return Max>(dept[0]+dept[1])?Max:(dept[0]+dept[1]);
	}
}
int main(){
	memset(deep,0,sizeof(deep));
	scanf("%d%d",&n,&m);
	int a;
	for(int i=1;i<=m+n;i++){
		if(i!=1){
			scanf("%d",&a);
			G[a].push_back(i);	
		}
	}
	long long res=find(1);
	cout<<res<<endl;
	return 0;
}
