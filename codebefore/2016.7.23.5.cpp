#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int a[100010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        int i;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        printf("%d\n",a[n/2]);
    }
    return 0;
}

