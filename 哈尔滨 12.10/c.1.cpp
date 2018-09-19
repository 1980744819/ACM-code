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
int main(){
    int t;
    int i,j,k;
    int n;
    long long ans;
    long long temp;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%lld",&ans);
        for(i=1;i<n;i++){
            scanf("%lld",&temp);
            ans=ans^temp;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
