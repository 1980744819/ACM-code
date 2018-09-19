#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
using namespace std;
int a[50005];
int d[50005];

int main(){
    int n;
    while(~scanf("%d",&n)){
        int i,j;
        int maxn=1;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            d[i]=1;
            for(j=0;j<n;j++){
                if(a[i]>a[j]&&d[j]+1>d[i]){
                    d[i]=d[j]+1;
                }
            }
            if(maxn<d[i])
                maxn=d[i];
        }
        printf("%d\n",maxn);
    }
    return 0;
}




