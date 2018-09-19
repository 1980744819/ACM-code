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
int a[5005];
int b[5005];
int main(){
    int i,j,k;
    int n;
    int lena,lenb;
    while(~scanf("%d",&n)){
        lena=0;
        lenb=0;
        for(i=n;i>=1;i--){
            if(i&1){
                a[lena]=i;
                lena++;
            }
            else{
                b[lenb]=i;
                lenb++;
            }
        }
        int ans=n;
        int flag=0;
        if(a[lena-1]-b[0]==1||a[lena-1]-b[0]==-1){
            flag=1;
             n--;
        }
        printf("%d\n",ans);
        printf("%d",a[0]);
        for(i=1;i<lena;i++)
            printf(" %d",a[i]);
        if(!flag)
            printf(" %d",b[0]);
        for(i=1;i<lenb;i++)
            printf(" %d",b[i]);
        printf("\n");
    }
    return 0;
}

