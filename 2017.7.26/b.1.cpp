#include<bits/stdc++.h>  
using namespace std;  
  
const int MAXN=10001000;  
unsigned x,y,z,a[MAXN],b[110],ans[110],od[110];  
  
unsigned rng61() {  
  unsigned t;  
  x ^= x << 16;  
  x ^= x >> 5;  
  x ^= x << 1;  
  t = x;  
  x = y;  
  y = z;  
  z = t ^ x ^ y;  
  return z;  
}  
  
bool cmp(int x,int y)  
{  
    return b[x]<b[y];  
}  
  
int main()  
{  
    freopen("test.txt","r",stdin);
    int n,m,i;  
    unsigned cas=1,A,B,C;  
    while(~scanf("%u%u%u%u%u",&n,&m,&A,&B,&C))  
    {  
        for(i=0;i<m;i++)  
        {  
            scanf("%u",&b[i]);  
            od[i]=i;  
        }  
        x=A; y=B; z=C;  
        for(i=0;i<n;i++)  
            a[i]=rng61();  
        sort(od,od+m,cmp);
        for(i=0;i<m;i++)
            printf("%d ",od[i]);
        printf("\n");
        for(i=0;i<m;i++)
            printf("%d ",b[i]);
        printf("\n");  
        od[m]=m;  
        b[m]=n;  
        for(i=m-1;i>=0;i--)  
        {  
            if(b[od[i]]==b[od[i+1]])  
                ans[od[i]]=ans[od[i+1]];  
            else  
            {  
                nth_element(a,a+b[od[i]],a+b[od[i+1]]);  
                ans[od[i]]=a[b[od[i]]];  
            }  
        }  
        printf("Case #%u:",cas++);  
        for(i=0;i<m;i++)  
            printf(" %u",ans[i]);  
        printf("\n");  
    }  
}  