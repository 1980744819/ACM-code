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
char c[100005];
int pa[100005],pb[100005];
int main(){
	int n,k;
	int i,j;
	scanf("%d %d",&n,&k);
	int left,right;
	getchar();
	for(i=1;i<=n;i++){
		scanf("%c",&c[i]);
		if(c[i]=='a')
			pa[i]=pa[i-1]+1;
		else
			pa[i]=pa[i-1];
		if(c[i]=='b')
			pb[i]=pb[i-1]+1;
		else
			pb[i]=pb[i-1];
	}
	left=1;
	right=1;
	int ans=0;
	while(right<=n){
		while(pa[right]-pa[left-1]<=k&&right<=n){
			right++;
		}
		ans=max(ans,right-left);
		left++;
	}
	left=right=1;
	while(right<=n){
		while(pb[right]-pb[left-1]<=k&&right<=n){
			right++;
		}
		ans=max(ans,right-left);
		left++;
	}
	printf("%d\n",ans);
    return 0;
}
