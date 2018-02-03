#include <stdio.h>
#include <string.h>
char ns[15];
int leng=0;
int isYes(int par){
    while(1){
        if(par==0)
            return 1;
        int a=par%10;
        int i;
        int flag=0;
        for(i=0;i<leng;i++){
            if(a==(ns[i]-'0')){
                flag=1;
                break;
            }
        }
        if(!flag)
            return 0;
        par/=10;
    }
}
int match(int i,int j){
    int t1=i*(j%10);
    int t2=i*(j/10);
    int t3=t1+t2*10;
    if(isYes(i)&&isYes(j)&&isYes(t1)&&isYes(t2)&&isYes(t3)){
        return 1;
    }else
        return 0;
}
int main(){
    int num=1;
    memset(ns,0,sizeof(ns));
    scanf("%s",ns);
    leng=strlen(ns);
    int i,j;
    for(i=111;i<=999;i++)
        for(j=11;j<=99;j++){
            if(match(i,j)){
                //print
                printf("<%d>\n",num++);
                printf("  %d\n",i);
                printf("X  %d\n",j);
                printf("-----\n");
                int t1=i*(j%10);
                printf("%5d\n",t1);
                int t2=i*(j/10);
                printf("%4d \n",t2);
                printf("-----\n");
                printf("%d\n\n",t2*10+t1);
            }
        }
    printf("the number is %d\n",num-1);
    return 0;
}