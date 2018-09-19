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
const int maxn=1e7+5;
unsigned x,y,z;
unsigned a[maxn];
int b[110],c[110];
unsigned rng61(){
	unsigned t;
	x ^= x << 16;  
	x ^= x >> 5;
	x ^= x << 1;
	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;
	return z;
}
int od[110];
bool cmp(int x,int y){
	return b[x]<b[y];
}
unsigned ans[110];
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	int n,m;
	unsigned A,B,C;
	int kase=0;
	while(~scanf("%d %d %u %u %u",&n,&m,&A,&B,&C)){
		kase++;
		x = A, y = B, z = C;
		for(i=0;i<n;i++){
			a[i]=rng61();
			//printf("%d ",a[i]);
		}
		//printf("\n");
		for(i=0;i<m;i++){
			scanf("%d",&b[i]);
			od[i]=i;
		}
		sort(od,od+m,cmp);
		od[m]=m;
		b[m]=n;
		int now,last;
		last=b[od[m]];
		for(i=m-1;i>=0;i--){
			now=b[od[i]]; 
			if(now==last){
				ans[od[i]]=ans[od[i+1]];
			}
			else{
				nth_element(a,a+now,a+last);
				ans[od[i]]=a[now];
			}
			last=now;
		}
		printf("Case #%d:",kase);
		for(i=0;i<m;i++){
			printf(" %u",ans[i]);
		}
		printf("\n");
	}
	return 0;
}