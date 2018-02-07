/**
 * 仅仅实现了一个除法      高精度/整数
 * 
 * */

#ifndef BIGNUMBER_H_
#define BIGNUMBER_H_
#include <cstring>
#include <iostream>
using namespace std;
#define MAXSIZE  1000
class BigNumber{
    int length; //数组长度
    int start;  //数字位于数组中的位置

    int array[MAXSIZE];

public:
    BigNumber();
    BigNumber operator=(const char* num);
    BigNumber operator=(const int num);
    BigNumber operator=(const BigNumber& num);
    BigNumber division(int ss);
   // BigNumber division(BigNumber a);
    friend ostream& operator<<(ostream& out,const BigNumber& num);
    friend istream& operator>>(istream& in,BigNumber& num);
};
#endif