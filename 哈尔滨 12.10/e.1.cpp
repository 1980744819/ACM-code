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
long long a[100005];
struct stu{
    long long num;
    int id;
}c[100005];
bool cmp(struct stu u,struct stu v){
    return u.num>v.num;
}
/*int fin(int low,int high,int val){
    if(low==high)
        return c[low].id;
    int mid=(low+high)/2;
    if(c[mid].num>=)
}*/
int main(){
    int t;
    int i,j,k;
    int n;
    int b;
    int ans,tmp;
    scanf("%d",&t);
    int m;
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            c[i].num=a[i];
            c[i].id=i;
        }
        sort(c,c+n,cmp);
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&b);
            ans=b;
            t=0;
            while(ans!=0&&t<n){
                ans%=a[t];
                t++;
                while(a[t]>ans&&t<n)
                    t++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

