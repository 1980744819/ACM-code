#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int n;
long long w[50];
long long f[50][50];
int g[50][50];
int time;
void print(int l,int r){
    if(l>r)
        return;
    int k=g[l][r];
    printf("%d",k);
    time++;
    if(time<n)
        printf(" ");
    print(l,k-1);
    print(k+1,r);
}
int main(){
    scanf("%d",&n);
    int i,j,k;
    time=0;
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
        f[i][i]=w[i];
        g[i][i]=i;
    }
    for(i=n;i>0;i--){
        for(j=i+1;j<=n;j++){
            for(k=i;k<=j;k++){
                int x=f[i][k-1],y=f[k+1][j];
                if(x==0)x=1;
                if(y==0)y=1;
                if(f[i][j]<(x*y+w[k])){
                    f[i][j]=x*y+w[k];
                    g[i][j]=k;
                }
            }
        }
    }
    printf("%d\n",f[1][n]);
    print(1,n);
    printf("\n");
    return 0;
}
