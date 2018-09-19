#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int dp[600005];
int s[600005];
void dfs(int i){
    if(i==0)
        return;
    printf("%d",s[i]);
    if(s[i]==1)
        dfs(s[i-1])
}
int main(){
    int i,j,k;
    int a,b;
    int n,w;
    while(~scanf("%d %d",&n,&w)){
        for(i=1;i<=w;i++)
        dp[i]=999999999;
        dp[0]=0;
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            for(j=w;j>=0;j--){
                if(j>=2){
                    if(dp[j]>dp[j-2]+b){
                        dp[j]=dp[j-2]+b;
                        s[j]=2;
                    }
                }
                if(j>=1){
                    if(dp[j]>dp[j-1]+a){
                        dp[j]=dp[j-1]+a;
                        s[j]=1;
                    }
                }
            }
        }
        printf("%d\n",dp[w]);
    }
    return 0;
}
