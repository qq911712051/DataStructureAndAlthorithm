#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct Node{
	int a,b,c;
};
int vis[1000][1000],a,b,c,x;
int Max=99999999;
vector<Node> Max_vec;
void dfs(Node cur,vector<Node> path){
	int size=path.size()-1;
	if(size>Max)return;
	if(cur.a==x||cur.b==x||cur.c==x){
		if(size<Max){
			Max_vec=path;
			Max=size;
		}
	}else{
		Node tmp;int kk;
		//aµ¹Ë®
		if(cur.a>0){
			tmp=cur;
			kk=b-tmp.b;
			if(tmp.a>=kk){
				tmp.a-=kk;tmp.b=b;
			}else{
				tmp.b+=tmp.a;tmp.a=0;
			}
			if(!vis[tmp.b][tmp.c]){
			
				vis[tmp.b][tmp.c]=1;
				path.push_back(tmp);
				dfs(tmp,path);
				path.pop_back();
				vis[tmp.b][tmp.c]=0;
			}
			tmp=cur;
			kk=c-tmp.c;
			if(tmp.a>=kk){
				tmp.a-=kk;tmp.c=c;
			}else{
				tmp.c+=tmp.a;tmp.a=0;
			}
			if(!vis[tmp.b][tmp.c]){
				vis[tmp.b][tmp.c]=1;
				path.push_back(tmp);
				dfs(tmp,path);
				path.pop_back();
				vis[tmp.b][tmp.c]=0;
			}
			
			
		}
		//bµ¹Ë®
		if(cur.b>0){
			tmp=cur;
			kk=a-tmp.a;
			if(tmp.b>=kk){
				tmp.b-=kk;tmp.a=a;
			}else{
				tmp.a+=tmp.b;tmp.b=0;
			}
			if(!vis[tmp.b][tmp.c]){
				vis[tmp.b][tmp.c]=1;
				path.push_back(tmp);
				dfs(tmp,path);
				path.pop_back();
				vis[tmp.b][tmp.c]=0;
			}
			
			
			tmp=cur;
			kk=c-tmp.c;
			if(tmp.b>=kk){
				tmp.b-=kk;tmp.c=c;
			}else{
				tmp.c+=tmp.b;tmp.b=0;
			}
			if(!vis[tmp.b][tmp.c]){
				vis[tmp.b][tmp.c]=1;
				path.push_back(tmp);
				dfs(tmp,path);
				path.pop_back();
				vis[tmp.b][tmp.c]=0;
			}
			
		}
		//cµ¹Ë® 
		if(cur.c>0){
			tmp=cur;
			kk=a-tmp.a;
			if(tmp.c>=kk){
				tmp.c-=kk;tmp.a=a;
			}else{
				tmp.a+=tmp.c;tmp.c=0;
			}
			if(!vis[tmp.b][tmp.c]){
				vis[tmp.b][tmp.c]=1;
				path.push_back(tmp);
				dfs(tmp,path);
				path.pop_back();
				vis[tmp.b][tmp.c]=0;
			}
			
			
			tmp=cur;
			kk=b-tmp.b;
			if(tmp.c>=kk){
				tmp.c-=kk;tmp.b=b;
			}else{
				tmp.b+=tmp.c;tmp.c=0;
			}
			if(!vis[tmp.b][tmp.c]){
				vis[tmp.b][tmp.c]=1;
				path.push_back(tmp);
				dfs(tmp,path);
				path.pop_back();
				vis[tmp.b][tmp.c]=0;
			}
			
		}
	}
}
int main(){
	memset(vis,0,sizeof(vis));
	vis[0][0]=1;
	scanf("%d%d%d%d",&a,&b,&c,&x);
	vector<Node> tmp;
	Node cur;cur.a=a;cur.b=0;cur.c=0;
	tmp.push_back(cur);
	dfs(cur,tmp);
	cout<<Max<<endl;
	int hehe=Max_vec.size();
	for(int i=0;i<hehe;i++)
		cout<<"("<<Max_vec[i].a<<","<<Max_vec[i].b<<","<<Max_vec[i].c<<")"<<endl;
	return 0;
}
