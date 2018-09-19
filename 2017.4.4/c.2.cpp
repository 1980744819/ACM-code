#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 2e5 + 5;
int pre[maxn], a[maxn], b[maxn]; //pre���鼯�������飬a��¼ÿ�����ӵ���ɫ��b����������¼ÿ�����ϵ���ɫ������ĳ���춼��һ����ɫ����¼������ɫ�ı��
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
        scanf("%d%d", &x, &y), join(x, y); //���������һ��Ҫ������ɫҪһ���������ǡ���ͨ�����������ﲢ�鼯�����ȡ��ĸ�������һ���м�����ɫ
    int cnt = 1;
    for(int i = 1; i <= n; i++)
    {
        if(pre[i] == i)      //�������pre[i] == i������������ĳ����ġ����ȡ���Ҳ����һ����ɫ����������ȵ���ɫһ�����cnt
            b[i] = cnt++;
    }
    for(int i = 1; i <= n; i++)  //������ǰ����ȵ�С���������ȵĻ��b[]�����ȵı�ţ�����С�ܵ�b[Find����]����ɫ��a��¼�ģ������v�����v�±�����ĸ�
    {
        v[b[Find(i)]].push_back(a[i]);
    }
    int ans = 0;
    for(int i = 1; i < cnt; i++)  //��һ��for����cnt�����ȣ�Ҳ����һ����cnt�ֲ�ͬ����ɫ
    {
        int maxx = 0;
        map<int, int> mm;
        for(int j = 0; j < v[i].size(); j++)  //������Ǳ����ղ�ÿ����ɫ�յ�С�ܣ���һ��map��¼ÿ����ɫ���������ҳ�����������ɫ
        {
            mm[v[i][j]]++;
            if(mm[v[i][j]] > maxx)  maxx = mm[v[i][j]];
        }
        ans += v[i].size() - maxx;  //��������ü������е����ӣ���ȥ����������ɫ������
    }
    printf("%d\n", ans);
    return 0;
}
