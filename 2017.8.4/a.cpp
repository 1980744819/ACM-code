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
			if(x>=n+1||y>=n+1){
				ans++;
				continue;
			}
			a=find(x);
			b=find(y);
			if(type==1){
				if(a==b){
					if((ran[x]-ran[y]+3)%3!=type-1)
						ans++;
				}
				else{
					f[a]=b;
					ran[a]=(-ran[x]+ran[y]+3+type-1)%3;
				}
			}
			else{
				if(x==y){
					ans++;
				}
				else{
					if(a==b){
						if((ran[x]-ran[y]+3)%3!=type-1)
							ans++;
					}
					else{
						f[a]=b;
						ran[a]=(-ran[x]+ran[y]+type-1+3)%3;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}