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
    int n;
    while(~scanf("%d",&n)){
        int a=1,b=0,c=0;
        for(i=1;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
            printf("%d %d\n",i,c);
        }
    }
    return 0;
}
