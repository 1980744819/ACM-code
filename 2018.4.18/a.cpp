#include<bits/stdc++.h>
using namespace std;
int main(){
	// freopen("test.txt","r",stdin);
	long long n;
	long long t;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		// for(long long i=1;i<=n;i++){
		long long a=1;
		long long b=2*n;
		// printf("%lld %lld\n",a,b);
		long long ans=0;
		while(a<=n*n){
			ans+=a;
			a+=2*n;
		}
		while(b<=n*n){
			ans+=b;
			b+=2*n;
		}
		printf("%lld",ans);
		if(n%2){
			for(long long i=2;i<=n;i++){
				ans++;
				printf(" %lld",ans);
			}
		}
		else{
			for(long long i=2;i<=n;i++){
				printf(" %lld",ans);
			}
		}
		printf("\n");
			// if(i!=n)
				// printf(" ");
		// }
		// printf("\n");
	}
	return 0;
}
	