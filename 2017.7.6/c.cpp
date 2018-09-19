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
const int inf=1<<30;
int dp[2005][2],s[2005],d[2005];
int main(){
	freopen("test.txt","r",stdin);
	int n;
	int i,j;
	int k;
	while(~scanf("%d",&n)){
		while(n--){
			scanf("%d",&k);
			//printf("%d\n",k);
			for(i=0;i<k;i++){
				scanf("%d",&s[i]);
			}
			for(i=0;i<k-1;i++){
				scanf("%d",&d[i]);
			}
			for(i=0;i<2005;i++){
				dp[i][0]=inf;
				dp[i][1]=inf;
			}
			dp[0][0]=s[0];
			//dp[0][1]=0;
			for(i=1;i<k;i++){
				dp[i][0]=min(dp[i-1][0]+s[i],min(dp[i-1][1]+s[i],dp[i][0]));
				dp[i][1]=min(dp[i-2][0]+d[i-1],min(dp[i-2][1]+d[i-1],dp[i][1]));
				//printf("%d %d\n",dp[i][0],dp[i][1]);
			}
			//printf("%d\n",);
			int ans=dp[k-1][0]<dp[k-1][1]?dp[k-1][0]:dp[k-1][1];
			int h=8;
			int m=0;
			int s=0;
			h+=ans/3600;
			ans%=3600;
			m+=ans/60;
			ans%=60;
			s+=ans;
			if(h>=24)
				h%=24;
			printf("%02d:",h);
			printf("%02d:",m);
			printf("%02d",s);
			if(h<=12)
				printf(" am");
			else
				printf(" pm");
			printf("\n");
		}
	}
	return 0;
}