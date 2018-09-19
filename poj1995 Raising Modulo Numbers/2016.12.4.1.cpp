#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int z;
    long long m;
    long long a,b,h;
    long long ans;
    long long res;
    scanf("%d",&z);
    while(z--){
        scanf("%lld %lld",&m,&h);
        long long i,j;
        res=0;
        for(i=0;i<h;i++){
            scanf("%lld %lld",&a,&b);
            ans=1;
            while(b){
                if(b&1){
                    ans=(ans*a)%m;
                    //b--;
                }
                b=b>>1;
                a=(a*a)%m;
            }
            res+=ans%m;
            res%=m;
        }
        printf("%lld\n",res);
    }
    return 0;
}

