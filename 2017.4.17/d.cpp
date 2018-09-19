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
string s[100005][2];
long long dp[100005][2];
int c[100005];
int main(){
	int i,j;
	int n;
	scanf("%d",&n);
	int len;
	for(i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(i=1;i<=n;i++){
		cin>>s[i][0];
		len=0;
		for(j=s[i][0].size()-1;j>=0;j--){
			s[i][1][len]=s[i][0][j];
			len++;
		}
	}
	dp[1][0]=0;
	dp[1][1]=c[1];
	for(i=2;i<=n;i++){
		dp[i][0]=1e15;
		dp[i][1]=1e15;
		if(s[i][0]>s[i-1][0]){
			dp[i][0]=min(dp[i][0],dp[i-1][0]);
		}
		if(s[i][0]>s[i-1][1]){
			dp[i][0]=min(dp[i][0],dp[i-1][1]);
		}
		if(s[i][1]>s[i-1][0]){
			dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
		}
		if(s[i][1]>s[i-1][1]){
			dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
		}
		if(dp[i][1]==1e15&&dp[i][0]==1e15){
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n",dp[n][0]<dp[n][1]?dp[n][0]:dp[n][1]);
    return 0;
}
