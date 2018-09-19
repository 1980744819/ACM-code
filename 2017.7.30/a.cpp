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
const int maxn=300005;
bool book[maxn];
vector<int>tree[maxn];
vector<int>s[maxn];
int p[maxn];
int n,m,P; 
bool dfs(int x){
	if(x==n+1){
		return true;
	}
	for(int i=0;i<tree[x].size();i++){
		if(book[tree[x][i]]==false){
			// if(dfs(x+1)==true){
			// 	book[tree[x][i]]=true;
			// 	//return true;
			// 	printf("%d ",tree[x][i]+1);
			// }
			book[tree[x][i]]=true;
			dfs(x+1);
			book[tree[x][i]]=false;
		}
	}
	//printf("\n");
	return false;
}
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	int sum,si;
	while(~scanf("%d %d %d",&n,&m,&P)){
		for(i=0;i<maxn;i++)
			s[i].clear();
		for(i=0;i<maxn;i++)
			tree[i].clear();
		//printf("%d %d %d",n,m,P);
		memset(book,false,sizeof(book));
		memset(p,0,sizeof(p));
		for(i=0;i<m;i++){
			scanf("%d",&sum);
			for(j=0;j<sum;j++){
				scanf("%d",&si);
				s[i].push_back(si);
			}
		}
		for(i=0;i<P;i++){
			scanf("%d",&si);
			for(j=0;j<s[si].size();j++){
				tree[s[si][j]].push_back(i);
			}
		}
		dfs(1);
	}
	return 0;
}