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
int main(){
	int dph[1005],dpl[1005];
	double height[1005];
	int n;
	int i,j;
	int m,u;
	int ans;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++){
			scanf("%lf",&height[i]);
		}
		ans=0;
		dph[0]=1;
		for(i=1;i<n;i++){
			m=0;
			for(j=0;j<i;j++){
				if(height[i]>height[j]&&dph[j]>m){
					m=dph[j];
				}
			}
			dph[i]=m+1;
		}
		dpl[n-1]=1;
		for(i=n-2;i>=0;i--){
			m=0;
			for(j=n-1;j>i;j--){
				if(height[i]>height[j]&&dpl[j]>m){
					m=dpl[j];
				}
			}
			dpl[i]=m+1;
		}
		ans=0;
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				ans=max(ans,(dph[i]+dpl[j]));
			}
		}
		printf("%d\n",n-ans);
	}
    return 0;
}
