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
int dp[55][55];
int c[55];
int main(){
    int i,j,k;
    int n;
    int len;
    int l;
    while(~scanf("%d",&l)&&l){
        scanf("%d",&n);
        c[n+1]=l;
        c[0]=0;
        dp[0][0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&c[i]);
        }
        for(len=2;len<=n+1;len++){
            for(i=0;i+len<=n+1;i++){
                j=i+len;
                dp[i][j]=99999999;
                for(k=i+1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+c[j]-c[i]);
                }
            }
        }
        printf("The minimum cutting is %d.\n",dp[0][n+1]);
        memset(dp,0,sizeof(dp));
    }
    return 0;
}

