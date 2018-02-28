#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring> 
using namespace std;
int Map[1005][1005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	while(n!=0){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&Map[i][j]);
		int Q,x1,y1,x2,y2;;
		scanf("%d",&Q);
		for(int q=1;q<=Q;q++){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(Map[x1][y1]!=Map[x2][y2]||Map[x1][y1]==0||Map[x2][y2]==0){
				cout<<"NO"<<endl;
				continue;
			}
			//水平方向
			int glo_flag=0;
			int y1_l=y1,y1_r=y1,y2_l=y2,y2_r=y2;
			while(y1_l>1&&Map[x1][y1_l-1]==0)y1_l--;
			while(y1_r<m&&Map[x1][y1_r+1]==0)y1_r++;
			while(y2_l>1&&Map[x2][y2_l-1]==0)y2_l--;
			while(y2_r<m&&Map[x2][y2_r+1]==0)y2_r++;
			int y_ll=max(y1_l,y2_l);
			int y_rr=min(y1_r,y2_r);
			for(int k=y_ll;k<=y_rr;k++){
				int flag_2=0;
				int x_min=min(x1,x2);
				int x_max=max(x1,x2);
				for(int i=x_min+1;i<=x_max-1;i++){
					if(Map[i][k]!=0){
						flag_2=1;
						break;
					}
				}
				if(!flag_2){
					glo_flag=1;
					break;
				}
			}
			if(glo_flag){
				cout<<"YES"<<endl;
				continue;
			}
			//竖直方向
			int x1_up=x1,x1_down=x1,x2_up=x2,x2_down=x2;
			while(x1_up>1&&Map[x1_up-1][y1]==0)x1_up--;
			while(x1_down<n&&Map[x1_down+1][y1]==0)x1_down++;
			while(x2_up>1&&Map[x2_up-1][y2]==0)x2_up--;
			while(x2_down<n&&Map[x2_down+1][y2]==0)x2_down++;
			int x_up=max(x1_up,x2_up);
			int x_down=min(x1_down,x2_down);
			for(int k=x_up;k<=x_down;k++){
				int flag_2=0;
				int y_min=min(y1,y2);
				int y_max=max(y1,y2);
				for(int i=y_min+1;i<=y_max-1;i++){
					if(Map[k][i]!=0){
						flag_2=1;
						break;
					}
				}
				if(!flag_2){
					glo_flag=1;
					break;
				}
			} 
			
			if(glo_flag)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			
		}
		
		scanf("%d%d",&n,&m);
	}
	return 0;
} 
