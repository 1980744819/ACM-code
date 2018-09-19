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
long long b,d,s;
int main(){
    scanf("%lld %lld %lld",&b,&d,&s);
    long long ans=0;
    if(b>=d&&b>=s){
        b--;
        if(b>d)
            ans+=b-d;
        if(b>s)
            ans+=b-s;
    }
    else if(d>=b&&d>=s){
        d--;
        if(d>b)
            ans+=d-b;
        if(d>s)
            ans+=d-s;
    }
    else if(s>=b&&s>=d){
        s--;
        if(s>b)
            ans+=s-b;
        if(s>d)
            ans+=s-d;
    }
    printf("%lld\n",ans);
    return 0;
}

