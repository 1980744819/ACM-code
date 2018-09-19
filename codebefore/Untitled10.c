#include<stdio.h>
#include<string.h>
int min(int x,int y)
{
    return x<y?x:y;
}
int dp[5010],t[5010],f[5010],st[5010],sf[5010];
int main()
{
    //freopen("batch.in","r",stdin);
    //freopen("batch.out","w",stdout);
    int i,j,k,l,m,n,p,q,x,y,z,s;
    scanf("%d%d",&n,&s);
    for (i=1;i<=n;i++)
      scanf("%d%d",&t[i],&f[i]);
    for (i=n;i;i--)
    {
        st[i]=st[i+1]+t[i];
        sf[i]=sf[i+1]+f[i];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[n+1]=0;
    for (i=n;i;i--)
      for (j=i+1;j<=n+1;j++)
        dp[i]=min(dp[i],dp[j]+sf[i]*(st[i]-st[j]+s));
    printf("%d\n",dp[1]);
}
