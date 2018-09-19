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
const int maxn=10005;
struct edge{
	int u,v;
	int w;
};
bool cmp(struct edge a,struct edge b){
	return a.w<b.w;
}
int f[maxn];
int getf(int num){
	if(f[num]!=num)
		return getf(f[num]);
	return num;
}
int main(){
	freopen("test.txt","r",stdin);
	// freopen("test.out","w",stdout);
	int n,m;
	struct edge edges[maxn];
	int ans,M;
	int count;
	while(~scanf("%d %d",&n,&m)){
		ans=0;
		M=0;
		count=0;
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=0;i<m;i++){
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			edges[i].u=u;
			edges[i].v=v;
			edges[i].w=w;
		}
		sort(edges,edges+m,cmp);
		// for(int i=0;i<m;i++){
		// 	printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].w);
		// }
		for(int i=0;i<m;i++){
			int u=edges[i].u;
			int v=edges[i].v;
			int w=edges[i].w;
			if(getf(u)!=getf(v)){
				f[getf(v)]=getf(u);
				ans+=w;
				M=max(M,w);
				count++;
				if(count==n-1){
				// printf("%d\n",M);
					break;
				}
			}
		}
		printf("%d\n",M);
	}
    return 0;
}
