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
int dp[1005];
int sum[1005];
struct stu{
    int v,k,c,l;
}bulb[1005];
bool cmp(struct stu a,struct stu b){
    return a.v<b.v;
}
int main(){
    int n;
    int i,j,k;
    while(~scanf("%d",&n)&&n){
        for(i=1;i<=n;i++){
            scanf("%d %d %d %d",&bulb[i].v,&bulb[i].k,&bulb[i].c,&bulb[i].l);
        }
        sort(bulb+1,bulb+n+1,cmp);
        sum[1]=bulb[1].l;
        dp[0]=0;
        dp[1]=99999999;
        for(i=2;i<=n;i++){
            sum[i]=bulb[i].l;
            sum[i]+=sum[i-1];
            dp[i]=99999999;
        }
        for(i=1;i<=n;i++){
            for(j=0;j<i;j++){
                dp[i]=min(dp[i],dp[j]+(sum[i]-sum[j])*bulb[i].c+bulb[i].k);
            }
        }
        printf("%d\n",dp[n]);
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
    }
    return 0;
}
