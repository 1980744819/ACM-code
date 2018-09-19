#include <bits/stdc++.h>
/*#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>
*/
using namespace std;
#define Riep(n) for(int i=1;i<=n;i++)
#define Riop(n) for(int i=0;i<n;i++)
#define Rjep(n) for(int j=1;j<=n;j++)
#define Rjop(n) for(int j=0;j<n;j++)
#define mst(ss,b) memset(ss,b,sizeof(ss));
typedef long long LL;
template<class T> void read(T&num) {
    char CH; bool F=false;
    for(CH=getchar();CH<'0'||CH>'9';F= CH=='-',CH=getchar());
    for(num=0;CH>='0'&&CH<='9';num=num*10+CH-'0',CH=getchar());
    F && (num=-num);
}
int stk[70], tp;
template<class T> inline void print(T p) {
    if(!p) { puts("0"); return; }
    while(p) stk[++ tp] = p%10, p/=10;
    while(tp) putchar(stk[tp--] + '0');
    putchar('\n');
}

const LL mod=1e9+7;
const double PI=acos(-1.0);
const LL inf=1e10;
const int N=1e5+15;
char s[N];
int check(int x)
{
    if(s[x]>='0'&&s[x]<='9')return s[x]-'0';
    else if(s[x]>='a'&&s[x]<='z')return s[x]-'a'+36;
    else if(s[x]>='A'&&s[x]<='Z')return s[x]-'A'+10;
    else if(s[x]=='-')return 62;
    else if(s[x]=='_')return 63;
}
int fun(int x)
{
    int num=0;
    int cnt=6;
    while(cnt--)
    {
        if(x%2==0)num++;
        x=(x>>1);
    }
    return num;
}
LL fastpow(int y)
{
    LL ans=1,base=3;
    while(y)
    {
        if(y&1)
        {
            ans=ans*base;
            ans%=mod;
        }
        base=base*base;
        base%=mod;
        y=(y>>1);
    }
    return ans;
}


int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int sum=0;
    for(int i=0;i<len;i++)
    {
        int x=check(i);
        printf("%d\n",x);
        sum=sum+fun(x);
    }
    print(fastpow(sum));
    return 0;
}