#include <iostream>
#include <cstring>
using namespace std;
#define MAXSIZE 50010
int by[MAXSIZE],N;
int tree[MAXSIZE<<2];

//建树
void build(int l,int r,int pos){
    if(l==r){
        tree[pos]=by[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1);
    tree[pos]=tree[pos<<1]+tree[pos<<1|1];
}
//查询
int query(int L,int R,int l,int r,int pos){
    if(L==l&&R==r){
        return tree[pos];
    }
    int mid=(L+R)>>1;
    if(r<=mid)
        return query(L,mid,l,r,pos<<1);
    else if(l>=mid+1)
        return query(mid+1,R,l,r,pos<<1|1);
    else if(l<=mid)
        return query(L,mid,l,mid,pos<<1)+query(mid+1,R,mid+1,r,pos<<1|1);

}
//更新
void update_sub(int L,int R,int pos,int src_pos,int var){
    if(L==R&&L==src_pos){
        tree[pos]-=var;
        return;
    }
    int mid=(L+R)>>1;
    if(src_pos<=mid){
        update_sub(L,mid,pos<<1,src_pos,var);
    }else{
        update_sub(mid+1,R,pos<<1|1,src_pos,var);
    }
    tree[pos]-=var;
}
void update_add(int L,int R,int pos,int src_pos,int var){
    if(L==R&&L==src_pos){
        tree[pos]+=var;
        return;
    }
    int mid=(L+R)>>1;
    if(src_pos<=mid){
        update_add(L,mid,pos<<1,src_pos,var);
    }else{
        update_add(mid+1,R,pos<<1|1,src_pos,var);
    }
    tree[pos]+=var;
}
int main(){
    int N,n,para1,para2;
    char comm[20];
    scanf("%d",&N);
    for(int k=0;k<N;k++){
        printf("Case %d:\n",k+1);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&by[i]);
        build(1,n,1);
        scanf("%s",comm);
        while(strcmp(comm,"End")){
            scanf("%d%d",&para1,&para2);
            if(!strcmp(comm,"Query")){
                printf("%d\n",query(1,n,para1,para2,1));
            }else if(!strcmp(comm,"Add")){
                update_add(1,n,1,para1,para2);
            }else if(!strcmp(comm,"Sub")){
                update_sub(1,n,1,para1,para2);
            }
            scanf("%s",comm);
        }
    }
    return 0;
}