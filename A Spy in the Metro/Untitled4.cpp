#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int INF=0x3f3f3f3f;
int kase=0;

int main()
{
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        int T,M1,M2,time[n+1];
        scanf("%d",&T);
        int dp[T+1][n+1];

        int has_train[T+100][n+1][2];

        memset(has_train,0,sizeof(has_train));
        memset(time,0,sizeof(time));
        memset(dp,0,sizeof(dp));

        for(int i=1; i<n; i++)
            scanf("%d",&time[i]);

        scanf("%d",&M1);
        for(int i=0; i<M1; i++)
        {
            int a;
            scanf("%d",&a);
            int k=a;
            for(int j=1; j<=n; j++)
            {
                has_train[k][j][0]=1;
                k+=time[j];
            }

        }

        scanf("%d",&M2);
        for(int i=0; i<M2; i++)
        {
            int a;
            scanf("%d",&a);
            int k=a;
            for(int j=n; j>=1; j--)
            {
                has_train[k][j][1]=1;
                k+=time[j-1];
            }

        }

        for(int i=1; i<=n-1; i++) dp[T][i]=INF;
        dp[T][n]=0;

        for(int i=T-1; i>=0; i--)
            for(int j=1; j<=n; j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                if(j<n&&has_train[i][j][0]&&i+time[j]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+time[j]][j+1]);
                if(j>1&&has_train[i][j][1]&&i+time[j-1]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+time[j-1]][j-1]);

            }

        cout<<"Case Number "<<++kase<<": ";
        if(dp[0][1]>=INF) cout<<"impossible\n";
        else cout<<dp[0][1]<<"\n";
    }
    return 0;
}
