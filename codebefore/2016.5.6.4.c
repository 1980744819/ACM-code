#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
struct stu{
    double left;
    double right;
}p[10001],temp;
int main(){
    int n;
    double r,x,y;
    int i,j;
    int Case=1;
    while(scanf("%d %lf",&n,&r)&&(n||r)){
        int flag=0;
        for(i=0;i<n;i++){
            scanf("%lf%lf",&x,&y);
            if(fabs(y)>r){
                flag=1;
                //break;
            }
            p[i].left=x*1.0-sqrt(r*r-y*y);
            p[i].right=x*1.0+sqrt(r*r-y*y);
            if(p[i].left>p[i].right){
                double a=p[i].left;
                p[i].left=p[i].right;
                p[i].right=a;
            }
        }
        printf("Case %d: ",Case);
        Case++;
        for(i=0;i<n;i++){
            for(j=0;j<i;j++){
                if(p[i].left<p[j].left){
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }
        if(flag)
            printf("-1\n");
        else{
            int count=1;
            temp=p[0];
            for(i=1;i<n;i++){
                if(p[i].left>temp.right){
                    count++;
                    temp=p[i];
                }
                else if(p[i].right<temp.right)
                    temp=p[i];
            }
        printf("%d\n",count);
        }
    }
    return 0;
}

