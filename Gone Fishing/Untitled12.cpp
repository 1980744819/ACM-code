#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 30;
int f[N], d[N], ans[N], tmp[N], time[N];
int ff[N];
int main()
{
    int n, h, i, j, t, cas = 0;
    while(~scanf("%d",&n) && n)
    {
        scanf("%d",&h); h *= 60;
        for(i = 0; i < n; i++)
            scanf("%d",&f[i]);
        for(i = 0; i < n; i++)
            scanf("%d",&d[i]);
        time[0] = 0;
        for(i = 1; i < n; i++)
        {
            scanf("%d",&t);
            time[i] = time[i-1] + t*5;
        }
        memset(ans, 0, sizeof(ans));  //注意初始化
        int maxsum = -1;
        for(i = 0; i < n; i++)
        {
            int sum = 0, left_time = h - time[i];
            for(j = 0; j <= i; j++)
                ff[j] = f[j]; //注意不要直接对f[i]进行操作，不然会影响下一次的结果
            memset(tmp, 0, sizeof(tmp));
            while(left_time > 0)
            {
                int mmax = 0, id = 0;
                for(j = 0; j <= i; j++)
                {
                    if(ff[j] > mmax)
                    {
                        mmax = ff[j];
                        id = j;
                    }
                }
                if(mmax == 0) break;
                sum += mmax;
                tmp[id] += 5;
                ff[id] -= d[id];
                left_time -= 5;
            }
            if(left_time > 0)
                tmp[0] += left_time;
            if(sum > maxsum)
            {
                maxsum = sum;
                for(j = 0; j <= i; j++)
                    ans[j] = tmp[j];
            }
        }
        if(cas > 0)
            printf("\n");
        printf("%d",ans[0]);
        for(i = 1; i < n; i++)
            printf(", %d",ans[i]);
        printf("\n");
        printf("Number of fish expected: %d\n",maxsum);
        cas++;
    }
    return 0;
}
