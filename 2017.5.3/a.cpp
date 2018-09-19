#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,n;
    int sum=0;
    int a[105][105];
    scanf("%d",&n);
    for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       scanf("%d",&a[i][j]);
     }
     for(i=0;i<n;i++)
     {
       sum=sum+a[i][i];
       sum+=a[i][n-1-i];
     }
    if(n%2==0)
     printf("%d\n",sum);
    else
     printf("%d\n",sum-a[n/2][n/2]);
    return 0;
}
