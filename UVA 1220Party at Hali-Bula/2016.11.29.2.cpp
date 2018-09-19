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
vector<int>child[300];
map<string,int>v;
int dp[300][3];
bool f[300][3];
void dfs(int u){
    if(child[u].size()==0){
        dp[u][0]=0;
        dp[u][1]=1;
        return;
    }
    int Size=child[u].size();
    for(int i=0;i<Size;i++){
        dfs(child[u][i]);
        if(f[child[u][i]][0])
            f[u][1]=1;
        dp[u][1]+=dp[child[u][i]][0];
        if(dp[child[u][i]][0]>dp[child[u][i]][1]){
            dp[u][0]+=dp[child[u][i]][0];
            if(f[child[u][i]][0])
                f[u][0]=1;
        }
        else{
            dp[u][0]+=dp[child[u][i]][1];
            if(dp[child[u][i]][1]==dp[child[u][i]][0]||f[child[u][i]][1])
                f[u][0]=1;
        }
    }
    dp[u][1]++;
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        int top=1;
        string s1,s2;
        cin>>s1;
        v[s1]=top++;
        for(int i=1;i<n;i++){
            cin>>s1>>s2;
            if(!v[s1])
                v[s1]=top++;
            if(!v[s2])
                v[s2]=top++;
            child[v[s2]].push_back(v[s1]);
        }
        dfs(1);
        if(dp[1][1]==dp[1][0])
            printf("%d No\n",dp[1][1]);
        else if(dp[1][1]>dp[1][0])
            printf("%d %s\n",dp[1][1],f[1][1]?"No":"Yes");
        else
            printf("%d %s\n",dp[1][0],f[1][0]?"No":"Yes");
        for(int i=1;i<=n;i++)
            child[i].clear();
        v.clear();
    }
    return 0;
}

