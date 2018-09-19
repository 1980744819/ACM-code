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
    set<int> a[55];
    int n;
    int num;
    int i,j;
    int tmp;
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++){
            scanf("%d",&num);
            for(j=0;j<num;j++){
                scanf("%d",&tmp);
                a[i].insert(tmp);
            }
        }
    }
    return 0;
}

