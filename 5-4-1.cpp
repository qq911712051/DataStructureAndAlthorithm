#include <iostream>
using namespace std;
int cal(int n){
    return n*(n+1)/2;
}
int main(){
    int n;
    int flag=0;
    while(cin>>n){
        //二分找到行数
        int left=1,right=n,mid=(left+right)/2;
        while(!(n<=cal(mid)&&n>=cal(mid-1))){
            if(n<cal(mid-1)){
                right=mid;
                mid=(left+right)/2;
            }else{
                left=mid;
                mid=(left+right)/2;
            }
        }

        int row=mid;
        int dir_flag=row%2;
        int mm=n-(row*(row-1)/2);
        int mu,zi;
        if(dir_flag==0){
            mu=row-mm+1;
            zi=mm;
        }else{
            mu=mm;
            zi=row-mm+1;
        }
        if(flag)
            cout<<endl<<zi<<"/"<<mu;
        else{
            flag=1;
            cout<<zi<<"/"<<mu;
        }
        
    }
    return 0;
}