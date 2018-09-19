#include <cstdio>  
#include <algorithm>  
using namespace std;  
int const MAX = 1e3 + 5;  
int const INF = 0x3fffffff;  
int l[MAX], r[MAX];  
double lstk[MAX], rstk[MAX];  
double h[MAX];  
  
int main()  
{  
    int n, ltop = 0, rtop = 0;  
    scanf("%d", &n);  
    for(int i = 1; i <= n; i++)  
    {  
        scanf("%lf", &h[i]);  
        if(h[i] > lstk[ltop])  
            lstk[++ ltop] = h[i];  
        else  
        {  
            int low = 1, high = ltop, mid;  
            while(low <= high)  
            {  
                mid = (low + high) >> 1;  
                if(h[i] > lstk[mid])  
                    low = mid + 1;  
                else  
                    high = mid - 1;  
            }  
            lstk[low] = h[i];  
      
        }  
       l[i] = ltop;  
    }  
    for(int i = n; i >= 1; i--)  
    {  
        if(h[i] > rstk[rtop])  
            rstk[++ rtop] = h[i];  
        else  
        {  
            int low = 1, high = rtop, mid;  
            while(low <= high)  
            {  
                mid = (low + high) >> 1;  
                if(h[i] > rstk[mid])  
                    low = mid + 1;  
                else  
                    high = mid - 1;  
            }  
            rstk[low] = h[i];  
        }  
        r[i] = rtop;     
    }  
    int in = 0;  
    for(int i = 1; i < n; i++)  
        for(int j = i + 1; j <= n; j++)  
            in = max(in, (l[i] + r[j]));  
    printf("%d\n", n - in);  
} 