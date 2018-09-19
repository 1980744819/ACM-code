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
long long a[500010];
int main(){
    int t;
    scanf("%d",&t);
    int n,m,z,l;
    while(t--){
        scanf("%d %d %d %d",&n,&m,&z,&l);
        a[1]=0;
        for(int i=2;i<=n;i++){
            a[i]=(a[i-1]*m+z)%l;
        }
        long long ans=a[1]+a[1];
        for(int i=2;i<=n;i++)
            ans^=(a[i]);
        printf("%lld\n",ans*2);
    }
    return 0;
}

