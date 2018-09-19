#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int fi(int step){
    if(step==1)
        return 6;
    else
        return 3+fi(step-1);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",fi(n));
    return 0;
}
