#include <iostream>
#include <cstring>
using namespace std;
int hn[1010],flag[1010];
int maxarea=0;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&hn[i]);
	for(int i=0;i<n;i++){
		int left=i,right=i;
		while(left>=0&&hn[left]>=hn[i])left--;
		while(right<n&&hn[right]>=hn[i])right++;
		if((right-left-1)*hn[i]>maxarea){
			maxarea=(right-left-1)*hn[i];
		}
	}
	cout<<maxarea<<endl;
	return 0;
}
