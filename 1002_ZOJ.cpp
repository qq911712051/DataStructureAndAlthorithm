#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
char city[100][100];
int tmpc[100][100];
int max_num,n;
int start_flag;
int check_yes(int a,int b){
    if(city[a][b]=='X')
        return 0;
    for(int i=a-1;i>=0;i--)
        if(city[i][b]=='X')
            break;
        else if(city[i][b]=='1')
            return 0;
    for(int i=b-1;i>=0;i--)
        if(city[a][i]=='X')
            break;
        else if(city[a][i]=='1')
            return 0;
    return 1;
}
void find_max(int a,int b){
    int flag_1=0;
    if(a>=n||b>=n)
        return;
    if(check_yes(a,b)){
        city[a][b]='1';
        flag_1=1;
        if((b+1)==n)
            find_max(a+1,0);
        else    
            find_max(a,b+1);

        city[a][b]='.';
        if((b+1)==n)
            find_max(a+1,0);
        else    
            find_max(a,b+1);
    }else{
        if((b+1)==n)
            find_max(a+1,0);
        else    
            find_max(a,b+1);
    }
    int sum=0;
    if(a==(n-1)&&b==(n-1)){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(city[i][j]=='1')
                    sum++;
        if(flag_1==0&&sum>max_num)
            max_num=sum;
        if(flag_1==1&&sum>=max_num)
            max_num=sum+1;

    }
    

}
int main(){
    cin>>n;
    while(n!=0){
        max_num=0;
        memset(city,0,sizeof(city));
        for(int i=0;i<n;i++)
            scanf("%s",city[i]);
        find_max(0,0);
        cout<<max_num<<endl;
        cin>>n;
    }
    
    return 0;
}