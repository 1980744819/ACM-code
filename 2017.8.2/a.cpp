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
const int maxn=500005;
int a[maxn];
int l[100],r[100];
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int i,j;
	int n;
	int k;
	int lcnt,rcnt;
	read(t);
	//printf("%d\n",t);
	while(t--){
		read(n);
		read(k);
		ll ans=0;
		for(i=1;i<=n;i++){
			read(a[i]);
		}
		for(i=1;i<=n;i++){
			lcnt=1;
			rcnt=1;
			for(j=i+1;j<=n;j++){
				if(rcnt>k)
					break;
				if(a[j]>a[i]){
					r[rcnt]=j-i;
					rcnt++;
				}
			}
			if(j>=n+1)
				r[rcnt]=n+1-i;
			for(j=i-1;j>=1;j--){
				if(lcnt>k)
					break;
				if(a[j]>a[i]){
					l[lcnt]=i-j;
					lcnt++;
				}
			}
			if(j<=0)
				l[lcnt]=i;
			//printf("%d %d\n",lcnt,rcnt);
			for(j=0;j<lcnt;j++){
				if(k-j-1>=rcnt)
					continue;
				int lnum=l[j+1]-l[j];
				int rnum=r[k-j]-r[k-j-1];
				//printf("%d %d\n",lnum,rnum);
				ans+=(ll)a[i]*lnum*rnum;
			}
			//printf("%lld\n",ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}