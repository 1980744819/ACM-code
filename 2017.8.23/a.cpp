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
const int maxn=2e5+10;
int tem[maxn];
int cnt[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int n,k,q;
	while(~scanf("%d %d %d",&n,&k,&q)){
		int a,b;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&a,&b);
			//int c=b-a+1;
			tem[a]+=1;
			tem[b+1]-=1;		
		}
		for(int i=1;i<maxn;i++){
			tem[i]+=tem[i-1];
			if(tem[i]>=k)
				cnt[i]++;
		}
		for(int i=1;i<maxn;i++)
			cnt[i]+=cnt[i-1];
		for(int i=0;i<q;i++){
			scanf("%d %d",&a,&b);
			printf("%d\n",cnt[b]-cnt[a-1]);
		}
		memset(cnt,0,sizeof(cnt));
		memset(tem,0,sizeof(tem));
	}
	return 0;
}