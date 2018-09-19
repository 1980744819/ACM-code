#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long da[1000005];
int main(){
	int i,j;
	int n,q;
	long long num;
	int l,r,mid;
	freopen("D:\\4.in","r",stdin);
	freopen("D:\\4.out","w",stdout);
	while(~scanf("%d",&n)){
		//printf("%d\n",n);
		for(i=0;i<n;i++){
			scanf("%lld",&da[i]);
		}
		sort(da,da+n);
		// for(i=0;i<n;i++){
		// 	printf("%lld ",da[i]);
		// }
		scanf("%d",&q);
		//printf("%d\n",q);
		for(i=0;i<q;i++){
			scanf("%lld",&num);
			//printf("%lld\n",num);
			l=0;
			r=n-1;
			while(l<=r){
				mid=(l+r)/2;
				if(da[mid]==num){
					break;
				}
				else{
					if(da[mid]<num){
						l=mid+1;
					}
					else{
						r=mid-1;
					}
				}
			}
			printf("%d ",n-mid);
		}
		printf("\n");
	}
    return 0;
}
