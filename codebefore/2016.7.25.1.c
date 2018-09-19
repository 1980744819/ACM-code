#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
long long num[500005];
long temp[500005];
long long ans=0;
int n;

void merge(int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    while(i<=mid&&j<=high){
        if(num[i]<=num[j]){
            temp[k]=num[i];
            k++;
            i++;
        }
        else{
            ans+=j-k;//Í³¼ÆÄæÐò
            temp[k]=num[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k]=num[i];
        k++;
        i++;
    }
    while(j<=high){
        temp[k]=num[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++){
        num[i]=temp[i];
    }
}
void mergesort(int a,int b){
    if(a<b){
        int mid=(a+b)/2;
        mergesort(a,mid);
        mergesort(mid+1,b);
        merge(a,mid,b);
    }
}
int main(){
    while(~scanf("%d",&n)&&n){
        ans=0;
        int i;
        for(i=0;i<n;i++){
            scanf("%lld",&num[i]);
        }
        mergesort(0,n-1);
        printf("%lld\n",ans);
    }
    return 0;
}

