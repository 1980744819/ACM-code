#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    int n;
    int T;
    int i,j,k;
    int t[55];
    int kase=0;
    int m1,m2;
    int a,b,coun;
    bool hastrain[305][55][2];
    int dp[205][55];
    while(~scanf("%d",&n)&&n!=0){
        memset(hastrain,false,sizeof(hastrain));
        memset(t,0,sizeof(t));
        memset(dp,0,sizeof(dp));
        kase++;
        scanf("%d",&T);
        for(i=1;i<n;i++)
            scanf("%d",&t[i]);
        scanf("%d",&m1);
        for(i=0;i<m1;i++){
            scanf("%d",&a);
            coun=a;
            hastrain[coun][1][0]=true;
            for(j=1;j<n;j++){
                coun+=t[j];
                hastrain[coun][j+1][0]=true;
            }
        }
        scanf("%d",&m2);
        for(i=0;i<m2;i++){
            scanf("%d",&a);
            coun=a;
            hastrain[coun][n][1]=true;
            for(j=n-1;j>=1;j--){
                coun+=t[j];
                hastrain[coun][j][1]=true;
            }
        }
        for(i=1;i<n;i++)
            dp[T][i]=0x3f3f3f3f;
        dp[T][n]=0;
        for(i=T-1;i>=0;i--){
            for(j=1;j<=n;j++){
                dp[i][j]=dp[i+1][j]+1;
                if(j<n&&hastrain[i][j][0]&&(i+t[j]<=T))
                    dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
                if(j>1&&hastrain[i][j][1]&&(i+t[j-1]<=T))
                    dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
            }
        }
        printf("Case Number %d: ",kase);
        if(dp[0][1]>=0x3f3f3f3f)
            printf("impossible\n");
        else
            printf("%d\n",dp[0][1]);
    }
    return 0;
}
