#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int main(){
    double num;
    while(~scanf("%lf",&num)){
        double a=2;
        int i=0;
        int flag=0;
        /*double b=4294898577.055844;
        if(num>b){
            printf("TAT\n");
            continue;
        }*/
        if(num<1){
            printf("TAT\n");
            continue;
        }
        for(i=1;i<=5;i++){
            a=a*a;
            if(num<a){
                printf("%d\n",i);
                flag=1;
                break;
            }
        }
        //printf("%lf",a);
        if(!flag){
            printf("TAT\n");
        }
    }
    return 0;
}
