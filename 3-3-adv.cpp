#include <stdio.h>
#include <string.h>
#include <time.h>
int main(){
    int i,ok,abc,de,x,y,z,count=0;
    char s[20],buf[99];
    memset(buf,0,sizeof(buf));
    scanf("%s",s);
    clock_t start=clock();
    clock_t sum_1=0;
    for(abc=111;abc<=999;abc++)
        for(de=11;de<=99;de++){
            x=abc*(de%10);y=abc*(de/10);z=abc*de;
            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);

            clock_t n1=clock();
            ok=1;
            for(i=0;i<strlen(buf);i++)
                if(strchr(s,buf[i])==NULL)
                    ok=0;
            sum_1+=clock()-n1;
            if(ok){
                
                printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",++count,abc,de,x,y,z);
            }
            
        }
    printf("tdsadsadsad is %d\n",count);
    clock_t end=clock();
    printf("the cost is %1f s\n",(double)(end-start)/1000);
    printf("test time is %1f s",(double)sum_1/1000);
    return 0;
}