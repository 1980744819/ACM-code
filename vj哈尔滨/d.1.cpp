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
int dp[505][505];
int cost[105],val[105];
int book[15];
int main(){
    int t;
    int i,j,k;
    int l,n,m;
    int temp;
    scanf("%d",&t);
    int last;
    int ans;
    while(t--){
        memset(book,0,sizeof(book));
        memset(dp,0,sizeof(dp));
        scanf("%d %d %d",&l,&n,&m);
        last=0;
        temp=0;
        for(i=1;i<=n;i++){
            scanf("%d",&temp);
            book[i]=temp-last;
            last=temp;
        }
        book[n+1]=l-temp;
        for(i=1;i<=m;i++){
            scanf("%d %d",&cost[i],&val[i]);
        }
        ans=0;
        for(k=1;k<=n+1;k++){
            for(i=1;i<=book[k];i++){
                for(j=1;j<=m;j++){
                    if(i<cost[j])
                        continue;
                    else
                        dp[k][i]=max(dp[k][i],dp[k][i-cost[j]]+val[j]);
                }
            }
        }
        for(k=1;k<=n+1;k++)
            ans+=dp[k][book[k]];
        printf("%d\n",ans);
    }
    return 0;
}

