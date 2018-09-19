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
vector<int>sons[155];
int dp[155][155];
int father[155];
int n,p;
int dfs(int root){
    int i,j,k;
    for(i=0;i<sons[root].size();i++)
        dfs(sons[root][i]);
    dp[root][1]=sons[root].size();
    for(i=0;i<sons[root].size();i++){
        for(j=p-1;j>0;j--){
                if(dp[root][j]!=999999){
                for(k=1;k<=p-j;k++){
                        if(dp[sons[root][i]][k]!=999999)
                            dp[root][j+k]=min(dp[root][j]+dp[sons[root][i]][k]-1,dp[root][j+k]);
                }
            }
        }
    }
    return dp[root][p];
}
int main(){
    int i,j,k;
    int a,b;
    int Min;
    int root;
    while(~scanf("%d %d",&n,&p)){
        memset(father,0,sizeof(father));
        for(i=1;i<=n;i++){
            for(j=1;j<=p;j++){
                dp[i][j]=999999;
            }
        }
        for(i=0;i<n-1;i++){
            scanf("%d %d",&a,&b);
            sons[a].push_back(b);
            father[b]=a;
        }
        root=1;
        while(father[root]!=0)
            root=father[root];
        Min=dfs(root);
        for(i=1;i<=n;i++)
            if(Min>dp[i][p]+1)
            Min=dp[i][p]+1;
        printf("%d\n",Min);
    }
    return 0;
}

