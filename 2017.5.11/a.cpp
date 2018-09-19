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
double d[100005];
int main(){
	int i,j;
	long long n,p;
	long long l,r;
	long long cnt;
	scanf("%lld %lld",&n,&p);
	for(i=1;i<=n;i++){
		scanf("%lld %lld",&l,&r);
		cnt=r/p-l/p;
		if(l%p==0)
			cnt++;
		d[i]=(double)cnt/(r-l+1);
	}
	d[0]=d[n];
	double ans=0.0;
	for(i=1;i<=n;i++){
		ans+=1000*(d[i]*d[i-1]+(1-d[i])*d[i-1]+d[i]*(1-d[i-1]));
	}
	printf("%.10f\n",(double)ans*2);
    return 0;
}
