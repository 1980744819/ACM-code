#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<malloc.h>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int dp[105][105];
int s[105][105];
int main(){
    int n;
    int i,j;
    int a,b,c;
    int Max;
    int t;
    int k;
    while(~scanf("%d",n)){
        for(i=0;i<n;i++){
            scanf("%d%d%d",&a,&b,&c);
            s[a][b]=c;
            s[b][a]=c;
        }
        int len;
        for(len=2;len<n;len++){
            for(i=0;i<n-len+1;i++){
                j=i+len-1;
                Max=0;
                for(k=i;k<j;j++){
                    t=dp[i][k]+dp[k+1][j]+s[i][k]+s[k+1][j]+s[i][j];
                    if(t>Max){
                        t=Max;
                    }
                }
                dp[i][j]=Max;
            }
        }
        cout<<dp[0][n-1]<<endl;
    }
    return 0;
}



