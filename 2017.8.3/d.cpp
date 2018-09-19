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
using namespace std;
const int maxn=1e6+5;
const long long mod=998244353;
ll prim[maxn];
ll p[maxn];
ll num[maxn];
ll ans[maxn];
int sz;
void init() {
    for(int i = 2; i <maxn; ++i) {
        if(!p[i])  prim[sz++] = i;
        for(int j = 0; j < sz; ++j) {
            int t = i * prim[j];
            if(t >= maxn) break;
            p[t] = true;
            if(i%prim[j] == 0) break;
        }
    }
    // for(int i=0;i<sz;i++)
    // 	printf("%d ",prim[i]);
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int i,j;
	ll l,r,k,cnt;
	init();
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld %lld",&l,&r,&k);
		for(i=0;i<=r-l;i++){
			num[i]=i+l;
			ans[i]=1;
		}
		// for(j=0;j<=r-l;j++)
		// 	printf("%lld ",num[j]);
		// printf("\n");
		// for(j=0;j<=r-l;j++)
		// 	printf("%lld ",ans[j]);
		// printf("\n");
		for(i=0;prim[i]*prim[i]<=r;i++){
			//printf("     %d\n",prim[i]);
			// for(j=0;j<=r-l;j++){
			// 	if(num[j]%prim[i]==0){
			// 		//printf("%lld %d\n",num[j],prim[i]);
			// 		break;
			// 	}
			// }
			j=0;
			ll left=l%prim[i];
			if(left!=0)
				j=prim[i]-left;
			else
				j=0;
			while(j<=r-l){
				cnt=0;
				while(num[j]%prim[i]==0){
					cnt++;
					num[j]/=prim[i];
				}
				//cnt++;
				cnt%=mod;
				ans[j]=(ans[j]*(cnt*k+1))%mod;
				//ans[j]%=mod;
				j+=prim[i];
			}
			// for(j=0;j<=r-l;j++)
			// 	printf("%lld ",num[j]);
			// printf("\n");
			// for(j=0;j<=r-l;j++)
			// 	printf("%lld ",ans[j]);
			// printf("\n");
		}
		for(i=0;i<=r-l;i++){
			if(num[i]!=1){
				ans[i]*=(k+1);
				ans[i]%=mod;
				num[i]=1;
			}
		}
		cnt=0;
		for(i=0;i<=r-l;i++){
			cnt+=ans[i];
			cnt%=mod;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}