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
int dp[105][105];
int a[105][105];
int m,k;
bool check(int x,int y){
	if(x<0||x>=m||y<0||y>=m)
		return false;
	return true;
}
int nextx[4]={0,0,1,-1};
int nexty[4]={1,-1,0,0};
int dfs(int x,int y){
	int i,j;
	int tmpx,tmpy;
	int ans=0;
	if(!dp[x][y]){
		for(i=1;i<=k;i++){
			for(j=0;j<4;j++){
				tmpx=x+nextx[j]*i;
				tmpy=y+nexty[j]*i;
				if(!check(tmpx,tmpy))
					continue;
				if(a[tmpx][tmpy]>a[x][y]){
					ans=max(ans,dfs(tmpx,tmpy));
				}
			}
		}
		dp[x][y]=ans+a[x][y];
	}
	return dp[x][y];
}
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	while(~scanf("%d %d",&m,&k)&&m!=-1&&k!=-1){
		memset(dp,0,sizeof(dp));
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		printf("%d\n",dfs(0,0));
	}
	return 0;
}