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
int w[1005],s[1005];
int dp[1005];
void dfs(int coun,int x){
	if(x==0||coun==0)
		return;
	int temp=x;
	while(temp--){
		if(coun-1==dp[temp]){
			dfs(coun-1,temp);
			printf("%d\n",x);
			break;
		}
	}
}
int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	int coun;
	coun=1;
	while(~scanf("%d %d",&w[coun],&s[coun])){
		dp[coun]=1;
		coun++;
	}
	int Max=0;
	for(i=2;i<coun;i++){
		for(j=1;j<i;j++){
			if(w[j]<w[i]&&s[j]>s[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
				if(Max<dp[i])
					Max=dp[i];
			}
		}
	}
	printf("%d\n",Max);
	for(i=coun-1;i>=0;i--){
		if(dp[i]==Max){
			dfs(Max,i);
			break;
		}
	}
	return 0;
}