#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    int i,j;
    int p[100005];
    scanf("%d %d",&n,&k);
    int ans=0;
    int coun=n;
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    int tmp=2*k;
    for(i=0;i<n;i++){
        ans+=p[i]/tmp;
        p[i]%=tmp;
        if(p[i]==0)
            coun--;
    }
    for(i=0;i<n;i++){
        if(p[i]>k){
            coun--;
            p[i]=0;
            ans++;
        }
    }
    ans+=coun/2;
    if(coun%2==1)
        ans++;
    printf("%d\n",ans);
    return 0;
}

