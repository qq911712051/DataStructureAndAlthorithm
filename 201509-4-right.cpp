#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <cstring>
using namespace std;
const int MAXN=10005;
const int MAXE=100005;
vector<int> G[MAXN];
long long index=0;
long long total=0;
int instack[MAXN];
long long  DFN[MAXN],LOW[MAXN];
int m,n;
stack<int> sss;
void tarjan(int u){
	DFN[u]=LOW[u]=++index;
	sss.push(u);
	instack[u]=1;
	vector<int>& cur=G[u];
	for(int i=0;i<cur.size();i++){
		if(!DFN[cur[i]]){
			tarjan(cur[i]);
			LOW[u]=min(LOW[u],LOW[cur[i]]);
		}
		else if(instack[cur[i]])
			LOW[u]=min(LOW[u],DFN[cur[i]]);
			
	}
	
	if(LOW[u]==DFN[u]){
		int num=1;	
		int v=sss.top();
		sss.pop();
		instack[v]=0;
		while(v!=u){v=sss.top();sss.pop();instack[v]=0;num++;} 
		if(num>=2){
		
			total+=(num)*(num-1)/2;
		}
	}
}
int main(){
	total=0;
	memset(instack,0,sizeof(instack));
	memset(DFN,0,sizeof(DFN));
	memset(LOW,0,sizeof(LOW));
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!DFN[i]){
			
			tarjan(i);
		}
	}
	cout<<total<<endl;
	return 0;
}
