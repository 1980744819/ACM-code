#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int w[1005],a[1005],b[1005];
int dp[2005];
int main(){
    int t;
    scanf("%d",&t);
    int m,n;
    int i,j,k;
    while(t--){
        scanf("%d %d",&m,&n);
        for(i=1;i<=n;i++){
            scanf("%d %d %d",&w[i],&a[i],&b[i]);
        }
        for(i=1;i<=n;i++){
            for(int v=m;v>=w[i];v--){
                dp[v]=max(dp[v-w[i]]+a[i]+b[i],dp[v]);
            }
            for(int v=w[i];v<=m;v++){
                dp[v]=max(dp[v-w[i]]+a[i],dp[v]);
            }
        }
        printf("%d\n",dp[m]);
        memset(dp,0,sizeof(dp));
    }
    return 0;
}

