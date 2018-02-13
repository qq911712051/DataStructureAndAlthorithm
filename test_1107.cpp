#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int maps[13][13];
struct people
{
    int posx,posy;
    int hp,neili,wuli;
    int num;
    bool fan;
    char flag;
} person[1001];

int renshu;

bool setdizi(char temp)
{
    scanf("%c",&temp);
    if(temp=='0')
        return false;
    int x,y,neili,wuli,shengming;
    scanf("%d %d %d %d %d",&x,&y,&neili,&wuli,&shengming);
    maps[x][y]++;
    if(temp=='S')
    {
        person[renshu].posx=x;
        person[renshu].posy=y;
        person[renshu].neili=neili;
        person[renshu].wuli=wuli;
        person[renshu].hp=shengming;
        person[renshu].num=renshu;
        person[renshu].flag='S';
        person[renshu].fan=false;

    }
    else if(temp=='W')
    {
        person[renshu].fan=false;
        person[renshu].posx=x;
        person[renshu].posy=y;
        person[renshu].neili=neili;
        person[renshu].wuli=wuli;
        person[renshu].hp=shengming;
        person[renshu].num=renshu;
        person[renshu].flag='W';

    }
    else if(temp=='E')
    {
        person[renshu].fan=false;
        person[renshu].posx=x;
        person[renshu].posy=y;
        person[renshu].neili=neili;
        person[renshu].wuli=wuli;
        person[renshu].hp=shengming;
        person[renshu].num=renshu;
        person[renshu].flag='E';

    }
    renshu++;
    return true;
}

int fighting(char c,int nei,int wu,int sheng)
{
    if(c=='S')
    {
        double temp= (  (0.5*(double)nei + 0.5*(double)wu) * (sheng+10)  /100 );
        //  printf("%c %d %d %d temp is %lf\n",c,nei,wu,sheng,temp);
        return (int)temp;
    }
    else if(c=='W')
    {
        double temp= (  (0.8*(double)nei+0.2*(double)wu) * (sheng+10)  /100 );
        //printf("%c %d %d %d temp is %lf\n",c,nei,wu,sheng,temp);
        return (int)temp;
    }
    else if(c=='E')
    {
        double temp= (  (0.2*(double)nei+0.8*(double)wu) * (sheng+10) /100 );
        //printf("%c %d %d %d temp is %lf\n",c,nei,wu,sheng,temp);
        return (int)temp;
    }
}

int harm1,harm2;
int book1,book2;

void fight_and_move()
{
    int i,j,k;
    //互相伤害
    for(i=1; i<=12; i++)
    {
        for(j=1; j<=12; j++)
        {
            if(maps[i][j]==2)
            {

                for(k=0; k<renshu; k++)
                {
                    if(person[k].posx==i&&person[k].posy==j&&person[k].hp>0)
                    {
                        book1=k;
                        break;
                    }
                }
                for(k+=1; k<renshu; k++)
                {
                    if(person[k].posx==i&&person[k].posy==j&&person[k].hp>0)
                    {
                        book2=k;
                        break;
                    }
                }

                if(person[book1].flag!=person[book2].flag)
                {
                    harm1=fighting(person[book1].flag,person[book1].neili,person[book1].wuli,person[book1].hp);
                    harm2=fighting(person[book2].flag,person[book2].neili,person[book2].wuli,person[book2].hp);

                    if(person[book1].hp>0)
                        person[book1].hp-=harm2;
                    if(person[book2].hp>0)
                        person[book2].hp-=harm1;
                }
            }
        }
    }

    //  移动

    for(k=0; k<renshu; k++)
    {
        if(person[k].hp>0)
        {
            if(person[k].flag=='S')//少林走
            {
               // maps[person[k].posx][person[k].posy]--;

                if(person[k].posx==12)
                    person[k].fan=true;
                if(person[k].posx==1)
                    person[k].fan=false;

                if(person[k].fan==false)//继续往前走
                {
                    person[k].posx+=1;
                }
                else person[k].posx-=1;

             //   maps[person[k].posx][person[k].posy]++;
            }
            else if(person[k].flag=='W')//武当走
            {
                //maps[person[k].posx][person[k].posy]--;
                if(person[k].posy==12)
                    person[k].fan=true;
                if(person[k].posy==1)
                    person[k].fan=false;

                if(person[k].fan==false)
                {
                    person[k].posy+=1;
                }

                else person[k].posy-=1;


                //maps[person[k].posx][person[k].posy]++;
            }
            else if(person[k].flag=='E')//峨眉走
            {
               // maps[person[k].posx][person[k].posy]--;
                if( (person[k].posx==12&&person[k].posy==1) || (person[k].posx==1&&person[k].posy==12) )
                    continue;

                if(person[k].posy==12||person[k].posx==12)
                    person[k].fan=true;
                if(person[k].posy==1||person[k].posx==1)
                    person[k].fan=false;

                if(person[k].fan==false)
                {
                    person[k].posx+=1;
                    person[k].posy+=1;
                }
                else
                {
                    person[k].posx-=1;
                    person[k].posy-=1;
                }


               // maps[person[k].posx][person[k].posy]++;
            }
        }
    }
}


int main()
{
    int N;
    int times;
    scanf("%d",&times);
    while(times--)
    {
        scanf("%d",&N);
        renshu=0;
        char temp;
        getchar();
        while(setdizi(temp))
        {
            getchar();
        }

        while(N--)
        {
            fight_and_move();
            memset(maps,0,sizeof(maps));
            for(int x=0;x<renshu;x++)
            {
                if(person[x].hp>0)
                {
                    maps[person[x].posx][person[x].posy]++;
                }
            }
        }
     //   printf("Move    %d 弟子\n",renshu);

        int ss=0,s_hp=0,ww=0,w_hp=0,ee=0,e_hp=0;

        for(int i=0; i<renshu; i++)
        {
            if(person[i].hp>0)
            {
                if(person[i].flag=='S')
                {
                    ss++;
                    s_hp+=person[i].hp;
                }
                else if(person[i].flag=='W')
                {
                    ww++;
                    w_hp+=person[i].hp;
                }
                else if(person[i].flag=='E')
                {
                    ee++;
                    e_hp+=person[i].hp;
                }
            }
        }
        printf("%d %d\n",ss,s_hp);
        printf("%d %d\n",ww,w_hp);
        printf("%d %d\n",ee,e_hp);
        printf("***\n");
    }
    return 0;
}