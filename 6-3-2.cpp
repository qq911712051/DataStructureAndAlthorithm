#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
#define Error  999999
char src[10000];
struct Tnode{
    int var;
    Tnode *left,*right;
};
class Tree{
    Tnode *root;
    int first_flag;
    int error_flag;
    void clear(Tnode *root){
        if(root){
            clear(root->left);
            clear(root->right);
            delete root;
               
        }
    }
    void print(Tnode *root){
        if(root){
            print(root->left);
            if(first_flag)
                cout<<" "<<root->var;
            else{
                first_flag=1;
                cout<<root->var;
            }
            print(root->right);
        }
    }
    void bfs_print(Tnode * root){
        if(root){
            queue<Tnode*> q;
            q.push(root);
            while(!q.empty()){
                Tnode *cur=q.front();
                if(!first_flag){
                    first_flag=1;
                    cout<<cur->var;
                }else{
                    cout<<" "<<cur->var;
                }
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
    }
public:
    Tree(){
        root=NULL;
        first_flag=0;
        error_flag=0;
    }
    void insert(int var,const char *pos){
        if(root==NULL){
            Tnode *tmp=new Tnode();
            tmp->var=Error;
            tmp->left=NULL;
            tmp->right=NULL;
            root=tmp;
        }
        Tnode *cur=root;
        int dept=strlen(pos);
        if(!dept){
            root->var=var;
            return;
        }
        for(int i=0;i<dept;i++){
            if(pos[i]=='L'){
                if(cur->left==NULL){
                    Tnode *tmp=new Tnode();
                    tmp->var=Error;
                    tmp->left=NULL;
                    tmp->right=NULL;
                    cur->left=tmp;
                }
                cur=cur->left;
            }else{
                if(cur->right==NULL){
                    Tnode *tmp=new Tnode();
                    tmp->var=Error;
                    tmp->left=NULL;
                    tmp->right=NULL;
                    cur->right=tmp;
                }
                cur=cur->right;
            }
        }
        cur->var=var;
    }
    void clear(){
        ///
        clear(root);
        root=NULL;
    }
    void bfs_print(){
        ///
        first_flag=0;
        bfs_print(root);
        cout<<endl;
    }
};
int main(){
    Tree t;
    while(fgets(src,10000,stdin)){
        t.clear();
        int length=strlen(src);
        int num;
        char nice[100];
        int pos=0;
        int sflag=0;
        for(int i=0;i<length;i++){
            if(src[i]=='('){
                num=0;
                pos=0;
                sflag=1;
            }else if(src[i]==','){
                sflag=0;
            }else if(src[i]==')'){
                if(sflag){
                    t.bfs_print();
                    break;
                }
                nice[pos]='\0';
                t.insert(num,nice); 
            }else{
                if(sflag){
                    num=num*10+(src[i]-'0');
                }else{
                    nice[pos++]=src[i];
                }
            }
        }
    }
    return 0;
}