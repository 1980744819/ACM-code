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
int dp[2005],s[2005],d[2005];
int main(){
	//freopen("test.txt","r",stdin);
	int n;
	int i,j;
	int k;
	while(~scanf("%d",&n)){
		while(n--){
			scanf("%d",&k);
			//printf("%d\n",k);
			for(i=1;i<=k;i++){
				scanf("%d",&s[i]);
			}
			for(i=1;i<=k-1;i++){
				scanf("%d",&d[i]);
			}
			memset(dp,0,sizeof(dp));
			//dp[0][0]=s[0];
			dp[1]=s[1];
			//dp[0][1]=0;
			for(i=2;i<=k;i++){
				dp[i]=min(dp[i-1]+s[i],dp[i-2]+d[i-1]);
				//printf("%d %d\n",dp[i][0],dp[i][1]);
			}
			//printf("%d\n",);
			int ans=dp[k];
			int h=8;
			int m=0;
			int s=0;
			h+=ans/3600;
			ans%=3600;
			m+=ans/60;
			ans%=60;
			s+=ans;
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