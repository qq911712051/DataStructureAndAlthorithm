#include <iostream>
#include <cstring>
using namespace std;
char src[100];
int main(){
    fgets(src,sizeof(src),stdin);
    int str_len=strlen(src);
    src[str_len-1]='\0';
    str_len=strlen(src);
    for(int i=1;i<=str_len/2;i++){
        if(str_len%i==0){
            int flag_1=0;
            int size=str_len/i;
            for(int j=1;j<=i;j++){
                for(int k=1;k<size;k++){
                    if(src[j-1+(k-1)*i]!=src[j-1+k*i]){
                        flag_1=1;
                        break;
                    }
                
                }
                if(flag_1)break;
            }
            if(!flag_1)
                printf("%d",i);
        }
    }
    return 0;
}