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
long long num[100005];
int fin(int low,int high,int val){
    if(high-low<=1)
        return low;
    int mid=(low+high)/2;
    if(num[mid]<=val)
        fin(low,mid,val);
    else
        fin(mid,high,val);
}
int main(){
    int t;
    int n;
    int m;
    int i,j,k;
    int b;
    long long last;
    int coun;
    long long temp;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%lld",&last);
        num[0]=last;
        coun=1;
        for(i=1;i<n;i++){
            scanf("%lld",&temp);
            if(temp<last){
                last=temp;
                num[coun]=last;
                coun++;
            }
        }
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&b);
            int x=0;
            while(x<coun&&b!=0){
                b%=num[x];
                x=fin(x+1,coun-1,b);
            }
            printf("%d\n",b);
        }
    }
    return 0;
}

