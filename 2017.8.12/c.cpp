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
  
ll gcd(ll x,ll y){  
    if(y==0) return x;  
    else return(gcd(y,x%y));  
}
ll ans;
void dfs(ll m,ll n){
	if(m<=0||n<=0)
		return;
	if(m==n)
		return;
	if(m<n)
		swap(m,n);
	ll y=n;
	//int i=1;
	ll lcm=y;
	//m-=y;
	//printf("%lld %lld\n",m,n);
	while(lcm<m){
		ll x=m-lcm;
		//printf("		%lld %lld\n",x,y);
		if((x*y/gcd(x,y))==lcm){
			//printf("%lld %lld\n",x,y);
			ans++;
			dfs(x,y);
		}
		lcm+=y;
		//m-=y;
	}
	return;
}
int main(){
	freopen("test.txt","r",stdin);
	ll m,n;
	ll x,y;
	ll lcm;
	int t;
	scanf("%d",&t);
	int ca=1;
	while(t--){
		scanf("%lld %lld",&m,&n);
		if(m<n)
			swap(m,n);
		int N=m/n;
		int b=m%n;
		for(i)
	}
	return 0;
}