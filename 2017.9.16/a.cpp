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
#define ll long long
using namespace std;
const int maxn=10000;
const ll mod=1e9+7;
ll fun(ll x,ll n){  
    ll res=1;  
    while(n>0){  
        if(n & 1)  
            res=(res*x)%mod;  
        x=(x*x)%mod;  
        n >>= 1;  
    }  
    return res;  
} 
ll ver(ll a,ll n){
	if(a==1)return 1;
	return ver(n%a,n)*(n-n/a)%n;
} 
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		ll p,q,k;
		scanf("%lld %lld %lld",&p,&q,&k);
		ll a=(fun(p-2*q,k)+fun(p,k))%mod;
		ll b=(2*fun(p,k))%mod;
		ll ans=(a%mod)*ver(2*fun(p,k)%mod,mod)%mod;
		// 
		printf("%lld\n",ans%mod);
		// 	ans++;
	}
    return 0;
}
