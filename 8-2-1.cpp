#include <iostream>
#include <cstdlib>
using namespace std;
int mul[100000],array[100000];
void merge_sort(int* A,int l,int r,int* tmp){
	if(l==r)return;
	int mid=(l+r)>>1;
	merge_sort(A,l,mid,tmp);
	merge_sort(A,mid+1,r,tmp);

	int t=0,lc=l,rc=mid+1,lflag=0,rflag=0;;
	for(t=0;t<r-l+1;t++){
		if(lflag){
			tmp[t]=A[rc++];continue;
		}
		if(rflag){
			tmp[t]=A[lc++];continue;
		}
		if(A[lc]<=A[rc]){
			tmp[t]=A[lc++];
			if(lc>mid)lflag=1;
		}else{
			tmp[t]=A[rc++];
			if(rc>r)rflag=1;
		}
	}
	memcpy(A+l,tmp,sizeof(int)*(r-l+1));
}
int main(){
	srand(1);
	for(int i=0;i<100;i++)
		array[i]=0+rand()%100000;
	for(int i=0;i<100;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	merge_sort(array,0,99,mul);
	for(int i=0;i<100;i++)
		cout<<array[i]<<endl;
}
