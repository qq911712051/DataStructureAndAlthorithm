#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string pwd,tmp;
	cin>>n>>pwd;cin.get();
	if(pwd=="")
		pwd="/";
	for(int i=0;i<n;i++){
		getline(cin,tmp);
		if(tmp[0]==0){
			cout<<"/"<<endl;continue;
		}
		string path;
		string file="";
		if(tmp[0]=='/'){
			int xiegang=1,wenzi=0,preYe=0,curYe=0;
			file="";
			for(int p=0;p<tmp.size();p++){
				if(tmp[p]=='/'){
					while(tmp[p]=='/')p++;
					p--;
					if(preYe){
						preYe=0;
						string tmp11=string(path.begin(),path.end()-1);
						int nice=tmp11.rfind('/');
						path=string(path.begin(),path.begin()+nice+1);
						if(path=="")path="/";
						continue;
					}
					if(curYe){
						curYe=0;
						continue;
					}
					
					path+=file+"/";
					file="";
				}else if(tmp[p]=='.'){
					int now=p;
					while(now<tmp.size()&&tmp[now]=='.')now++;
					int num=now-p;
					if(tmp[now]=='/'){
						if(num==1){
							curYe=1;
						}else if(num==2){
							preYe=1;
						}else{
							for(int s=0;s<num;s++)file+='.';
							p=now-1;
						}
					}else{
						for(int s=0;s<num;s++)file+='.';
						p=now-1;
					}
				}else{
					file+=tmp[p];
				}
			}
		}else{
			if(pwd!="/")	
				path=pwd+"/";
			else
				path=pwd;
			int xiegang=1,wenzi=0,preYe=0,curYe=0;
			file="";
			for(int p=0;p<tmp.size();p++){
				if(tmp[p]=='/'){
					while(tmp[p]=='/')p++;
					p--;
					if(preYe){
						preYe=0;
						string tmp11=string(path.begin(),path.end()-1);
						int nice=tmp11.rfind('/');
						path=string(path.begin(),path.begin()+nice+1);
						if(path=="")path="/";
						continue;
					}
					if(curYe){
						curYe=0;
						continue;
					}
					
					path+=file+"/";
					file="";
				}else if(tmp[p]=='.'){
					int now=p;
					while(now<tmp.size()&&tmp[now]=='.')now++;
					int num=now-p;
					if(tmp[now]=='/'){
						if(num==1){
							curYe=1;
						}else if(num==2){
							preYe=1;
						}else{
							for(int s=0;s<num;s++)file+='.';
						
						}
						p=now-1;
					}else{
						for(int s=0;s<num;s++)file+='.';
						p=now-1;
					}
				}else{
					file+=tmp[p];
				}
			}
		}
		if(file!="")
			path+=file;
		else if(path.size()>1&&path[path.size()-1]=='/')
			path=string(path.begin(),path.end()-1); 
		cout<<path<<endl;
	}
	return 0;
}
