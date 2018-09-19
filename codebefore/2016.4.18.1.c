#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int n,m;
char s[101][101];
int next[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int dfs(int i,int j){
    int k;
    int tx,ty;
    s[i][j]='$';
    for(k=0;k<8;k++){
        tx=i+next[k][0];
        ty=j+next[k][1];
        if(tx<0||tx>=n||ty<0||ty>=m)
            continue;
        if(s[tx][ty]=='@'){
            dfs(tx,ty);
        }
    }
    return;
}
int main(){
    int i,j;
    int color;
    int k;
    while(~scanf("%d %d",&n,&m)&&m){
            color=0;
            getchar();
        for(i=0;i<n;i++)
            gets(s[i]);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(s[i][j]=='@'){
                    dfs(i,j);
                    color++;
                }
            }
        }
        /*for(i=0;i<n;i++)
            puts(s[i]);*/
        printf("%d\n",color);
    }
    return 0;
}
