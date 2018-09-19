#include<iostream>  
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<math.h>  
#include<vector>  
#include<map>  
#include<set>  
#include<queue>  
#include<stack>  
#include<string>  
#include<algorithm>  
using namespace std;  
#define ll long long 
#define inf 99999999  
int v[2200],dp[2200];  
int main()  
{  
    freopen("test.txt","r",stdin);
    int n,i,j,T;  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d",&n);  
        for(i=1;i<=n-1;i++){  
            scanf("%d",&v[i]);  
        }  
        int ans=0;  
        ans+=v[1]*n;  
        for(i=2;i<=n-1;i++){  
            v[i]-=v[1];  
        }  
        for(i=1;i<=n-2;i++){  
            dp[i]=-inf;  
        }  
        dp[0]=0;  
        for(i=1;i<=n-2;i++){  
            v[i]=v[i+1];  
        }  
        for(i=1;i<=n-2;i++){  
            for(j=i;j<=n-2;j++){  
                dp[j]=max(dp[j],dp[j-i]+v[i]);  
            }  
        }  
        ans+=dp[n-2];  
        printf("%d\n",ans);  
    }  
}  