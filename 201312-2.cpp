#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char code[20];
	memset(code,0,sizeof(code));
	cin>>code;
	int hehe[10],t=0;
	for(int i=0;i<strlen(code);i++){
		if(code[i]!='-')
			hehe[t++]=code[i]-'0';
	}
	int sum=0;
	for(int i=1;i<10;i++)
		sum+=hehe[i-1]*i;
	
	int res=sum%11;
	char ch=res==10?'X':res+'0';
	if(ch==code[strlen(code)-1])
		cout<<"Right"<<endl;
	else{
		code[strlen(code)-1]=ch;
		cout<<code<<endl;
	}
	return 0;
}
