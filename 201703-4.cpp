#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAXSIZE=100005;
const int INF=0x7fffffff;
int n,m;
struct Edge{
	int next;
	int w;
	Edge(int a,int b){
		next=a;
		w=b;
	}
};
int vis[MAXSIZE];
int dis[MAXSIZE];
struct cmp{
	bool operator()(const int a,const int b){
		return dis[a]>dis[b];
	}
};

vector<Edge> G[MAXSIZE];
void dj(int start){
	priority_queue<int,vector<int>,cmp> que;
	que.push(1);
	while(!que.empty()){
		int cur=que.top();
		que.pop();
	
		vis[cur]=1;
		vector<Edge>& list=G[cur];
		for(int i=0;i<list.size();i++){
			if(!vis[list[i].next]){
				int now=dis[cur]>list[i].w?dis[cur]:list[i].w;
				if(now<dis[list[i].next]){
					dis[list[i].next]=now;
					que.push(list[i].next);
				}
				
			}
		}
	}
}
int main(){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<MAXSIZE;i++)dis[i]=INF;
	dis[1]=0;
	scanf("%d%d",&n,&m);
	int a,b,c;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		G[a].push_back(Edge(b,c));
		G[b].push_back(Edge(a,c));
	}
	dj(1);
	cout<<dis[n]<<endl;
	return 0;
}
