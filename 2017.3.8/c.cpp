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
int a[805][805],b[805][805],c[805][805];
int main(){
    int i,j,k;
    int n;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&a[i][j]);
                a[i][j]%=3;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&b[i][j]);
                b[i][j]%=3;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i][j]){
                    for(k=0;k<n;k++){
                        c[i][k]+=a[i][j]*b[j][k];
                    }
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++){
                printf("%d ",c[i][j]%3);
                c[i][j]=0;
            }
            printf("%d\n",c[i][n-1]%3);
            c[i][n-1]=0;
        }
    }
    return 0;
}

