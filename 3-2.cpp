#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
int dir[5][2]={0,0,1,0,0,-1,-1,0,0,1}; //下左上右
int matrix[MAXSIZE][MAXSIZE];
int main(){
    memset(matrix,0,sizeof(matrix));
    int n,i,direc=1;
    scanf("%d",&n);
    int pos_row=1;
    int pos_col=n;
    for(i=1;i<=n*n;i++){
        matrix[pos_row][pos_col]=i;
        int tmp_row=pos_row+dir[direc][0];
        int tmp_col=pos_col+dir[direc][1];
        
        if(matrix[tmp_row][tmp_col]!=0||(direc==1&&tmp_row>n)||(direc==2&&tmp_col<1)||(direc==3&&tmp_row<1)||(direc==4&&tmp_col>n)){
            direc++;
            if(direc>4)
                direc=1;
        }
        pos_row+=dir[direc][0];pos_col+=dir[direc][1];
    }
    int j;
    //print
    int first_flag=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(first_flag)
                first_flag=0;
            else
                printf(" ");
            printf("%4d",matrix[i][j]);    
        
        }
        first_flag=1;
        printf("\n");
    }
    return 0;
}