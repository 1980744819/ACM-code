#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[(1<<20)+2];//1:Ê¤;0£º¸º
int a[25],n;
bool mark[25];
int update(int state,int k)
{
    int st=state^(1<<k),p=a[k],t;
    mark[p]=false;
    for(int i=0;i<n;i++)
    {
        if(st&(1<<i))
        {
            t=a[i]-p;
            if(t>1&&!mark[t])
            {
                mark[a[i]]=false;
                st^=(1<<i);
            }
        }
    }
    return st;
}
void resume(int state,int org)
{
    for(int i=0;i<n;i++)
    {
        int t=1<<i;
        if(!(state&t)&&(org&t))
            mark[a[i]]=true;
    }
}
int dfs(int state)
{
    if(dp[state]!=-1)
        return dp[state];
    for(int i=0;i<n;i++)
    {
        if(state&(1<<i))
        {
            int st=update(state,i);
            if(dfs(st)==0)
            {
                resume(st,state);
                return dp[state]=1;
            }
            resume(st,state);
        }
    }
    return dp[state]=0;
}
int main()
{
    int ca=0;
    while(scanf("%d",&n),n)
    {
        int state=0;
        memset(mark,false,sizeof(mark));
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]),mark[a[i]]=true,state|=(1<<i);
        sort(a,a+n);
        int top=0,ans[25];
        for(int i=0;i<n;i++)
        {
            int st=update(state,i);
            if(dfs(st)==0)
                ans[top++]=a[i];
            resume(st,state);
        }
        printf("Test Case #%d\n",++ca);
        if(top==0)
            printf("There's no winning move.\n\n");
        else
        {
            printf("The winning moves are:");
            for(int i=0;i<top;i++)
                printf(" %d",ans[i]);
            printf("\n\n");
        }
    }
    return 0;
}
