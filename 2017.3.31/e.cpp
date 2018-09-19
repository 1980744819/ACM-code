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
int Gcd(int a, int b)
{
    if(b == 0)
        return a;
    return Gcd(b, a % b);
}
int main(){
    int n;
    int b,c;
    while(~scanf("%d",&n)){
        if(n!=1){
            printf("%d",n);
        printf(" %d",n+1);
        printf(" %d\n",n*(n+1));
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}

