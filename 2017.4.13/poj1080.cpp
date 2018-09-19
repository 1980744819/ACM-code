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
int mx[5][5]={{5,-1,-2,-1,-3},  
                {-1,5,-3,-2,-4},  
                {-2,-3,5,-2,-2},  
                {-1,-2,-2,5,-1},  
                {-3,-4,-2,-1,0}};
 map<char,int>mp;
 int dp[105][105];
int main(){
	int t;
	int n1,n2;
	char s1[105],s2[105];
	int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n1);
		scanf("%s",s1+1);
		scanf("%d",&n2);
		scanf("%s",s2+1);
		dp[0][0]=0;
		mp['A']=0;mp['C']=1;mp['G']=2;mp['T']=3;mp['-']=4;
		for(i=1;i<=n1;i++){
			dp[i][0]=dp[i-1][0]+mx[mp[s1[i]]][mp['-']];
		}
		for(j=1;j<=n2;j++){
			dp[0][j]=dp[0][j-1]+mx[mp['-']][mp[s2[j]]];
		}
		for(i=1;i<=n1;i++){
			for(j=1;j<=n2;j++){
				dp[i][j]=dp[i-1][j-1]+mx[mp[s1[i]]][mp[s2[j]]];
				dp[i][j]=max(dp[i][j],dp[i-1][j]+mx[mp[s1[i]]][mp['-']]);
				dp[i][j]=max(dp[i][j],dp[i][j-1]+mx[mp['-']][mp[s2[j]]]);
			}
		}
		printf("%d\n",dp[n1][n2]);
	}
    return 0;
}
