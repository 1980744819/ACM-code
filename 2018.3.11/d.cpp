#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1000006;
int prime[maxn];
void getprime()
{
    int n = 2;
    while (n < maxn)
    {
        int num = n * 2;
        while (num < maxn)
        {
            prime[num] = n;
            num += n;
        }
        num = n + 1;
        while (prime[num] != 0 && num < maxn)
        {
            num++;
        }
        n = num;
    }
}
int main()
{
    getprime();
    int x0, x1, x2;
    while (~scanf("%d", &x2))
    {
        int a = 0, b = 0;
        b = prime[x2];
        x0 = 99999999;
        for (int i = x2 - b + 1; i <= x2; i++)
        {
            a = prime[i];
            x0 = min(i - a + 1, x0);
        }
        printf("%d\n", x0);
    }
    return 0;
}
