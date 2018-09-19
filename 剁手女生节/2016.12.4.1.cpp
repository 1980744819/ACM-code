#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
long long dp[20];
int main(){
    int t;
    int i,j,k;
    long long n,a,b,c;
    long long Min,Max;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
        dp[0]=0;
        dp[1]=a;
        for(i=2;i<=20;i++){
            dp[i]=min(dp[i-1]+a,dp[i-2]+b);
            if(i>=3)
                dp[i]=min(dp[i],dp[i-3]+c);
        }
        n=n%4;
        //printf("%lld %lld %lld %lld\n",n,a,b,c);
        //for(i=0;i<4;i++)
            //printf("%lld\n",dp[i]);
        if(n==0)
            printf("0\n");
        else{
            Min=9999999999999;
            n=4-n;
            for(i=n;i<=20;i+=4){
                if(dp[i]<Min)
                    Min=dp[i];
            }
            printf("%lld\n",Min);
        }
        memset(dp,0,sizeof(dp));
    }
    return 0;
}

