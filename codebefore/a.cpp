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
int a[1000005];
int main(){
    a[1]=1;
    a[2]=1;
    int n;
    int m=3;
    while(~scanf("%d",&n)){
        while(m<=n){
            a[m]=a[m-1]+a[m-2];
            a[m]%=10007;
            m++;
        }
        printf("%d\n",a[n]);
    }
    return 0;
}

