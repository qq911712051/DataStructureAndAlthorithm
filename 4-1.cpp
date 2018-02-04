#include <iostream>
#include <cstring>
using namespace std;
int com(int n,int m){
    long long* collect=new long long[n+1];
    memset(collect,0,sizeof(long long)*n+8);
    collect[0]=1;
    for(int i=1;i<=n;i++)
        collect[i]=collect[i-1]*i;
    
    return collect[n]/(collect[m]*collect[n-m]);
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    cout<<com(a,b)<<endl;

    return 0;
} 