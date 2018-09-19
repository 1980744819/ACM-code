#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int n;
    while(~scanf("%d",&n)){
        long long Min;
        long long step[105];
        int i,j;
        step[1]=1;
        step[2]=3;
        long long m;
        for(i=3;i<=n;i++){
            Min=99999999999999999;
            for(j=1;j<i;j++){
                m=2*step[j]+(long long)pow(2,i-j)-1;
                printf("%lld\n",m);
                if(Min>m)
                    Min=m;
            }
            step[i]=Min;
            //printf("%d\n",Min);
        }
        printf("%lld\n",step[n]);
    }
    return 0;
}
