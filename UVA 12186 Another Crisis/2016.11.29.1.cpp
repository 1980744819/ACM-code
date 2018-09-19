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
int n,t;
vector<int>sons[100005];
int dp(int a){
    if(sons[a].empty())
        return 1;
    int k=sons[a].size();
    vector<int>d;
    for(int i=0;i<k;i++)
        d.push_back(dp(sons[a][i]));
    sort(d.begin(),d.end());
    int c=(k*t-1)/100+1;
    int ans=0;
    for(int i=0;i<c;i++)
        ans+=d[i];
    return ans;
}
int main(){
    int i,j,k;
    while(~scanf("%d %d",&n,&t)&&(n||t)){
        for(i=0;i<=n;i++)
            sons[i].clear();
        int temp;
        for(i=1;i<=n;i++){
            scanf("%d",&temp);
            sons[temp].push_back(i);
        }
        printf("%d\n",dp(0));
    }
    return 0;
}

