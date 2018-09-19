#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
//#include<windows.h>
using namespace std;
int next[5][4][2];//1,2,3,4表示东南西北//1,2,3表示前进，左转，右转
bool instr[10][10][5][4];//表示i行j列朝着dir方向可以转哪个方向
int parent[10][10][2];//存进上一个节点的i,j
int x,y;
char s[25];
struct stu{
    int a;
    int b;
}node,nodet;
int startx,starty,endx,endy;
void init(){
    memset(instr,false,sizeof(instr));
    memset(parent,0,sizeof(parent));
    next[1][1][0]=0;next[1][1][1]=1;
    next[1][2][0]=-1;next[1][2][1]=0;
    next[1][3][0]=1;next[1][3][1]=0;
    next[2][1][0]=1;next[2][1][1]=0;
    next[2][2][0]=0;next[2][2][0]=-1;
    next[2][3][0]=0;next[2][3][1]=1;
    next[3][1][0]=0;next[3][1][1]=-1;
    next[3][2][0]=1;next[3][2][1]=0;
    next[3][3][0]=-1;next[3][3][1]=0;
    next[4][1][0]=-1;next[4][1][1]=0;
    next[4][2][0]=0;next[4][2][1]=-1;
    next[4][3][0]=0;next[4][3][1]=1;
}
void translation(){
    int i=0,j=0;
    while(s[i]!='*'){
        if(s[i]=='E'){
            i++;
            while(s[i]!=' '&&s[i]!='*'){
                if(s[i]=='F'){
                    instr[x][y][1][1]=true;
                    i++;
                }
                else if(s[i]=='L'){
                    instr[x][y][1][2]=true;
                    i++;
                }
                else if(s[i]=='R'){
                    instr[x][y][1][3]=true;
                    i++;
                }
            }
        }
        else if(s[i]=='S'){
                i++;
            while(s[i]!=' '&&s[i]!='*'){
                if(s[i]=='F'){
                    instr[x][y][2][1]=true;
                    i++;
                }
                else if(s[i]=='L'){
                    instr[x][y][2][2]=true;
                    i++;
                }
                else if(s[i]=='R'){
                    instr[x][y][2][3]=true;
                    i++;
                }
            }
        }
        else if(s[i]=='W'){
            i++;
            while(s[i]!=' '&&s[i]!='*'){
                if(s[i]=='F'){
                    instr[x][y][3][1]=true;
                    i++;
                }
                else if(s[i]=='L'){
                    instr[x][y][3][2]=true;
                    i++;
                }
                else if(s[i]=='R'){
                    instr[x][y][3][3]=true;
                    i++;
                }
         char s[25];   }
        }
        else if(s[i]=='N'){
            i++;
            while(s[i]!=' '&&s[i]!='*'){
                if(s[i]=='F'){
                    instr[x][y][4][1]=true;
                    i++;
                }
                else if(s[i]=='L'){
                    instr[x][y][4][2]=true;
                    i++;
                }
                else if(s[i]=='R'){
                    instr[x][y][4][3]=true;
                    i++;
                }
            }
        }
        else
            i++;
    }
}
int main(){
    char dir;
    init();
    char c;
    int i,j,k;
    while(~scanf("%d %d %c %d %d",&startx,&starty,&c,&endx,&endy)){
        queue<struct stu>que;
        node.a=startx;
        node.b=starty;
        que.push(node);
        while(~scanf("%d",&x)&&x!=0){
            scanf("%d",&y);
            getchar();
            gets(s);
            translation();
            /*for(i=1;i<=4;i++){
                for(j=1;j<=3;j++){
                    printf("%d %d %d %d %d\n",x,y,i,j,instr[x][y][i][j]);
                    //Sleep(500);
                }
            }*/
        }
    }
    return 0;
}
