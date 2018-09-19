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
#define ll long long
using namespace std;
const int maxn=10000;
int main(){
	freopen("test.txt","r",stdin);
	//freopen("test.out","w",stdout);
	unsigned ll num=(unsigned ll)1<<62;
	//printf("%llu\n",num);
	int t;
	scanf("%d",&t);
	while(t--){
		unsigned ll a,b,c,d;
		scanf("%llu %llu %llu %llu",&a,&b,&c,&d);
		if(a==num&&b==num&&c==num&&d==num)
			printf("18446744073709551616\n");
		else{
			//unsigned ll ans =(unsigned ll)a+(unsigned ll)b+(unsigned ll)c+(unsigned ll)d;
			printf("%llu\n",a+b+c+d);
		}
	}
    return 0;
}
