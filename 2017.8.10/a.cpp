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
#define ll long long
#define read(a) scanf("%d",&a);
using namespace std;
const int maxn=1e5+5;
const int inf=99999999;
int n;
int a[maxn],g[maxn],d[maxn];
int main(){
	freopen("test.txt","r",stdin);
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			printf("%d ",a[i]);
			g[i]=inf;
		}
		printf("\n");	
		for(int i=1;i<=n;i++){
			int k=lower_bound(g+1,g+n+1,a[i])-g;
			d[i]=k;
			g[k]=a[i];
		}
		for(int i=1;i<=n;i++)
			printf("%d ",d[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
			printf("%d ",g[i]);
		printf("\n");	
	}
	return 0;
}