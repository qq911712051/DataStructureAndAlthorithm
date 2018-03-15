#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n,m,t;
int map[105][105];
int sTime[105][105];
int eTime[105][105];
int vis[105][105][400];
int dir[4][2]={-1,0,0,1,1,0,0,-1};//上右下左 
struct Node{
	int x,y;
	int step;
	Node(int a,int b,int c){
		x=a;y=b;step=c;
	}
	bool operator<(const Node& b)const{
		return step>b.step;
	}
};
int bfs(Node node){
	queue<Node> que;
	que.push(node);
	
	while(!que.empty()){
		Node cur=que.front();
		que.pop();
		if(vis[cur.x][cur.y][cur.step])continue;
		if(cur.x==n&&cur.y==m){
			return cur.step;
		}
		vis[cur.x][cur.y][cur.step]=1;
		for(int i=0;i<4;i++){
			Node tmp=cur;
			tmp.x+=dir[i][0];
			tmp.y+=dir[i][1];
			tmp.step++;
			if(!vis[tmp.x][tmp.y][tmp.step]&&tmp.x>0&&tmp.x<=n&&tmp.y>0&&tmp.y<=m){
				//位置合法
				 if(sTime[tmp.x][tmp.y]==-1||tmp.step<sTime[tmp.x][tmp.y]||tmp.step>eTime[tmp.x][tmp.y]){
				 
					que.push(tmp);
				 }
			}
		}
	}
	return -1;
}
int main(){
	memset(map,0,sizeof(map));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<105;i++)
		for(int j=0;j<105;j++){
			sTime[i][j]=-1;
			eTime[i][j]=-1;
		}
	scanf("%d%d%d",&n,&m,&t);
	int a,b,c,d;
	for(int i=0;i<t;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		sTime[a][b]=c;
		eTime[a][b]=d;
	}
	int res=bfs(Node(1,1,0));
	cout<<res<<endl;
	return 0;
}
