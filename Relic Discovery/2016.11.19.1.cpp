#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    int i,j,k;
    int t;
    int ans;
    int n;
    scanf("%d",&t);
        int a,b;
        while(t--){
            ans=0;
            scanf("%d",&n);
            while(n--){
                scanf("%d %d",&a,&b);
                ans+=a*b;
            }
            printf("%d\n",ans);
        }
    return 0;
}


