#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MaxSize=10;
int array[MaxSize];
void swap(int* a,int* b){
	if(a!=b){
		int tmp=*a;
		*a=*b;
		*b=tmp;
	}
}
int topk(int* A,int l,int r,int k){
	if(l>=r)
		return 0;
	if(l==r-1){
		if(A[l]>A[r])swap(A+l,A+r);
		return 0;
	}
	int mid=(l+r)>>1;
	
	int cur=A[mid];
	swap(A+mid,A+r);
	int p=l,q=r-1;
	while(p<q){
		while(p<q&&A[p]<=cur)p++;
		if(A[p]<=cur){
			p++;break;
		}
		while(p<q&&A[q]>cur)q--;
		swap(A+p,A+q);	
	}
	swap(A+p,A+r);
	cout<<"tartget is "<<cur<<endl;
	cout<<"left is ";
	for(int i=l;i<p;i++)
		cout<<A[i]<<"  ";
	cout<<"  right is ";
	for(int i=p+1;i<r+1;i++)
		cout<<A[i]<<"  ";
	cout<<endl;
	topk(A,l,p-1,k);
	topk(A,p+1,r,k);
		
//	if(k<p)return topk(A,l,p-1,k);
//	else if(k==p)return A[k];
//	else return topk(A,p+1,r,k);
}
int main(){
	memset(array,0,sizeof(array));
	int k;
	srand(1);
	for(int i=0;i<MaxSize;i++){
		array[i]=0+rand()%100000;
		cout<<array[i]<<"  ";
	}
	cout<<endl;
	scanf("%d",&k);
	int num=topk(array,0,MaxSize-1,k);
//	cout<<num<<endl;
	for(int i=0;i<MaxSize;i++)
		cout<<array[i]<<"  ";
	cout<<endl;
	return 0;
} 
