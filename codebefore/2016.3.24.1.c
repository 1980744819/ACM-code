#include<stdio.h>
#include<string.h>
int e[1005][1005],book[1005],dis[1005];
int inf=999999;
int main(){
    int T,n;
    int min;
    int u,v;
    int i,j,k;
    int a,b,c;
    while(~scanf("%d%d",&T,&n)){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i==j)
                    e[i][j]==0;
                else e[i][j]=e[j][i]=inf;
                }
            }
        for(i=1;i<=T;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(e[a][b]>c)
            e[a][b]=e[b][a]=c;
            }
        for(i=1;i<=n;i++)//初始化dis数组
            dis[i]=e[1][i];
        for(i=1;i<=n;i++)
            book[i]=0;
    book[1]=1;
    for(i=1;i<=n-1;i++){//算法核心
        min=inf;
        for(j=1;j<=n;j++){
            if(book[j]==0&&dis[j]<min){
                min=dis[j];
                u=j;
                }
            }
            book[u]=1;
            for(v=1;v<=n;v++){
                if(e[u][v]<inf){
                    if(dis[v]>dis[u]+e[u][v])
                        dis[v]=dis[u]+e[u][v];
                }
            }
        }
    printf("%d\n",dis[n]);
    }
    return 0;
}
