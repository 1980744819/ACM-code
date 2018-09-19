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
struct stu{
	int w,s;
	int num;
	int fa;
}a[10005];
bool cmp(struct stu u,struct stu v){
	return u.w==v.w?u.s<v.s:u.w<v.w;
}
int dp[10005];
void dfs(int x){
	if(dp[x]==1){
		printf("%d\n",a[x].num);
		return;
	}
	dfs(a[x].fa);
	printf("%d\n",a[x].num);
}
// void dfs(int coun,int x){
// 	int temp=x;
// 	if(coun==0||x<0)
// 		return;
// 	while(temp--){
// 		if(dp[temp]==coun-1){
// 			dfs(coun-1,temp);
// 			printf("%d\n",a[temp].num);
// 			break;
// 		}
// 	}
// }
int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	int m,n;
	int coun;
	coun=0;
	while(~scanf("%d %d",&a[coun].w,&a[coun].s)){
		a[coun].num=coun+1;
		a[coun].fa=coun;
		dp[coun]=1;
		coun++;
	}
	sort(a,a+coun,cmp);
	int Max=0;
	for(i=1;i<coun;i++){
		for(j=0;j<i;j++){
			if(a[i].w>a[j].w&&a[i].s<a[j].s&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
				a[i].fa=j;
				if(Max<dp[i])
					Max=dp[i];
			}
		}
	}
	printf("%d\n",Max);
	for(i=coun-1;i>=0;i--){
		if(dp[i]==Max){
			//dfs(Max,i);
			dfs(i);
			break;
		}
	}
	return 0;
}