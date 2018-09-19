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
const int maxn=1e6+5;
struct node{
	int v,next;
}edge[maxn];
int dfn[maxn],low[maxn],heads[maxn],visit[maxn],sta[maxn],tol,cnt,inde;
int flag;
int ans;
void add(int x,int y){
	edge[++cnt].next=heads[x];
	edge[cnt].v=y;
	heads[x]=cnt;
	return;
}
void tarjan(int x){
	if(flag)
		return;
	dfn[x]=low[x]=++tol;
	sta[++inde]=x;
	visit[x]=1;
	//printf("%d ",x);
	for(int i=heads[x];i!=0;i=edge[i].next){
		if(!dfn[edge[i].v]){
			tarjan(edge[i].v);
			low[x]=min(low[x],low[edge[i].v]);
		}
		else if(visit[edge[i].v]){
			low[x]=min(low[x],dfn[edge[i].v]);
		}
	}
	if(low[x]==dfn[x]&&x!=1){
		flag=1;
		// while(x!=sta[inde+1]){
		// 	//printf("%d ",sta[inde]);
		// 	visit[sta[inde]]=0;
		// 	inde--;
		// 	if(!flag)
		// 		ans++;
		// }
		// if(!flag)
		// 	flag=1;
		//printf("\n");
		//return;
	}

}
int main(){
	freopen("test.txt","r",stdin);
	int n,m;
	while(~scanf("%d %d",&n,&m)&&(m+n)){
		int a,b;
		cnt=0;
		tol=0;
		inde=0;
		//ans=0;
		//printf("%d %d\n",n,m);
		memset(visit,0,sizeof(visit));
		memset(heads,0,sizeof(heads));
		memset(dfn,0,sizeof(dfn));
		flag=0;
		for(int i=1;i<=m;i++){
			scanf("%d %d",&a,&b);
			add(a,b);
		}
		// for(int i=1;i<=cnt;i++)
		// 	printf("%d %d %d\n",i,edge[i].v,edge[i].next);
		tarjan(1);
		if(!flag&&tol==n)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}