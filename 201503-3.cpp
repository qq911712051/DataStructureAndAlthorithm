#include <iostream>
#include <cstring>
using namespace std;
int ry[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int cy[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int isRun(int year){
	if((year%4==0&&year%100!=0)||(year%400==0))
		return 1;
	return 0;
}
int main(){
	int a,b,c,y1,y2;
	scanf("%d%d%d%d%d",&a,&b,&c,&y1,&y2);
	if(c==7)c=0;
	long long sumDay=0;
	
	for(int i=1850;i<y1;i++)
		if(isRun(i))sumDay+=366;
		else sumDay+=365; 
	for(int i=y1;i<=y2;i++){
		int hasFlag=0;
		int rflag=0;
		if(isRun(i))rflag=1;
		int tmpDay=sumDay;
		for(int m=1;m<a;m++)
			if(rflag)tmpDay+=ry[m];
			else tmpDay+=cy[m];
		int now=(2+tmpDay%7)%7;
		int day;
		if(now<=c){
			int first=c-now+1;
			day=first+(b-1)*7;
			if(rflag&&day<=ry[a]){
				hasFlag=1;
				cout<<i<<"/";
				if(a<10)
					cout<<0<<a;
				else
					cout<<a;
				cout<<"/";
				if(day<10)
					cout<<0<<day<<endl;
				else
					cout<<day<<endl;
			}else if(!rflag&&day<=cy[a]){
				hasFlag=1;
				cout<<i<<"/";
				if(a<10)
					cout<<0<<a;
				else
					cout<<a;
				cout<<"/";
				if(day<10)
					cout<<0<<day<<endl;
				else
					cout<<day<<endl;
			}
		}else{
			int first=7-now+c+1;
			day=first+(b-1)*7;
			if(rflag&&day<=ry[a]){
				hasFlag=1;
				cout<<i<<"/";
				if(a<10)
					cout<<0<<a;
				else
					cout<<a;
				cout<<"/";
				if(day<10)
					cout<<0<<day<<endl;
				else
					cout<<day<<endl;
			}else if(!rflag&&day<=cy[a]){
				hasFlag=1;
				cout<<i<<"/";
				if(a<10)
					cout<<0<<a;
				else
					cout<<a;
				cout<<"/";
				if(day<10)
					cout<<0<<day<<endl;
				else
					cout<<day<<endl;
			}
			
		}
		if(!hasFlag){
			cout<<"none"<<endl;
		}
		
		if(isRun(i))sumDay+=366;
		else sumDay+=365; 
	}
	
	return 0;
}
