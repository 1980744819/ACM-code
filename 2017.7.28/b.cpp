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
bool book[maxn],line[maxn][maxn];
int part[maxn];
int n,k;
bool found(int x){
	for(int i=1;i<=n;i++){
		if(line[x][i]&&!book[i]){
			book[i]=true;
			if(part[i]==-1||found(part[i])){
				part[x]=i;
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
	while(~scanf("%d %d",&k,&n)){
		memset(line,false,sizeof(line));
		memset(part,-1,sizeof(part));
		for(i=0;i<n;i++){
			scanf("%d %d",&x,&y);
			line[x][y]=true;
		}
		ans=0;
		for(i=1;i<=n;i++){
			memset(book,false,sizeof(book));
			if(found(i))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}				