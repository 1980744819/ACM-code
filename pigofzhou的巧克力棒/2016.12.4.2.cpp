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
    scanf("%d",&t);
    int coun;
    int n;
    while(t--){
        scanf("%d",&n);
        if(n==1){
            printf("0\n");
            continue;
        }
        n=n>>1;
        //printf("%d\n",n);
        int ans=0;
        coun=0;
        while(n!=0){
            coun++;
            if(n&1){
                ans+=1<<coun;
                ans--;
                //printf("%d\n",ans);
            }
            n=n>>1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
