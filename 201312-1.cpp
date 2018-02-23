#include <iostream>
#include <cstring>
using namespace std;
int num[10010];
int min_num=999999;
int count=0;
int main(){
	int n;
	memset(num,0,sizeof(num));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		num[tmp]++;
	}
	for(int i=1;i<=10009;i++)
		if(num[i]>count){
			count=num[i];
			min_num=i;
		}
	cout<<min_num<<endl;
	return 0;
}
