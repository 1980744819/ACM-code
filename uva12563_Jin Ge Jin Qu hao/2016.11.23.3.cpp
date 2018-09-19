#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int dp[10005];
int Time[55];
int main(){
    int i,j,k;
    int ans;
    int Max;
    int n;
    int kase;
    int t;
    scanf("%d",&kase);
    for(k=1;k<=kase;k++){
        scanf("%d %d",&n,&t);
        for(j=0;j<n;j++)
            scanf("%d",&Time[j]);
        t--;
        memset(dp,0,sizeof(dp));
        Max=0;
        for(i=0;i<n;i++){
            for(j=t;j>=Time[i];j--){
                if(dp[j-Time[i]]>=1||j==Time[i]){
                    dp[j]=max(dp[j],dp[j-Time[i]]+1);
                    if(Max<dp[j])
                        Max=dp[j];
                }
            }
        }
        printf("Case %d:",k);
        if(Max==0){
            printf(" 1 678\n");
        }
        else{
            for(i=t;i>=0;i--){
                if(Max==dp[i])
                    break;
            }
            printf(" %d %d\n",dp[i]+1,i+678);
        }
    }
    return 0;
}

