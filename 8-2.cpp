#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MaxSize=10;
int array[MaxSize],num[MaxSize],cf[MaxSize];
int main(){
	srand(1);
	memset(array,0,sizeof(array));
	memset(num,0,sizeof(num));
	memset(cf,0,sizeof(cf));
	for(int i=0;i<MaxSize;i++){
		array[i]=0+rand()%10000;
		cout<<array[i]<<"  ";
	}
	cout<<endl;
	int count=0;
	for(int i=MaxSize-1;i>=0;i--){
		int k=i+1;
		while(k<MaxSize){
			if(array[i]>array[k]){
				num[i]=cf[k]+1;
				cf[i]=num[k]+1;
				break;
			}else if(array[i]==array[k]){
				num[i]=num[k];
				cf[i]=cf[k]+1;
				break;
			}
			k++;
		}
		cout<<"pos:"<<i<<" num:"<<num[i]<<endl;
		count+=num[i]; 
	}
	cout<<count<<endl;
	return 0;
}
