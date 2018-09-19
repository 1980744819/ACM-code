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
double dp[20][256];
double p[256][256];
int main(){
    int n;
    int i,j,k;
    double Max;
    int num;
    int id;
    while(~scanf("%d",&n)&&n!=-1){
        for(i=0;i<(1<<n);i++){
            for(j=0;j<(1<<n);j++){
                scanf("%lf",&p[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<(1<<n);i++)
            dp[0][i]=1;
        for(i=1;i<=n;i++){//一共进行n次比赛
            for(j=0;j<(1<<n);j++){
                    num=j>>(i-1);
                if(num&1){
                        for(k=num*(1<<(i-1))-1;k>=(num-1)*(1<<(i-1));k--){
                        dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
                    }
                }
                else{
                    for(k=(num+1)*(1<<(i-1 ));k<(num+2)*(1<<(i-1));k++){
                        dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
                    }
                }
            }
        }
        Max=0.0;
        id=0;
        for(i=0;i<(1<<n);i++){
            //printf("%lf\n",dp[n][i]);
            if(dp[n][i]>Max){
                Max=dp[n][i];
                id=i;
            }
        }
        printf("%d\n",id+1);
    }
    return 0;
}

