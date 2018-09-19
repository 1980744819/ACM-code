#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;

int main(){
    int t;
    int x1,x2,y1,y2;
    int n;
    int i,j,k;
    int r1,r2;
    int rt1,rt2;
    int x,y;
    double d;
    double rr1,rr2;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        d=sqrt(x);
        scanf("%d",&n);
        r1=0;
        r2=0;
        for(i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            rt1=(x-x1)*(x-x1)+(y-y1)*(y-y1);
            rt2=(x-x2)*(x-x2)+(y-y2)*(y-y2);
            if(rt1>r1&&rt2>r2){
                int a=rt1+r2;
                int b=r1+rt2;
                if(a>b){
                    r2=rt2;
                    rr2=sqrt(r2);
                    rr1=sqrt(r1);
                    if(rr2>rr1+d){
                        r1=0;
                    }
                }
                else{
                    r1=rt1;
                    rr2=sqrt(r2);
                    rr1=sqrt(r1);
                    if(rr1>rr2+d){
                        r2=0;
                    }
                }
            }
        }
        printf("%d\n",r1+r2);
    }
    return 0;
}
