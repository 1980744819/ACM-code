#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1000],last[1000],times[1000][1000],work[1000][1000],num[1000];
bool b[21][100000];
int i,j,t,n,m,l,r,k,z,y,x,ans;
int main()
{
    scanf("%d%d",&m,&n);
    memset(b,false,sizeof(b));
    memset(a,0,sizeof(a));
    memset(times,0,sizeof(times));
    memset(work,0,sizeof(work));
    memset(num,0,sizeof(num));
    ans=0;
    for (i=0;i<n*m;i++) scanf("%d",&a[i]);
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) scanf("%d",&work[i][j]);
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) scanf("%d",&times[i][j]);
    for (i=0;i<n*m;i++)
    {
        x=a[i];
        num[x]++;
        t=last[x]+1;
        for (j=t;true;j++)
        {
            if (b[work[x][num[x]]][j]) t=j+1;
            if (j-t+1==times[x][num[x]]) break;
        }
        last[x]=j;
        ans=max(ans,j);
        for (k=t;k<=j;k++) b[work[x][num[x]]][k]=true;
    }
    printf("%d\n",ans);
    return 0;
}
