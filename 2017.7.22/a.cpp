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
using namespace std;
long long gcd(long long a,long long b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
// long long exgcd(long long a,long long b,long long &x,long long &y){
// 	if(b==0){
// 		x=1;
// 		y=0;
// 		return a;
// 	}
// 	long long r=exgcd(b,a%b,x,y);
// 	long long t=x;x=y;y=t-a/b*y;
// 	return r;
// }
long long exgcd(long long a, long long b, long long &d, long long &x, long long &y)
{
    if(!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        exgcd(b, a%b, d, y, x);
        y -= x * (a / b);
    }
}
int main(){
	//freopen("test.txt","r",stdin);
	long long i,j;
	long long a,b,n;
	long long x,y;
	long long t;
	long long GCD;
	long long ans;
	long long x_,y_;
	scanf("%lld",&t);
	long long MI,MA;
	long long k;
	long long num;
	while(t--){
		scanf("%lld %lld %lld",&n,&a,&b);
		exgcd(a,b,GCD,x,y);
		n++;
		//GCD=gcd(a,b);
		//printf("%d\n",gcd(a,b));
		k=n/GCD;
		if(n%GCD!=0){
			printf("0\n");
			continue;
		}
		// n/=GCD;
		// a/=GCD;
		// b/=GCD;
		// exgcd(a,b,x,y);
		// printf("%d %d\n",x,y);
		// MI=n*x/b;
		// MI=0-MI;
		// MA=n*y/a;
		// printf("%d %d ",MA,MI);
		// printf("%lld\n",MA-MI>0?MA-MI:0);
		else
        {
            long long bl = b / GCD, al = a /GCD;
            long long xm = (x*k%bl + bl) % bl;
            long long lc = a * b / GCD;
            if(xm == 0)
            {
                xm = bl;
            }
            num = 0;
            long long remain = n - 1 - xm * a;
            if(remain >= 0)
            {
                num = 1;
                num += remain / lc;
            }
        }
        printf("%lld\n", num);
	}
	return 0;
}