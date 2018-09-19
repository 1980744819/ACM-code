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
const int maxn=205;
const int inf=99999999;
int c[maxn][maxn];
int dis[maxn];
int m,n;
int ans;
bool bfs(){
	int i,j;
	memset(dis,-1,sizeof(dis));
	//printf("%d\n",dis[0])
	dis[1]=0;
	queue<int>que;
	que.push(1);
	while(!que.empty()){
		j=que.front();
		que.pop();
		for(i=1;i<=n;i++){
			if(dis[i]<0&&c[j][i]>0){
				dis[i]=dis[j]+1;
				que.push(i);
			}
		}
	}
	if(dis[n]>0)
		return true;
	return false;
}
int find(int x,int low){
	int i,a=0;
	if(x==n)
		return low;
	for(i=1;i<=n;i++){
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
	int u,v,val;
	while(~scanf("%d %d",&m,&n)){
		//printf("%d %d\n",m,n);
		memset(c,0,sizeof(c));
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&u,&v,&val);
			c[u][v]+=val;
		}
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=n;j++){
		// 		printf("%d ",c[i][j]);
		// 	}
		// 	printf("\n");
		// }
		int tmp;
		ans=0;
		while(bfs()){
			while(tmp=find(1,inf))
				ans+=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}