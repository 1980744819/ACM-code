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
	map<long long ,int>mp;
	int a[100005];
	int n;
	long long sum=0;
	int ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	mp[0]=1;
	for(int i=1;i<n;i++){
		sum+=a[i];
		mp[sum]++;
		if(ans<=mp[sum])
			ans=mp[sum];
	}
	printf("%d\n",n-ans);
    return 0;
}
