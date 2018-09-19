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
long long a[200005];
int main(){
    long long min,min_coun;
    int n;
    int i,j,k;
    scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        min=999999999999999;
        min_coun=1;
        long long dis;
        sort(a,a+n);
        for(i=0;i<n-1;i++){
            dis=a[i+1]-a[i];
            if(dis<0)
                dis=0-dis;
            if(dis<min){
                min=dis;
                min_coun=1;
            }
            else if(dis==min){
                min_coun++;
            }
        }
        printf("%lld %lld\n",min,min_coun);
    return 0;
}

