#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 2e5 + 5;
int pre[maxn], a[maxn], b[maxn]; //pre并查集祖先数组，a记录每个袜子的颜色，b数组用来记录每个集合的颜色（就是某几天都是一种颜色，记录这种颜色的编号
vector<int> v[maxn];
int Find(int x)
{
    return x == pre[x] ? x : pre[x] = Find(pre[x]);
}
void join(int x, int y)
{
    pre[Find(y)] = Find(x);
}
int main()
{
    int n, m, k, x, y;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), pre[i] = i;
    for(int i = 1; i <= m; i++)
        scanf("%d%d", &x, &y), join(x, y); //这里就是这一天要袜子颜色要一样，把他们“联通”起来，这里并查集“祖先”的个数就是一共有几种颜色
    int cnt = 1;
    for(int i = 1; i <= n; i++)
    {
        if(pre[i] == i)      //这里如果pre[i] == i，代表了这是某几天的“祖先”，也就是一种颜色，给这个祖先的颜色一个编号cnt
            b[i] = cnt++;
    }
    for(int i = 1; i <= n; i++)  //这里就是把祖先的小弟拉近祖先的怀里，b[]是祖先的编号，他的小弟的b[Find（）]的颜色（a记录的）都存进v数组里，v下标代表哪个
    {
        v[b[Find(i)]].push_back(a[i]);
    }
    int ans = 0;
    for(int i = 1; i < cnt; i++)  //第一个for遍历cnt个祖先，也就是一共有cnt种不同的颜色
    {
        int maxx = 0;
        map<int, int> mm;
        for(int j = 0; j < v[i].size(); j++)  //这里就是遍历刚才每种颜色收的小弟，用一个map记录每种颜色的数量，找出数量最多的颜色
        {
            mm[v[i][j]]++;
            if(mm[v[i][j]] > maxx)  maxx = mm[v[i][j]];
        }
        ans += v[i].size() - maxx;  //这里就是用集合所有的袜子，减去数量最多的颜色。。。
    }
    printf("%d\n", ans);
    return 0;
}
