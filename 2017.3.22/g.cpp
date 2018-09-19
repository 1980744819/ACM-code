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
long long a[105],b[105];
bool is[105];
long long gcd(long long m,long long n){
    return (m==0)?n:gcd(n%m, m);
}
long long lcm(long long m,long long n){
    return m*n/gcd(m,n);
}
int main(){
    int n;
    int i,j;
    char c;
    long long gc,lc,sum,e,f;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            scanf("%lld%c%lld",&a[i],&c,&b[i]);
            if(a[i]<0){
                a[i]=0-a[i];
                is[i]=true;
            }
        }
        lc=b[0];
        for(i=1;i<n;i++){
            lc=lcm(lc,b[i]);
        }
        //printf("%lld\n",lc);
        sum=0;
        for(i=0;i<n;i++){
            if(is[i]){
                sum-=lc/b[i]*a[i];
                //printf("%d")
            }
            else{
                sum+=lc/b[i]*a[i];
            }
        }
        bool flag=false;
        if(sum<0){
            flag=true;
            sum=0-sum;
        }
        e=gcd(lc,sum);
        sum/=e;
        lc/=e;
        if(flag)
        printf("-");
        if(sum%lc==0)
            printf("%lld\n",sum/lc);
        else{
            if(sum>lc){
                printf("%lld %lld/%lld\n",sum/lc,sum%lc,lc);
            }
            else{
                printf("%lld/%lld",sum,lc);
            }
        }
    }
    return 0;
}
