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
int a[200005],t[200005],r[200005];
int main(){
	int n,m;
	int i,j;
	int ma;
	scanf("%d %d",&n,&m);
	int ti,ri;
	int len=0;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d %d",&t[0],&r[0]);
	int las=0;
	for(i=1;i<m;i++){
		scanf("%d %d",&ti,&ri);
		if(ti==t[las]){
			if(ri>r[las]){
				r[las]=ri;
			}
		}
		else{
			las++;
			t[las]=ti;
			r[las]=ri;
		}
	}
	for(i=0;i<=las;i++){
		printf("%d %d\n",t[i],r[i]);
	}
	for(i=0;i<=las;i++){
		if(t[i]==1){
			sort(a,a+r[i]);
		}
		else{
			sort(a,a+r[i],greater<int>());
		}
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
    return 0;
}
