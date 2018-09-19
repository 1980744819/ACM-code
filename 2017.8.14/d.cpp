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
const int maxn=1e5+10;
ll a[maxn],qmax[maxn],qmin[maxn];
ll l[maxn],r[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int n,k;
	while(~scanf("%d",&n)&&n){
		int head,tail;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		a[n+1]=-1;
		a[0]=-1;
		head=tail=0;
		for(int i=1;i<=n+1;i++){
			while(head<tail&&a[qmax[tail-1]]>a[i]){
				r[qmax[tail-1]]=i;
				tail--;
			}
			qmax[tail++]=i;
		}
		head=tail=0;
		for(int i=n;i>=0;i--){
			while(head<tail&&a[qmax[tail-1]]>a[i]){
				l[qmax[tail-1]]=i;
				tail--;
			}
			qmax[tail++]=i;
		}
		ll num=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			num=(r[i]-l[i]-1)*a[i];
			if(num>ans)
				ans=num;
		}
		printf("%lld\n",ans);
	}
	return 0;
}