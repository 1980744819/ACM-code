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
    int n,d1,d2;
    int i,j,k;
    int ans;
    while(~scanf("%d %d %d",&n,&d1,&d2)){
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        ans=0;
        int count,u1,u2;
        for(i=2;i<n;i++){
            if(a[i+1]==a[i]+d2&&a[i-1]+d1==a[i]){
                count=1;
                u1=2,u2=2;
                for(j=i+2;j<=n&&a[j]==a[j-1]+d2;j++){
                    count++;
                    u2++;
                }
                for(j=i-2;j>=1&&a[j]+d1==a[j+1];j--){
                    count*=2;
                    u1++;
                }
                //printf("%d %d\n",u1,u2);
                ans+=count+u1*(u1-1)/2+u2*(u2-1)/2;
            }
            else{
                u1=0,u2=0;
                if(a[i]==a[i-1]+d1){
                    u1=2;
                    for(j=i-2;j>=1&&a[j]+d1==a[j+1];j--){
                        u1++;
                    }
                }
                else if(a[i+1]==a[i]+d2){
                    u2=2;
                    for(j=i+2;j<=n&&a[j]==a[j-1]+d2;j++){
                        //count++;
                        u2++;
                    }
                }
                ans+=u1*(u1-1)/2+u2*(u2-1)/2;
            }
        }
        printf("%d\n",ans+n);
    }
    return 0;
}
