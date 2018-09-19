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
int a[50005],b[50005];
int main(){
    int t;
    int n,k;
    scanf("%d",&t);
    int i,j;
    int ans;
    int sum,cos,max;
    while(t--){
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        ans=0;
        sum=0;
        cos=0;
        for(i=0;i<n;i++){
            cos=0;
            sum=0;
            max=0;
            int flag=0;
            j=i;
            while(j<n&&cos<=k){
                cos+=a[j];
                sum+=b[j];
                if(max<a[j]){
                    max=a[j];
                }
                if(cos>k&&flag==0){
                    flag=1;
                    cos-=max;
                }
                j++;
            }
            if(cos>k){
                j--;
                sum-=b[j];
            }
            if(ans<sum)
                ans=sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}

