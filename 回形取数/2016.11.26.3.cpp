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
    int a,b;
    int m,n;
    int p[100005],q[100005];
    int i;
    int flag=0;
    int nump,numq;
    while(~scanf("%d %d",&m,&n)){
        a=0;
        b=0;
        nump=0;
        numq=0;
        for(i=1;i<=m;i++){
            scanf("%d",&p[i]);
            if(p[i]>n)
                flag=1;
            if(p[i]==n)
                nump++;
            a+=p[i];
        }
        for(i=1;i<=n;i++){
            scanf("%d",&q[i]);
            if(q[i]>m)
                flag=1;
            if(q[i]==m)
                numq++;
            b+=q[i];
        }
        for(i=1;i<m;i++){
            if(p[i]<numq)
                flag=1;
        }
        for(i=1;i<n;i++)
            if(q[i]<nump)
                flag=1;
        if(flag){
            printf("NO\n");
        }
        else{
            if(a==b)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
