#include <stdio.h>
#include <limits.h>
int main(){
    int min=INT_MAX,max=INT_MIN;
    int par,num=0;
    long long sum=0;
    while(scanf("%d", &par) == 1){
        sum+=par;
        num++;
        if(par > max){
            max=par;
        }
        if(par < min)
            min=par;
        
    }
    printf("%d %d %.3lf", min, max, (double)sum/num);
    return 0;
}