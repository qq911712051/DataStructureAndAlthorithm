#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int s_num,w_num,e_num;
struct Dizi{
    char type;
    int neili,wuyi;
    int dir;
    int hp;
    int cal_flag;
    int gjl;
    char status;
    void updateG(){
        switch(type){
            case 'S':
                gjl=(0.5*neili+0.5*wuyi)*(hp+10)/100;
                break;
            case 'W':
                gjl=(0.8*neili+0.2*wuyi)*(hp+10)/100;
                break;
            case 'E':
                gjl=(0.2*neili+0.8*wuyi)*(hp+10)/100;
                break;
            default:
                break;
        };
    }
};
vector<Dizi> map[13][13];
int main(){
    char type;
    int dir,cal_flag=0;
    int neili,wuyi,row,col;
    int hp;
    char status='1';
    int N,steps;
    cin>>N;
    for(int ecp=0;ecp<N;ecp++){
        for(int i=1;i<13;i++)
            for(int j=1;j<13;j++)
                map[i][j].clear();
        s_num=0;
        w_num=0;
        e_num=0;
        cin>>steps;
        cin>>type;
        while(type!='0'){
            cin>>row>>col>>neili>>wuyi>>hp;
            Dizi tmp;
            tmp.type=type;
            tmp.neili=neili;
            tmp.wuyi=wuyi;
            tmp.hp=hp;
            tmp.status=status;
            switch(type){
                case 'S':
                    if(row==12)
                        dir=0;
                    else    
                        dir=1;
                  
                    break;
                case 'E':
                    if(row==12||col==12)
                        dir=0;
                    else
                        dir=1;
                    
                    break;
                case 'W':
                    if(col==12)
                        dir=0;
                    else    
                        dir=1;
                   
                    break;
                default:
                    break;
            };
            tmp.dir=dir;
            tmp.cal_flag=cal_flag;
            tmp.updateG();
            map[row][col].push_back(tmp);
            cin>>type;
        }
       
        for(int s=0;s<steps;s++){
            for(int i=1;i<13;i++)
                for(int j=1;j<13;j++){
                    if(map[i][j].size()==2&&map[i][j][0].type!=map[i][j][1].type){
                        map[i][j][0].hp-=map[i][j][1].gjl;
                        map[i][j][1].hp-=map[i][j][0].gjl;
                        map[i][j][0].updateG();
                        map[i][j][1].updateG();
                       
                        if(map[i][j][1].hp<=0){
                            map[i][j][1].status='0';
                            map[i][j].pop_back();
                        }
                        if(map[i][j][0].hp<=0){
                            map[i][j][0].status='0';
                            map[i][j].pop_back();
                        }
                    }
                }
            //move
            for(int i=1;i<13;i++)
                for(int j=1;j<13;j++){
                    for(int k=0;k<map[i][j].size();k++){
                        if(map[i][j][k].cal_flag<=s){
                            if(map[i][j][k].type=='S'){
                                if(map[i][j][k].dir==0){
                                    Dizi tmp_1=map[i][j][k];
                                    tmp_1.cal_flag=s+1;
                                    if(i-1==1)
                                        tmp_1.dir=1;
                                    map[i-1][j].push_back(tmp_1);
                                    map[i][j].erase(map[i][j].begin()+k);
                                    k--;
                                }else{
                                    Dizi tmp_1=map[i][j][k];
                                    tmp_1.cal_flag=s+1;
                                    if(i+1==12)
                                        tmp_1.dir=0;
                                    map[i+1][j].push_back(tmp_1);
                                    map[i][j].erase(map[i][j].begin()+k);
                                    k--; 
                                }
                            }else if(map[i][j][k].type=='W'){
                                if(map[i][j][k].dir==0){
                                    Dizi tmp_1=map[i][j][k];
                                    tmp_1.cal_flag=s+1;
                                    if(j-1==1)
                                        tmp_1.dir=1;
                                    map[i][j-1].push_back(tmp_1);
                                    map[i][j].erase(map[i][j].begin()+k);
                                    k--;
                                }else{
                                    Dizi tmp_1=map[i][j][k];
                                    tmp_1.cal_flag=s+1;
                                    if(j+1==12)
                                        tmp_1.dir=0;
                                    map[i][j+1].push_back(tmp_1);
                                    map[i][j].erase(map[i][j].begin()+k);
                                    k--; 
                                }
                            }else{
                                if((i==12&&j==1)||(i==1&&j==12))
                                    continue;
                                if(map[i][j][k].dir==0){
                                    Dizi tmp_1=map[i][j][k];
                                    tmp_1.cal_flag=s+1;
                                    if((i-1==1)||(j-1==1))
                                        tmp_1.dir=1;
                                    map[i-1][j-1].push_back(tmp_1);
                                    map[i][j].erase(map[i][j].begin()+k);
                                    k--;
                                }else{
                                    Dizi tmp_1=map[i][j][k];
                                    tmp_1.cal_flag=s+1;
                                    if((i+1==12)||(j+1==12))
                                        tmp_1.dir=0;
                                    map[i+1][j+1].push_back(tmp_1);
                                    map[i][j].erase(map[i][j].begin()+k);
                                    k--; 
                                }
                            }
                        }
                    }    
                
                }

        }
        int s_hp_num=0,w_hp_num=0,e_hp_num=0;
        for(int i=1;i<13;i++)
            for(int j=1;j<13;j++)
                for(int k=0;k<map[i][j].size();k++)
                    if(map[i][j][k].type=='S'){
                        s_hp_num+=map[i][j][k].hp;
                        s_num++;
                    }
                    else if(map[i][j][k].type=='W'){
                        w_hp_num+=map[i][j][k].hp;
                        w_num++;
                    }
                    else{        
                        e_hp_num+=map[i][j][k].hp;
                        e_num++;
                    }
        cout<<s_num<<" "<<s_hp_num<<endl;
        cout<<w_num<<" "<<w_hp_num<<endl;
        cout<<e_num<<" "<<e_hp_num<<endl;
        cout<<"***"<<endl;
    }
    return 0;
}