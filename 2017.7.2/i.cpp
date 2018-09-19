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
char mp[105][105];
bool book[105][105];
int ans;
int m,n;
int nextx[8]={-1,-1,0,1,1,1,0,-1};
int nexty[8]={0,1,1,1,0,-1,-1,-1};
void dfs(int x,int y){
	int tmx,tmy;
	book[x][y]=true;
	for(int i=0;i<8;i++){
		tmx=x+nextx[i];
		tmy=y+nexty[i];
		if(tmx>=m||tmx<0||tmy>=n||tmy<0)
			continue;
		if(mp[tmx][tmy]=='@'&&book[tmx][tmy]==false){
			dfs(tmx,tmy);
		}
	}
}
int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	while(~scanf("%d %d",&m,&n)&&m&&n){
		ans=0;
		for(i=0;i<m;i++){
			scanf("%s",mp[i]);
		}
		// for(i=0;i<m;i++){
		// 	printf("%s\n",mp[i]);
		// }
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(mp[i][j]=='@'&&book[i][j]==false){
					ans++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",ans);
		memset(book,false,sizeof(book));
	}
	return 0;
}