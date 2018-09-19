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
const int maxn=1e5+5;
using namespace std;
char tmp[105];
bool judge(int n,int x){
	for(int i=0;i<x;i++){
		if(tmp[i]!=tmp[i+x])
			return false;
	}
	return true;
}
int main(){
	freopen("test.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		scanf("%s",tmp);
		int ans=0;
		// printf("%s\n",tmp);
		for(int i=1;i<=n/2;i++){
			if(judge(n,i))
				ans=max(ans,i);
		}
		printf("%d\n",ans==0?n:n-ans+1);
	}
	return 0;
}