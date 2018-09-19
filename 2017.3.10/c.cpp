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
using namespace std;
const int MAXN=2010;
const int MAXM=400010;
const int INF=1<<30;
struct EDG{
    int to,next;
    int cap,flow;
    int d;
}edg[MAXM];
int eid,head[MAXN];
int gap[MAXN];
int dis[MAXN];
int cur[MAXN];
int pre[MAXN];
int D[MAXN],vis[MAXN],mindis;
void init(){
    eid=0;
    memset(head,-1,sizeof(head));
}
void addEdg(int u,int v,int rc=0){
    edg[eid].to=v;
    edg[eid].next=head[u];edg[eid].d=d;
    edg[eid].cap=1;
    edg[eid].flow=0;
    head[u]=eid++;
}
int main(){
    return 0;
}

