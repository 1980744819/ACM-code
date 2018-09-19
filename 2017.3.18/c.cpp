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
int a[100005];
int c[100005],d[100005],e[100005];
bool judege(int start,int end,int len){
    for(i=start,i<start+len;i++)
    for(i=start+len+len-1;i>=start+len;i--)
    for(i=start+len+len;i<=end;i)
}
int solve(int start,int end,long long sum){
    int t=start-end+1;
    int num=t%3;
    long long m;
    int i,j;
    if(num==0){
        if(sum%3==0){

        }
        else{
            return max(solve(start+1,end,sum-a[start]),solve(start,end-1,sum-a[end]));
        }
    }
    else if(num==1){

    }
    else if(num==2){

    }
}
int main(){
    int t,n;
    int i,j;
    int kase=1;
    int ans=0;
    long long sum;
    scanf("%d",&t);
    while(t--){
        sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        printf("Case #%d: ",&kase++);
    }
    return 0;
}

