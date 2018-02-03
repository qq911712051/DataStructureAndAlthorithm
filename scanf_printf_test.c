#include <stdio.h>
#include <limits.h>
#define false 0
#define true 1
int main(){
    double a=0.1;
    printf("%d\n", false&&false||true);
    return 0;
}


//test the range of int
// int main(int argc, int* argv[]){
//     int int_start_1=30000,int_start_2=-30000,i=0;
//     int int_max,int_min;
//     //test int value in (min max)
    
//     for(i=int_start_1;;i++){
//         if(i > (i+1)){
//             printf("int max is %d\n", i);
//             break;
//         }
//     }
//     for(i=int_start_2;;i--){
//         if(i < (i-1)){
//             printf("int min is %d\n", i);
//             break;
//         }
//     }
//     printf("the right value is (%d,%d)", INT_MAX, INT_MIN);
//     return 0;
// }

// int main(){
//     int a,b;
//     scanf("%d%d", &a, &b);
//     printf("a=%d b=%d\n", a, b);
//     return 0;
// }


//double
// int main(){
//     double a=111111;
//     double ans1=a*a;
//     printf("size=%d  %f\n",sizeof(double),ans1);
//     return 0;
// }

/**
 * 测试int   
 * 
 * 
 * /
/*
int main1(){
    long long a=111111111;
    long long ans1=a*a;
    printf("size=%d  %lld\n",sizeof(long long),ans1);
    return 0;
}*/