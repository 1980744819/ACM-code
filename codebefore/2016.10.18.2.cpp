#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
using namespace std;
void perm(int a[],int k,int m){
    int i;
    if(k==m){
        for(i=0;i<=m;i++)
            printf("%d ",a[i]);
        printf("\n");
        return;
    }
    else{
        for(i=k;i<=m;i++){
            swap(a[i],a[k]);
            perm(a,k+1,m);
            swap(a[i],a[k]);
        }
    }
}
int main(){
    int n;
    int a[100];
    while(~scanf("%d",&n)){
        int i;
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
        perm(a,0,n-1);
    }
    return 0;
}

