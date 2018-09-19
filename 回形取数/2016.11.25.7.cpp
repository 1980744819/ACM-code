#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int Map[205][205];
int Next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool book[205][205];
int main(){
    int m,n;
    int i,j;
    int num;
    int coun;
    int x,y;
    int dir;
    int a,b;
    while(~scanf("%d %d",&m,&n)){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%d",&Map[i][j]);
            }
        }
        printf("%d",Map[0][0]);
        memset(book,false,sizeof(book));
        book[0][0]=true;
        num=m*n;
        coun=1;
        x=0;
        y=0;
        dir=0;
        while(coun<num){
            dir%=4;
            a=x+Next[dir][0];
            b=y+Next[dir][1];
            if(a>=m||b>=n||a<0||b<0||book[a][b]==true)
                dir++;
            else{
                x+=Next[dir][0];
                y+=Next[dir][1];
                book[x][y]=true;
                coun++;
                printf(" %d",Map[x][y]);
            }
        }
        printf("\n");
    }
    return 0;
}

