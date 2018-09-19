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
__int64 a[100005];
int main(){
    int t;
    int n;
    int i,j;
    scanf("%d",&t);
    int ans;
    __int64 num;
    int coun;
    while(t--){
        scanf("%d",&n);
        ans=1;
        for(i=0;i<n;i++){
            scanf("%I64d",&a[i]);
        }
        for(i=0;i<n-1;i++){
            if(a[i]==a[i+1]){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

