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
const int maxn=10005;
ll a[maxn],b[maxn];
ll c[55][55];
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
	int t;
	int n,m;
	init();
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<=m;i++){
			scanf("%lld",&b[i]);
		}
		ll cnt,tmp;
		cnt=0;
		int i=1;
		while(i<=m){
			for(int j=cnt+1;j<=cnt+b[i];j++){
				a[j]=i;
			}
			tmp=b[i];
			cnt+=tmp;
			if(cnt>=n+5)
				break;
			for(int len=2;len<=tmp;len++){
				ll sum1=i*len;
				//ll sum2=i*(tmp-len);
				b[sum1]-=c[tmp][len];
				// if(sum1!=sum2)
				// 	b[sum2]-=c[tmp][len];
			}
			// ll sum=tmp*i;
			// 	b[sum]-=1;
			i++;
			//printf("%d\n",cnt);
		}
		for(i=1;i<=n;i++)
			printf("%lld ",a[i]);
		printf("\n");
	}
	return 0;
}