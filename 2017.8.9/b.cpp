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
//#define read(a) scanf("%d",&a);
using namespace std;
const int maxn=10005;
ll a[maxn],b[maxn];
ll dp[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&m);
		for(int i=0;i<=m;i++){
			scanf("%lld",&b[i]);
		}
		int cnt=0;
		dp[0]=1;
		for(int i=1;i<=	m;i++){
			b[i]-=dp[i];
			for(int j=1;j<=b[i];j++){
				a[++cnt]=i;
				for(int k=m;k>=i;k--){
					dp[k]+=dp[k-i];
				}
			}
			//i++;
		}
		for(int i=1;i<=cnt;i++){
			if(i>1)
				printf(" ");
			printf("%lld",a[i]);
		}
		printf("\n");
	}
	return 0;
}			