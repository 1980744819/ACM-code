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
int a[1000005];
long long b[1000005],c[1000005];
int main(){
	freopen("test.txt","r",stdin);
	int m,n;
	int i,j;
	long long Min;
	while(~scanf("%d %d",&m,&n)){
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(i=1;i<=m;i++){
			Min=-9999999999;
			for(j=i;j<=n;j++){
				b[j]=max(b[j-1]+a[j],c[j-1]+a[j]);
				c[j-1]=Min;
				Min=max(b[j],Min);
			}
		}
		printf("%lld\n",Min);
	}
	return 0;
}