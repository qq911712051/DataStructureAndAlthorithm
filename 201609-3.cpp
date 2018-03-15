#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int hp1[10],act1[10],num1;
int hp2[10],act2[10],num2;
int mode;
int main(){
	int n;
	mode=0;  //ох 
	memset(hp1,0,sizeof(hp1));memset(act1,0,sizeof(act1));num1=0;hp1[0]=30;act1[0]=0;
	memset(hp2,0,sizeof(hp2));memset(act2,0,sizeof(act2));num2=0;hp2[0]=30;act2[0]=0;
	scanf("%d",&n);
	string oper;
	for(int i=0;i<n;i++){
		cin>>oper;
		if(oper=="end")mode=!mode;
		else if(oper=="summon"){
			int pos,hel,ata;
			cin>>pos>>ata>>hel;
			if(mode){
				//2p
				memcpy(hp2+pos+1,hp2+pos,sizeof(int)*(num2-pos+1));
				memcpy(act2+pos+1,act2+pos,sizeof(int)*(num2-pos+1));
				hp2[pos]=hel;act2[pos]=ata;
				num2++;
			}else{
				//1p
				memcpy(hp1+pos+1,hp1+pos,sizeof(int)*(num1-pos+1));
				memcpy(act1+pos+1,act1+pos,sizeof(int)*(num1-pos+1));
				hp1[pos]=hel;act1[pos]=ata;
				num1++;
			}
		}else if(oper=="attack"){
			int a,b;
			cin>>a>>b;
			if(mode){
				//2p
				hp2[a]-=act1[b];
				hp1[b]-=act2[a];
				if(hp2[a]<=0&&a!=0){
					memcpy(hp2+a,hp2+a+1,sizeof(int)*(num2-a));
					memcpy(act2+a,act2+a+1,sizeof(int)*(num2-a));
					num2--;
				}
				if(hp1[b]<=0&&b!=0){
					memcpy(hp1+b,hp1+b+1,sizeof(int)*(num1-b));
					memcpy(act1+b,act1+b+1,sizeof(int)*(num1-b));
					num1--;	
				}
			}else{
				//1p
				hp1[a]-=act2[b];
				hp2[b]-=act1[a];
				if(hp2[b]<=0&&b!=0){
					memcpy(hp2+b,hp2+b+1,sizeof(int)*(num2-b));
					memcpy(act2+b,act2+b+1,sizeof(int)*(num2-b));
					num2--;
				}
				if(hp1[a]<=0&&a!=0){
					memcpy(hp1+a,hp1+a+1,sizeof(int)*(num1-a));
					memcpy(act1+a,act1+a+1,sizeof(int)*(num1-a));
					num1--;	
				}
			}
			if(hp1[0]<=0||hp2[0]<=0)break;
		}
	}
	if(hp1[0]>0&&hp2[0]<=0)
		cout<<1<<endl;
	else if(hp1[0]<=0&&hp2[0]>0)
		cout<<-1<<endl;
	else
		cout<<0<<endl;
	cout<<hp1[0]<<endl;
	cout<<num1;
	for(int i=1;i<=num1;i++)
		cout<<" "<<hp1[i];
	cout<<endl;
	cout<<hp2[0]<<endl;
	cout<<num2;
	for(int i=1;i<=num2;i++)
		cout<<" "<<hp2[i];
	cout<<endl;
	return 0;
}
