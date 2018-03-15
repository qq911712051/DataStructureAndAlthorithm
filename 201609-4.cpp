#include <iostream>
#include <queue>
#include <list>
#include <set>
#include <cstring>
using namespace std;
int dist[10005];
struct Edge{
	int next;
	int weight;
	bool operator==(const Edge e)const{
		return next==e.next;
	}
};
struct cmp{
	bool operator()(const int a,const int b){
		return dist[b]>dist[a];
	}
};
int n,m;
const int INF=0x7fffffff;

vector<Edge> head[10005];
int vis[10005];
int pre[10005],reco[10005];
void dijk(){
	priority_queue<int,vector<int>,cmp> que;
	que.push(1);
	while(!que.empty()){
		int cur=que.top();
		que.pop();
		if(vis[cur])continue;
		vis[cur]=1;
		vector<Edge>& tmp=head[cur];
		int len=tmp.size();
		for(int i=0;i<len;i++){
			Edge& te=tmp[i];
			if(!vis[te.next]&&(te.weight+dist[cur]<=dist[te.next])){
				if((te.weight+dist[cur]==dist[te.next])&&reco[te.next]>te.weight){
					reco[te.next]=te.weight;
					pre[te.next]=cur;
					continue;
				}
				dist[te.next]=te.weight+dist[cur];
				pre[te.next]=cur;
				reco[te.next]=te.weight;
				que.push(te.next);
			}
		}
	}
}
int main(){
	memset(head,0,sizeof(head));
	memset(pre,0,sizeof(pre));
	memset(vis,0,sizeof(vis));
	memset(reco,0,sizeof(reco));
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++){
		dist[i]=INF;
	}
	dist[1]=0;
	
	int a,b,c;
	Edge e;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		e.next=b;e.weight=c;
		head[a].push_back(e);
		e.next=a;
		head[b].push_back(e);
	}
	dijk();
	long long sum=0;
	for(int i=2;i<=n;i++){
		sum+=reco[i];
	}
	cout<<sum<<endl;
	return 0;
	
} 
