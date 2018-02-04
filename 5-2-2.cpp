//高精度
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
int bign[3000];
int main(){
    memset(bign,0,sizeof(bign));
    bign[0]=1;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int c=0;
        for(int j=0;j<3000;j++){
            int tmp=bign[j]*i;
            bign[j]=tmp%10000+c;
            c=tmp/10000;
            
        }
    }
    stringstream ss;
    char res[4000];
    int flag=0;
    memset(res,0,sizeof(res));
    for(int i=3000-1;i>=0;i--){
        if(flag==0&&bign[i]!=0){
            flag=1;
            ss<<bign[i];
            continue;
        }
        if(flag){
            ss<<bign[i]/1000<<bign[i]/100%10<<bign[i]/10%10<<bign[i]%10;
        }
    }
    ss>>res;
    printf("%s",res);
    return 0;
}