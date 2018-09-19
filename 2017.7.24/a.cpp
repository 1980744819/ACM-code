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
using namespace std;
ll a[1005],b[1005];
ll gcd(ll num1,ll num2){
	if(num2==0)
		return num1;
	else return gcd(num2,num1%num2);
}
ll ex_gcd(ll num1,ll num2,ll &x,ll &y){
	if(num2==0){
		x=1;
		y=0;
		return num1;
	}
	ll d=ex_gcd(num2,num1%num2,x,y);
	ll t=x;
	x=y;
	y=t-num1/num2*y;
	return d;
}
ll inv(ll num1,ll num2){
	ll x,y;
	ll t=ex_gcd(num1,num2,x,y);
	if(t!=1)
		return -1;
	else
		return (x%num2+num2)%num2;
}
bool merage(ll a1,ll n1,ll a2,ll n2,ll &a3,ll &n3){
	ll d=gcd(n1,n2);
	ll c=a2-a1;
	if(c%d)
		return false;
	c=(c%n2+n2)%n2;
	c/=d;
	n1/=d;
	n2/=d;
	c*=inv(n1,n2);
	c%=n2;
	c*=n1*d;
	c+=a1;
	n3=n1*n2*d;
	a3=(c%n3+n3)%n3;
	return true;

}
ll China_reminder(int len,ll *a,ll *n){
	ll a1=a[0],n1=n[0];
	ll a2,n2;
	for(int i=1;i<len;i++){
		ll aa,nn;
		a2=a[i],n2=n[i];
		if(!merage(a1,n1,a2,n2,aa,nn))
			return -1;
		a1=aa;
		n1=nn;
	}
	return (a1%n1+n1)%n1;
}
int main(){
	//freopen("test.txt","r",stdin);
	int i,k;
	while(~scanf("%d",&k)){
		for(i=0;i<k;i++)
			scanf("%lld %lld",&a[i],&b[i]);
		printf("%lld\n",China_reminder(k,b,a));
	}
	return 0;
}