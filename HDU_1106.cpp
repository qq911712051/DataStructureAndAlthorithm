#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;
char tmp[2000];
int hehe[1000];
int main(){
    memset(hehe,0,sizeof(hehe));
    while(cin>>tmp){
        stringstream ss;
        for(int i=0;i<strlen(tmp);i++)
            if(tmp[i]=='5')
                tmp[i]=' ';
        ss<<tmp;
        int j=0,a;
        while(ss>>a){
            hehe[j++]=a;
        }
        sort(hehe,hehe+j);
        int flag=0;
        for(int i=0;i<j;i++){
            if(i!=0)
                cout<<" "<<hehe[i];
            else   
                cout<<hehe[i];

        }
        cout<<endl;
    }
    
    return 0;
}