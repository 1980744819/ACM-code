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
long long gcd(long long x,long long y){  
    if(y==0) return x;  
    else return(gcd(y,x%y));  
}  
  
long long lcm(long long x,long long y){  
    return x*y/gcd(x,y);  
}
int main(){
	long long a1,b1,a2,b2,l,r;
	long long L,R;
	long long la,ra,lb,rb;
	long long i,j;
	scanf("%lld %lld %lld %lld %lld %lld",&a1,&b1,&a2,&b2,&l,&r);
	la=l-b1;
	ra=r-b1;
	lb=l-b2;
	rb=r-b2;
	if(la<lb)
		L=lb;
	else 
		L=la;
	if(ra<rb)
		R=ra;
	else
		R=rb;
	//printf("%d %d\n",L,R);
	long long tmp=lcm(a1,a2);
	//printf("%d\n",tmp);
	long long ans=R/tmp-(L-1)/tmp;
	printf("%d\n",ans);
    return 0;
}
