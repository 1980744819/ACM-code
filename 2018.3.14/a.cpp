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
const int maxn=10005;
int n,k;
int costs[maxn][maxn];
int dp[maxn][maxn];
int solve(){
	for(int j=0;j<k;j++){
		dp[0][j]=costs[0][j];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<k;j++){
			dp[i][j]=999999999;
			for(int t=0;t<k;t++){
				if(j!=t){
					dp[i][j]=min(dp[i-1][t]+costs[i][j],dp[i][j]);
				}
			}
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	int ans=999999999;
	for(int j=0;j<k;j++){
		ans=min(ans,dp[n-1][j]);
	}
	return ans;
}
int main(){
	// freopen("test.txt","r",stdin);
	// freopen("test.out","w",stdout);
	while(~scanf("%d %d",&n,&k)){
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				scanf("%d",&costs[i][j]);
				printf("%d ",costs[i][j]);
			}
			printf("\n");
		}
		printf("%d\n",solve());
	}
	
    return 0;
}
