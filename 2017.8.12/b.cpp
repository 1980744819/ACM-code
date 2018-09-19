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
vector<int>ve;
void dfs(int cur,int node,int ans,int end){
	if(cur==end){
		//printf("%d ",ans);
		ve.push_back(ans);
		return;
	}
	dfs(cur+1,node*2,ans+node*2,end);
	dfs(cur+1,node*2,ans-node*2,end);
	dfs(cur+1,node*2+1,ans+node*2+1,end);
	dfs(cur+1,node*2+1,ans-node*2-1,end);
	return;
}
int main(){
	//freopen("test.txt","r",stdin);
	for(int i=1;i<=4;i++){
		ve.clear();
		dfs(1,1,1,i);
		//printf("\n");
		dfs(1,1,-1,i);
		//printf("\n");
		sort(ve.begin(),ve.end());
		for(int j=0;j<ve.size();j++){
			if(j!=0){
				// if(ve[j]!=ve[j-1]){
				// 	printf("%d ",ve[j]);
				// }
				printf("%d ",ve[j]);
			}
			else
				printf("%d ",ve[j]);
		}
		printf("\n");
	}
	//dfs(1,1,1,1);
	return 0;
}