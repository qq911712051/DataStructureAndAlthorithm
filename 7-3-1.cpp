#include <iostream>
#include <vector>
using namespace std;
void sub_set(vector<int> A,vector<int> B){
    if(!A.empty()){
        cout<<"("<<A[0];
        for(int i=1;i<A.size();i++)
            cout<<","<<A[i];
        cout<<")"<<endl;
    }
    for(int i=0;i<B.size();i++){
        vector<int> ta=A;
        ta.push_back(B[i]);
        B.erase(B.begin()+i);i--;
        sub_set(ta,B);
    }

}
void sub_set_1(vector<int> A,vector<int> vec,int cur){
    if(cur==A.size()){
        for(int i=0;i<A.size();i++)
            if(vec[i])
                cout<<A[i]<<" ";
        cout<<endl;
    }else{
        vec.push_back(1);
        sub_set_1(A,vec,cur+1);
        vec[cur]=0;
        sub_set_1(A,vec,cur+1);
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
    sub_set_1(sets,tmp,0);
    // vector<int> tmp;
    // sub_set(tmp,sets);
    return 0;
}