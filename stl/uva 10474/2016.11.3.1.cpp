#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a[10005];
    int kase;
    int n;
    kase=1;
    int num;
    while(~scanf("%d %d",&n,&num)){
        int i,j;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=0;i<num;i++){
                int x;
            scanf("%d",&x);
            printf("CASE# %d:\n",kase++);
            int p=lower_bound(a,a+n,x)-a;
            if(a[p]==x){
                printf("%d found at %d\n",x,p+1);
            }
            else{
                printf("%d not found\n",x);
            }
        }
    }
    return 0;
}
