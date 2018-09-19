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
int a[105];
bool book[105];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int num;
    int i,j;
    int lea=0;
    int coun;
    int pos;
    for(i=0;i<n;i++)
        a[i]=i;
    while(k--){
        scanf("%d",&num);
        pos=(num+lea)%n;
        printf("%d",a[pos]+1);
        if(k!=0)
            printf(" ");
        for(i=pos;i<n-1;i++){
            a[i]=a[i+1];
        }
        lea=pos;
        n--;
    }
    printf("\n");
    return 0;
}

