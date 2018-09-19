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
const int maxn=100005;
struct node{
	ll n;
	ll total;
}pi[maxn];
ll v[maxn],t[maxn];
ll num[maxn];
void init(){
	for(int i=0;i<maxn;i++){
		pi[i].n=0;
		pi[i].total=0;
		v[i]=0;
		t[i]=0;
		num[i]=0;
	}
}

int main(){
	// freopen("test.txt","r",stdin);
	// freopen("test.out","w",stdout);
	int n;
	while(~scanf("%d",&n)){
		// printf("%d\n",n);
		init();
		// printf("%lld\n",num[0]);
		for(int i=1;i<=n;i++){
			scanf("%lld",&v[i]);
			// printf("%d %lld %lld %lld\n",i,v[i],t[i],num[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&t[i]);
			v[i]+=num[i-1];
			num[i]=num[i-1]+t[i];
		}
		// printf("v[i]:");
		// for(int i=1;i<=n;i++){
		// 	printf("%lld ",v[i]);
		// }
		// printf("\n");
		// printf("num[i]:");
		// for(int i=1;i<=n;i++){
		// 	printf("%lld ",num[i]);
		// }
		// printf("\n");
		for(int i=1;i<=n;i++){
			if(v[i]>0){
				int a=lower_bound(num,num+n+1,v[i])-num;
				// printf("%d %d\n",i,a);
				if(num[a]>=v[i]){
					if(pi[a].n>0){
						pi[a].n++;
						pi[a].total+=num[a]-v[i];
					}
					else{
						pi[a].n=1;
						pi[a].total=num[a]-v[i];
					}
				}
			}
			else{
				pi[i].n++;
				pi[i].total+=t[i];
			}
		}
		// for(int i=1;i<=n;i++){
		// 	printf("%lld %lld\n",pi[i].n,pi[i].total);
		// }
		int cou=0;
		for(int i=1;i<=n;i++){
			printf("%lld ",t[i]*(i-cou)-pi[i].total);
			cou+=pi[i].n;
		}
		printf("\n");
	}
    return 0;
}
