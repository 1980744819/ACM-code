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
int a[10006];
int main(){
    int i,j;
    int n;
    int num;
    int coun;
    while(~scanf("%d",&n)){
        memset(a,-1,sizeof(a));
        coun=1;
        while(n--){
            scanf("%d",&num);
            if(a[num]==-1){
                a[num]=coun;
            }
            coun++;
        }
        scanf("%d",&num);
        printf("%d\n",a[num]);
    }
    return 0;
}

