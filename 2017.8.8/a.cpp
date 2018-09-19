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
const int maxn=405;	
const int inf=99999999;
int f,d,n;
int c[maxn][maxn];
int dis[maxn];
bool bfs(){
	memset(dis,-1,sizeof(dis));
	queue<int>que;
	que.push(0);
	dis[0]=0;
	while(!que.empty()){
		int num=que.front();
		que.pop();
		for(int i=0;i<=n;i++){
			if(c[num][i]>0&&dis[i]==-1){
				dis[i]=dis[num]+1;
				que.push(i);
			}
		}
	}
	if(dis[n]!=-1)
		return true;
	return false;
}
int find(int x,int low){
	int a=0;
	if(x==n)
		return low; 
	for(int i=0;i<=n;i++){
		if(c[x][i]>0&&dis[i]==dis[x]+1&&(a=find(i,min(low,c[x][i])))){
			c[x][i]-=a;
			c[i][x]+=a;
			return a;
		}
	}
	return 0;
}
int main(){
	freopen("test.txt","r",stdin);
	int fi,di;
	int num;
	int ans;
	while(~scanf("%d %d %d",&n,&f,&d)){
		//printf("%d %d %d\n",n,f,d);
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&fi,&di);
			//printf("%d %d ",fi,di);
			for(int j=1;j<=fi;j++){//food
				scanf("%d",&num);
				//printf("%d ",num);
				c[num][i+f]=1;
				c[0][num]=1;
			}
			for(int j=1;j<=di;j++){//drink	
				scanf("%d",&num);
				//printf("%d ",num);
				c[f+n+i][num+f+n+n]=1;
				c[num+f+n+n][f+n+n+d+1]=1;
			}
			c[i+f][i+f+n]=1;
			//printf("\n");
		}
		n=n+n+f+d;
		n++;
		ans=0;
		while(bfs()){
			//printf(">>>>>>>>>>>>>>>");
			int tmp;
			while(tmp=find(0,inf)){
				ans+=tmp;
				//printf("%d %d\n",ans,tmp);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}