#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
string origin[10000];
string sorted[10000];
int flag=0;
map<string,string> yinshe;
int main(){
    string s;
    int numn=0;
    cin>>s;
    while(s!="******"){
        origin[numn++]=s;
        string tmp=s;
        sort(tmp.begin(),tmp.end());
        if(yinshe.find(tmp)!=yinshe.end()){
            string tmp_3;
            stringstream ss;
            ss<<numn-1;
            ss>>tmp_3;
            yinshe.at(tmp)+=" "+tmp_3;
        }else{
            string tmp_2;
            stringstream ss;
            ss<<numn-1;
            ss>>tmp_2;
            ss.clear();
            yinshe.insert(pair<string,string>(tmp,tmp_2));
        }
        cin>>s;
    }

    while(cin>>s){
        string tmp=s;
        sort(tmp.begin(),tmp.end());
        if(yinshe.find(tmp)!=yinshe.end()){
            int sorted_size=0;
            string pos=yinshe.at(tmp);
            stringstream ss;
            ss<<pos;
            while(!ss.eof()){
                int a;
                ss>>a;
                sorted[sorted_size++]=origin[a];
            }

            sort(sorted,sorted+sorted_size);

            if(flag)
                cout<<endl;
            else
                flag=1;
            int flag_sort=0;
            for(int i=0;i<sorted_size;i++){
                if(flag_sort)
                    cout<<" "<<sorted[i];
                else{
                    flag_sort=1;
                    cout<<sorted[i];
                }
            }
        }else{
            if(flag)
                cout<<endl<<":(";
            else{
                flag=1;
                cout<<":(";
            }
        }

    }
    return 0;
}