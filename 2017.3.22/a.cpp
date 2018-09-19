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
int a[3];
int main(){
    while(~scanf("%d %d %d",&a[0],&a[1],&a[2])){
        sort(a,a+3);
        printf("%d->%d->%d\n",a[0],a[1],a[2]);
    }
    return 0;
}

