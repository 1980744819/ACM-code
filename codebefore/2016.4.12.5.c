#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

int main(){
    int a[10001];
    a[0]=0;
    a[1]=1;
    int num;
    int c;
    scanf("%d",&c);
    while(c--){
            scanf("%d",&num);
            a[0]=0;
            a[1]=1;
           int  i=2;
        while(i<=num){
            a[i]=a[i-2]+a[i-1];
            i++;
        }
        printf("%d\n",a[num]);
    }
    return 0;
}
