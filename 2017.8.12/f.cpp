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
int ans;
void dfs(int a,int b){
	ans++;
	if(a<b)
		swap(a,b);
	if(a%(1+b)==0)
		dfs(a/(1+b),b);
}
ll gcd(ll a,ll b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	ll x,y;
	scanf("%d",&t);
	int ca=1;
	while(t--){
		ans=0;
		scanf("%lld %lld",&x,&y);
		ll gc=gcd(x,y);
		x/=gc;
		y/=gc;
		dfs(x,y);
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}