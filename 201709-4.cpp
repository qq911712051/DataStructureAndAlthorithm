#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int vis[1005][1005],n,m;
int state[1005];
int tu[1005],t;
int enter[1005],now;
vector<int> G[1005];
void dfs(int cur){
	state[cur]=1;
	vis[cur][now]=vis[now][cur]=1;
	vector<int>& list=G[cur];
	for(int i=0;i<list.size();i++){
		if(!state[list[i]])dfs(list[i]);
	}
}
int main(){
	memset(vis,0,sizeof(vis));
	memset(tu,0,sizeof(tu));
	memset(G,0,sizeof(G));
	memset(enter,0,sizeof(enter));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)vis[i][i]=1;
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		memset(state,0,sizeof(state));
		now=i;
		dfs(i);
	}
	int num=0;
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=1;j<=n;j++){
			if(!vis[i][j]){
				flag=1;break;
			}
		}
		if(!flag){
			num++;
		}
	}	
	cout<<num<<endl;
	return 0;
}
