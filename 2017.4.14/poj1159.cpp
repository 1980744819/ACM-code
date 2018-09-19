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
int dp[2][5005];
int main(){
	char s1[5005];
	char s2[5005];
	int i,j;
	int n;
	int len;
	while(~scanf("%d",&n)){
		getchar();
		for(i=1;i<=n;i++){
			scanf("%c",&s1[i]);
			s2[n-i+1]=s1[i];
		}
		int e=0;
		for(i=1;i<=n;i++){
			e=1-e;
			for(j=1;j<=n;j++){
				if(s1[i]==s2[j]){
					dp[e][j]=dp[1-e][j-1]+1;
				}
				else{
					dp[e][j]=max(dp[1-e][j],dp[e][j-1]);
				}
			}
		}
		printf("%d\n",n-dp[e][n]);
		memset(dp,0,sizeof(dp));
	}
    return 0;
}
