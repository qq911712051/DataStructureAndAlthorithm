#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXSIZE=1000000;
int tree[MAXSIZE];
int main(){
    int D,I;
    while(cin>>D>>I){
        memset(tree,0,pow(2,D+1));
        int dep=1,last,cur;
        for(int i=1;i<=I;i++){
            dep=1;
            cur=1;
            while(dep<D){
                int tmp=cur;
                if(tree[cur])
                    cur=cur*2+1;
                else    
                    cur=2*cur;
                tree[tmp]=!tree[tmp];
                dep++;
            }
        }
        cout<<cur<<endl;
    }
    return 0;
}