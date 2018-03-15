#include <iostream>
#include <string>
#include <cstring> 
#include <map>
#include <sstream>
#include <iterator>
using namespace std;
int n,m,t;
map<string,string> cont[1000000];
string readName(){
	
}
void readObject(string str,int pos){
	int h=str.size();
	int isInput=0,isName=1,isTrans=0;
	int findObj=0,start=0;
	int num=1;
	string name="",value="";
	for(int i=1;i<h-1;i++){
		char ch=str[i];
		if(findObj){
			if(ch=='{')num++;
			else if(ch=='}')num--;
			if(num==0){
				string tmp=string(str.begin()+start,str.begin()+i+1);
				findObj=0;
				t++;
				
				stringstream ss;
				ss<<"#"<<t;
				string daia;
				ss>>daia;
				ss.clear();
				cont[pos].insert(pair<string,string>(name,daia));
				readObject(tmp,t);
			}
			continue;
		}
		if(ch=='{'){
			findObj=1;
			start=i;
			num=1;
			continue;
		}
		if(ch=='"'){
			if(!isInput){
				isInput=1;
				continue;
			}else{
				if(isTrans){
					isTrans=0;
					if(isName)name+='"';
					else value+='"';
				}else
					isInput=0;
				continue;
			}
		}
		if(ch==','){
			isName=1;
			cont[pos].insert(pair<string,string>(name,value));
			name="";value="";
			continue;
		}
		if(ch==':'){
			isName=0;
			continue;
		}
		if(ch=='\\'){
			if(isTrans){
				if(isName)name+=ch;
				else value+=ch;
				isTrans=0;
				continue;
			}
			isTrans=1;
			continue;
		}
		if(isInput){
			if(isName)name+=ch;
			else value+=ch;
		}
	}
	if(value!=""){
		cont[pos].insert(pair<string,string>(name,value));
	}
}
string json;
void find(int pos,string para,int flag){
	map<string,string>& cur=cont[pos];
	int nice=para.find('.');
	if(nice==string::npos){
		
		map<string,string>::iterator res=cur.find(para);
		if(res==cur.end()){
		
			cout<<"NOTEXIST"<<endl;
			return;
		}else{
			
			if(res->second[0]=='#'){
				cout<<"OBJECT"<<endl;return;
			}else{
				cout<<"STRING "<<res->second<<endl;return;
			}
			
		}
	}else{
		string tmp1=string(para.begin(),para.begin()+nice);
		
		map<string,string>::iterator res=cur.find(tmp1);
		if(res==cur.end()){
			
			cout<<"NOTEXIST"<<endl;
			return;
		}
		string tt=res->second;
		stringstream ss;
		ss<<tt;
		ss.get();
		int tmp2;
		ss>>tmp2;
		ss.clear();
	
		find(tmp2,string(para.begin()+nice+1,para.end()),1);
	}
	
	
}
int main(){
	t=0;json="";
	scanf("%d%d",&n,&m);cin.get();
	string tmp;
	for(int i=0;i<n;i++){
		getline(cin,tmp);
		json+=tmp;
	}
	readObject(json,0);
	
	for(int i=0;i<m;i++){
		string para;
		cin>>para;
		find(0,para,0);
	}
	return 0;
}
