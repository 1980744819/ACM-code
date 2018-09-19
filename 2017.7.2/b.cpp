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
int ans;
int n,k;
bool book[15];
char mp[10][10];
void dfs(int x,int num){
	if(num==k){
		ans++;
		return;
	}
	if(x>=n||x<0){
		return;
	}
	for(int j=0;j<n;j++){
		if(mp[x][j]=='#'&&book[j]==false){
			book[j]=true;
			mp[x][j]='$';
			dfs(x+1,num+1);
			book[j]=false;
			mp[x][j]='#';
		}
	}
	dfs(x+1,num);
}
int main(){
	//int n,k;
	//freopen("test.txt","r",stdin);
	int i,j;
	while(~scanf("%d %d",&n,&k)&&n!=-1&&k!=-1){
		for(i=0;i<n;i++){
			scanf("%s",mp[i]);
			//puts(mp[i]);
		}
		// for(i=0;i<n;i++){
		// 	puts(mp[i]);
		// }
		ans=0;
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}