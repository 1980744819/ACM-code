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
int dp[1005];
int chess[1005];
int main(){
	//freopen("test.txt","r",stdin);
	int m,n;
	int i,j;
	while(~scanf("%d",&n)&&n){
		for(i=0;i<n;i++){
			scanf("%d",&chess[i]);
			dp[i]=chess[i];
		}
		int Max;
		Max=0;
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				if(chess[j]<chess[i]&&dp[i]<dp[j]+chess[i]){
					dp[i]=chess[i]+dp[j];
				}
			}
			if(Max<dp[i])
				Max=dp[i];
		}
		printf("%d\n",Max);
	}
	return 0;
}