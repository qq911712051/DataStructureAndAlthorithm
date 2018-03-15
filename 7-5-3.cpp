#include <iostream>
#include <cstring> 
#include <set>
using namespace std;
typedef int State[9];
State Queue[100000],start,end;
int dist[100000],head[100000],next[100000],pre_path[100000];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int hash(int pos){
	State& now=Queue[pos];
	int sum=now[0];
	for(int i=1;i<9;i++)sum=sum*10+now[i];
	return sum%100000; 
}
int can_insert(int pos){
	int h=hash(pos);
	int m=head[h];
	while(m){
		
		if(!memcmp(Queue[pos],Queue[m],sizeof(State))){
			return 0;
		}
		m=next[m];
	}
	next[pos]=head[h];
	head[h]=pos;
	return 1;
}
int bfs(){
	int flag=0;
	int front=1,rear=2;
//	Queue[1]=start;
	memcpy(Queue[1],start,sizeof(State));
	while(front<rear){
		State& cur=Queue[front];
		//compare
		if(!memcmp(cur,end,sizeof(State)))return front; 
		int s1;
		for(s1=0;s1<9;s1++)if(!cur[s1])break;
		int x=s1/3+1,y=s1%3+1;
		for(int i=0;i<4;i++){
			int tmpx=x+dir[i][0],tmpy=y+dir[i][1];  
			if(tmpx>0&&tmpx<4&&tmpy>0&&tmpy<4){
				int z=(tmpx-1)*3+tmpy-1;
				dist[rear]=dist[front]+1;
				memcpy(Queue[rear],cur,sizeof(State));
				Queue[rear][s1]=Queue[rear][z];
				Queue[rear][z]=0;
				pre_path[rear]=front;
				if(can_insert(rear)){
					rear++;
				}
			}
		}
		front++;
	}
}
void print(int cur){
	if(pre_path[cur])
		print(pre_path[cur]);
	cout<<"-----------------"<<endl;
	cout<<Queue[cur][0]<<"\t"<<Queue[cur][1]<<"\t"<<Queue[cur][2]<<endl;a.	
	cout<<Queue[cur][3]<<"\t"<<Queue[cur][4]<<"\t"<<Queue[cur][5]<<endl;
	cout<<Queue[cur][6]<<"\t"<<Queue[cur][7]<<"\t"<<Queue[cur][8]<<endl;
}
int main(){
	memset(Queue,0,sizeof(Queue));
	memset(dist,0,sizeof(dist));
	memset(pre_path,0,sizeof(pre_path));
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	for(int i=0;i<9;i++)scanf("%d",&start[i]);
	for(int i=0;i<9;i++)scanf("%d",&end[i]);
	int pos=bfs();
	cout<<pos<<"  "<<dist[pos]<<endl;
	print(pos);
	return 0;
} 