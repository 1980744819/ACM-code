#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<malloc.h>
#include<algorithm>
using namespace std;
struct stu{
    int start;
    int en;
}plan[1005];
bool cmp(struct stu a,struct stu b){
    return a.en<b.en;
}
int main(){
    int n,m;
    int i,j,k;
    while(~scanf("%d",&m)){
        while(m--){
           scanf("%d",&n);
           for(i=0;i<n;i++){
                int a,b;
                scanf("%d %d",&a,&b);
                plan[i].start=a;
                plan[i].en=a+b;
           }
           sort(plan,plan+n,cmp);
           int end=-1;
           int ans=0;
           for(i=0;i<n;i++){
               if(end<=plan[i].start){
                   end=plan[i].en;
                   ans++;
               }
           }
           printf("%d\n",ans);
        }
    }
}

