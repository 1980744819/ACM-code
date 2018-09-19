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
long long gcd_(long long a, long long b){//递归版本  
  long long big = max(a, b);  
  long long small = min(a, b);  
  long long temp = big % small;  
  return temp == 0 ? small : gcd_(small, temp);  
} 
int main(){
	long long n,a,b,p,q;
	long long ans=0;
	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&p,&q);
	ans+=n/a*p;
	ans+=n/b*q;
	long long tmp=a*b/(gcd_(a,b));
	long long tm=n/tmp;
	if(p>q){
		ans-=tm*q;
	}
	else{
		ans-=tm*p;
	}
	printf("%lld\n",ans);
    return 0;
}
