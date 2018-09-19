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
long long a[18];
long long num;
int ans;
void dfs(long long  nu,int k){
    if(k<1||nu==0)
        return;
    int t=nu/a[k];
    nu%=a[k];
    ans+=t*k;
    dfs(nu,k-1);
}
int main(){
    int i,j,k;
    int tmp=0;
    for(i=1;i<18;i++){
        a[i]=a[i-1]*10+1;
        //printf("%lld\n",a[i]);
    }
    while(~scanf("%lld",&num)){
        ans=0;
        dfs(num,17);
        printf("%d\n",ans);
    }
    return 0;
}
