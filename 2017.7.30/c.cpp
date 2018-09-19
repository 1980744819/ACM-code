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
const int maxn=20;
const int inf=99999999;
int n,sum,cost;
int link[maxn];
bool useds[maxn],usede[maxn];
int line[maxn],preline[maxn];
int w[maxn][maxn];
int s[maxn][maxn],e[maxn][maxn];
int cs[maxn],ce[maxn];
bool book[maxn];
bool find(int x){
	usede[x]=true;
	for(int i=1;i<=n;i++){
		if(useds[i]==false&&(ce[x]+cs[i]==w[x][i])){
			useds[i]=true;
			if(line[i]==0||find(line[i])){
				line[i]=x;
				return true;
			}
		}
	}
	return false;
}
int km(){
	for(int i=1;i<=n;i++){
		while(true){
			memset(useds,false,sizeof(useds));
			memset(usede,false,sizeof(usede));
			int d=inf;
			if(find(i))break;
			for(int j=1;j<=n;j++){
				if(usede[j]){
					for(int k=1;k<=n;k++){
						if(useds[k]==0){
							d=min(d,ce[j]+cs[k]-w[j][k]);
						}
					}
				}
			}
			if(d==inf)
				return -1;
			for(int j=1;j<=n;j++){
				if(usede[j]){
					ce[j]-=d;
				}
			}
			for(int j=1;j<=n;j++){
				if(useds[j]){
					cs[j]+=d;
				}
			}
		}
	}
	double ans=0;
	for(int i=1;i<=n;i++){
		ans+=w[line[i]][i];
	}
	cost=ans;
	ans=0-ans;
	ans-=2*n;
	printf("Best average difference: %.6lf\n",ans*1.0/(n*2));
	// printf("Best Pairing 1\n");
	// for(int i=1;i<=n;i++){
	// 	printf("Supervisor %d with Employee %d\n",i,line[i]);
	// }
	return ans;
}
void dfs(int cur,int cnt){
	if(cnt<cost){
		return;
	}
	if(cur==n+1){
		if(cnt!=cost){
			return;
		}
		sum++;
		printf("Best Pairing %d\n",sum);
		for(int i=1;i<=n;i++){
			printf("Supervisor %d with Employee %d\n",i,link[i]);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(book[i]==false){
				book[i]=true;
				link[cur]=i;
				dfs(cur+1,cnt+w[cur][i]);
				book[i]=false;
			}
		}
	}
}
int main(){
	freopen("test.txt","r",stdin);
	int ca=0;
	int t;
	scanf("%d",&t);
	int i,j;
	while(t--){
		scanf("%d",&n);
		memset(w,0,sizeof(w));
		memset(line,0,sizeof(line));
		memset(preline,0,sizeof(line));
		memset(book,false,sizeof(book));
		sum=0;
		cost=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&s[i][j]);
				w[s[i][j]][i]+=j;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&e[i][j]);
				w[i][e[i][j]]+=j;
			}
		}
		// for(i=1;i<=n;i++){
		// 	for(j=1;j<=n;j++){
		// 		printf("%d ",w[i][j]);
		// 	}
		// 	printf("\n");
		// }
		memset(ce,0,sizeof(ce));
		memset(cs,0,sizeof(cs));
		for(i=1;i<=n;i++){
			int d=-inf;
			for(j=1;j<=n;j++){
				w[i][j]=0-w[i][j];
				d=max(d,w[i][j]);
			}
			ce[i]=d;
		}
		printf("Data Set %d, ",++ca);
		km();
		dfs(1,0);
		printf("\n");
	}
	return 0;
}