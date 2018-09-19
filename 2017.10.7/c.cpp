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
const int N = 105, M = 50000;
const int INF = 1e9;
const double eps = 1e-7;
int q[1000000];
struct Node{
    int u, v, cap;
    double cost;
    int next;
}edge[M];
int tot;
int head[N], pre[N], path[N];
double dis[N];
bool inq[N];
void addedge(int u, int v, int cap, double cost){
    edge[tot].u = u;edge[tot].v = v;edge[tot].cap = cap;edge[tot].cost = cost;edge[tot].next = head[u];
    head[u] = tot++;
    edge[tot].u = v;edge[tot].v = u;edge[tot].cap = 0;edge[tot].cost = -cost;edge[tot].next = head[v];
    head[v] = tot++;
}
bool SPFA(int st, int des){
    memset(inq, 0, sizeof(inq));
    fill(dis, dis + des + 2, INF);
    memset(pre, -1, sizeof(pre));
    int front = 0, rear = 0;
    q[rear++] = st;
    dis[st] = 0;
    inq[st] = true;
    while(front < rear){
        int u = q[front++];
        inq[u] = false;
        for(int i = head[u]; ~i; i = edge[i].next){
            int v = edge[i].v;
            if(edge[i].cap > 0 && dis[v] > dis[u] + edge[i].cost + eps){
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = u;
                path[v] = i;
                if(!inq[v]){
                    inq[v] = true;
                    q[rear++] = v;
                }
            }
        }
    }
    return pre[des] != -1;
}

double MCMF(int st, int des){
    double min_cost = 0, flow = 0;
    while(SPFA(st, des)){
        int f = INF;
        for(int i = des; i != st; i = pre[i]){
            if(f > edge[path[i]].cap){
                f = edge[path[i]].cap;
            }
        }
        for(int i = des; i != st; i = pre[i]){
            edge[path[i]].cap -= f;
            edge[path[i]^1].cap += f;
        }
        min_cost += f * dis[des];
        flow += f;
    }
    return min_cost;
}

int main(){
    freopen("test.txt","r",stdin);
    int n,m;
    int T; scanf("%d",&T);
    while(T--) {
        tot = 0;
        memset(head, -1, sizeof(head));
        scanf("%d %d",&n,&m);
        int s = 0; int t = n+1;
        for(int i = 1; i <= n; i++) {
            int a,b; 
            scanf("%d %d",&a,&b);
            if(a > b) 
                addedge(s,i,a-b,0);
            else if(b > a) 
                addedge(i,t,b-a,0);
        }
        for(int i = 1; i <= m; i++) {
            int a,b,c; 
            double p; 
            scanf("%d %d %d %lf",&a,&b,&c,&p);
            if(c>0)
                addedge(a,b,1,0);
            if(c>1) 
                addedge(a,b,c-1,-log(1-p) );
        }
        double tt = MCMF(s, t);
        tt = exp(-tt);
        printf("%.2f\n", 1-tt);
    }
    return 0;
}