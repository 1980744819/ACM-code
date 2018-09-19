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
	long long a;
	scanf("%lld",&a);
	long long b,c;
	long long n;
	if(a%2==1&&a>1){
		n=(a-1)/2;
		b=n*n*2+2*n;
		c=b+1;
	}
	else if(a%2==0&&a>4){
		n=a/2;
		b=n*n-1;
		c=b+2;
	}
	else{
		if(a==4){
			b=3;
			c=5;
		}
	}
	if(a==1||a==2){
		printf("-1\n");
	}
	else{
		printf("%lld %lld\n",b,c);
	}
    return 0;
}
