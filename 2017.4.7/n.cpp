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
    int ma,mi;
    int n;
    int coun;
    int num;
    while(~scanf("%d",&n)){
        coun=0;
        ma=-9999999;
        mi=9999999;
        while(n--){
            scanf("%d",&num);
            coun+=num;
            if(ma<num)
                ma=num;
            if(mi>num)
                mi=num;
        }
        printf("%d\n%d\n%d\n",ma,mi,coun);
    }
    return 0;
}

