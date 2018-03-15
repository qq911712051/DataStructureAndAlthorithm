#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define MAXSIZE 1000000  
  
typedef int State[9];//s的素具类型是长度为100的数组，数组元素s[i]的数据类型是State是长度为10的数组，等同于定义了一个二维数组s[100]=iArr[100][9],数组元素师int  
                     //int iarr[100][10]，arr的数据类型是长度为100的数组，数组元素师arr[i],arr[i]的数据类型是长度为10的数组，数组元素师int  
State st[MAXSIZE];//状态数一定要多定义，否则一不小心就超了  
State stEnd;  
int iDist[MAXSIZE];  
  
int go[][2] =   
{  
    {-1,0},  
    {1,0},  
    {0,-1},  
    {0,1}  
};  
  
  
  
int iVis[362880],fact[9];//9!=362880，8!=40320,9*8!=9!共有这么多排序，然后我们寻找，我们初始化fact  
void init()  
{  
    fact[0] = 1;  
    for(int i = 1 ; i < 9; i++)  
    {  
        fact[i] = fact[i-1]*i;  
    }  
}  
  
  
//bool isInsert(State state)  
bool isInsert(int n)//去重，采用编码与解码机制，确保一个9维状态只能映射到一个数字，并且映射的数字最大值不能超过9!  
{  
    int iCode = 0;//编码值  
    for(int i = 0 ; i < 9 ; i++)  
    {  
        int iCnt = 0;  
        for(int j = i+1; j < 9;j++)  
        {  
            if(st[n][j] < st[n][i])//统计每个排列中，后面小于前面排列的数字个数  
            {  
                iCnt++;  
            }  
        }  
        iCode += fact[8-i]*iCnt;  
    }  
    if(iVis[iCode])//如果已经访问过  
    {  
        return false;  
    }  
    else  
    {  
        iVis[iCode] = 1;  
        return true;//同时完成赋值和返回值操作  
    }  
}  
  
int bfs()  
{  
    int iRear = 2,iFront = 1;  
    init();//这里进行判重，对于树不需要判断重复。但是对于图需要判断  
    while(iFront < iRear)  
    {  
        State& state = st[iFront];  
        if(memcmp(stEnd,state,sizeof(state)) == 0)//判断是否找到的工作要放在开头  
        {  
            return iFront;  
        }  
          
        int iZ,iX,iY;  
        for(int i = 0 ; i < 9; i++)//确定0所在的位置  
        {  
            if(!state[i])  
            {  
                iZ = i;  
                iX = iZ / 3;  
                iY = iZ % 3;  
                break;//凡是寻找类的问题，一旦找到，必须用break跳出  
            }  
        }  
        //生成下一步位置  
        int iNewZ,iNewX,iNewY;  
        for(int i = 0; i < 4; i++)  
        {  
            iNewX = go[i][0] + iX;  
            iNewY = go[i][1] + iY;  
            iNewZ = iNewX*3 + iNewY;//确定0的新位置  
            if(iNewX >= 0 && iNewX < 3 && iNewY >= 0 && iNewY < 3)//剪枝  
            {  
                State& newState = st[iRear];//这里应该从队尾提前将原来老的状态拷贝给新的状态，再将新状态中需要修改0元素的地方进行修改,需要用引用，为修改做准备  
                memcpy(&newState,&state,sizeof(state));  
                newState[iNewZ] = state[iZ];//新矩阵0元素的位置上放0元素  
                newState[iZ] = state[iNewZ];//新矩阵原来放0元素的位置上现在放上新生成的0元素的坐标,这里必须用原来被交换元素的值替换  
                iDist[iRear] = iDist[iFront] + 1;//更新移动的步数  
            }  
            if(isInsert(iRear))//修改队尾指针  
            {  
                iRear++;  
            }  
        }  
        iFront++;//不管是否成功，修改队头  
    }  
    return -1;  
}  
  
void process()  
{  
    //初始化队头和队尾元素  
    for(int i = 0 ; i < 9;i++)  
    {  
        scanf("%d",&st[1][i]);  
    }  
    for(int j = 0 ; j < 9; j++)  
    {  
        scanf("%d",&stEnd[j]);  
    }  
    iDist[1] = 0;//设置第一步移动的距离为0  
    memset(iVis,0,sizeof(iVis));//初始化访问内存块,就是这句话没加导致错误的  
}  
  
int main(int argc,char* argv[])  
{  
    process();  
    int iRes = bfs();//返回的是front的值，但不是移动次数，移动次数得用dist来计算，因为这里是宽度优先搜索，如果用front的值，那么中间尝试的节点也算了  
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
