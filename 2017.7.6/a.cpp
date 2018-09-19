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
const int  Maxn=(1<<15)+10;
const int inf=(1<<30)-1;
struct stu {
	int deadline,need_time;
	char name[100];
}a[20];
int dp[Maxn],tim[Maxn],prin[Maxn];
void print(int num){
	if(!num)
		return;
	print(num-(1<<prin[num]));
	printf("%s\n",a[prin[num]].name);
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int i,j;
	int m,n;
	int temp;
	int total;
	scanf("%d",&t);
	int tmp;
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s %d %d",a[i].name,&a[i].deadline,&a[i].need_time);
		}
		// for(i=0;i<n;i++){
		// 	printf("%s %d %d\n",a[i].name,a[i].deadline,a[i].need_time);
		// }
		total=1<<n;
		for(i=1;i<total;i++){
			dp[i]=inf;
			for(j=n-1;j>=0;j--){
				temp=1<<j;
				if(!(temp&i))
					continue;
				tmp=tim[i-temp]+a[j].need_time-a[j].deadline;
				if(tmp<0)
					tmp=0;
				if(dp[i]>dp[i-temp]+tmp){
					dp[i]=dp[i-temp]+tmp;
					tim[i]=tim[i-temp]+a[j].need_time;
					prin[i]=j;
				}
			}
		}
		printf("%d\n",dp[total-1]);
		print(total-1);
		memset(tim,0,sizeof(tim));
	}
	return 0;
}