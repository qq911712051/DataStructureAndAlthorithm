#include <iostream>
#include <cstring>
using namespace std;
struct Bign{
	int number[1010];
	int length;
};
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n-3;i++)
		for(int j=1;j<=n-i-2;j++)
			for(int k=1;k<=n-i-j-1;k++){
				//0 =i   1=  j   2=  k  3=   n-i-k-j  
				
			}
	return 0;
}
