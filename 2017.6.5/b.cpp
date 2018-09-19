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
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
	int n;
	int i,j;
	int a[250005],b[250005];
	int tmp;
	while(~scanf("%d",&n)){
		map<int,int>mp;
		for(i=0;i<n*n;i++){
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		sort(a,a+n*n);
		int sum=0;
		int p=0;
		for(i=n*n-1;i>=0;i--){
			if(sum==n){
				break;
			}
			if(mp[a[i]]==0){
				continue;
			}
			else{
				mp[a[i]]--;
				b[p]=a[i];
				for(j=0;j<p;j++){
					tmp=gcd(b[j],a[i]);
					mp[tmp]-=2;
				}
				p++;
				sum++;
			}
		}
		for(i=0;i<n;i++){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
    return 0;
}
