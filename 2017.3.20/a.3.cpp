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
int a[100005];
int main(){
    long long ans;
    int i,j,k;
    int n,d1,d2;
    long long count;
    bool flag;
    while(~scanf("%d %d %d",&n,&d1,&d2)){
        flag=0;
        ans=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        count=1;
        for(i=1;i<n;i++){
            if(a[i]-a[i-1]==d1&&flag==0){
                count++;
            }
            else if(a[i]-a[i-1]==d2&&flag==0){
                count++;
                flag=1;
            }
            else if(a[i]-a[i-1]==d2&&flag==1){
                count++;
            }
            else{//a[i]-a[i-1]!=d1&&a[i]-a[i-1]!=d2||a[i]-a[i-1]==d1
                ans+=count*(count-1)/2;
                if(flag)//c
                    i--;
                flag=0;
                count=1;
            }
            if(i==n-1){
                ans+=count*(count-1)/2;
            }
        }
        printf("%lld\n",ans+n);
    }
    return 0;
}
