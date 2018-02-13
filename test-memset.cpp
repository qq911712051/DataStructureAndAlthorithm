#include <iostream>
#include <cstring>
#include <ctime>
const int MAX_SIZE=100000000;
using namespace std;
int a[MAX_SIZE];
int main(){
    clock_t start=clock();
    for(int i=0;i<MAX_SIZE;i++){
        a[i]=1;
    }
    cout<<"the for loop cost time is "<<(double)(clock()-start)/1000<<" s"<<endl;
    start=clock();
    memset(a,0,sizeof(a));
    cout<<"the memset cost time is "<<(double)(clock()-start)/1000<<" s"<<endl;
    return 0;
}