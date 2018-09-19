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
//#define long long ll
using namespace std;
const long long mod=1e9+7; 
int f[1000];
int main(){
	freopen("test.txt","r",stdin);
	f[1]=1;
	f[2]=1;
	int i,j;
	for(i=3;i<1000;i++){
		f[i]=f[i-1]%mod+2*f[i-2]%mod;
		f[i]%=mod;
		printf("%d %d\n",i,f[i]);
	}
	return 0;
}