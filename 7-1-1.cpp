#include <iostream>
#include <vector>
using namespace std;
int n;
void print(vector<int> cur,vector<int> shunxu){
    if(cur.empty()){
        cout<<"("<<shunxu[0];
        for(int i=1;i<shunxu.size();i++){
            cout<<","<<shunxu[i];
        }
        cout<<")"<<endl;
        return ;
    }
    int len=cur.size();
    for(int i=0;i<len;i++){
        vector<int> tmp_shun=shunxu;
        vector<int> tmp_cur=cur;
        tmp_cur.erase(tmp_cur.begin()+i);
        tmp_shun.push_back(cur[i]);
        print(tmp_cur,tmp_shun);
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    while(cin>>n){
        vector<int> cur,hehe;
        for(int i=1;i<=n;i++)
            cur.push_back(i);
        print(cur,hehe);
    }
    return 0;
}