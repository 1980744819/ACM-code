#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=10000;
int mp[maxn][maxn];
int vx,vy;
void solve(int n,int m){
	int x=1,y=1;
	vx=1;
	vy=1;
	int ans=0;
	memset(mp,0,sizeof(mp));
	mp[x][y]=1;
	while(1){
		x+=vx;
		y+=vy;
		mp[x][y]++;
		//printf("%d %d %d %d ",x,y,vx,vy);
		if(x==1){
			//printf("1\n");
			if(y==1||y==m){
				break;
			}
			else{
				vx=0-vx;
			}
		}
		else if(x==n){
			//printf("2\n");
			if(y==1||y==m){
				break;
			}
			else{
				vx=0-vx;
			}
		}
		else{
			//printf("3\n");
			if(y==1||y==m){
				vy=0-vy;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==1){
				ans++;
			}
		}
	}
	printf("%d %d %d\n",n,m,ans);
}
int main(){
	freopen("test.txt","r",stdin);
	//solve(3,4);
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		solve(n,m);
	}
    return 0;
}
