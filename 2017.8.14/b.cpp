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
ll a[maxn],l[maxn],r[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)&&n){
		//int l=0,r=0;
		//int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			//printf("%d ",a[i]);
		}
		//printf("\n");
		stack< ll >st;
		while(!st.empty())
			st.pop();
		for(int i=1;i<=n;i++){
			while(!st.empty()&&a[st.top()]>=a[i])st.pop();
			if(st.empty())
				l[i]=1;
			else
				l[i]=st.top()+1;
			st.push(i);
			//printf("%d ",l[i]);
		}
		//printf("\n");
		while(!st.empty())
			st.pop();
		for(int i=n;i>=1;i--){
			while(!st.empty()&&a[st.top()]>=a[i])st.pop();
			if(st.empty())
				r[i]=n;
			else
				r[i]=st.top()-1;
			st.push(i);
			//printf("%d ",r[i]);
		}
		//printf("\n");
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans=max((r[i]-l[i]+1)*a[i],ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}