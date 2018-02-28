///目前最快的N皇后解法
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long sum = 0, upperlim = 1;

void test(long row, long ld, long rd)
{

   if (row != upperlim)
   {
  long pos = upperlim & ~(row | ld | rd);
  while (pos)
  {
 long p = pos & -pos;

 pos -= p;
 test(row + p, (ld + p) << 1, (rd + p) >> 1);
  }
   } else
  sum++;
}

int main(int argc, char *argv[])
{
   time_t tm;
   int n = 16;

   if (argc != 1)
  n = atoi(argv[1]);
   tm = time(0);
   if ((n < 1) || (n > 32))
   {
 
  exit(-1);
   }

   upperlim = (upperlim << n) - 1;

   test(0, 0, 0);
   printf("time %d s \n", (int) (time(0) - tm));
}



// #include <iostream>
// #include <cstring>
// #include <ctime>
// using namespace std;
// const int maxn=15;
// int vis[maxn+1][maxn+1];
// int count=0;
// void setflag(int x,int y,int flag){
//     for(int i=1;i<=maxn;i++){
//         vis[x][i]+=flag;
//         vis[i][y]+=flag;
//     }
//     vis[x][y]-=flag;
//     int tmpx=x,tmpy=y;
//     while(tmpx<=maxn&&tmpy<=maxn){
//         tmpx++;tmpy++;
//         vis[tmpx][tmpy]+=flag;
//     }
//     tmpx=x;tmpy=y;
//     while(tmpy>=1&&tmpx<=maxn){
//         tmpy--;tmpx++;
//         vis[tmpx][tmpy]+=flag;
//     }
// }
// void eightxxx(int h){
//     for(int i=1;i<=maxn;i++)
//         if(!vis[h][i]){
//             if(h==maxn)
//                 count++;
//             else{
//                 setflag(h,i,1);
//                 eightxxx(h+1);
//                 setflag(h,i,-1);
//             }
//         }
// }
// int main(){
//     clock_t ss=clock();
//     memset(vis,0,sizeof(vis));
//     eightxxx(1);
//     cout<<maxn<<"   ans:"<<count<<"    time:"<<(double)(clock()-ss)/1000<<"s"<<endl;

//     return 0;
// }