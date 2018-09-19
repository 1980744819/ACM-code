#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;
int dp[21][15001];
int main(){
    int n;
    int g;
    int c[21];
    int w[21];
    int i,j,k;
    cin>>n>>g;
    for(i=1;i<=n;i++)
        cin>>c[i];
    for(i=1;i<=g;i++)
        cin>>w[i];

    memset(dp,0,sizeof(dp));
    dp[0][7500]=1;

    for(i=1;i<=g;i++){
        for(j=0;j<=15000;j++){
            if(dp[i-1][j]){
                for(k=1;k<=n;k++){
                    dp[i][j+w[i]*c[k]]+=dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[g][7500]<<endl;
    return 0;
}
