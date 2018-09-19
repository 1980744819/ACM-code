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
long long gcd(long long a,long long b){
    long long big = max(a, b);
    long long small = min(a, b);
    long long temp = big % small;
    return temp == 0 ? small : gcd(small, temp);
}
int main(){
    long long x,y;
    long long i,j,a,b,c,d,e,f;
    while(~scanf("%lld %lld",&x,&y)){
        a=gcd(x,y);//6
        x/=a;
        y/=a;
        while(gcd(a,x)!=1)x/=gcd(a,x);
        while(gcd(a,y)!=1)y/=gcd(a,y);
        if(x==1&&y==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

