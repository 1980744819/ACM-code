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
ll qpow(ll k,ll num){
	ll ans=1;
	while(num!=0){
		if(num&1)
			ans*=k;
		k*=k;	
		num>>=1;
	}
	return ans;
}
void init(){
	ll a=1;
	ll ans=1;
	while(a<=1000000000000000000){
		a++;
		ans^=a;
		printf("%lld %lld\n",a,ans);
	}
}
ll xor_n(ll n)
{
    ll tt = n&3;
    if(tt&1) return tt/2ll^1;
    return tt/2ll^n;
}
int main(){
	//clock_t start=clock();
	freopen("test.txt","r",stdin);
	//init();
	int t;
	scanf("%d",&t);
	//printf("%d\n",t);
	//printf("%lld\n",(ll)pow(1,10));
	while(t--){
		ll n,k;
		scanf("%lld %lld",&n,&k);
		//printf("%lld %lld\n",n,k);
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
			//printf("%lld\n",xor_n(n));
			continue;
		}
		ll cnt1,cnt2,cnt3;//full ,not full ,full but in last deepth
		ll size1=0,size2=0,size3=0;
		ll cnt2_left=0;
		ll deepth=0;
		ll sum=1;
		ll ans=0;
		sz[0]=1;
		int i=0;
		ll left=0;
		ll m=n-1;
		//m=(m-1)/k;
		while(m){
			i++;
			deepth++;
			//if(qpow(k,deepth))
				sum+=qpow(k,deepth);
			// else
			// 	break;
			sz[i]=qpow(k,deepth)/(k-1);
			m=(m-1)/k;
			printf("%d %lld %lld \n",i,qpow(k,deepth),sz[i]);
		}
		printf("%lld ",deepth);
		// while(sum<n){
		// 	i++;
		// 	deepth++;
		// 	if(qpow(k,deepth)>1000000000000000000)
		// 		break;
		// 	sum+=qpow(k,deepth);
		// 	sz[i]=sum;
		// 	//printf("%d %lld %lld\n",i,qpow(k,deepth),sz[i]);
		// }
		//printf("\n");
		// if(sum==n){
		// 	cnt1=qpow(k,deepth-1);
		// 	cnt2=0;
		// 	cnt3=0;
		// 	cnt2_left=0;
		// 	if((cnt1*k)%2==0)
		// 		ans=0;
		// 	else
		// 		ans=1;
		// }
		//else{
			left=qpow(k,deepth)-(sum-n);
			cnt1=left/k;
			cnt2_left=left-cnt1*k;
			if(cnt2_left==0)
				cnt2=0;
			else
				cnt2=1;
			cnt3=(sum-n)/k;
			if(left%2==0)
				ans=0;
			else
				ans=1;
		//}
		//printf("%lld %lld %lld %lld %lld %lld\n",cnt1,cnt2,cnt3,cnt2_left,left,ans);
		//printf("%lld ",deepth);
		ll deep=deepth;
		deep--;
		while(deep>=0){
			if(cnt2_left!=0){
				size2=sz[deepth-deep-1]+cnt2_left;
				ans^=size2;				
			}
			if(cnt1!=0){
				size1=sz[deepth-deep];
				if(cnt1%2!=0)
					ans^=size1;
				ll tmp=cnt1%k;
				cnt1/=k;
				if(tmp!=0)
					cnt2_left+=tmp*qpow(k,deepth-deep);
			}
			if(cnt3!=0){
				size3=sz[deepth-deep-1];
				if(cnt3%2!=0)
					ans^=size3;
				cnt3/=k;
			}
			deep--;
			//printf("%lld ",size2);
		}
		//printf("\n");
		printf("%lld\n",ans);
	}
	//clock_t end=clock();
	//cout<< "Running time is: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	return 0;
}