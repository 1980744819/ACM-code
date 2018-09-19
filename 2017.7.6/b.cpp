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
int a[100005][15];
int dp[100005][15];
bool book[100005][15];
int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	int m,n;
	int Max_t;
	int x,t;
	int temp;
	while(~scanf("%d",&n)&&n){
		Max_t=0;
		for(i=0;i<n;i++){
			scanf("%d %d",&x,&t);
			a[t][x]++;
			if(Max_t<t)
				Max_t=t;
		}
		//printf("%d\n",Max_t);
		// for(i=0;i<Max_t;i++){
		// 	for(j=0;j<=10;j++){
		// 		dp[i][j]=inf;
		// 	}
		// }
		// dp[0][5]=0;
		book[0][5]=true;
		for(i=1;i<=Max_t;i++){
			for(j=0;j<=10;j++){
				if(j-1>=0&&book[i-1][j-1]){
					book[i][j]=true;
					//break;
				}
				if(book[i-1][j]){
					book[i][j]=true;
					//break;
				}
				if(j+1<=10&&book[i-1][j+1]){
					book[i][j]=true;
					//break;
				}
			}
		}
		// for(i=1;i<=Max_t;i++){
		// 	printf("%d : ",i);
		// 	for(j=0;j<=10;j++){
		// 		printf("%d ",book[i][j]);
		// 	}
		// 	printf("\n");
		// }
		for(i=1;i<=Max_t;i++){
			for(j=0;j<=10;j++){
				if(j-1>=0&&book[i-1][j-1]){
					if(dp[i][j]<dp[i-1][j-1]+a[i][j]){
						dp[i][j]=dp[i-1][j-1]+a[i][j];
					}
				}
				if(book[i-1][j]){
					if(dp[i][j]<dp[i-1][j]+a[i][j]){
						dp[i][j]=dp[i-1][j]+a[i][j];
					}
				}
				if(j+1<=10&&book[i-1][j+1]){
					if(dp[i][j]<dp[i-1][j+1]+a[i][j]){
						dp[i][j]=dp[i-1][j+1]+a[i][j];
					}
				}
			}
		}
		int Max=0;
		for(j=0;j<=10;j++){
			if(Max<dp[Max_t][j]){
				Max=dp[Max_t][j];
			}
		}
		printf("%d\n",Max);
		memset(dp,0,sizeof(dp));
		memset(book,false,sizeof(book));
		memset(a,0,sizeof(a));
	}
	return 0;
}