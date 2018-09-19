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
ll ans;
ll gcd(ll x,ll y){
    if(y==0) return x;  
    else return(gcd(y,x%y));  
}
void dfs(int m,int n){
	if(m<=0||n<=0)
		return;
	if(m==n)
		return;
	ll lcm;
	if(m>n){
		lcm=n;
		ll y=n;
		while(lcm<m){
			ll x=m-lcm;
			if(lcm>=x){
				ll gc=gcd(x,y);
				if(x*y/gc==lcm&&x*y%gc==0){
					ans++;
					dfs(x,y);
					break;
				}
			}
			lcm+=n;
		}
	}
	else{
		lcm=m;
		ll x=m;
		while(lcm<=n){
			ll y=n-lcm;
			if(lcm>=y){
				ll gc=gcd(x,y);
				if(x*y/gc==lcm&&x*y%gc==0){
					ans++;
					dfs(x,y);
					break;
				}

			}
			lcm+=m;
		}
	}
	return;
}
int main(){
	//freopen("test.txt","r",stdin);
	int t;
	ll m,n;
	ll x,y;
	ll lcm;
	scanf("%d",&t);
	int ca=1;
	while(t--){
		scanf("%lld %lld",&m,&n);
		ans=0;
		dfs(m,n);
		printf("Case #%d: ",ca++);
		printf("%lld\n",ans+1);
	}
	return 0;
}