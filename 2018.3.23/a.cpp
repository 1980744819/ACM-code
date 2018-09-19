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
char mv[105];
int main(){
	// freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	scanf("%s",mv);
	int i=1;
	int ans=n;
	while(i<n){
		if(mv[i]!=mv[i-1]){
			i+=2;
			ans--;
		}
		else{
			// ans++;
			i++;
		}
			
	}
	printf("%d\n",ans);
	return 0;
}