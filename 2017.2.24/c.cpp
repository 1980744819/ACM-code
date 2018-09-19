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
int a[100000],b[100000],r[100000],d[100000];
bool visit[100000];
struct stu{
    double cost;
    int cover[100];
    bool isfiber;
}stu[200000];
bool cmp(stu p,stu q){
    return p.cost<q.cost;
}
int main(){
    int i,j,k;
    int n;
    int t;
    int b=0,range=0;
    scanf("%d",&t);
    int ans;
    while(t--){
        scanf("%d %d",&n,&k);
        for(i=1;i<n;i++)
            scanf("%d",&d[i]);
        for(i=1;i<=n;i++){
            scanf("%d %d %d",&a[i],&r[i],&b[i]);
        }
        for(i=1;i<=n;i++){
            stu[i].cover[0]=0;
            bi=1;range=0;
            for(j=i-1;j>=1;j--){
                range+=r[j];
                if(range<=r[i]){
                    stu[i].cover[bi]=j;
                    stu[i].cover[0]++;
                    bi++;
                }
                else
                    break;
            }
            stu[i].cover[bi]=i;
            stu[i].cover[0]++;
            bi++;
            range=0;
            for(j=i+1;j<=n;j++){
                range+=r[j];
                if(range<=r[j]){
                    stu[i].cover[bi]=j;
                    stu[i].cover[0]++;
                    bi++;
                }
                else
                    break;
            }
            stu[i].cost=a[i]/bi;
            stu[i].isfiber=false;
        }
        for(i=n+1;i<=2*n;i++){
            stu[i].cover[0]=0;
            stu[i].cost=b[i-n];
            stu[i].cover[0]=1;
            stu[i].cover[1]=i-n;
            stu[i].isfiber=true;
        }
        sort(stu,stu+2*n,cmp);
        ans=0;
        for(i=1;i<=2*n;i++){
            ans+=
        }
    }
    return 0;
}

