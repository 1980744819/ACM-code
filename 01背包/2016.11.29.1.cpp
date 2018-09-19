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
int a[105],w[105],dp[105][200];
int main(){
    int i,j,k;
    int n,v;
    while(scanf("%d",&v)&&v){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d %d",&a[i],&w[i]);
        for(i=0;i<=v;i++)
            dp[0][v]=0;
        for(i=1;i<=n;i++){
            for(j=a[i];j<=v;j++){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+w[i]);
            }
        }
        printf("%d\n",dp[n][v]);
    }
    return 0;
}

