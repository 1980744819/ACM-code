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
#define ll long long
#define read(a) scanf("%d",&a);
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int dp[maxn][18];
int dpmax[maxn][18];
int dpindex[maxn][18];
int dpmaxindex[maxn][18];
int n;
void makermq(){
	int i,j;
	for(i=0;i<n;i++){
		dp[i][0]=a[i];
		dpmax[i][0]=a[i];
	}
	for(j=1;(1<<j)<=n;j++){
		for(i=0;i+(1<<j)-1<n;i++){
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
			dpmax[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
}
int rmq(int s,int v){
	int k=(int)(log((v-s+1)*1.0)/log(2.0));
	return min(dp[s][k],dp[v-(1<<k)+1][k]);
}
int rmqmax(int s,int v){
	int k=(int)(log(v-s+1)*1.0)/log(2.0);
	return max(dpmax[s][k],dpmax[v-(1<<k)+1][k]);
}
void makermqindex(){
	int i,j;
	for(i=0;i<n;i++){
		dpindex[i][0]=i;
		//dpmaxindex[i][0]=i;
	}
	for(j=1;(1<<j)<=n;j++){
		for(i=0;i+(1<<j)-1<n;i++){
			dpindex[i][j]=a[dpindex[i][j-1]]<a[dpindex[i+(1<<(j-1))][j-1]]?dpindex[i][j-1]:dpindex[i+(1<<(j-1))][j-1];
		}
	}

}
int rmqindex(int s,int v){
	int k=(int)(log(v-s+1)*1.0)/log(2.0);
	return a[dpindex[s][k]]<a[dpindex[v-(1<<k)+1][k]]?dpindex[s][k]:dpindex[v-(1<<k)+1][k];
}
int main(){
	freopen("test.txt","r",stdin);
	int m,k;
	while(~scanf("%d %d %d",&n,&m,&k)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		makermq();
		makermqindex();
		// for(int i=0;i<n;i++)
		// 	printf("%d ",a[i]);
		// printf("\n");
		// for(int i=0;i<n;i++){
		// 	for(int j=i;j<n;j++){
		// 		printf("min %d %d :%d\n",i,j,rmq(i,j));
		// 		printf("min id:%d %d %d\n",i,j,rmqindex(i,j));
		// 		printf("max %d %d :%d\n",i,j,rmqmax(i,j));
		// 	}
		// }
		int ans=0;
		int left,right;
		left=right=0;
		while(right<n){
			int num=rmqmax(left,right)-rmq(left,right);
			if(num<m){
				right++;
			}
			else if(num>k){
				left=rmqindex(left,right)+1;
				if(left>right)
					left=right;
				//left++;
			}
			else{
				if(ans<right-left+1)
					ans=right-left+1;
				right++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}