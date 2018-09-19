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
#define read(a) scanf("%d",&a)
#define ll long long
using namespace std;
const int maxn=2005;

int f[maxn],ran[maxn];
bool flag;
int find(int x){
	if(x==f[x])
		return f[x];
	int t=find(f[x]);
	ran[x]=(ran[f[x]]+ran[x])&1;
	f[x]=t;
	return f[x];
}
void merge(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a==b){
		if(ran[x]==ran[y]){
			flag=true;
		}
		return;
	}
	f[a]=b;
	ran[a]=(ran[x]+ran[y]+1)&1;
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int n,m;
	int i,j;
	read(t);
	int a,b;
	int ca=0;
	while(t--){
		read(n);
		read(m);
		for(i=0;i<=n;i++){
			f[i]=i;
			ran[i]=0;
		}
		flag=false;
		for(i=1;i<=m;i++){
			scanf("%d %d",&a,&b);
			if(flag)
				continue;
			merge(a,b);
		}
		printf("Scenario #%d:\n",++ca);
		if(flag){
			printf("Suspicious bugs found!\n");
		}
		else{
			printf("No Suspicious bugs found!\n");
		}
		printf("\n");
	}
	return 0;
}