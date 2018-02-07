#include <iostream>
#include "BigNumber/BigNumber.h"
#define LOCAL
using namespace std;
int main(){
    BigNumber num;
    cin>>num;
    int n;
    cin>>n;
    cout<<"origin is:"<<num<<endl;
    cout<<"division :"<<num.division(n)<<endl;
    return 0;
}