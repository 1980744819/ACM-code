#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
using namespace std;
int dp[10005],t[10005],st[10005],sf[10005],f[10005];

int main(){
    //int t;
    int n,s;
    int i,j,k;
    scanf("%d %d",&n,&s);
    //int a,b;
    for(i=1;i<=n;i++){
        scanf("%d%d",&t[i],&f[i]);
        //st[i]=t[i]+st[i-1];
        //sf[i]=f[i]+sf[i-1];
    }
    for (i=n;i;i--)
    {
        st[i]=st[i+1]+t[i];
        sf[i]=sf[i+1]+f[i];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[n+1]=0;
    for(i=n;i;i--){
        for(j=i+1;j<=n+1;j++){
            dp[i]=min(dp[i],dp[j]+sf[i]*(st[i]-st[j]+s));
        }
    }
    printf("%d\n",dp[1]);
    return 0;
}


