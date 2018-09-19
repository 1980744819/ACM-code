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
const int maxn=20005;
std::vector<int> v[maxn];
int dfn[maxn],low[maxn],sccno[maxn];
int total,color;
stack<int>sta;
int n,m;
void tarjan(int x){
	dfn[x]=low[x]=++total;
	sta.push(x);
	for(int i=0;i<v[x].size();i++){
		if(!dfn[v[x][i]]){
			tarjan(v[x][i]);
			low[x]=min(low[x],low[v[x][i]]);	
		}
		else if(!sccno[v[x][i]]){
			low[x]=min(low[x],dfn[v[x][i]]);
		}
	}
	if(low[x]==dfn[x]){
		color++;
		int tmp=-1;
		//int u=sta.top();
		while(tmp!=x){
			tmp=sta.top();
			sta.pop();
			sccno[tmp]=color;
		}
	}
}
int solve(){
	if(color==1)
		return 0;
	int id[maxn],od[maxn];
	memset(id,0,sizeof(id));
	memset(od,0,sizeof(od));
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			if(sccno[i]!=sccno[v[i][j]]){
				od[sccno[i]]++;
				id[sccno[v[i][j]]]++;
			}
		}
	}
	int idnum=0,odnum=0;
	for(int i=1;i<=color;i++){
		idnum+=(id[i]==0);
		odnum+=(od[i]==0);
	}
	return max(idnum,odnum);
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
		}
		total=0;
		color=0;
		while(!sta.empty())
			sta.pop();
		memset(sccno,0,sizeof(sccno));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				tarjan(i);
			}
		}
		printf("%d\n",solve());
		for(int i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}