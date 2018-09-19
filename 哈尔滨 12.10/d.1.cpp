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
struct stu{
    int c;
    int v;
    double val;
}a[105];
bool cpu[505],book[505];
bool cmp(struct stu u,struct stu v){
    return u.val>v.val;
}
int main(){
    int t;
    int i,j,k;
    int l,n,m;
    scanf("%d",&t);
    int tmp;
    while(t--){
        scanf("%d %d %d",&l,&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            book[tmp]=true;
        }
        book[0]=true;
        book[l]=true;
        for(i=0;i<m;i++){
            scanf("%d %d",&a[i].c,&a[i].v);
            a[i].val=(1.0*a[i].c)/a[i].v;
        }
        sort(a,a+m,cmp);
        for(i=0;i<m;i++){
            for(i=1;i<l;i++){
                if(book[i]==0);
            }
        }
    }
    return 0;
}

