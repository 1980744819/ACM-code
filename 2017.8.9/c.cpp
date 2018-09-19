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
	const int maxn=1e6+5;
	ll num[maxn];
	void init(){
		for(ll i=1;i<=maxn;i++){
			num[i]=i*i*i;
		}
	}
	int main(){
		freopen("test.txt","r",stdin);
		int t;
		init();
		scanf("%d",&t);
		ll a,b,c;
		while(t--){
			scanf("%lld %lld",&a,&b);
			c=a*b;
			ll pos=lower_bound(num,num+maxn,c)-num;
			if(num[pos]!=c){
				printf("No\n");
			}
			else{
				if(a<pos||b<pos){
					printf("No\n");
				}
				else{
					int n1=a/pos;
					int n2=b/pos;
					if(n1*n2!=pos)
						printf("No\n");
					else
						printf("Yes\n");
				}
			}
		}
		return 0;
	}