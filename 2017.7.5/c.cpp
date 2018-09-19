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
int dp[1005][1005];
char s[1005][1005];
int main(){
	//freopen("test.txt","r",stdin);
	int m,n;
	int i,j;
	int x,y;
	int num,ans;
	while(~scanf("%d",&n)&&n){
		for(i=0;i<n;i++){
			scanf("%s",s[i]);
			dp[0][i]=1;
		}
		// for(i=0;i<n;i++){
		// 	puts(s[i]);
		// }
		ans=1;
		for(i=1;i<n;i++){
			for(j=0;j<n-1;j++){
				x=i-1;
				y=j+1;
				num=1;
				while(x>=0&&x<n&&y>=0&&y<n&&s[x][j]==s[i][y]){
					x--;
					y++;
					num++;
				}
				if(num>dp[i-1][j+1]){
					dp[i][j]=dp[i-1][j+1]+1;
				}
				else{
					dp[i][j]=num;
				}
				ans=max(ans,dp[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}