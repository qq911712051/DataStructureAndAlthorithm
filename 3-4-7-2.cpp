#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <stdio.h>
using namespace std;
int main(){
    string s;
    clock_t start=clock();
    int ch;
    while((ch=getchar())!=EOF)
        ;//putchar(ch);
    cout<<"the cost is "<<(double)(clock()-start)/1000<<"s"<<endl;
    return 0;
} 