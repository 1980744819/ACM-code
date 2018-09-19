#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    int n;
    int ans;
    int i,j;
    int a,b;
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            ans+=a*b;
        }
        printf("%d\n",ans);
    }
    return 0;
}


