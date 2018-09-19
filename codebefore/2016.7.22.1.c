#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<malloc.h>
#include<math.h>
int dis[505];
int n,m,W;
int u[6005],v[6005],w[6005];
void init(){
    int i;
    dis[1]=0;
    for(i=2;i<=n;i++){
        dis[i]=99999;
    }
}
int main(){
    int kase;
    scanf("%d",&kase);
    int i,j;
    int flag;
    while(kase--){
        flag=0;
        scanf("%d%d%d",&n,&m,&W);
        init();
        int e=1;
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&u[e],&v[e],&w[e]);
            e++;
            u[e]=v[e-1];
            v[e]=u[e-1];
            w[e]=w[e-1];
            e++;
        }
        for(;i<=m+W;i++){
            scanf("%d %d %d",&u[e],&v[e],&w[e]);
            w[e]=0-w[e];
            e++;
        }
        for(i=1;i<=n-1;i++){
            for(j=1;j<e;j++){
                if(dis[v[j]]>dis[u[j]]+w[j])
                    dis[v[j]]=dis[u[j]]+w[j];
            }
        }
        for(j=1;j<e;j++){
            if(dis[v[j]]>dis[u[j]]+w[j]){
                dis[v[j]]=dis[u[j]]+w[j];
                flag=1;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

