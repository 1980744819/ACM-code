#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int se[210][2];
double rc[210][2];
int N,M,S;
double V;
double dis[105];
int sum;
int bellman_ford(){
    int i,j;
    for(i=1;i<=N;i++){
        dis[i]=0;
    }
    dis[S]=V;
    for(i=1;i<N;i++){
        int flag=0;
        for(j=0;j<sum;j++){
            int u=se[j][0];
            int v=se[j][1];
            if(dis[v]<(dis[u]-rc[j][1])*rc[j][0]){
                flag=1;
                dis[v]=(dis[u]-rc[j][1])*rc[j][0];
            }
        }
        if(flag==0){
            printf("000000%d\n",i );
            return 0;
        }
    }
    for(j=0;j<sum;j++){
        if(dis[se[j][1]]<(dis[se[j][0]]-rc[j][1])*rc[j][0]){
                //printf("11111");
            return 1;
        }
    }
    return 0;
}
int main(){
    int a,b;
    double Rab,Cab,Rba,Cba;
    while(~scanf("%d%d%d%lf",&N,&M,&S,&V)){
        sum=0;
        while(M--){
            scanf("%d%d%lf%lf%lf%lf",&a,&b,&Rab,&Cab,&Rba,&Cba);
            se[sum][0]=a;
            se[sum][1]=b;
            rc[sum][0]=Cab;
            rc[sum][1]=Cab;
            sum++;
            se[sum][0]=b;
            se[sum][1]=a;
            rc[sum][0]=Rba;
            rc[sum][1]=Cba;
            sum++;
        }
        if(bellman_ford()==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

