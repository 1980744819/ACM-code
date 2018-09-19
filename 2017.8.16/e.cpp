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
ll sz[110];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
void table(ll k,ll deepth){
	ll sum=1;
	for(ll i=1;i<deepth;i++){
		sum+=qpow(k,i);
		sz[i]=sum;
		//printf("%lld %lld\n",i,sz[i]);
	}
}

int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,k;
		scanf("%lld %lld",&n,&k);
		if(k==1){
			ll num=n%4;
			ll ans=0;
			if(num==0){
				ans=n;
			}
			else if(num==1){
				ans=1;
			}
			else if(num==2){
				ans=n+1;
			}
			else if(num==3){
				ans=0;
			}
			printf("%lld\n",ans);
			continue;
		}
		ll cnt1,cnt2,cnt3;
		ll cnt2_left;
		ll deepth;
		ll m=n-1;
		ll ans=0;
		ll size1,size2,size3;
		sz[0]=1;
		deepth=0;
		while(m){
			deepth++;
			m=(m-1)/k;
		}
		//printf("%lld\n",deepth);
		table(k,deepth);
		ll left=n-sz[deepth-1];
		cnt1=left/k;
		if(left%k){
			cnt2=1;
			cnt2_left=left%k;
		}
		else{
			cnt2=0;
			cnt2_left=0;
		}
		cnt3=sz[deepth-1]-sz[deepth-2]-cnt1-cnt2;
		if(left%2)
			ans^=1;
		//printf("%lld %lld %lld %lld %lld %lld\n",cnt1,cnt2,cnt3,cnt2_left,left,ans);
		ll deep=deepth-1;
		while(deep>=0){
			if(cnt2_left>0){
				size2=sz[deepth-deep-1]+cnt2_left;
				ans^=size2;
			}
			if(cnt1>0){
				size1=sz[deepth-deep];
				if(cnt1%2)
					ans^=size1;
				ll num=cnt1%k;
				cnt2_left+=num*(size1-sz[deepth-deep-1]);
				cnt1/=k;
			}
			if(cnt3>0){
				size3=sz[deepth-deep-1];
				if(cnt3%2)
					ans^=size3;
				cnt3/=k;
			}
			deep--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}