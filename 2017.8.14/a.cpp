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
const int maxn=1e5+10;
int a[maxn],qmax[maxn],qmin[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int n,m,k;
	while(~scanf("%d %d %d",&n,&m,&k)){
		int head1,tail1,head2,tail2;
		int last=0;
		int ans=0;
		head1=tail1=head2=tail2=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			while(head1<tail1&&a[qmax[tail1-1]]<a[i])tail1--;
			while(head2<tail2&&a[qmin[tail2-1]]>a[i])tail2--;
			qmax[tail1++]=i;
			qmin[tail2++]=i;
			while(a[qmax[head1]]-a[qmin[head2]]>k){
				last=(qmax[head1]>qmin[head2]?qmin[head2++]:qmax[head1++]);
			}
			if(a[qmax[head1]]-a[qmin[head2]]>=m){
				ans=max(ans,i-last);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}	