#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string sam;
	int mode,n;
	vector<string> vec;
	cin>>sam>>mode>>n;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		vec.push_back(a);
	}
	if(mode){
		for(int i=0;i<n;i++)
			if(vec[i].find(sam)!=string::npos)
				cout<<vec[i]<<endl;
	}else{
		for(int i=0;i<sam.size();i++){
			if(sam[i]>='A'&&sam[i]<='Z')sam[i]+='a'-'A';
		}
		for(int i=0;i<n;i++){
			string tmp=vec[i];
			for(int j=0;j<tmp.size();j++){
				if(tmp[j]>='A'&&tmp[j]<='Z')tmp[j]+='a'-'A';
			
			}
			if(tmp.find(sam)!=string::npos)
				cout<<vec[i]<<endl;
		}
	}
	
	return 0;
}
