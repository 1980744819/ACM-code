#include<stdio.h>
int vist[105],node[105][105],len[105],val[105],step;
int dp[2][105][205];//dp[1][p][k]��ʾ��k����k����ֻ�����Խڵ�pΪ������������������p�ĸ��ڵ��ߵ�p�Ĳ����������գ��˻��ڽڵ�p�����ڵ���������ӽڵ���ԣ�
int max(int a,int b)
{
    return a>b?a:b;
}
void dfs(int p)
{
    for(int i=0;i<=step;i++)//ע���0��ʼ
    dp[0][p][i]=dp[1][p][i]=val[p];
    vist[p]=1;
    for(int i=1;i<=len[p];i++)
    {
        int son=node[p][i];
        if(vist[son])continue;
        dfs(son);

        for(int s=step;s>=1;s--)//��pΪ���������̶�����s
        for(int st=0;st<=s-1;st++)//�ӽڵ㣨�����Ĳ���st
        {
            if(s-st-2>=0)
           {
               dp[1][p][s]=max(dp[1][p][s],dp[1][p][s-st-2]+dp[1][son][st]);
               dp[0][p][s]=max(dp[0][p][s],dp[0][p][s-(st+2)]+dp[1][son][st]);//(st+2)��ʾ�����ܴ�p��son������son��p
           //(�������2��Ϊ�˱�֤�����ԣ�)������son��ǰ���ӽڵ�������һ��û�з��ظ��ڵ㣬�����뱣֤�ܴ�son�ڵ㷴�ظ��ڵ�p,��������û�ص�p
           }
           dp[0][p][s]=max(dp[0][p][s],dp[1][p][s-st-1]+dp[0][son][st]);//ͬ��Ҫ��֤������,������ͬ��
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
