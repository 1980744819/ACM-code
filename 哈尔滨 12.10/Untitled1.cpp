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


int ans,len;
long long one[20]={0,1,11,111,1111,11111,111111,1111111,11111111,111111111,
            1111111111LL,11111111111LL,111111111111LL,1111111111111LL,
            11111111111111LL,111111111111111LL,1111111111111111LL};
void dfs(long long x,int sum)
{
    int a,b;
    if(sum>=ans) return;
    if(x==0)
    {
        ans=sum;
        return;
    }
    if(x<0) x=-x;
    long long y=x;
    int t=0;
    while(y!=0){
        t++;
        y/=10;
    }
    long long reta=x,retb=one[t+1]-x;
    long long h=pow(10,t-1);
    int sa=0,sb=t+1;
    while(reta>=h) {
        reta-=one[t];
        sa+=t;
    }
    while(retb>=h){
        retb-=one[t];
        sb+=t;
    }
    dfs(reta,sum+sa);
    dfs(retb,sum+sb);
    return;
}

int main()
{
    long long x;
    while(scanf("%I64d",&x)!=EOF)
    {
        ans=1e9;
        dfs(x,0);
        printf("%d\n",ans);
    }
    return 0;
}
