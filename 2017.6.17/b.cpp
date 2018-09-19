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
using namespace std;
//int l[2000005],r[2000005];
int de[200005];
int dp[200005];
int main(){
	int n,k,q;
	int l,r;
	int i,j;
	int a,b;
	int ans;
	while(~scanf("%d %d %d",&n,&k,&q)){
		for(i=0;i<n;i++){
			scanf("%d %d",&l,&r);
			de[l]++;
			de[r+1]--;
		}
		for(i=1;i<=200000;i++){
			de[i]=de[i-1]+de[i];
			if(de[i]>=k){
				dp[i]=dp[i-1]+1;
			}
			else{
				dp[i]=dp[i-1];
			}
		}
		while(q--){
			scanf("%d %d",&a,&b);
			//ans=0;
			printf("%d\n",dp[b]-dp[a-1]);
		}
		memset(de,0,sizeof(de));
		memset(dp,0,sizeof(dp));
	}
    return 0;
}
