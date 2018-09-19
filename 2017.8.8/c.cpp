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
const long long maxn=10007;
long long b[maxn];
long long a[maxn];
long long  c[55][55];
void init(){
	for(long long i=0;i<55;i++){
		for(long long j=0;j<=i;j++){
			if(j==i||j==0){
				c[i][j]=1;
			}
			else{
				c[i][j]=c[i-1][j]+c[i-1][j-1];
			}
			//printf("%lld ",c[i][j]);
		}
		//printf("\n");
	}
}

int main(){
	freopen("test.txt","r",stdin);
	long long n,m;
	long long t;
	init();
	scanf("%lld",&t);
	while(t--)
	{
		// memset(a,0,sizeof(a));
		// memset(b,0,sizeof(b));
		scanf("%lld %lld",&n,&m);
		for(long long i=0;i<=m;i++)
		{
			scanf("%lld",&b[i]);
		}	
		long long cnt=0;
		long long i=1;
		while(i<=m)
		{
			if(b[i]<=0)
			{
				i++;
				continue;
			}
			for(long long j=cnt;j<cnt+b[i];j++)
			{
				a[j]=i;
			}
			cnt+=b[i];
			long long tmp=b[i];
			for(long long lenth=1;lenth<=(tmp+1)/2;lenth++)
			{
				long long sum=i*lenth;
				long long sum2=i*(tmp-lenth);
				if(sum<=m)
					b[sum]-=c[tmp][lenth];
				if(sum2!=sum&&sum2<=m)
					b[sum2]-=c[tmp][lenth];
			}
			long long sum=i*tmp;
			if(sum<=m)
				b[sum]-=1;
			i++;
		}
		for(i=0;i<n;i++)
			printf("%lld ",a[i]);
		printf("\n");
	}
	return 0;
}