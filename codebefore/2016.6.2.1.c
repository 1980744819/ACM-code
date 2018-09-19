#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int main(){
    int n,h;
    int i;
    int a;
    scanf("%d",&n);
    scanf("%d",&h);
    int  k=n;
    for(i=0;i<k;i++){
        scanf("%d",&a);
        if(a>h)
            n++;
    }
    printf("%d\n",n);
    return 0;
}

