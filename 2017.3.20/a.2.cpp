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
int a[100005],res[100005];
int main(){
    int n,d1,d2;
    int i,j,k;
    int old,ne;
    int num;
    long long ans;
    while(~scanf("%d %d %d",&n,&d1,&d2)){
        old=99999999;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(i==1){
                //ne=a[i];
                res[i]=1;
                ans=1;
                continue;
            }
            ne=a[i]-a[i-1];
            if(old==d1&&ne==d1||old==d1&&ne==d2||old==d2&&ne==d2){
                res[i]=res[i-1]+1;
            }
            else{
                if(ne==d1||ne==d2){
                    res[i]=2;
                }
                else{
                    res[i]=1;
                }
            }
            old=ne;
            ans+=res[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

