#include <iostream>
#include <ctime>
using namespace std;
char hehe[10006];
int main(){
    clock_t start=clock();
    while(scanf("%s",hehe)==1)
        //puts(hehe);
         printf("%s\n",hehe);
        ;
    cout<<"the cost is "<<(double)(clock()-start)/1000<<"s"<<endl;
    return 0;
}