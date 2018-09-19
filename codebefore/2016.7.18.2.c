#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int tol;
int D[210][2];
double C[210][2];
double dis[105];
int bellman_ford(int start,int n,double v){
    int i,j;
    for(i=1;i<=n;i++) dis[i]=0;
    dis[start]=v;
    for(i=1;i<n;i++){
        int flag=0;
        for(j=0;j<tol;j++){
            int u=D[j][0];
            int v=D[j][1];
            if(dis[v]<(dis[u]-C[j][1])*C[j][0]){
                flag=1;
                dis[v]=(dis[u]-C[j][1])*C[j][0];
            }
        }
        if(!flag)
            return 0;
    }
    for(j=0;j<tol;j++)
        if(dis[D[j][1]]<(dis[D[j][0]]-C[j][1])*C[j][0])
        return 1;
    return 0;
}
int main(){
    int n;
    int M;
    int a,b;
    double c,d,e,f;
    int s;
    double v;
    while(scanf("%d%d%d%lf",&n,&M,&s,&v)!=EOF){
        tol=0;
        while(M--){
            scanf("%d%d%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
            D[tol][0]=a;
            D[tol][1]=b;
            C[tol][0]=c;
            C[tol][1]=d;
            tol++;
            D[tol][0]=b;
            D[tol][1]=a;
            C[tol][0]=e;
            C[tol][1]=f;
            tol++;
        }
        if(bellman_ford(s,n,v))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
