#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
int dp[45005];
int a[505];
int n;
int h;
int main(){
    while(~scanf("%d %d",&h,&n)){
        int i,j,k;
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            for(j=h;j>=a[i];j--){
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            }
        }
        printf("%d\n",dp[h]);
    }
    return 0;
}


