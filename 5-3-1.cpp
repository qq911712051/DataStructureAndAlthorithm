#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int n;
    int flag=0;
    int array[4];
    set<int> sets;
    cin>>n;
    while(1){
        if(sets.find(n)==sets.end()){
            if(flag){
                cout<<"->"<<n;
            }else{
                flag=1;
                cout<<n;
            }
            sets.insert(n);
            array[0]=n/1000;array[1]=n/100%10;array[2]=n/10%10;array[3]=n%10;
            sort(array,array+4);
            int s1=array[0]-array[3];
            int s2=array[1]-array[2];
            int s3=array[2]-array[1];
            int s4=array[3]-array[0];
            n=s1+s2*10+s3*100+s4*1000;
            
        }else{
            break;
        }

    }
    return 0;
}