#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define MAXSIZE 1000000  
  
typedef int State[9];//s���ؾ������ǳ���Ϊ100�����飬����Ԫ��s[i]������������State�ǳ���Ϊ10�����飬��ͬ�ڶ�����һ����ά����s[100]=iArr[100][9],����Ԫ��ʦint  
                     //int iarr[100][10]��arr�����������ǳ���Ϊ100�����飬����Ԫ��ʦarr[i],arr[i]�����������ǳ���Ϊ10�����飬����Ԫ��ʦint  
State st[MAXSIZE];//״̬��һ��Ҫ�ඨ�壬����һ��С�ľͳ���  
State stEnd;  
int iDist[MAXSIZE];  
  
int go[][2] =   
{  
    {-1,0},  
    {1,0},  
    {0,-1},  
    {0,1}  
};  
  
  
  
int iVis[362880],fact[9];//9!=362880��8!=40320,9*8!=9!������ô������Ȼ������Ѱ�ң����ǳ�ʼ��fact  
void init()  
{  
    fact[0] = 1;  
    for(int i = 1 ; i < 9; i++)  
    {  
        fact[i] = fact[i-1]*i;  
    }  
}  
  
  
//bool isInsert(State state)  
bool isInsert(int n)//ȥ�أ����ñ����������ƣ�ȷ��һ��9ά״ֻ̬��ӳ�䵽һ�����֣�����ӳ����������ֵ���ܳ���9!  
{  
    int iCode = 0;//����ֵ  
    for(int i = 0 ; i < 9 ; i++)  
    {  
        int iCnt = 0;  
        for(int j = i+1; j < 9;j++)  
        {  
            if(st[n][j] < st[n][i])//ͳ��ÿ�������У�����С��ǰ�����е����ָ���  
            {  
                iCnt++;  
            }  
        }  
        iCode += fact[8-i]*iCnt;  
    }  
    if(iVis[iCode])//����Ѿ����ʹ�  
    {  
        return false;  
    }  
    else  
    {  
        iVis[iCode] = 1;  
        return true;//ͬʱ��ɸ�ֵ�ͷ���ֵ����  
    }  
}  
  
int bfs()  
{  
    int iRear = 2,iFront = 1;  
    init();//����������أ�����������Ҫ�ж��ظ������Ƕ���ͼ��Ҫ�ж�  
    while(iFront < iRear)  
    {  
        State& state = st[iFront];  
        if(memcmp(stEnd,state,sizeof(state)) == 0)//�ж��Ƿ��ҵ��Ĺ���Ҫ���ڿ�ͷ  
        {  
            return iFront;  
        }  
          
        int iZ,iX,iY;  
        for(int i = 0 ; i < 9; i++)//ȷ��0���ڵ�λ��  
        {  
            if(!state[i])  
            {  
                iZ = i;  
                iX = iZ / 3;  
                iY = iZ % 3;  
                break;//����Ѱ��������⣬һ���ҵ���������break����  
            }  
        }  
        //������һ��λ��  
        int iNewZ,iNewX,iNewY;  
        for(int i = 0; i < 4; i++)  
        {  
            iNewX = go[i][0] + iX;  
            iNewY = go[i][1] + iY;  
            iNewZ = iNewX*3 + iNewY;//ȷ��0����λ��  
            if(iNewX >= 0 && iNewX < 3 && iNewY >= 0 && iNewY < 3)//��֦  
            {  
                State& newState = st[iRear];//����Ӧ�ôӶ�β��ǰ��ԭ���ϵ�״̬�������µ�״̬���ٽ���״̬����Ҫ�޸�0Ԫ�صĵط������޸�,��Ҫ�����ã�Ϊ�޸���׼��  
                memcpy(&newState,&state,sizeof(state));  
                newState[iNewZ] = state[iZ];//�¾���0Ԫ�ص�λ���Ϸ�0Ԫ��  
                newState[iZ] = state[iNewZ];//�¾���ԭ����0Ԫ�ص�λ�������ڷ��������ɵ�0Ԫ�ص�����,���������ԭ��������Ԫ�ص�ֵ�滻  
                iDist[iRear] = iDist[iFront] + 1;//�����ƶ��Ĳ���  
            }  
            if(isInsert(iRear))//�޸Ķ�βָ��  
            {  
                iRear++;  
            }  
        }  
        iFront++;//�����Ƿ�ɹ����޸Ķ�ͷ  
    }  
    return -1;  
}  
  
void process()  
{  
    //��ʼ����ͷ�Ͷ�βԪ��  
    for(int i = 0 ; i < 9;i++)  
    {  
        scanf("%d",&st[1][i]);  
    }  
    for(int j = 0 ; j < 9; j++)  
    {  
        scanf("%d",&stEnd[j]);  
    }  
    iDist[1] = 0;//���õ�һ���ƶ��ľ���Ϊ0  
    memset(iVis,0,sizeof(iVis));//��ʼ�������ڴ��,������仰û�ӵ��´����  
}  
  
int main(int argc,char* argv[])  
{  
    process();  
    int iRes = bfs();//���ص���front��ֵ���������ƶ��������ƶ���������dist�����㣬��Ϊ�����ǿ�����������������front��ֵ����ô�м䳢�ԵĽڵ�Ҳ����  
    if(iRes > 0)  
    {  
        printf("%d\n",iDist[iRes]);  
    }  
    else  
    {  
        printf("-1\n");  
    }  
    system("pause");  
    return 0;  
}  
