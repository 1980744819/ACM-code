#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
struct numtype{
    int len;
    int a[1000];
}dp[400];
int n;
/*void add(numtype a,numtype b,numtype c){
    int i;
    int len;
    if(a.len>b.len)
        len=a.len;
    else
        len=b.len;
    for(i=1;i<=len;i++){
        c.a[i]=a.a[i]+b.a[i];
    }
    for(i=1;i<=len;i++){
        if(c.a[i]>9){
            c.a[i]-=10;
            c.a[i+1]++;
        }
    }
    if(c.a[len+1]!=0) c.len=len+1;
    else c.len=len;
}*/
int main(){
    int i=3;
    int j,len;
    for(j=1;j<=1000;j++){
                    dp[1].a[j]=0;
    }
    for(j=1;j<=1000;j++){
                    dp[2].a[j]=0;
    }
    dp[0].len=0;
    dp[0].a[1]=0;
    dp[1].len=1;
    dp[2].len=1;
    dp[1].a[1]=1;
    dp[2].a[1]=3;
    while(~scanf("%d",&n)){
            i=3;
            while(i<=n){
                dp[i].len=0;
                len=dp[i-1].len;
                for(j=1;j<=1000;j++){
                    dp[i].a[j]=0;
                }
                for(j=1;j<=len;j++){
                    dp[i].a[j]=dp[i-1].a[j]+dp[i-2].a[j]+dp[i-2].a[j];
                }
                for(j=1;j<=len;j++){
                    while(dp[i].a[j]>=10){
                        dp[i].a[j]-=10;
                        dp[i].a[j+1]++;
                    }
                }
                if(dp[i].a[len+1]!=0)
                    dp[i].len=len+1;
                else
                    dp[i].len=len;
                i++;
            }
        if(n!=0){
            for(i=dp[n].len;i>0;i--){
                printf("%d",dp[n].a[i]);
            }
        }
        else
            printf("1");
        printf("\n");
    }
    return 0;
}

//A[1]=1,A[2]=3,A[n]=A[n-1]+2*A[n-2]
