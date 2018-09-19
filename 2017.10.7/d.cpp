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
#define ll long long
using namespace std;
const   int oo=1e9;  
const   int mm=11111111;  
const   int mn=888888;  
int node,src,dest,edge;  
int ver[mm],flow[mm],cost[mm],nex[mm];  
int head[mn],dis[mn],p[mn],q[mn],vis[mn];  
/**这些变量基本与最大流相同，增加了 
 cost 表示边的费用， 
 p 记录可行流上节点对应的反向边 
 */  
void prepare(int _node,int _src,int _dest)  
{  
    node=_node,src=_src,dest=_dest;  
    for(int i=0; i<node; i++)head[i]=-1,vis[i]=0;  
    edge=0;  
}  
void addedge(int u,int v,int f,int c)  
{  
    ver[edge]=v,flow[edge]=f,cost[edge]=c,nex[edge]=head[u],head[u]=edge++;  
    ver[edge]=u,flow[edge]=0,cost[edge]=-c,nex[edge]=head[v],head[v]=edge++;  
}  
/**以上同最大流*/  
/**spfa 求最短路，并用 p 记录最短路上的边*/  
bool spfa()  
{  
    int i,u,v,l,r=0,tmp;  
    for(i=0; i<node; ++i)dis[i]=oo;  
    dis[q[r++]=src]=0;  
    p[src]=p[dest]=-1;  
    for(l=0; l!=r; (++l>=mn)?l=0:l)  
        for(i=head[u=q[l]],vis[u]=0; i>=0; i=nex[i])  
            if(flow[i]&&dis[v=ver[i]]>(tmp=dis[u]+cost[i]))  
            {  
                dis[v]=tmp;  
                p[v]=i^1;  
                if(vis[v]) continue;  
                vis[q[r++]=v]=1;  
                if(r>=mn)r=0;  
            }  
    return p[dest]>-1;  
}  
/**源点到汇点的一条最短路即可行流，不断的找这样的可行流*/  
int SpfaFlow()  
{  
    int i,ret=0,delta;  
    while(spfa())  
    {  
        for(i=p[dest],delta=oo; i>=0; i=p[ver[i]])  
            if(flow[i^1]<delta)delta=flow[i^1];  
        for(i=p[dest]; i>=0; i=p[ver[i]])  
            flow[i]+=delta,flow[i^1]-=delta;  
        ret+=delta*dis[dest];  
    }  
    return ret;  
}  
int main(){
    freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        int
    }
    return 0;
}