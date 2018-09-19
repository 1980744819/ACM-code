#include<stdio.h>
#include<windows.h>
int main()
{
    //1,1, 2, 3,5,8,13.....
    long long a[100];
    a[0]=1;
    a[1]=1;
    int i;
    for(i=2;i<100;i++){
        a[i]=a[i-1]+a[i-2];
        printf("%lld\n",a[i]);
    }
    return 0;
}
