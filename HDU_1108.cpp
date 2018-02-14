#include <iostream>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        for(int i=max(a,b);i<=a*b;i++)
            if(i%a==0&&i%b==0){
                cout<<i<<endl;
                break;
            }
    }
    return 0;
} 