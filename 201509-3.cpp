#include <iostream>
#include <string>
#include <map>

using namespace std;
int m,n;
string cont[200],t;
map<string,string> var;
int main(){
	
	scanf("%d%d",&m,&n);
	cin.get();
	string html,tmp;
	int first=0;
	for(int i=0;i<m;i++){
		getline(cin,tmp);
		if(!first){
			html=tmp;
			first=1;
		}else{
			html+="\n"+tmp;
		}
	}
	for(int i=0;i<n;i++){
		getline(cin,tmp);
		string name,value;
		int pos1=tmp.find(' ');
		int pos2=tmp.find('"');
		name=string(tmp.begin(),tmp.begin()+pos1);
		value=string(tmp.begin()+pos2+1,tmp.end()-1);
		var[name]=value;
	}
	while(1){
		int pos1=html.find(" }}");
		if(pos1!=string::npos){
			string tmp1=string(html.begin(),html.begin()+pos1);
			int pos2=tmp1.rfind("{{ ");
			if(pos2!=string::npos){
				string v=string(html.begin()+pos2+3,html.begin()+pos1);
			
				map<string,string>::iterator it=var.find(v);
				string hehe="";
				if(it!=var.end()){
					hehe=it->second;
					
				}
				
				cout<<string(html.begin(),html.begin()+pos2)+hehe;
				html=string(html.begin()+pos1+3,html.end());
			}else
				break;
		}else break;
	}
	cout<<html<<endl;
	return 0;
}
