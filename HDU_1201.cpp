#include <iostream>
using namespace std;
int rn[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int cn[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int check(int y){
	if((y%4==0&&y%100!=0)||y%400==0)
		return 1;
	return 0;
}
int main(){
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int year,month,day;
		cin>>year;cin.get();cin>>month;cin.get();cin>>day;
		
		int sum=0;
		if(check(year)){
			sum+=rn[month]-day;
			for(int m=month+1;m<=12;m++)
				sum+=rn[m];
		}else{
			sum+=cn[month]-day;
			for(int m=month+1;m<=12;m++)
				sum+=cn[m];
		}
		for(int y=year+1;y<year+18;y++){
			if(check(y))
				sum+=366;
			else
				sum+=365;
		}
		if(check(year+18)){
			for(int i=1;i<month;i++)
				sum+=rn[i];
			if(day>rn[month]){
				cout<<"-1"<<endl;
				continue;
			}
			sum+=day;
		}else{
			for(int i=1;i<month;i++)
				sum+=cn[i];
			if(day>cn[month]){
				cout<<"-1"<<endl;
				continue;
			}
			sum+=day;
		}
		cout<<sum<<endl;
	}
	return 0;
}
