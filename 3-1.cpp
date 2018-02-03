//开灯问题
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 1005
char hehe[MAXSIZE];
int main(){
    memset(hehe,0,sizeof(hehe));
    int first_flag=1;
    int n,k;
    scanf("%d%d", &n, &k);
    int i;
    for(i=1;i<=k;i++){
        if(i!=1){
            int j;
            for(j=1;j<=n;j++)
                if(j%i==0)
                    hehe[j-1]=!hehe[j-1];
        }else{
            memset(hehe,1,sizeof(hehe));
        }
    }
    for(i=0;i<n;i++)
        if(hehe[i]==1){
            if(first_flag)
                first_flag=0;
            else
                printf(" ");
            printf("%d",i+1); 
        }
            
    return 0;
}