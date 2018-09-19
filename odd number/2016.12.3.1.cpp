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
    int n;
    int ans;
    while(~scanf("%d",&n)){
            ans=0;
        while(n--){
            int a;
            scanf("%d",&a);
        if(a%2!=0)
            ans++;
        }
    printf("%d\n",ans);
    }
    return 0;
}
