#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int main(){
    int days;
    int i,j,k;
    int min,max;
    while(~scanf("%d",&days)){
            int num=days%7;
            min=days/7;
            min*=2;
        if(num<=2){
            max=days%7+min;
        }
        else if(num==6){
            max=2+min;
            min+=1;
        }
        printf("%d %d\n",min,max);
    }
    return 0;
}

