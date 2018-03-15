#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
int n,m;
struct Edge{
	int node;
	int w;
	int t;
	Edge(int node,int wei,int t){
		this.node=node;
		this.w=wei;
		this.t=t;
	}
};
vector<Edge> G[505];
int state[505];
long long dist[505],small[505],big[505];
int find(int cur){
	if(state[cur]==1)
		return 1;
	state[cur]=-1;
	
	
	
	state[cur]=1;
	return 1;
	
}
int main(){
	memset(G,0,sizeof(G));
	memset(state,0,sizeof(state));
	memset(dist,0,sizeof(dist));
	memset(small,0,sizeof(small));
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int t,u,v,w;
		scanf("%d%d%d%d",&t,&u,&v,&w);
		G[u].push_back(Edge(v,w,t));
		G[v].push_back(Edge(u,w,t));
	}
	find(n);
	return 0;
}
