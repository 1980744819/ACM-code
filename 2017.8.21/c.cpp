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
const int maxn=1005;
bool flag,book[maxn];
std::vector<int> v[maxn];
int dfn[maxn],low[maxn];
int total;
void tarjan(int x){
	if(!flag)
		return;
	dfn[x]=low[x]=++total;
	book[x]=true;
	for(int i=0;i<v[x].size();i++){
		if(!book[v[x][i]]){
			tarjan(v[x][i]);
			low[x]=min(low[x],low[v[x][i]]);
		}
		low[x]=min(low[x],dfn[v[x][i]]);
	}
	if(dfn[x]==low[x]&&x!=1){
		flag=false;
	}
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
		}
		total=0;
		flag=true;
		memset(book,false,sizeof(book));
		tarjan(1);
		if(flag&&total==n)
			printf("Yes\n");
		else
			printf("No\n");
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
	}
	return 0;
}