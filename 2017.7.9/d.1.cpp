#include <iostream>
#include <cstdio>

using namespace std;
typedef  long long ll;
const int maxn=1000;
ll mod;int n;
ll c[100000005],A[100000005];
void init(){
    A[1]=1;
    ll p=mod;
        //线性求逆元
    for(int i=2;i<=n;++i){
        A[i] = ((p-(p / i)) * A[p % i]%p+p)%p;
    }
    c[0]=1;
    printf("1->");
    for(int i=1;i<=n;++i){
               //先c[i-1]*(n-i+1),否则c[i-1]可能不整除i
        c[i]=(((c[i-1]*(n-i+1)%p)*A[i]))%p;
        printf("%lld->",c[i]);
    }
    printf("\n");
}
int main(){
    while(~scanf("%d",&n)){
        mod=1e9+7;
        init();
    }
    return 0;
}