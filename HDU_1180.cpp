#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
struct Node{
	int x,y,dist;
	bool operator<(const Node& a)const{
		return dist>a.dist;
	}
};
int dir[4][2]={-1,0,0,1,1,0,0,-1};
char Map[30][30],M,N;
int vis[30][30];
int sx,sy,tx,ty;
int check(Node node,int dire){
	
	int x=node.x,y=node.y;
	if(x<1||x>M||y<1||y>N||Map[x][y]=='*'||vis[x][y])
		return 0;
	else if(Map[x][y]=='.'||Map[x][y]=='T') 
		return 1;
	else if((Map[x][y]=='-'&&(dire==1||dire==3)&&node.dist%2==0)||(Map[x][y]=='-'&&(dire==0||dire==2)&&node.dist%2==1)||(Map[x][y]=='|'&&(dire==0||dire==2)&&node.dist%2==0)||(Map[x][y]=='|'&&(dire==1||dire==3)&&node.dist%2==1)){ 
		return 2;
	} 
	else 
		return 3;	
}

void bfs(Node node){
	priority_queue<Node> q;
	q.push(node);
	while(!q.empty()){
		Node cur=q.top();
		
		q.pop();
		if(cur.x==tx&&cur.y==ty){
			cout<<cur.dist<<endl;
			return;
		}
		for(int i=0;i<4;i++){
			Node tmp=cur;
			tmp.x+=dir[i][0];tmp.y+=dir[i][1];	
			int res=check(tmp,i);
			tmp.dist+=1;
			switch(res){
				case 0:		
					break;
				case 1:
					vis[tmp.x][tmp.y]=1;
					q.push(tmp);
				
					break;
				case 2:
					if(i==0&&tmp.x>1&&(Map[tmp.x-1][tmp.y]=='.'||Map[tmp.x-1][tmp.y]=='T')&&!vis[tmp.x-1][tmp.y]){
						tmp.x-=1;
						vis[tmp.x][tmp.y]=1;
						
						
						q.push(tmp);
					} else 
					if(i==1&&tmp.y<N&&(Map[tmp.x][tmp.y+1]=='.'||Map[tmp.x][tmp.y+1]=='T')&&!vis[tmp.x][tmp.y+1]){
						tmp.y+=1;
						vis[tmp.x][tmp.y]=1;
						
						q.push(tmp);
					} else
					if(i==2&&tmp.x<M&&(Map[tmp.x+1][tmp.y]=='.'||Map[tmp.x+1][tmp.y]=='T')&&!vis[tmp.x+1][tmp.y]){
						tmp.x+=1;
						vis[tmp.x][tmp.y]=1;
					
						q.push(tmp);
					} else
					if(i==3&&tmp.y>1&&(Map[tmp.x][tmp.y-1]=='.'||Map[tmp.x][tmp.y-1]=='T')&&!vis[tmp.x][tmp.y-1]){
						tmp.y-=1;
						vis[tmp.x][tmp.y]=1;
					
						q.push(tmp);
					}
					break;
				case 3:
					tmp.x-=dir[i][0];tmp.y-=dir[i][1];
					q.push(tmp);
				
					break;
				default:break;	
			};
		}
	
	}
	
}
int main(){
	while(scanf("%d %d",&M,&N)==2){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++){
				cin>>Map[i][j];
				if(Map[i][j]=='S'){
					sx=i;sy=j;
				}else if(Map[i][j]=='T'){
					tx=i;ty=j;
				}
			}
		Node tmp_n;
		tmp_n.x=sx;tmp_n.y=sy;tmp_n.dist=0;
		vis[sx][sy]=1;
		bfs(tmp_n);
	}
	return 0;
}
