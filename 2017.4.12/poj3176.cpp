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
int dp[355][355];
int a[355][355];
int main(){
	int n,i,j;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=1;i<=n;i++){
			dp[n][i]=a[n][i];
		}
		for(i=n-1;i>=1;i--){
			for(j=1;j<=i;j++){
				dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
			}
		}
		printf("%d\n",dp[1][1]);
		memset(dp,0,sizeof(dp));
	}
    return 0;
}
