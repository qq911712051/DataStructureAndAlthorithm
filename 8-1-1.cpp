#include <iostream>
#include <cstring>
using namespace std;
int ct[100000],st,en,cs;
long long Max,premax;
int main(){
	int flag=0,first=0,n;
	premax=0;
	scanf("%d",&n);
	memset(ct,0,sizeof(ct));
	for(int i=0;i<n;i++){
		scanf("%d",&ct[i]);
		if(!flag&&ct[i]>0){
			flag=1;
			cs=i;
			Max=ct[i];
			continue;
		}
		if(flag){
			if(ct[i]>=0){
				Max+=ct[i];
				if(Max>premax&&first){
					premax=Max;
					en=i+1;
					st=cs;
					first=0;
				}
			}else{
				if(Max+ct[i]<0){
					//Ë¢ÐÂ
					flag=0;first=0; 
					if(Max>premax){
						premax=Max;
						st=cs;en=i;
					}
				}else{		
					if(!first){
						if(Max>premax){
							first=1;
							premax=Max;
							st=cs;
							en=i;
						}
						Max+=ct[i];
					}else{
						Max+=ct[i];
					}
				}
			}
			
		}
	}
	if(Max>premax)
		cout<<cs<<"  "<<n<<"   "<<Max<<endl;
	else
		cout<<st<<"  "<<en<<"   "<<premax<<endl;
	return 0;
}
