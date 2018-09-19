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
    int a[205];
    int i;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        printf("%d",a[0]);
        for(i=1;i<n;i++){
            printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}

