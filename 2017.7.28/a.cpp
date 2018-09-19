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
const int maxn=505;
int k,m,n;
bool book[maxn];
bool line[maxn][maxn];
int girl[maxn];
bool found(int x){
	for(int i=1;i<=n;i++){
		if(line[x][i]&&!book[i]){
			book[i]=true;
			if(girl[i]==-1||found(girl[i])){
				girl[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	int x,y;
	int ans;
	while(~scanf("%d",&k)&&k){
		scanf("%d %d",&m,&n);
		memset(book,false,sizeof(book));
		memset(girl,-1,sizeof(girl));
		memset(line,false,sizeof(line));
		for(i=0;i<k;i++){
			scanf("%d %d",&x,&y);
			line[x][y]=true;
		}
		ans=0;
		for(i=1;i<=m;i++){
			memset(book,false,sizeof(book));
			if(found(i))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}