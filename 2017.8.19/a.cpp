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
struct node{
	int v,next;
}edge[1001];
int DFN[1001],LOW[1001],heads[1001],visit[1001],Stack[1001],cnt,tot,Index;
void add(int x,int y){
	edge[++cnt].next=heads[x];
	edge[cnt].v=y;
	heads[x]=cnt;
	return;
}
void tarjan(int x){
	DFN[x]=LOW[x]=++tot;
	Stack[++Index]=x;
	visit[x]=1;
	for(int i=heads[x];i!=-1;i=edge[i].next){
		if(!DFN[edge[i].v]){
			tarjan(edge[i].v);
			LOW[x]=min(LOW[x],LOW[edge[i].v]);
		}
		else if(visit[edge[i].v]){
			LOW[x]=min(LOW[x],LOW[edge[i].v]);
		}
	}
	if(LOW[x]==DFN[x]){
		while(x!=Stack[Index+1]){
			printf("%d ",Stack[Index]);
			visit[Stack[Index]]=0;
			Index--;
		}
		printf("\n");
	}
}
int main(){
	freopen("test.txt","r",stdin);
	memset(heads,-1,sizeof(heads));
	int n,m;
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++){
		if(!DFN[i])
			tarjan(i);
	}
	return 0;
}