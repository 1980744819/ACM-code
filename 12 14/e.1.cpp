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
int a[205],b[205];
int main(){
    int n,m;
    int i,j;
    int tmp;
    bool flag;
    while(~scanf("%d %d",&n,&m)){
        int num;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&num);
        for(i=0;i<num;i++){
            scanf("%d",&tmp);
            a[tmp]=1;
        }
        scanf("%d",&num);
        for(i=0;i<num;i++){
            scanf("%d",&tmp);
            b[tmp]=1;
        }
        int Max=max(m,n);
        for(int i=0;i<10000;i++)
            if(a[i%n]||b[i%m])
                a[i%n]=b[i%m]=1;
        flag=0;
        for(i=0;i<n||i<m;i++){
            if(i<n&&a[i%n]==0){
                flag=1;
                break;
            }
            if(i<m&&b[i%m]==0){
                flag=1;
                break;
            }
        }
        if(flag)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}

