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
std::vector<int> v[maxn];
bool book[maxn];
int dfn[maxn],low[maxn];
int total;
bool flag;
int minx(int a,int b){
	if(a>b)
		return b;
	return a;
}
void tarjan(int x){
	if(!flag)
		return;
	dfn[x]=low[x]=++total;
	book[x]=true;
	for(int i=0;i<v[x].size();i++){
		int t=v[x][i];
		if(!book[t]){
			tarjan(t);
			low[x]=min(low[x],low[t]);
		}
		low[x]=min(low[x],dfn[v[x][i]]);
	}
	if(low[x]==dfn[x]&&x!=1){
		flag=false;
	}
}
int main(){
	freopen("test.txt","r",stdin);
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		if(m==n&&m==0)
			break;
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
		}
		flag=true;
		total=0;
		memset(book,false,sizeof(book));
		tarjan(1);
		//printf("%d %d\n",total,flag);

		if(total==n&&flag)
			printf("Yes\n");
		else
			printf("No\n");
		for(int i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}