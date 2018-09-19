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
int main(){
	freopen("test.txt","r",stdin);
	ll n,k;
	while(~scanf("%lld %lld",&n,&k)){
		ll N=n/2;
		ll a=N/(k+1);
		ll b=a*k;
		printf("%lld %lld %lld\n",a,b,n-a-b);
	}
	return 0;
}