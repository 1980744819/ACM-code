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
ll a[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)&&n){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		a[n+1]=-1;
		int pos=1;
		stack<ll>st;
		ll ans=0;
		while(pos<=n+1){
			if(st.empty()||a[st.top()]<=a[pos]){
				st.push(pos);
				pos++;
			}
			else{
				ll num=0;
				ll tmp=st.top();
				st.pop();
				if(st.empty()){
					num=(pos-1)*a[tmp];//the last one left in the stack must be zhe min number in the array 
				}
				else{
					num=(pos-st.top()-1)*a[tmp];
				}
				if(ans<num)
					ans=num;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}