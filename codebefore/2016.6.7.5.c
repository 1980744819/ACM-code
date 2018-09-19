#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int main(){
    int n,m;
    int a,b,d,p;
    int s,t;
    int i,j,k;
    int map[51][51];
    int cost[51][51];
    while(~scanf("%d %d",&n,&m)){
        if(n==0&&m==0)
            break;
        for(i=1;i<=n;i++){
            for(j=0;j<=1;j++){
                if(i==j) map[i][j]=0;
                else map[i][j]=9999999;
            }
        }
        for(i=1;i<=m;i++){
            scanf("%d%d%d%d",&a,&b,&d,&p);
            map[a][b]=d;
            map[b][a]=d;
            cost[a][b]=p;
            cost[b][a]=p;
        }
        for(k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(map[i][j]>map[i][k]+map[k[j]){
                        map[i][j]=map[i][k]+map[k][j];
                        cost[]
                    }
                }
            }
        }
    }
    return 0;
}

