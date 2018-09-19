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
    long long n;
    int t;
    long long i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        int coun;
        long long ans=0;
        //printf("%d\n",coun);
        while(n){
            n/=2;
            ans+=n;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
