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
int a[50005];
int main(){
    int n;
    int i,j;
    int Max,Min;
    int coun;
    while(~scanf("%d",&n)){
            coun=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            Max=a[i];
            Min=a[i];
            for(j=i;j<n;j++){
                if(a[j]>Max)
                    Max=a[j];
                if(a[j]<Min)
                    Min=a[j];
                if(Max-Min==j-i)
                    coun++;
            }
        }
        printf("%d\n",coun);
    }
    return 0;
}

