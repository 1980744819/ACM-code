#include <stdio.h>
#include <string.h>

#define MAX 20001

int main(void)
{
   int m,n,tv,v,i,j,k ;
   int a[MAX] ={0} ;
   a[0] = 1;
   scanf("%d",&v) ;
   scanf("%d",&n) ;


   for(i=1 ; i<= n ; i++)
   {
       scanf("%d",&tv);
       for(j=v ; j>=tv ; j--)
       if(!a[j])
       a[j] = a[j-tv] ;
    }
   m = v ;
   while ( a[m] == 0)
   m -- ;
   printf("%d ",v-m) ;

   return 0 ;
}
