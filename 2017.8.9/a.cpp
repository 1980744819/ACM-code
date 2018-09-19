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
const int maxn=10005;
ll a[maxn],b[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<=m;i++){
			scanf("%lld",&b[i]);
		}
		int cnt=0;
		int i=1;
		while(i<=m){
			while(b[i]>0){
				a[++cnt]=i;
				b[i]--;
				for(int j=i+1;j<=m;j++){
					if(b[j]>0)
						b[j]-=b[j-i];
				}
			}
			i++;
		}
		for(i=1;i<=cnt;i++){
			if(i>1)
				printf(" ");
			printf("%lld",a[i]);
		}
		printf("\n");
	}
	return 0;
}