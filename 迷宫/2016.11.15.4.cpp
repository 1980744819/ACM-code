#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<malloc.h>
#include<cmath>
#include<stack>
using namespace std;
char Map[10][10];
int startx,starty,endx,endy;
int nextx[4]={0,1,0,-1};
int nexty[4]={1,0,-1,0};
struct stu{
    int x,y;
};
stack<struct stu>walk;
struct stu pos,t;
void mov(int a,int b){
    pos.x=startx;
    pos.y=starty;
    walk.push(pos);
    int flag=0;
    int i,j;
    int f=0;
    while(!walk.empty()){
        flag=0;
        for(i=0;i<4;i++){
            t=walk.top();
            a=t.x+nextx[i];
            b=t.y+nexty[i];
            if(a<0||a>=10||b<0||b>=10||Map[a][b]!=' ')
                continue;
            else{
                Map[a][b]='*';
                pos.x=a;
                pos.y=b;
                walk.push(pos);
                flag=1;
                if(a==endx&&b==endy){
                    f=1;
                    break;
                }
                mov(a,b);
            }
        }
        if(f)
            break;
        if(!flag){
            pos=walk.top();
            Map[pos.x][pos.y]='!';
            walk.pop();
        }
    }
}
int main(){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            scanf("%c",&Map[i][j]);
            if(Map[i][j]=='S'){
                startx=i;
                starty=j;
                Map[startx][starty]='*';
            }
            if(Map[i][j]=='E'){
                endx=i;
                endy=j;
                Map[endx][endy]=' ';
            }
        }
        getchar();
    }
    mov();
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%c",Map[i][j]);
        }
        cout<<endl;
    }
    return 0;
}

