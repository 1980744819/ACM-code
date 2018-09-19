#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
double a[1005];
int main(){
    int n;
    while(~scanf("%d",&n)){
        int i;
        double sum=1;
        for(i=1;i<=n;i++){
            scanf("%lf",&a[i]);
            sum*=i;
        }
        if(n==1){
            printf("%lf\n",a[1]);
            continue;
        }
        //printf("%d\n",sum);
        double ans=0;
        ans+=a[1];
        ans+=a[n];
        ans/=2;
        double ansa=0;
        for(i=2;i<n;i++){
            ansa+=a[i];
        }
        ansa/=3;
        ans+=ansa;
        printf("%lf\n",ans);
    }
    return 0;
}
