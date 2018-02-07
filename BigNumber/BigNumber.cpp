#include "BigNumber.h"
#include <string>
#ifdef LOCAL
    using namespace std;
#endif
BigNumber::BigNumber(){
    length=0;
    start=0;
    memset(array,0,MAXSIZE);
}

BigNumber BigNumber::operator=(const char* num){
    if(num!=NULL){
        start=0;
        int size=strlen(num);
        length=size;
        for(int i=0;i<size;i++){
            array[i]=num[size-i-1]-'0';
        }
    
    }
    return *this;
}

BigNumber BigNumber::operator=(const int num){
    if(num>=0){
        start=0;
        int tmp=num;
        int i=0;
        while(1){
            array[i++]=tmp%10;
            tmp/=10;
            if(!tmp)
                break;
        }
        length=i;
       
    }
    return *this;
}

BigNumber BigNumber::division(int ss){
    BigNumber res;
    int numn=0;
    int flag=0;
    int c=0;
    for(int i=length+start;i>start;i--){
        int tmp=c*10+array[i-1];
        int hehe=tmp/ss;
        c=tmp%ss;
        if(hehe){
            flag=1;
            res.array[MAXSIZE-numn++ -1]=hehe;
            
        }else if(flag)
            res.array[MAXSIZE-numn++ -1]=hehe;
    }
    //结束计算
    res.length=numn;
    res.start=MAXSIZE-numn;
    return res;
}

BigNumber BigNumber::operator=(const BigNumber& num){
    length=num.length;
    start=num.start;
    memcpy(array,num.array,sizeof(num.array));
    return *this;
}

ostream& operator<<(ostream& out,const BigNumber& num){
    for(int i=num.length+num.start;i>num.start;i--)
        out<<num.array[i-1];
    return out;
}

istream& operator>>(istream& in,BigNumber& num){
    string s;
    in>>s;
    num=s.c_str();
    return in;
}