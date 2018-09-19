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
const int maxn=1005;
int f[maxn];
int getf(int v){
	if(f[v]==v)
		return v;
	else{
		f[v]=getf(f[v]);
		return f[v];
	}
}
void merge(int v,int u){
	int t1,t2;
	t1=getf(v);
	t2=getf(u);
	if(t1!=t2){
		f[t2]=t1;
	}
}
int main(){
	//freopen("test.txt","r",stdin);
	int t;
	int n,m;
	int i,j;
	int a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++){
			f[i]=i;
		}
		for(i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			merge(a,b);
		}
		int ans=0;
		for(i=1;i<=n;i++){
			if(f[i]==i)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}