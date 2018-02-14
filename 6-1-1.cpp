#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    int flag=0;
    cin>>n;
    deque<int> q;
    for(int i=1;i<=n;i++)
        q.push_back(i);
    while(q.size()>=2){
        if(!flag)
            flag=1;
        else    
            cout<<" ";
        cout<<q.front();
        q.pop_front();
        int tmp=q.front();
        q.pop_front();
        q.push_back(tmp);
    }
    cout<<" "<<q.front();
    return 0;
}