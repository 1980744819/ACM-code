#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int a[100001];
int top;
int main(){
    int num;
    top=-1;
    while(~scanf("%d",&num)){
        int t;
        while(num!=0){
            t=num%8;
            top++;
            a[top]=t;
            num=num/8;
        }
        while(top>=0){
            printf("%d",a[top]);
            top--;
        }
        printf("\n");
    }
    return 0;
}

