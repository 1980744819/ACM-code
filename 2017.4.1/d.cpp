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
//int a[105];
int main(){
    long long n;
    int i,j,k;
    long long coun;
    long long a,b;
    long long tmp;
    while(~scanf("%lld",&n)){
        i=2;
        a=1,b=1;
        coun=0;
        while(a+b<=n){
            tmp=a;
            a=b;
            b=a+tmp;
            coun++;
        }
        printf("%lld\n",coun);
    }
    return 0;
}

