#include<stdio.h>
int vist[105],node[105][105],len[105],val[105],step;
int dp[2][105][205];//dp[1][p][k]表示用k步（k仅仅只用于以节点p为根的子树，不包含从p的父节点走到p的步数）（最终）人还在节点p（根节点是相对于子节点而言）
int max(int a,int b)
{
    return a>b?a:b;
}
void dfs(int p)
{
    for(int i=0;i<=step;i++)//注意从0开始
    dp[0][p][i]=dp[1][p][i]=val[p];
    vist[p]=1;
    for(int i=1;i<=len[p];i++)
    {
        int son=node[p][i];
        if(vist[son])continue;
        dfs(son);

        for(int s=step;s>=1;s--)//以p为根的子树固定步数s
        for(int st=0;st<=s-1;st++)//子节点（树）的步数st
        {
            if(s-st-2>=0)
           {
               dp[1][p][s]=max(dp[1][p][s],dp[1][p][s-st-2]+dp[1][son][st]);
               dp[0][p][s]=max(dp[0][p][s],dp[0][p][s-(st+2)]+dp[1][son][st]);//(st+2)表示的是能从p到son，并从son到p
           //(这里面减2是为了保证连续性，)遍历了son以前的子节点中其中一个没有反回根节点，但必须保证能从son节点反回根节点p,所以最终没回到p
           }
           dp[0][p][s]=max(dp[0][p][s],dp[1][p][s-st-1]+dp[0][son][st]);//同样要保证连续性,跟上述同理
        }

    }
}
int main()
{
    int n,a,b,max;
    while(scanf("%d%d",&n,&step)>0)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
            len[i]=0,vist[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            len[a]++; node[a][len[a]]=b;
            len[b]++; node[b][len[b]]=a;
        }
        dfs(1);
        max=dp[0][1][step];
        if(max<dp[1][1][step])
        max=dp[1][1][step];

        printf("%d\n",max);
    }
}
