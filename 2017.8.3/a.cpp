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
const int maxn=2005;
int op[maxn],f[maxn];
int find(int x){
	if(x==f[x])
		return f[x];
	// int t=find(f[x]);
	// f[x]=t; 
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	// int a=find(x);
	// int b=find(y);
	// f[a]=b;
	f[find(x)]=find(y);
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int n,m;
	int i,j;
	int ca=0;
	int x,y;
	scanf("%d",&t);
	bool flag;
	while(t--){
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++){
			f[i]=i;
			op[i]=0;
		}
		flag=false;
		while(m--){
			scanf("%d %d",&x,&y);
			if(flag)
				continue;
			if(op[x]==0&&op[y]==0){
				op[x]=y;
				op[y]=x;
			}
			else if(op[x]==0&&op[y]!=0){
				op[x]=y;
				merge(x,op[y]);
			}
			else if(op[x]!=0&&op[y]==0){
				op[y]=x;
				merge(y,op[x]);
			}
			else{
				int a=find(x);
				int b=find(y);
				if(a==b){
					flag=true;
				}
				else{
					merge(x,op[y]);
					merge(y,op[x]);
				}
			}
		}
		printf("Scenario #%d:\n",++ca);
		if(!flag)
			printf("No suspicious bugs found!\n\n");
		else 
			printf("Suspicious bugs found!\n\n");
	}
	return 0;
}