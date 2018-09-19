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
int s[11]={1,3,9,33,153,873,5913,46233,409113,4037913};
int main(){
    int n;
    int sum;
    while(~scanf("%d",&n)){
        printf("%d\n",s[n-1]);
    }
    return 0;
}
