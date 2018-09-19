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
int main(){
	freopen("test.txt","r",stdin);
	for(ll i=1;i<100000000;i++){
		ll tmp=(i+1)*i/2;
		//printf("%lld : %lld\n",i,tmp);
		ll num=sqrt(tmp);
		if(num*num==(tmp)){
			printf("%lld : %lld %lld\n",i,num,tmp);
		}
	}
	return 0;
}