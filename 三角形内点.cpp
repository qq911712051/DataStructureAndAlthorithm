#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef int A[3][3];
int n,m,p;
int A1,A2,A3,B1,B2,B3,C1,C2,C3;
double cal(){
    int sum=0;
    sum+=A1*B2+B1*C2+A2*C1;
    sum-=B2*C1;
    sum-=A2*B1;
    sum-=C2*A1;
    double res=(double)abs(sum)/2;
    // cout<<"x1="<<A1<<",y1="<<A2<<endl;
    // cout<<"x2="<<B1<<",y2="<<B2<<endl;
    // cout<<"x3="<<C1<<",y3="<<C2<<endl;
    // cout<<"the result is "<<res<<endl;
    return res;
}
int main(){
    cin>>n>>m>>p;
    A1=0;A2=0;A3=1;
    B1=p;B2=0;B3=1;
    C1=n;C2=m;C3=1;
    double area=cal();
    int count=0;
    int maxx=max(n,p),maxy=m;
    double tan=(double)m/n;
    double tan2=(double)(p-n)/m;
    for(int i=1;i<maxx;i++)
        for(int j=1;j<=maxy;j++){
            A tmp;
            A1=0;A2=0;A3=1;
            B1=p;B2=0;B3=1;
            C1=i;C2=j;C3=1;
            double s1=cal();if(s1==0)continue;
            A1=n;A2=m;A3=1;
            double s2=cal();if(s2==0)continue;
            B1=0;B2=0;B3=1;
            double s3=cal();if(s3==0)continue;
            if(s1+s2+s3==area)count++;
            // cout<<"area="<<area<<",s1="<<s1<<",s2="<<s2<<",s3="<<s3<<endl;
        }
    cout<<count<<endl;
    return 0;
}