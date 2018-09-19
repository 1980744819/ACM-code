#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF=(1<<20)-1;
int f[81][1<<9][21]={0};//第i行状态为s[j],前i行放k个棋子的方案数。
int s[1<<9];//各种状态
int c[1<<9];//每种状态对应得1的个数
int n,m,maxn=0,count1=0,num=0;//n行，m列

void dfs(int state,int p,int count1)//当前状态，位置，1的个数
{
    if(p>m)//列从右向左走完了（即每一列都有相应的方案了）
    {
        num++;
        s[num]=state;
        c[num]=count1;
        return ;//返回上一个位置执行下一种方案。
    }
    dfs(state,p+1,count1);//当前位置不放
    dfs(state+(1<<(p-1)),p+2,count1+1);//当前位置放，放了之后下一个位置就不能放了。
}

int main()
{
    int i,j,k,t;
    while(~scanf("%d%d%d",&n,&m,&maxn)){
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        memset(c,0,sizeof(c));
        if(m>n) swap(n,m);//让列成为小的那个
        dfs(0,1,0);//全不放，从第一列开始，1的个数是0
        for(i=1;i<=num;++i)
            f[1][s[i]][c[i]]=1;//第一行使用状态s[i]，放了count[i]个棋子。是一种方案

        for(i=2;i<=n;++i)//前2-n行
        {
            for(j=1;j<=num;++j)//当前行的状态
            {
                for(k=1;k<=num;++k)//上一行状态
                {
                    if((s[j]&s[k])||((s[j]>>1)&s[k])||((s[j]<<1)&s[k]))continue;
                        for(t=0;t<=maxn;++t)//前i行放了几个棋子
                        {
                            if(t>=c[j])//到当前行为止放的棋子总数要不小于选择当前状态放会添加的棋子数。
                                f[i][s[j]][t] += f[i-1][s[k]][t-c[j]];
                        }
                }
            }
        }
        long long ans=0;
        for(i=1;i<=num;++i){
            ans+=f[n][s[i]][maxn];
        }//前n行放k个棋子，第n行选择状态s[i]的方案数相加
        ans%=200640345;
        printf("%lld\n",ans);
    }
    return 0;
}
