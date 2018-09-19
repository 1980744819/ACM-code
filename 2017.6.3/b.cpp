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
int v[4005],d[4005],p[4005];
int a[4005];
int main(){
	int n;
	int i,j;
	int num;
	int tmp;
	int ans=0;
	int l;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++){
			scanf("%d %d %d",&v[i],&d[i],&p[i]);
		}
		i=0;
		ans=0;
		l=0;
		while(i<n){
			//printf("10000\n");
			if(p[i]>=0){
				ans++;
				a[l]=i;
				l++;
				tmp=v[i];
				j=i+1;
				while(tmp>0&&j<n){
					p[j]-=tmp;
					tmp--;
					j++;
				}
			}
			else{
				j=i+1;
				tmp=d[i];
				while(j<n){
					p[j]-=tmp;
					j++;
				}
			}
			i++;
		}
		printf("%d\n",ans);
		for(i=0;i<l;i++){
			printf("%d ",a[i]+1);
		}
		printf("\n");
	}
    return 0;
}
