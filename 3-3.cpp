/** version 1.0
 * 通过和3-3-adv.cpp的算法对比，这份代码看起来很长，而adv看起来很简短，
 * 但实际运行时间，这份代码是1.8s左右，而adv是平均3.2s
 * 快了将近一倍
 * 开始我以为是字符串流导致速度变慢，因此换成一个一个赋值，发现速度上并没有太大的提升
 * 最后推测：可能是数组的原因，多次对数组进行写操作，导致了时间的花费
 * 而这份代码所有的数据基本都没有写回内存的操作，减少了大量访问内存时间
 * */


/**
 * version 2.0
 * 上面1.0的说法纯属放屁，最终通过测试，得出，导致时间加倍的原因：
 * 仅仅是因为多了一个printf，导致IO花费多了一倍而已。。。。。。
 * what's fuck???
 * */
#include <stdio.h>
#include <string.h>
#include <time.h>
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
    clock_t start=clock();
    leng=strlen(ns);
    int i,j;
    for(i=111;i<=999;i++)
        for(j=11;j<=99;j++){
            if(match(i,j)){
                //print
                int t1=i*(j%10);
                int t2=i*(j/10);
                printf("<%d>\n  %d\nX  %d\n-----\n%5d\n%4d \n-----\n%d\n\n",num++,i,j,t1,t2,t2*10+t1);
                
            }
        }
    printf("the number is %d\n",num-1);
    clock_t end=clock();
    printf("总用时：%lf s",(double)(end-start)/1000);
    return 0;
}