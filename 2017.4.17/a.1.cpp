#include <bits/stdc++.h>
#include <cstring>
using namespace std;
typedef long long ll;
int a[200];

ll dp[110][110][110];
ll p[200][200];
const ll INF=0x3f3f3f3f3f3f3f3f;
int main()
{
    memset(dp,0x3f3f3f3f,sizeof(dp));
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1 ; i<=n ; ++i)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=1 ; j<=m ; ++j)
        {
            scanf("%I64d",&p[i][j]);
        }
    }
    if(a[1])dp[1][1][a[1]]=0;
    else
    {
        for(int c=1 ; c<=m ; ++c)
        {
            dp[1][1][c]=p[1][c];
        }
    }
    for(int i=2 ; i<=n ; ++i)if(a[i]==0)
    {
        for(int x=1 ; x<i ; ++x)
        {
            for(int c=1 ; c<=m ; ++c)
            {
                for(int l=1 ; l<=m ; ++l)
                {
                    if(l!=c)dp[i][x+1][c]=min(dp[i][x+1][c],dp[i-1][x][l]+p[i][c]);
                    else dp[i][x][c]=min(dp[i][x][c],dp[i-1][x][l]+p[i][c]);
                }
            }
        }
    }
    else
    {
        for(int x=1 ; x<i ; ++x)
        {
            for(int l=1 ; l<=m ; ++l)
            {
                if(l!=a[i])dp[i][x+1][a[i]]=min(dp[i][x+1][a[i]],dp[i-1][x][l]);
                else dp[i][x][a[i]]=min(dp[i][x][a[i]],dp[i-1][x][l]);
            }
        }
    }
    ll ans=INF;
    for(int c=1 ; c<=m ; ++c)
    {
        ans=min(ans,dp[n][k][c]);
    }
    if(ans==INF)printf("-1\n");
    else printf("%I64d\n",ans);
    return 0;
}