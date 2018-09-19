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
long long mod=1000000007;
long long solve(long long u,long long v){
    long long re=1;
    while(v){
        if(v&1){
            re=re*u%mod;
        }
        u=u*u%mod;
        v>>=1;
    }
    return re;
}
int main(){
    long long ans;
    long long n;
    long long num;
    while(~scanf("%lld",&n)){
        while(n--){
            scanf("%lld",&num);
            printf("%lld\n",solve(2,num-1)-1);
        }
    }
    return 0;
}

