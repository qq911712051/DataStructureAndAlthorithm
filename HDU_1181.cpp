#include <iostream>
#include <cstring>
using namespace std;
char strs[500][100],t;
int vis[500];
int glo_flag=0;
void dfs(int pos){
	if(strs[pos][strlen(strs[pos])-1]=='m'){
		glo_flag=1;
		return;
	}
	vis[pos]=-1;
	for(int i=0;i<t;i++)
		if(glo_flag)
			return;
		else if(!vis[i]&&strs[pos][strlen(strs[pos])-1]==strs[i][0]){
			dfs(i);
		}
	vis[pos]=0;
}
int main(){
	char tmp[100];
	t=0;
	memset(vis,0,sizeof(vis));
	while(cin>>strs[t++]){
		if(!strcmp(strs[t-1],"0")){
			for(int i=0;i<t;i++)
				if(glo_flag)
					break;
				else if(strs[i][0]=='b')
					dfs(i);
			if(glo_flag)
				cout<<"Yes."<<endl;
			else 
				cout<<"No."<<endl;
			glo_flag=0;
			t=0;
			memset(vis,0,sizeof(vis));
		}
		
	}
	return 0;
}
