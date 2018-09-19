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
int main(){
	int t;
	int i,j;
	int dp[1005],sum[1005],a[1005],p[1005];
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sum[0]=0;
		for(i=1;i<=n;i++){
			scanf("%d %d",&a[i],&p[i]);
			sum[i]=sum[i-1]+a[i];
		}
		dp[0]=0;
		for(i=1;i<=n;i++){
			dp[i]=(a[i]+10)*p[i]+dp[i-1];
			for(j=0;j<i;j++){
				dp[i]=min(dp[i],(sum[i]-sum[j]+10)*p[i]+dp[j]);
			}
		}
		printf("%d\n",dp[n]);
	}
    return 0;
}
