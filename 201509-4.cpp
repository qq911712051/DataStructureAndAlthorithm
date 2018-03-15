#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<int> G[10005];
char go[10005][10005];
int vis[10005];
void bfs(int pos){
	queue<int> que;
	que.push(pos);
	while(!que.empty()){
		int cur=que.front();
		que.pop();
		if(vis[cur])continue;
		vis[cur]=1;
		go[pos][cur]=1;
		for(int i=0;i<G[cur].size();i++)
			if(!vis[G[cur][i]])que.push(G[cur][i]);
	}
}
int main(){
	memset(G,0,sizeof(G));
	memset(go,0,sizeof(go));
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		G[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		bfs(i);
	}
	long long num=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(go[i][j]&&go[j][i]){
				num++;
			}
		}
	}
	cout<<num<<endl;
	return 0;
}
