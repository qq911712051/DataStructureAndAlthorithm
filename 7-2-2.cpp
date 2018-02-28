#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int src[50];
void all_sort(vector<int> A,vector<int> B){
    if(B.empty()){
        cout<<"("<<A[0];
        for(int i=1;i<A.size();i++)
            cout<<","<<A[i];
        cout<<")"<<endl;
    }else{
        for(int i=0;i<B.size();i++){
            vector<int> ta=A;
            ta.push_back(B[i]);
            vector<int> tb=B;
            tb.erase(tb.begin()+i);
            all_sort(ta,tb);
        }

    }

}
int main(){
    int n,hehe;
    cin>>n;
    vector<int> sets;
    for(int i=0;i<n;i++){
        cin>>hehe;
        sets.push_back(hehe);
    }
    vector<int> tmp;
    all_sort(tmp,sets);
    return 0;
}