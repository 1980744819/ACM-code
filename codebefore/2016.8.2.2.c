#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int gcd(int a,int b){
    while(b){
        int r=b;
        b=a%b;
        a=r;
    }
    return a;
}
int main(){
    int t;
    int kase;
    int n,i,j,x1,x2,y1,y2,dx,dy,on,in,area;
    scanf("%d",&kase);
    for(t=1;t<=kase;t++){
        scanf("%d",&n);
        x1=y1=on=area=0;
        for(i=1;i<=n;i++){
            scanf("%d%d",&dx,&dy);
            x2=x1+dx;
            y2=y1+dy;
            on+=gcd(abs(dx),abs(dy));
            area+=x1*y2-x2*y1;
            x1=x2;
            y1=y2;
        }
        in=(area+2-on)/2;
        printf ("Scenario #%d:\n%d %d %.1lf\n\n", t, in, on, area/2.0);
    }
    return 0;
}
