#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
long long res[30];
long long sum_num;
long long Com(int n,int m){
	return res[n]/(res[m]*res[n-m]);
}
void init(){
	for(int i=0;i<=30;i++)
		if(i==0)
			res[i]=1;
		else
			res[i]=res[i-1]*i;
}
long long hehe(int n,int d,int shenyu,int cur,int pre,vector<int> num){
	if(d==cur){
		num.push_back(shenyu);
		int sy=n;
		long long cal=1;
		for(int i=0;i<num.size();i++){
			cal*=Com(sy,num[i]);
			sy-=num[i];
		}
		int flag_1=0,count=1;
		for(int i=0;i<num.size();i++){
			if(i==0)continue;
			if(num[i]==num[i-1]){
				flag_1=1;count++;continue;
			}else{
				if(flag_1){
					cal/=res[count];
				}
				flag_1=0;count=1;
			}	
		}
		if(flag_1)
			cal/=res[count];
		sum_num+=cal;
		//print
//		cout<<"fenzu: ";
//		for(int i=0;i<num.size();i++)
//			cout<<num[i]<<"  ";
//		cout<<"  res:"<<cal<<endl;
	}else{
		for(int i=pre;i<=shenyu/(d-cur+1);i++){
			vector<int> tmp=num;
			tmp.push_back(i);
			hehe(n,d,shenyu-i,cur+1,i,tmp);
		}
	}
}
long long fendui(int n,int d){
	vector<int> tmp;
	hehe(n,d,n,1,1,tmp);
}
int main(){
	memset(res,0,sizeof(res));
	int C;
	cin>>C;
	init();
	for(int c=0;c<C;c++){
		sum_num=0;
		int n,last=sum_num;
		cin>>n;
		for(int d=1;d<=n;d++){
			fendui(n,d);
//			cout<<"div "<<d<<" : "<<sum_num-last<<endl;
			last=sum_num;
		}
		cout<<sum_num<<endl;
	}
	return 0;
}
