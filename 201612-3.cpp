#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int roletopri[105][105];
int usertopri[105][105];
int p,q,u,r;
map<string,int> pritoint;
map<string,int> roletoint;
//map<string,int> usertopri;
map<string,int> usertoint;
int main(){
	for(int i=0;i<103;i++)
		for(int j=0;j<103;j++){
			roletopri[i][j]=-100;
			usertopri[i][j]=-100;
		}
	scanf("%d",&p);
	string name,pri,pname;
	for(int i=0;i<p;i++){
		cin>>pname;
		int nice=pname.find(':');
		if(nice==string::npos)
			pritoint.insert(pair<string,int>(pname,i));
		else
			pritoint.insert(pair<string,int>(string(pname.begin(),pname.begin()+nice),i));
		
	}
	scanf("%d",&r);

	for(int i=0;i<r;i++){
		int num;
		cin>>name>>num;
		roletoint.insert(pair<string,int>(name,i));
		for(int j=0;j<num;j++){
			cin>>pri;
			int nice=pri.find(':');
			if(nice!=string::npos){
				roletopri[i][pritoint.find(string(pri.begin(),pri.begin()+nice))->second]=pri[nice+1]-'0';
			}else{
				roletopri[i][pritoint.find(pri)->second]=-1;
			}
		}
		
	}
	scanf("%d",&u);
	for(int i=0;i<u;i++){
		int num;
		cin>>name>>num;
		usertoint.insert(pair<string,int>(name,i));
		for(int j=0;j<num;j++){
			cin>>pri;
			map<string,int>::iterator it=roletoint.find(pri);
			int pos=it->second;
			for(int k=0;k<pritoint.size();k++){
				if(roletopri[pos][k]==-1)
					usertopri[i][k]=-1;
				else if(roletopri[pos][k]>usertopri[i][k])
					usertopri[i][k]=roletopri[pos][k];
			}
		}
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		cin>>name>>pri;
		int level=-1;
		string priname;
		int nice=pri.find(':');
		if(nice!=string::npos){
			level=pri[nice+1]-'0';
			priname=string(pri.begin(),pri.begin()+nice);
		}else{
			priname=pri;
		}
				
	
		map<string,int>::iterator it=usertoint.find(name);
		if(it==usertoint.end()){
			
			cout<<"false"<<endl;
		}else{
			map<string,int>::iterator it2= pritoint.find(priname);
			if(it2==pritoint.end()){
				
				cout<<"false"<<endl;
			}else{
				int nameP=it->second,priP=it2->second;
				if(level!=-1){
					if(usertopri[nameP][priP]>=level)
						cout<<"true"<<endl;
					else{
						
						cout<<"false"<<endl;
					}
				}else{
					if(usertopri[nameP][priP]==-1){
						cout<<"true"<<endl;
					}else if(usertopri[nameP][priP]==-100){
						
						cout<<"false"<<endl;
					}else{
						cout<<usertopri[nameP][priP]<<endl;
					}
				}
						
			}
		}
	}
	return 0;
}
