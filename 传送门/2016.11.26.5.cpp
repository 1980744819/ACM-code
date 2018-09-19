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
long long a[100010],sum[100010];
int main(){
    int t;
    scanf("%d",&t);
    int i,j;
    long long Max,temp;
    int n;
    while(t--){
        scanf("%d",&n);
        memset(sum,0,sizeof(sum));
        for(i=2;i<=n;i++){
            scanf("%lld",&a[i]);
            sum[i]+=a[i]+sum[i-1];
        }
        i=j=1;
        Max=sum[n];
        while(i<=n){
            while(j<i&&sum[j]<=sum[i]-sum[j])
                j++;
            temp = max(sum[i] - sum[j], sum[j-1]);
            temp = max(sum[n] - sum[i], temp);
            if(temp<Max)
                Max=temp;
            i++;
        }
        printf("%lld\n",Max);
    }
    return 0;
}

