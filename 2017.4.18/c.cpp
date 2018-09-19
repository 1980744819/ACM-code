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
using namespace std;
int a[100005],b[100005];
int main(){
	int n,m;
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	b[0]=b[1];
	b[m+1]=b[m];
	int tmp,tm;
	int ans=0;
	for(i=1;i<=n;i++){
		tmp=lower_bound(b+1,b+1+m,a[i])-b;
		tm=min(abs(b[tmp]-a[i]),abs(b[tmp-1]-a[i]));
		ans=max(ans,tm);
	}
	printf("%d\n",ans);
    return 0;
}
