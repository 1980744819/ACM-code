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
const int maxn=50005;
int f[maxn],pre[maxn],nxt[maxn];
int find(int x){
	if(x==f[x])
		return f[x];
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
int main(){
	freopen("test.txt","r",stdin);
	int n,k;
	int i,j;
	int num,x,y;
	int ans;
	while(~scanf("%d %d",&n,&k)){
		for(i=1;i<=n;i++){
			f[i]=i;
			pre[i]=0;
			//nxt[i]=0;
		}
		ans=0;
		while(k--){
			scanf("%d %d %d",&num,&x,&y);
			if(x>n||y>n){
				ans++;
				continue;
			}
			int a=find(x);
			int b=find(y);
			if(num==1){
				if(a==b){
					ans++;
					printf("%d %d %d\n",num,x,y);
				}
				else{
					f[a]=b;
				}
			}
			else{
				if(a==b||x==y){
					ans++;
					printf("%d %d %d\n",num,x,y);
				}
				else{
					if(nxt[x]==0&&pre[y]==0){
						nxt[x]=y;
						pre[y]=x;
					}
					else if(nxt[x]==0&&pre[y]!=0){
						nxt[x]=y;
						merge(x,pre[y]);
					}
					else if(nxt[x]!=0&&pre[y]==0){
						pre[y]=x;
						merge(y,nxt[x]);
					}
					else{
						merge(x,pre[y]);
						merge(y,nxt[x]);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}