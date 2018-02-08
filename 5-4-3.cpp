#include <iostream>
using namespace std;
float min_L(float x1,float x2,float x3){
    float min=x1<x2?x1:x2;
    return min<x3?min:x3;
}
float max_L(float x1,float x2,float x3){
    float max=x1>x2?x1:x2;
    return max>x3?max:x3;
}
int main(){
    float x1,y1,x2,y2,x3,y3;
    float k1,b1,k2,b2,k3,b3;
    //1:(1 2)     2:(2 3)     3:(1 3)
    int flag1=0,flag2=0,flag3=0; //标识是否斜率正无穷
    int dir1=0,dir2=0,dir3=0; //标识上下，0上  1下
    int min_x=100,min_y=100,max_x=0,max_y=0;
    while(scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3)==6){
        int num=0;
        //标识范围
        min_x=min_L(x1,x2,x3);
        max_x=max_L(x1,x2,x3)+1;
        min_y=min_L(y1,y2,y3);
        max_y=max_L(y1,y2,y3)+1;
        y1=-y1;y2=-y2;y3=-y3;
        if(x1==x2){
            flag1=1;
            if(x3>x1)
                dir1=1;
            else    
                dir1=0;
        }else{
            flag1=0;
            k1=(y1-y2)/(x1-x2);
            b1=y1-k1*x1;
            if((k1*x3+b1)<y3)
                dir1=0;
            else
                dir1=1;
        }
    
        if(x2==x3){
            flag2=1;
            if(x1>x2)
                dir2=1;
            else    
                dir2=0;
        }else{
            flag2=0;
            k2=(y2-y3)/(x2-x3);
            b2=y2-k2*x2;
            if((k2*x1+b2)<y1)
                dir2=0;
            else
                dir2=1;
        }

        if(x1==x3){
            flag3=1;
            if(x2>x1)
                dir3=1;
            else    
                dir3=0;
        }else{
            flag3=0;
            k3=(y1-y3)/(x1-x3);
            b3=y1-k3*x1;
            if((k3*x2+b3)<y2)
                dir3=0;
            else
                dir3=1;
        }
        //遍历
        for(int i=min_x;i<=max_x;i++)
            for(int j=-min_y;j>=-max_y;j--){
                //判断第一条直线
                if(flag1==1){
                    if(dir1==0&&i<=x1);
                    else if(dir1==1&&i>=x1);
                    else continue;
                }else{
                    if(dir1==0&&(k1*i+b1<=j));
                    else if(dir1==1&&(k1*i+b1>=j));
                    else continue;
                }

                //第二条
                if(flag2==1){
                    if(dir2==0&&i<=x2);
                    else if(dir2==1&&i>=x2);
                    else continue;
                }else{
                    if(dir2==0&&(k2*i+b2<=j));
                    else if(dir2==1&&(k2*i+b2>=j));
                    else continue;
                }

                //第三条
                if(flag3==1){
                    if(dir3==0&&i<=x1);
                    else if(dir3==1&&i>=x1);
                    else continue;
                }else{
                    if(dir3==0&&(k3*i+b3<=j));
                    else if(dir3==1&&(k3*i+b3>=j));
                    else continue;
                }

                //在三角形内部
                num++;
            }
        //打印数量
        cout<<num<<endl;

    }
    return 0;
}