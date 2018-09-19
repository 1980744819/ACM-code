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
    int i,j;
    int p,k;
    while(~scanf("%d %d",&k,&p)){
        if(k/(p-1)%2==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
