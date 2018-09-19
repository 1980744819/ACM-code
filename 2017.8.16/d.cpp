#include <cstdio>
using namespace std;
const int N = 1000000;

long long fast_pow(long long a, int b)
{
    long long res = 1;
    for( ; b; b >>= 1, a *= a)
        if(b & 1)
            res *= a;
    return res;
}

// 满 k 叉树，前 n 层总结点数
long long nNode(long long k, int n)
{
    return (fast_pow(k, n) - 1) / (k - 1);
}

long long table[100];

// table[i] = 满 k 叉树前 i 层总结点数
// 减少 nNode() 的调用（快速幂的次数）
// 虽然后来发现超时的原因并不在这
void da_biao(long long k, int d)
{
    for(int i = 0; i <= d; ++i){
        table[i] = nNode(k, i);
        //printf("%d %lld %lld\n",i,fast_pow(k,i),table[i]);
    }
}

int main()
{
    freopen("test.txt","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long n, k, ans = 0;
        scanf("%lld%lld", &n, &k);
        // 特判 k = 1
        if(k == 1)
        {
            int rest = n & 3; // n % 4
            if(!rest)
                ans = n;
            else if(rest == 1)
                ans = 1;
            else if(rest == 2)
                ans = n + 1;
            else
                ans = 0;
            printf("%lld\n", ans);
            continue;
        }
        // 求树的高度
        // 根的高度设为 1
        int depth = 1;
        for(long long m = n - 1; m > 0; ++depth)
            m = (m - 1) / k;
        //printf("%d ",depth);

        da_biao(k, depth + 2);

        // 整棵树
        ans = n;
        // 最底层单独做
        ans ^= (n - table[depth - 1]) & 1;

        --depth;
        long long p = (n - 2) / k; // [(n - 1) - 1] / k，倒数第 2 层开始
        long long lid, rid, lnum, rnum, lch;
        for(int d = 2; p > 0; p = (p - 1) / k, ++d, --depth)
        {
            // 当前层最左边结点的标号
            lid = table[depth - 1];
            // 当前层最右边结点的标号
            rid = table[depth] - 1;
            // 左边的子树（满的）的大小
            lnum = table[d];
            // 右边的子树（少一层，但也是满的）的大小
            rnum = table[d - 1];

            if((p - lid) & 1)
                ans ^= lnum;
            if((rid - p) & 1)
                ans ^= rnum;

            lch = p; // p 为根的子数最左小角的后代结点
            while(lch <= (n - 2) / k) // lch * k + 1 <= n - 1
                lch = lch * k + 1;
            ans ^= table[d - 1] + n - lch;
        }
        printf("%lld\n", ans);
    }
    return 0;
}