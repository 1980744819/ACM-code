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
    int n;
    long long i,j;
    long long num;
    scanf("%d",&n);
    printf("2\n");
    for(i=2;i<=n;i++){
        num=i*(i+1)*(i+1)-(i-1);
        printf("%lld\n",num);
    }
    return 0;
}

