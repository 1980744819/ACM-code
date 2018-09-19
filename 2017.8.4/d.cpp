#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define ll long long
#define read(a) scanf("%d",&a);
using namespace std;
const int maxn=2005;
const ll mod=998244353;
int a[maxn],b[maxn];
ll dp[maxn][2],sum[maxn][2];
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int n,m;
	int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=m;i++)
			scanf("%d",&b[i]);
		ll ans=0;
		for(i=1;i<=n;i++){
			ll cnt1=1,cnt0=0;
			for(j=1;j<=m;j++){
				dp[j][1]=dp[j][0]=0;
				if(a[i]==b[j]){
					dp[j][0]=cnt1;
					dp[j][1]=cnt0;
					ans=(ans+cnt0+cnt1)%mod;
				}
				else if(b[j]<a[i]){
					cnt0=(cnt0+sum[j][0])%mod;
				}
				else{
					cnt1=(cnt1+sum[j][1])%mod;
				}
			}
			for(j=1;j<=m;j++){
				if(a[i]==b[j]){
					sum[j][0]+=dp[j][0];
					sum[j][0]%=mod;
					sum[j][1]+=dp[j][1];
					sum[j][1]%=mod;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}