#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[110000],num[100100],s[2000][2];
int main(){
    int i,j;
    int cash,n;
    while(~scanf("%d %d",&cash,&n)){
        int cnt=0;
        for(i=1;i<=n;i++)
            scanf("%d %d",&s[i][0],&s[i][1]);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            memset(num,0,sizeof(num));
            for(j=s[i][1];j<=cash;j++){
                if(dp[j]<dp[j-s[i][1]]+s[i][1]&&num[j-s[i][1]]<s[i][0]){
                    dp[j]=dp[j-s[i][1]]+s[i][1];
                    num[j]=num[j-s[i][1]]+1;
                }
            }
        }
        printf("%d\n",dp[cash]);
    }
    return 0;
}
