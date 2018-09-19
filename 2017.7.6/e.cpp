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
int a[30005];
int dp[30005];
bool book[30005];
int main(){
	freopen("test.txt","r",stdin);
	int n;
	int i,j;
	int last,now;
	int coun=0;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			dp[i]=1;
		}
		int Max=0;
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				if(a[j]<a[i]&&dp[i]<dp[j]+1)
					dp[i]=dp[j]+1;
				if(Max<dp[i])
					Max=dp[i];
			}
		}
		printf("%d\n",Max);
	}
	return 0;
}