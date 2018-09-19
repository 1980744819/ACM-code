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
bool vis[10005];
vector<int>ve[10005];
void dfs(int num){
	if(vis[num]==true){
		return;
	}
	else{
		printf("%d ",num);//遍历顺序
		vis[num]=true;
		for(int i=0;i<ve[num].size();i++){
			dfs(ve[num][i]);
		}
	}
}
int main(){
	int i,j;
	int n,m;
	int num;
	while(scanf("%d",&n)){//输入顶点的个数
		memset(vis,false,sizeof(vis));
		for(i=1;i<=n;i++){
			scanf("%d",&m);//输入第i个点有几个点与之相邻
			for(j=0;j<m;j++){
				scanf("%d",&num);//输入第i个点与之相邻的点
				ve[i].push_back(num);
			}
		}
		dfs(1);
		printf("\n");
		for(i=0;i<=n;i++)
		ve[i].clear();
	}
    return 0;
}
