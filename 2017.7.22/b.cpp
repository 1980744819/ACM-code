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
using namespace std;
const int maxn=16;
const int prime[maxn]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
long long ans,res;
long long n;
void dfs(long long cur,long long num,long long key,long long pre){
	if(key>=maxn)
		return;
	else{
		if(num>ans){
			res=cur;
			ans=num;
		}
		else if(num==ans){
			res=min(cur,res);
		}
		long long i;
		for(i=1;i<=pre;i++){
			if(cur<=n/prime[key]){
				cur*=prime[key]; 
				dfs(cur,num*(i+1),key+1,i);
			}
			else
				break;
		}
	}
}
void solve(){
	res=1;
	ans=1;
	dfs(1,1,0,15);
	printf("%lld %lld\n",res,ans);
}
int main(){
	//freopen("test.txt","r",stdin);
	int t;
	scanf("%d ",&t);
	while(t--){
		scanf("%lld",&n);
		solve();
	}
	return 0;
}