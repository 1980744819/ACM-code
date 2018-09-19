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
int a[200005];
int dp[200005];
int main(){
	int i,j;
	int n,m;
	int l,r,x;
	bool flag;
	int tmp;
	int k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	i=1;
	while(i<n){
		j=i+1;
		while(j<=n&&a[j]==a[i]){
			j++;
		}
		for(k=i;k<j;k++){
			dp[k]=j;
		}
		i=j;
	}
	// for(i=1;i<=n;i++)
	// 	printf("%d ",dp[i]);
	// printf("\n");
	for(i=0;i<m;i++){
		scanf("%d %d %d",&l,&r,&x);
		if(a[l]!=x){
			printf("%d\n",l);
		}
		else{
			l=dp[l];
			if(l==0||l==n+1||l>r){
				printf("-1\n");
			}
			else{
				printf("%d\n",l);
			}
		}
	}
    return 0;
}
