#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<malloc.h>
#include<cmath>
using namespace std;
char Map[10][10];
int startx,starty,endx,endy;
int nextx[4]={0,-1,0,1};
int nexty[4]={1,0,-1,0};
void dfs(int i,int j,int dir){
    if(i==endx&&j==endy)
        exit(0);
        //return;
    int x,y;
    x=i+nextx[dir];
    y=j+nexty[dir];
    int k;
    if(Map[x][y]==' '&&x<=0&&x<=9&&y>=0&&y<=9){
        Map[x][y]='*';
        dfs(x,y,dir);
    }
    else{
        if(Map[i][j+1]==' '&&j<=8){
            Map[i][j+1]='*';
            dfs(i,j+1,0);
        }
        else if(Map[i-1][j]==' '&&i>=1){
            Map[i-1][j]='*';
            dfs(i-1,j,1);
        }
        else if(Map[i][j-1]==' '&&j>=1){
            Map[i][j-1]='*';
            dfs(i,j-1,2);
        }
        else if(Map[i+1][j]==' '&&i<=8){
            Map[i+1][j]='*';
            dfs(i+1,j,3);
        }
        else{
            Map[i][j]='!';
            return;
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
    dfs(startx,starty,0);
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%c",Map[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
