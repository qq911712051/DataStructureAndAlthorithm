#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> makeof[1000];
int main(){
	makeof[1].push_back(1);
	makeof[2].push_back(1);makeof[2].push_back(1);
	makeof[3].push_back(3);
	makeof[4].push_back(1);makeof[4].push_back(3);
	makeof[5].push_back(5);
	int n;
	int sorted[100],t=0;
	while(cin>>n){
		for(int i=6;i<=n;i++)
			if(makeof[i].empty()){
				int a=makeof[i-1].size();
				int b=makeof[i-3].size();
				int c=makeof[i-5].size();
				int min=a,pos=i-1;
				if(b<min){
					min=b;pos=i-3;
				}
				if(c<min){
					min=c;pos=i-5;
				}
				vector<int> tmp=makeof[pos];
				tmp.push_back(i-pos);
				makeof[i]=tmp;
				sort(makeof[i].begin(),makeof[i].end());
			}
		for(int i=0;i<makeof[n].size();i++)
			cout<<makeof[n][i]<<" ";
		cout<<endl;
	}
	return 0;
}
