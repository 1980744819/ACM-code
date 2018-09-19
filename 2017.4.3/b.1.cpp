#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    ll b,d,s;
    while(~scanf("%I64d%I64d%I64d",&b,&d,&s))
    {
        ll ans=0;
        if(b>=d&&b>=s)
        {
            b--;
            if(b>d) ans+=b-d;
            if(b>s) ans+=b-s;
        }
        else if(d>=b&&d>=s)
        {
            d--;
            if(d>b) ans+=d-b;
            if(d>s) ans+=d-s;
        }
        else if(s>=b&&s>=d)
        {
            s--;
            if(s>b) ans+=s-b;
            if(s>d) ans+=s-d;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
