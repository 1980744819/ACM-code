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
long long a[100005];
long long gcd(long long m,long long n){
	if(n==0){
		return m;
	}
	else{
		return gcd(n,m%n);
	}
}
int main(){
	int n;
	int i,j;
	int flag;
	long long num;
	long long tmp1,tmp2;
	while(~scanf("%d",&n)){
		num=1;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			//tmp1=num*a[i];
			//num=gcd(num,a[i]);
			//num=tmp1/tmp2;
		}
		num=a[0];
		for(i=1;i<n;i++){
			num=gcd(num,a[i]);
		}
		//printf("%lld\n",num);
		for(i=0;i<n;i++){
			a[i]=a[i]/num;
			//printf("%lld ",a[i]);
		}
		flag=0;
		for(i=0;i<n;i++){
			while(a[i]%2==0)a[i]/=2;
			while(a[i]%3==0)a[i]/=3;
			if(a[i]!=1){
				flag=1;
				printf("No\n");
				break;
			}
		}
		if(flag==0){
			printf("Yes\n");
		}
	}
    return 0;
}
