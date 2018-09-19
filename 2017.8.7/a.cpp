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
const int maxn=105;
const int inf=99999999;
int c[maxn][maxn];
int dis[maxn];
int n,m,np,nc;
bool bfs(){
	memset(dis,-1,sizeof(dis));
	queue<int>que;
	que.push(0);
	dis[0]=0;
	while(!que.empty()){
		int num=que.front();
		que.pop();
		for(int i=0;i<=n;i++){
			if(dis[i]==-1&&c[num][i]>0){
				dis[i]=dis[num]+1;
				que.push(i);
			}
		}
	}
	if(dis[n]>0)
		return true;
	return false;
}
int find(int x,int low){
	int a;
	if(x==n)
		return low;
	for(int i=0;i<=n;i++){
		if(c[x][i]>0
			&&dis[i]==dis[x]+1
			&&(a=find(i,min(low,c[x][i])))){
			c[x][i]-=a;
			c[i][x]+=a;
			return a;
		}
	}
	return 0;
}
int main(){
	freopen("test.txt","r",stdin);
	int u,v,w;
	int ans=0;
	int tmp;
	while(~scanf("%d %d %d %d",&n,&np,&nc,&m)){
		memset(c,0,sizeof(c));
		n++;
		for(int i=0;i<m;i++){
			scanf(" (%d,%d)%d",&u,&v,&w);
			u++;
			v++;
			c[u][v]+=w;
		}
		for(int i=0;i<np;i++){
			scanf(" (%d)%d",&u,&v);
			u++;
			c[0][u]+=v;
		}
		for(int i=0;i<nc;i++){
			scanf(" (%d)%d",&u,&v);
			u++;
			c[u][n]+=v;
		}
		ans=0;
		tmp=0;
		while(bfs()){
			while(tmp=find(0,inf))
				ans+=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}