#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<malloc.h>
#include<cmath>
#include<stack>
using namespace std;
struct stu{
    int number;
    int qu;
};
bool cmp(struct stu a,struct stu b){
    return a.qu>b.qu;
}
int main(){
    int i,j;
    int m,n,k,l,d;
    int t;
    int s1[1005];
    //int s2[1005];
    while(~scanf("%d %d %d %d %d",&m,&n,&k,&l,&d)){
        struct stu mp_r[1005],mp_l[1005];
        for(i=0;i<=m;i++){
            mp_r[i].number=i;
            mp_r[i].qu=0;
        }
        for(i=0;i<=n;i++){
            mp_l[i].number=i;
            mp_l[i].qu=0;
        }
        int a1,a2,b1,b2;
        for(i=0;i<d;i++){
            scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
            if(a1==b1){
                t=min(a2,b2);
                mp_l[t].qu++;
            }
            else{
                t=min(a1,b1);
                mp_r[t].qu++;
            }
        }
        sort(mp_r,mp_r+m+1,cmp);
        sort(mp_l,mp_l+n+1,cmp);
        for(i=0;i<k;i++){
            s1[i]=mp_r[i].number;
        }
        sort(s1,s1+k);
        for(i=0;i<k;i++)
            printf("%d ",s1[i]);
        printf("\n");
        for(i=0;i<l;i++){
            s1[i]=mp_l[i].number;
        }
        sort(s1,s1+l);
        for(i=0;i<l;i++)
            printf("%d ",s1[i]);
        printf("\n");
    }
    return 0;
}


