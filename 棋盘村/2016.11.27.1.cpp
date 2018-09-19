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
long long dp[100][100];
bool Map[100][100];
int main(){
    int kase;
    scanf("%d",&kase);
    int m,n;
    int x,y;
    int i,j,k;
    while(kase--){
        memset(Map,false,sizeof(Map));
        memset(dp,0,sizeof(dp));
        scanf("%d %d %d %d",&n,&m,&x,&y);
        Map[x][y]=1;Map[x-2][y-1]=Map[x-2][y+1]=1;
        Map[x+2][y-1]=Map[x+2][y+1]=1;
        Map[x-1][y+2]=Map[x-1][y-2]=1;
        Map[x+1][y+2]=Map[x+1][y-2]=1;
        for(i=0;i<=n;i++)
            if(Map[i][0]!=1)
                dp[i][0]=1;
            else
                break;
        for(i=0;i<=m;i++)
            if(Map[0][i]!=1)
                dp[0][i]=1;
            else
                break;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(Map[i][j])
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        printf("%lld\n",dp[n][m]);
    }
    //込込込。。。
    return 0;
}
