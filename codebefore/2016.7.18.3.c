#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int main(){
    double n,p;
    while(~scanf("%lf%lf",&n,&p)){
        printf("%.0lf\n",pow(p,1/n));
    }
    return 0;
}

