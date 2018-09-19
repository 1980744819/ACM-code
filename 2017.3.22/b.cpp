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
int a[11]={1,2,4,8,16,32,64,128,256,512,1024};
int main(){
    int n;
    while(~scanf("%d",&n)){
        printf("2^%d = %d\n",n,a[n]);
    }
    return 0;
}
