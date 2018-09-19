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

int main(){
    int n;
    int a[5][5];
    int i,j;
    scanf("%d",&n);
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            a[i][j]=n;
            n++;
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

