#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
#define lson l,(l+r)/2,rt<<1
#define rson (l+r)/2+1,r,rt<<1|1
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define pb push_back
#define fi first
#define se second
#define ll long long
#define sz(x) (int)(x).size()
#define pll pair<long long,long long>
#define pii pair<int,int>
int a[1000];
void solve(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	stack<int> s,res;
	for(int i=n;i>=1;i--){
		res.push(a[i]);
	}
	for(int i=1;i<=n;i++){
		s.push(i);
		while(s.size() && res.size() && s.top()==res.top()){
			s.pop();
			res.pop();
		}
	}
	if(s.size()==0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}