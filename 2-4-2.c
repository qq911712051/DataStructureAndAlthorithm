#include <stdio.h>
// int main(){
//     double i=0;
//     i+=0.1;
//     if(i == 0.1){
//         printf("111\n");
//     }
// }
//浮点数陷阱
//浮点数并不是精确的
//
int main(){
    double i;

    for (i = 0; i <11; i += 0.1){
        printf("%.15lf %d\n", i, 10 == i);
    }


    return 0;
}