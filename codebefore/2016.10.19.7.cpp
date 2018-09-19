#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<malloc.h>
#include<cstdlib>
using namespace std;
long long dp[81][1<<10][105];
int s[1<<11];
int c[1<<11];
int Count(int num){
    int p=0;
    while(num>0){
        num=num&(num-1);
        p++;
    }
    return p;
}

int main(){
    int n,m,k;
    int sum;
    while(~scanf("%d %d %d",&n,&m,&sum)){
        int i,j;
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        memset(c,0,sizeof(c));
        if(m>n)
            swap(m,n);
        int t=1<<m;
        int p;
        int num=0;
        for(i=0;i<t;i++){
            if(!(i & i<<1)){//每一行的所有排列情况
                num++;
                s[num]=i;
                c[num]=Count(i);
            }
        }
        for(j=1;j<=num;j++){
            if(k>=c[j])
                dp[1][j][c[j]]=1;
        }
        for(i=2;i<=n;i++){
            for(j=1;j<=num;j++){
                if(c[j]>sum)
                    continue;
                for(t=1;t<=num;t++){//前一行的状态
                    if((s[j]&s[t])||((s[j]>>1)&s[t])||((s[j]<<1)&s[t]))continue;
                    for(k=0;k<=sum;k++){
                        if(k>=c[j]){
                            dp[i][j][k]+=dp[i-1][t][k-c[j]];
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(j=1;j<=num;j++){
            ans+=dp[n][j][sum];
            //printf("%lld\n",dp[n][j][sum]);
        }
        ans%=200640345;
        printf("%lld\n",ans);
    }
    return 0;
}
