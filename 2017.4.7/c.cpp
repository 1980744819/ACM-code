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
int main(){
    long long ans;
    long long num;
    while(~scanf("%lld",&num)){
        printf("%lld\n",num*(num-1)/2+num);
    }
    return 0;
}

