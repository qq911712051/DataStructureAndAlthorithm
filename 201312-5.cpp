#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int array[10005];
int main(){
	memset(array,0,sizeof(array));
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&array[i]);
	sort(array,array+n);
	int Min=999999999;
	for(int i=1;i<n;i++){
		if(abs(array[i]-array[i-1])<Min)
			Min=abs(array[i]-array[i-1]);
	}
	cout<<Min<<endl;
	return 0;
}
