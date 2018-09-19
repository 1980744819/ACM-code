#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[10005];
int k_find(int low,int high,int k){
    if(k<0||k>high-low+1)
        return -1;
    int pivot=low+rand()%(high+1-low);//需要大一个才能保证取模的范围为数组的范围
    swap(a[low],a[pivot]);
    int m=low;
    int coun=1;
    int i,j;
    for(i=low+1;i<=high;i++){
        if(a[i]>a[low]){
            coun++;
            swap(a[++m],a[i]);
        }
    }
    swap(a[m],a[low]);
    if(coun>k){
        k_find(low,m-1,k);
    }
    else if(coun<k){
        k_find(m+1,high,k-coun);
    }
    else
        return m;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        int i,j;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int k;
        scanf("%d",&k);
        k=k_find(0,n-1,k);
        if(k!=-1)
            printf("%d\n",a[k]);
        else
            printf("error\n");
    }
    return 0;
}
