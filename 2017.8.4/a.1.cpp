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
#define read(a) scanf("%d",&a);
using namespace std;
const int maxn=50005;
int f[maxn];
int ran[maxn];
int find(int x){
	if(x==f[x])
		return f[x];
	int t=find(f[x]);
	ran[x]=(ran[x]+ran[f[x]])%3;
	return f[x]=t;
}
int merge(int type,int x,int y){
	int a=find(x);
	int b=find(y);
	if(a==b){
		if((ran[x]-ran[y]+3)%3!=type-1)
			return 1;
		return 0;
	}
	f[a]=b;
	ran[a]=(-ran[x]+ran[y]+type-1+3)%3;
	return 0;
}
int main(){
	freopen("test.txt","r",stdin);
	int n,k;
	int i,j;
	int x,y;
	int type;
	int ans;
	while(~scanf("%d %d",&n,&k)){
		for(i=1;i<=n;i++){
			f[i]=i;
			ran[i]=0;
		}
		ans=0;
		int a,b;
		while(k--){
			scanf("%d %d %d",&type,&x,&y);
			if(x>n||y>n){
				ans++;
			}
			else if(x==y&&type==2){
				ans++;
			}
			else{
				ans+=merge(type,x,y);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}