#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    double a,b;
    while(T--){
        scanf("%lf %lf",&a,&b);
        if(a<=b)
            printf("0.000000\n");
        else
            printf("%.6f\n",1+log(a/b));
    }
    return 0;
}


