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
    long long ans;
    while(~scanf("%lld",&n)){
        if(n<=2)
            ans=n;
        else if(n%2){
            ans=n*(n-1)*(n-2);
        }
        else{
            if(n%3){
                ans=n*(n-1)*(n-3);
            }
            else{
                ans=(n-1)*(n-2)*(n-3);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

