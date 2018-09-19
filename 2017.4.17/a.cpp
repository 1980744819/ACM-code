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
long long dp[105][105][105];
int c[205];
long long p[205][205];
int main(){
	int n,m,K;
	int i,j,k;
	scanf("%d %d %d",&n,&m,&K);
	memset(dp,0x3f3f3f3f3f3f3f3f,sizeof(dp));
	for(i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%lld",&p[i][j]);
		}
	}
	if(c[1]==0){
		for(j=1;j<=m;j++){
			dp[1][j][1]=p[1][j];
		}
	}
	else{
		dp[1][c[1]][1]=0;
	}
	for(i=2;i<=n;i++){
		if(c[i]){
			for(k=1;k<i;k++){
				for(int l=1;l<=m;l++){
					if(l==c[i]){
						dp[i][c[i]][k]=min(dp[i][c[i]][k],dp[i-1][l][k]);
					}
					else{
						dp[i][c[i]][k+1]=min(dp[i][c[i]][k+1],dp[i-1][l][k]);
					}
				}
			}
		}
		else{
			for(k=1;k<i;k++){
				for(j=1;j<=m;j++){
					for(int l=1;l<=m;l++){//枚举前一棵树的颜色
						if(l==j){//和前一棵树颜色相同
							dp[i][j][k]=min(dp[i-1][l][k]+p[i][j],dp[i][j][k]);
						}
						else{//和前一棵树颜色不同
							dp[i][j][k+1]=min(dp[i-1][l][k]+p[i][j],dp[i][j][k+1]);
						}
					}
				}
			}
		}
	}
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(j=1;j<=m;j++){
		ans=min(ans,dp[n][j][K]);
	}
	if(ans==0x3f3f3f3f3f3f3f3f){
		printf("-1\n");
	}
	else{
		printf("%lld\n",ans);
	}
    return 0;
}
