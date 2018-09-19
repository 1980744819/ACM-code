#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int a[101][101];
int book[101][101]={0};
int m,n;
int t;
int dfs(int x,int y,int step){
    int next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int k;
    int tx,ty;
    if(a[x][y]!=t){
        return;
    }
    a[x][y]=0;
    for(k=0;k<4;k++){
            tx=x+next[k][0];
            ty=y+next[k][1];
            if(tx<1||tx>n||ty<1||ty>n)
                continue;
            if(book[tx][ty]==0){
                book[tx][ty]=1;
                dfs(tx,ty,step+1);
                book[tx][ty]=0;
            }
    }
    return;
}
int main(){
    memset(a,5,sizeof(a));
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    t=a[n][m];
    dfs(n,m,0);
    for(i=n;i>0;i--){
        for(j=1;j<=n;j++){
            if(a[i][j]==0){
                int p;
                p=i;
                while(p>1){
                    p--;
                    if(a[p][j]!=0){
                        a[i][j]=a[p][j];
                        a[p][j]=0;
                        break;
                    }
                }
            }
        }
    }
     //printf("\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
