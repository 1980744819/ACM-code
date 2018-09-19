#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int a[200005],color[200005];
bool exit[200005];
int find(int u){
    if(a[u]==u)
        return u;
    else
        return a[u]=find(a[u]);
}
void unio_set(int u,int v){
    int p1=find(u);
    int p2=find(v);
    if(p1!=p2)
        a[p1]=p2;
}
int main(){
    int n,m,k;
    int i,j;
    int coun1,coun2;
    int l,r;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
        a[i]=i;
    for(i=1;i<=n;i++){
        scanf("%d",&color[i]);
    }
    coun1=0;
    while(m--){
        scanf("%d %d",&l,&r);
        if(!exit[l]){
            exit[l]=true;
            coun1++;
        }
        if(!exit[r]){
            exit[r]=true;
            coun1++;
        }
        unio_set(l,r);
    }
    coun2=0;
    return 0;
}

