#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int main(){
    string s;
    clock_t start=clock();
    while(cin>>s)
    
        cout<<s<<endl;
    cout<<"the cost is "<<(double)(clock()-start)/1000<<"s"<<endl;
    return 0;
} 
/**
 * 经测试，读取大量数据fgets > scanf,getchar > cin
 * 输出数据  puts > cout > printf,putchar
 * 
 * */ 
