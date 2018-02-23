#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct Node{
    int number,para1,para2;
    int a,b,c,d;
}SSS;
SSS session[200];
int main(){
    int N;
    scanf("%d",&N);
    while(N!=0){
        SSS s;
        int t=0;
        for(int i=0;i<N;i++){
            scanf("%d%d%d",&s.number,&s.para1,&s.para2);
            s.a=s.number/1000;
            s.b=s.number/100%10;
            s.c=s.number/10%10;
            s.d=s.number%10;
            session[t++]=s;
        }
        int count=0,res;
        for(int i=1000;i<10000;i++){
            int flag_1=0;
            if(count>1){
                break;
            }
            int sa,sb,sc,sd,sorted[4],sort_1[4],vis[4];
            
            sa=i/1000;
            sb=i/100%10;
            sc=i/10%10;
            sd=i%10;
            sorted[0]=sa;sorted[1]=sb;sorted[2]=sc;sorted[3]=sd;
            sort(sorted,sorted+4);
            for(int k=0;k<t;k++){
                memset(vis,0,sizeof(vis));
                SSS tmp=session[k];
                sort_1[0]=tmp.a;sort_1[1]=tmp.b;sort_1[2]=tmp.c;sort_1[3]=tmp.d;
                sort(sort_1,sort_1+4);
                int count_2=0;
                for(int s=0;s<4;s++)
                    for(int m=0;m<4;m++)
                        if((!vis[m])&&sorted[s]==sort_1[m]){
                            count_2++;
                            vis[m]=1;
                            break;
                        }
                if(count_2!=tmp.para1){
                    flag_1=1;
                    break;
                }
                int count_1=0;
                if(sa==tmp.a)
                    count_1++;
                if(sb==tmp.b)
                    count_1++;
                if(sc==tmp.c)
                    count_1++;
                if(sd==tmp.d)
                    count_1++;
                if(count_1!=tmp.para2){
                    flag_1=1;
                    break;
                }
            }
            if(!flag_1){
                count++;
                res=i;
            }else
                continue;          
        }
        if(count==1)
            cout<<res<<endl;
        else 
            cout<<"Not sure"<<endl;
        scanf("%d",&N);
    }
    return 0;
}