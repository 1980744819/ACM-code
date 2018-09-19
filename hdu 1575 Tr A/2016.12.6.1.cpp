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
#define mod 9973
using namespace std;
int n,k;
struct mat{
    int m[12][12];
    mat(){
        memset(m,0,sizeof(m));
    }
};
mat state;
mat operator * (mat , mat);
mat operator ^ (mat a,int b){
    mat ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans.m[i][j]=(i==j);
        }
    }
    while(b>=1){
        if(b&1)
            ans=ans*a;
        b>>=1;
        a=a*a;
    }
    return ans;
}
mat operator *(const mat a,const mat b){
    mat ans;
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                ans.m[i][j]+=(a.m[i][k]*b.m[k][j])%mod;
            }
            ans.m[i][j]%=mod;
        }
    }
    return ans;
}

int main(){
    int t;
    int i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&state.m[i][j]);
            }
        }
        mat c;
        c=state^k;
        int ans=0;
        for(i=0;i<n;i++){
                ans+=c.m[i][i];
        }
        printf("%d\n",ans%mod);
    }
    return 0;
}

