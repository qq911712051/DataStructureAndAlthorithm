#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int map[100][100];
int vis[100][100];
struct pos{
    int x,y;
};
void dfs(int a,int b){
    stack<pos> st;
    pos tmp_p;
    tmp_p.x=a;tmp_p.y=b;
    st.push(tmp_p);
    while(!st.empty()){
        pos cur=st.top();
        int x=cur.x,y=cur.y;
        st.pop();
        vis[cur.x][cur.y]=1;
        if(map[x][y+1]&&!vis[x][y+1]){
            cur.x=x;cur.y=y+1;
            st.push(cur);
        }
        if(map[x+1][y+1]&&!vis[x+1][y+1]){
            cur.x=x+1;cur.y=y+1;
            st.push(cur);
        }
        if(map[x+1][y]&&!vis[x+1][y]){
            cur.x=x+1;cur.y=y;
            st.push(cur);
        }
        if(map[x+1][y-1]&&!vis[x+1][y-1]){
            cur.x=x+1;cur.y=y-1;
            st.push(cur);
        }
        if(map[x][y-1]&&!vis[x][y-1]){
            cur.x=x;cur.y=y-1;
            st.push(cur);
        }
        if(map[x-1][y-1]&&!vis[x-1][y-1]){
            cur.x=x-1;cur.y=y-1;
            st.push(cur);
        }
        if(map[x-1][y]&&!vis[x-1][y]){
            cur.x=x-1;cur.y=y;
            st.push(cur);
        }
        if(map[x-1][y+1]&&!vis[x-1][y+1]){
            cur.x=x-1;cur.y=y+1;
            st.push(cur);
        }
    }
}
int main(){
    int n;
    char tmp[100];
    memset(map,0,sizeof(map));
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        for(int j=1;j<=n;j++){
            map[i][j]=tmp[j-1]-'0';
        }
    }
    int count=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(map[i][j]&&!vis[i][j]){
                count++;
                dfs(i,j);
            }
        }
    cout<<count<<endl;


    return 0;
}