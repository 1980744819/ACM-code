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
long long cal(long long x){
	long long num=0;
	for (long long i = 2; i*i*i<=x; ++i)
	{
		/* code */
		num+=x/(i*i*i);
	}
	return num;
} 
int main(){
	long long  l,r;
	long long ans,mid,p;
	l=1;
	r=1e18;
	ans=-1;
	long long n;
	scanf("%lld",&n);
	while(l<=r){
		mid=(l+r)>>1;
		p=cal(mid);
		if(p==n){
			ans=mid;
		}
		if(p>=n){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	printf("%lld\n",ans);
    return 0;
}
