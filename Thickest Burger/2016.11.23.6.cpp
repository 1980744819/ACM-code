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
    int t;
    scanf("%d",&t);
    int a,b;
    while(t--){
        scanf("%d %d",&a,&b);
        if(a>b)
            printf("%d\n",2*a+b);
        else
            printf("%d\n",2*b+a);
    }
    return 0;
}



