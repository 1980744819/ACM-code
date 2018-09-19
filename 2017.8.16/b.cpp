#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll h;
ll ans;
ll ss[110];
ll qpow(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a;
        a*=a;
        b>>=1;
    }
    return res;

}

ll dfs(ll sum,ll dep,ll k)
{
    ss[dep]=sum;
    if(sum+qpow(k,dep+1)>=n)
    {
        ll res=n-sum;
        ans^=(res%2);
        ll hh=res;
        h++;
        ll beishu=qpow(k,h);
        ll no=hh/beishu;
        ll yu=hh%beishu;
        ll zong=qpow(k,dep);
        if(yu){
            zong=zong-no-1;
            ll summ=0;
            summ=(zong%2)*(ss[h-1]);
            ans^=summ;
            ll sum1=(no%2)*(ss[h]);
            ans^=sum1;
            ll sum3=0;
            sum3=(ss[h-1])+res%beishu;
            ans^=sum3;
        }
        else
        {
            zong=zong-no;
            ll summ=0;
            summ=(zong%2)*(ss[h-1]);
            ans^=summ;
            ll sum1=(no%2)*(ss[h]);
            ans^=sum1;
        }
    return res;
    }
    ll res=dfs(sum+qpow(k,dep+1),dep+1,k);
    ll hh=res;
    h++;
    ll bei=qpow(k,h);
    ll no1=hh/bei;
    ll yu1=hh%bei;
    ll zong1=qpow(k,dep);
    if(yu1){
        zong1=zong1-no1-1;
        ll summ1=0;
        summ1=(zong1%2)*(ss[h-1]);
        ans^=summ1;
        ll sum11=(no1%2)*(ss[h]);
        ans^=sum11;
        ll sum33=0;
        sum33=(ss[h-1])+res%bei;
        ans^=sum33;
    }
    else
    {
        zong1=zong1-no1;
        ll summ1=0;

        summ1=(zong1%2)*(ss[h-1]);
        ans^=summ1;
        ll sum11=(no1%2)*(ss[h]);
        ans^=sum11;
    }
    return res;
}


ll xor_n(ll n)
{
    ll tt = n&3;
    if(tt&1) return tt/2ll^1;
    return tt/2ll^n;
}

int main()
{
    freopen("test.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        ans=0;
        h=0;
        scanf("%lld%lld",&n,&k);
        if(k==1)
        { 
        printf("%lld\n",xor_n(n));
        continue;
        }
        dfs(1,0,k);
        printf("%lld\n",ans);
    }
    return 0;
}