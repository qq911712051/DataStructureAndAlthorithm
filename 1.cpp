#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char data[101];
int main(){
    ofstream ff;
    ff.open("test.data",ios::out);
    memset(data,'h',sizeof(data)-1);
    data[100]='\0';
    for(int i=0;i<1000;i++)
        ff<<i<<":  "<<data<<endl;
    ff.close();
    
    return 0;
}