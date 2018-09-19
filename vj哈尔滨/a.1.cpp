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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int i,j,k;
        int tmp;
        int coun=0;
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            if(tmp==1)
                coun++;
        }
        double ans=0.0;
        ans=coun*1.0/n;
        printf("%.2lf\n",ans);
    }
    return 0;
}

