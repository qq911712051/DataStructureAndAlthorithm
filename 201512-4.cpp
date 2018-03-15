#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;

set<int> G[10005];
char vis[10005][10005];
int pre[10005];
int n,m;
int path[100005],t,dst;
int global_flag=0;
int findRoot(int cur){
	if(pre[cur]!=cur)
		return pre[cur]=findRoot(pre[cur]);
	return cur;
}
void dfs(int ss){
	if(global_flag)return;
	path[t++]=ss;
	set<int>& cur=G[ss];
	int hehe=0;
	for(set<int>::iterator it=cur.begin();it!=cur.end();it++){
		if(global_flag)return;
		if(!vis[ss][*it]){
			vis[ss][*it]=1;
			vis[*it][ss]=1;
			dfs(*it);
			vis[ss][*it]=0;
			vis[*it][ss]=0;
			hehe=1;
		}
	}
	if(global_flag)return;
	if(!hehe&&t==m+1){
		global_flag=1;
		return;
	}
	t--;
}
int main(){
	
	t=0;
	memset(path,0,sizeof(path));
	memset(pre,0,sizeof(pre));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)pre[i]=i;
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		G[a].insert(b);
		G[b].insert(a);	
		int r1=findRoot(a);
		int r2=findRoot(b);
		if(r1!=r2){
			pre[r1]=r2;
		}
	}
	//check 
	int jNum=0,oNum=0,flaghehe=0;
	int haha=findRoot(1);
	for(int i=1;i<=n;i++){
		if(findRoot(i)!=haha){
			cout<<"-1"<<endl;
			return 0;
		}
		if(G[i].size()%2==0)oNum++;
		else {
			jNum++;	
		}
	
	} 
	if(!(jNum==0||jNum==2)){
		cout<<"-1";
		return 0;
	}
	if(jNum==2&&G[1].size()%2==0){
		cout<<"-1";
		return 0;
	}
	dfs(1);
	cout<<path[0];
	for(int i=1;i<t;i++)
		printf(" %d",path[i]);
//		cout<<" "<<path[i];
	
	return 0;
}
