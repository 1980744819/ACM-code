#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define inf -1000
int a[14];
int n;
int cou=0;
void init(){
    int *p;
    for(p=a;p<a+n;++p){
        *p=inf;
    }
}
int valid(int row,int col){
    int i;
    for(i=0;i<n;++i){
        if(a[i]==col||abs(i-row)==abs(a[i]-col)){
            return 0;
        }
    }
    return 1;
}
int print(){
    int i,j;
    cou++;
    if(cou<=3){
        for(i=0;i<n;++i){
            printf("%d ",a[i]+1);
        }
        printf("\n");
    }
}
void queen(){
    int N=0;
    int i=0,j=0;
    while(i<n){
        while(j<n){
            if(valid(i,j)){
                a[i]=j;
                j=0;
                break;
            }
            else{
                ++j;
            }
        }
        if(a[i]==inf){
            if(i==0)
                break;
            else{
                --i;
                j=a[i]+1;
                a[i]=inf;
                continue;
            }
        }
        if(i==n-1){
            print();
            j=a[i]+1;
            a[i]=inf;
            continue;
        }
        ++i;
    }
}
int main(){
    scanf("%d",&n);
    init();
    queen();
    printf("%d\n",cou);
    return 0;
}
