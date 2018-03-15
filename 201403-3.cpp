#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
int para[500];
int main(){
	
	memset(para,0,sizeof(para));
	string arg;
	cin>>arg;
	int size=arg.size();
	for(int i=0;i<size;i++){
		if(i!=size-1){
			if(arg[i+1]!=':')
				para[arg[i]]=1;
			else{
				para[arg[i]]=2;i++;
			}
		}else{
			para[arg[i]]=1;
		}
	}

	int n;
	cin>>n;cin.get();
	for(int i=0;i<n;i++){
		getline(cin,arg);
		map<char,string> text;
		stringstream ss;
		ss<<arg;
		ss>>arg;
		int flag=0;
		char canshu;
		while(ss>>arg){
			if(!flag){
				if(arg[0]!='-')
					break;
				else{
					canshu=arg[1];
					if(para[canshu]<1){
						break;
					}
					else if(para[canshu]==1){
						text.insert(pair<char,string>(canshu,""));
					}else{
						flag=1;
					}
				}
			}else{
				flag=0;
				if(arg[0]=='-')
					break;
				else{
					map<char,string>::iterator it=text.find(canshu);
					if(it!=text.end()){
						text.erase(it);
						text.insert(pair<char,string>(canshu,arg));
					}else{
						text.insert(pair<char,string>(canshu,arg));
					}
				}
			}
		}
		ss.clear();
		cout<<"Case "<<i+1<<":";
		for(map<char,string>::iterator it=text.begin();it!=text.end();it++)
			if(it->second=="")
				cout<<" -"<<it->first;
			else
				cout<<" -"<<it->first<<" "<<it->second;
		cout<<endl;
	}
	return 0;
}
