#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int cou=0;
int a[14];
int n;
void print(){
    cou++;
    int i;
    if(cou<=3){
        for(i=0;i<n;++i)
        printf("%d ",a[i]+1);
        printf("\n");
    }
}
int can(int i,int k){
    int j=0;
    for(j=0;j<i;j++){
        if(a[j]==k||i-j==k-a[j]||i-j==a[j]-k)
            return 0;
    }
    return 1;
}
void que(int i){
    if(i==n)
        print();
    else{
        int j=0;
        for(j=0;j<n;j++){
            if(can(i,j)==1){
                a[i]=j;
                que(i+1);
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    que(0);
    printf("%d\n",cou);
    return 0;
}


