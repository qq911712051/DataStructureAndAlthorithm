#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int n,m,k;
long long r;
long long distance(long long x1,long long y1,long long x2,long long y2){
	return pow((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1),0.5);
}
struct Node{
	int pos;
	int step;
	int preNum;
};
int posx[300],posy[300];
int vis[300];
int srcx,srcy,dstx,dsty;
int bfs(Node node){
	vis[node.pos]=1;
	queue<Node> q;
	q.push(node);
	while(!q.empty()){
		Node cur=q.front();
		q.pop();
		for(int i=1;i<=m+n;i++){
			if(!vis[i]&&distance(posx[cur.pos],posy[cur.pos],posx[i],posy[i])<=r){
				if(i<=n){
					if(posx[i]==dstx&&posy[i]==dsty){
						return cur.step+1; 
					}
					Node tmp;
					tmp.step=cur.step+1;
					tmp.pos=i;
					q.push(tmp);	
				}else{
					for(int s=1;s<=m+n;s++){
						if(vis[s]&&)
					}
					Node tmp;
					tmp.step=cur.step+1;
					tmp.pos=i;
					tmp.preNum=cur.preNum+1;
					if(tmp.preNum>k){
						continue;
					}
				}
				
				vis[i]=1;
			}
		}
		
		
	}
}
int main(){
	memset(posx,0,sizeof(posx));
	memset(vis,0,sizeof(vis));
	memset(posy,0,sizeof(posy));
	scanf("%d%d%d%d"k,&n,&m,&k,&r);
	int tmpx,tmpy;
	for(int i=1;i<=n+m;i++){
		cin>>posx[i]>>posy[i];
	}
	srcx=posx[0];srcy=posy[0];
	dstx=posx[1];dsty=posy[1];
	Node o;
	o.pos=1;
	o.step=0;
	o.preNum=0;
	bfs(o);
	return 0;
}
