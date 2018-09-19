#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int main(){
    int p,q;
    int t;
    int ans;
    while(scanf("%d",&t)==1&&t){
        while(t--){
            scanf("%d %d",&q,&p);
            if(q==2)
                printf("0\n");
            else {
                ans=(q-2)+(q-2)*(q-3)/2;
                ans=ans%p;
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

