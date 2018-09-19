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
const int maxn=55;
const int inf=99999999;
int shop[maxn][maxn],sup[maxn][maxn],price[maxn][maxn][maxn];
int cntx,cnty;
int cx[maxn*3],cy[maxn*3];
int A[maxn*3],B[maxn*3];
int w[maxn*3][maxn*3];
int line[maxn*3];
bool usedx[maxn*3],usedy[maxn*3];
int n,m,k;
bool find(int x){
	usedx[x]=true;
	for(int j=1;j<=cnty;j++){
		if(usedy[j]==false&&(cx[x]+cy[j]==w[x][j])){
			usedy[j]=true;
			if(line[j]==0||find(line[j])){
				line[j]=x;
				return true;
			}
		}
	}
	return false;
}
int km(){
	for(int i=1;i<=cntx;i++){
		while(true){
			int d=inf;
			memset(usedx,false,sizeof(usedx));
			memset(usedy,false,sizeof(usedy));
			if(find(i))break;
			for(int j=1;j<=cntx;j++){
				if(usedx[j]==true){
					for(int k=1;k<=cnty;k++){
						if(usedy[k]==false){
							d=min(d,cx[j]+cy[k]-w[j][k]);
						}
					}
				}
			}
			if(d==inf)
				return -1;
			for(int j=1;j<=cntx;j++){
				if(usedx[j]==true){
					cx[j]-=d;
				}
			}
			for(int j=1;j<=cnty;j++){
				if(usedy[j]==true){
					cy[j]+=d;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=cnty;i++){
		ans+=w[line[i]][i];
	}
	return -ans;
}
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	while(~scanf("%d %d %d",&n,&m,&k)&&n&&m&&k){
		for(i=1;i<=n;i++){
			for(j=1;j<=k;j++){
				scanf("%d",&shop[i][j]);
				shop[i][j]+=shop[i-1][j];
			}
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=k;j++){
				scanf("%d",&sup[i][j]);
				sup[i][j]+=sup[i-1][j];
			}
		}
		for(int K=1;K<=k;K++){
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					scanf("%d",&price[K][i][j]);
				}
			}
		}
		bool flag=false;
		for(int K=1;K<=k;K++){
			//printf("%d %d\n",shop[n][k],sup[m][k]);
			if(shop[n][K]>sup[m][K]){
				flag=true;
				printf("-1\n");
				break;
			}
		}
		if(flag)
			continue;
		int count1;
		int count2;
		int ans=0;
		for(int K=1;K<=k;K++){
			cntx=shop[n][K];
			cnty=sup[m][K];
			for(i=1;i<=n;i++){
				for(j=shop[i-1][K]+1;j<=shop[i][K];j++){
					A[j]=i;
				}
			}
			for(i=1;i<=m;i++){
				for(j=sup[i-1][K]+1;j<=sup[i][K];j++){
					B[j]=i;
				}
			}
			memset(cx,0,sizeof(cx));
			memset(cy,0,sizeof(cy));
			memset(line,0,sizeof(line));
			for(i=1;i<=cntx;i++){
				int d=0-inf;
				for(j=1;j<=cnty;j++){
					w[i][j]=price[K][A[i]][B[j]];
					w[i][j]=0-w[i][j];
					d=max(w[i][j],d);
				}
				cx[i]=d;
			}
			ans+=km();
		}
		printf("%d\n",ans);
	}
	return 0;
}