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
int main(){
	//freopen("test.txt","r",stdin);
	int t;
	int a,b;
	int coun;
	int i,j;
	int n;
	scanf("%d",&t);
	int temp;
	int p,w;
	while(t--){
		scanf("%d %d",&a,&b);
		coun=b-a;
		scanf("%d",&n);
		for(i=1;i<=coun;i++){
			dp[i]=999999999;
		}
		dp[0]=0;
		while(n--){
			scanf("%d %d",&p,&w);
			for(j=w;j<=coun;j++){
				if(dp[j]>dp[j-w]+p)
					dp[j]=dp[j-w]+p;
			}
		}
		if(dp[coun]==999999999){
			printf("This is impossible.\n");
		}
		else{
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[coun]);
		}
	}
	return 0;
}