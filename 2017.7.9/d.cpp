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
int c[1000][1000];
int qpow_mod(int a,int b,int mod){
    if(a==0)return 0;
    int ans=1;
    while(b){
        if(b&1)ans=(ans%mod)*(a%mod);//如果确定数据不会爆的话，可写成 ans*=a%=mod;
        b>>=1;a*=a%=mod;//等价于a=(a%mod)*(a%mod)，且将一个模运算通过赋值代替，提高了效率
    }
    return ans%mod;//数据不会爆的话，这里的%运算会等价于第5中不断重复的 ans%mod
}
int main(){
	freopen("test.txt","r",stdin);
	int i;
	int a,b;
	int mod=1000000007;
	int n;
	while(~scanf("%d",&n)){
		printf("%d\n",qpow_mod(2,n,mod)-1);
	}
	return 0;
}