#include<stdio.h>
int fact(int n)
{
     if(n<=1) return 1;
     else return n*fact(n-1);
}
int main()
{
    int n,res,i;
    scanf("%d",&n);
    for(i=1;1<=i&&i<=n;i++)
    {
        res=fact(i);
        printf("%d\n",res);
    }
   return 0;
}
