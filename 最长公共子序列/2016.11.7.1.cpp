#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[1005][1005];
int main(){
    char a[1005];
    char b[1005];
    while(~scanf("%s",a)){
        scanf("%s",b);
        int i,j,k;
        for(i=0;i<=strlen(a);i++){
            dp[i][0]=0;
        }
        for(i=0;i<=strlen(b);i++){
            dp[0][i]=0;
        }
        for(i=1;i<=strlen(a);i++){
            for(j=1;j<=strlen(b);j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else if(dp[i-1][j]>=dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        printf("%d\n",dp[strlen(a)][strlen(b)]);
    }
    return 0;
}
