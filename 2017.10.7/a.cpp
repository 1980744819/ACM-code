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
const int maxn=10000;
#define MV 105
#define INF (1 << 20)
struct edge
{
 int t, cap, rev;
 double cost;
 edge(int to = 0, int c = 0, int ct = 0, int r = 0): t(to), cap(c), cost(ct), rev(r) {};
};
vector <edge> G[MV];//图的邻接表表示
int dis[MV];//单源点s到其它顶点的最短距离（本次搜索的最小费用）
int prevv[MV], preve[MV];//最短路中的前驱结点 对应边
int min_cost_flow(int n, int v, int s, int t, int f)
{
 　　int ans = 0, i, j; //最小费用
 　　while(f > 0)
　　 {
  　　　　fill(dis, dis + v, INF);
 　　　　 dis[s] = 0

　　　　  bool update = true;
 　　　　 while(update)
 　　　　 {//bellman算法求解s-t可达路径中的最短路（费用最少）且是否可达由e.c是否大于0决定
   　　　　update = false;
   　　　　　　for(i = 0; i < v; ++i)
 　　　　  　　{
   　　　　 　　　　int size = G[i].size();
   　　　　　　　　 if(dis[i] == INF)
    　　　　　　　　　　 continue;   

　　　　　　　　　 for(j = 0; j < size; ++j)
    　　　　　　　　{
    　　　　　　　　　　 edge &es = G[i][j];
    　　　　　　　　　　 if(es.cap > 0 && dis[es.t] > dis[i] + es.cost)
    　　　　　　　　　　 {
      　　　　　　　　　　　　dis[es.t] = dis[i] + es.cost;
      　　　　　　　　　　　　prevv[es.t] = i;//路径还原
    　　　　　　　　　　　　  preve[es.t] = j;

      　　　　　　　　　　　　update = true;
     　　　　　　　　　　}
    　　　　　　　　}
   　　　　　　}
  　　　　}

 　　　　 if(dis[t] == INF)
 　　　　 return -1;
  　　　　int d = f; //d:本次求得的最小费用流
 　　　　 for(i = t; i != s; i = prevv[i])
  　　　　　　d = min(d, G[prevv[i]][preve[i]].cap);
  
 　　　　 ans += d * dis[t];
  　　　　f -= d;
 　　　　 for(i = t; i != s; i = prevv[i])
 　　　　 {
   　　　　　　edge &es = G[prevv[i]][preve[i]];
  　　　　　　 es.cap -= d;
   　　　　　　G[es.t][es.rev].cap += d; 

　　　　  }
 　　}
 　　return ans;
}

void solve(int n, int v, int s, int t, int f)
{
 　　int i, j;
 　　for(i = 0; i < n; ++i)
 　　{//建图
 　　　　 int s1, t1, cap, cost;
  　　　　cin >> s1 >> t1 >> cap >> cost;
 　　　　 G[s1].push_back(edge(t1, cap, cost, G[t1].size()));
 　　　　 G[t1].push_back(edge(s1, 0, -cost, G[s1].size() - 1)); 

 　　}

 　　cout << min_cost_flow(n, v, s, t, f) << endl;
}

int main()
{
 int n, v, s, t, f;//n条边 v个顶点 源点s  汇点t 传输的流量f
 cin >> n >> v >> s >> t >> f;
 solve(n, v, s, t, f);
 return 0;
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	int  point[105][2];
	while(t--){
		int n,m;
		int si,bi;
		scanf("%d %d",&n,&m);
		int s=0,t=n+1;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&si,&bi);
			if(si<bi){
				bi-=si;
				G[t].push_back(edge());
			}
			else{
				si-=bi;
				G[s].push_back(edge());
			}
		}
		int ui,vi,ci;
		double pi;
		for(int i=1;i<=m;i++){
			scanf("%d %d %d %lf",&ui,&vi,&ci,&pi);
			G[ui].push_back(edge(vi,ci,log()))
		}
	}
    return 0;
}
