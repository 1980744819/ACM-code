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
bool know[5005];
int a[5005];
int main(){
    int n;
    int i,j;
    int x,y,z;
    int coun;
    int a1,a2,a3;
    int ans;
    scanf("%d",&n);
    coun=0;
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d",&a1);
    printf("? 1 3\n");fflush(stdout);
    scanf("%d",&a2);
    printf("? 2 3\n");fflush(stdout);
    scanf("%d",&a3);
    ans=a1+a2+a3;
    ans/=2;
    z=ans-a1;
    y=ans-a2;
    x=ans-a3;
    a[1]=x;
    a[2]=y;
    a[3]=z;
    know[1]=know[2]=know[3]=true;
    coun=3;
    int tmp;
    i=4;
    while(coun<n){
        printf("? %d %d\n",i-1,i);fflush(stdout);
        scanf("%d",&tmp);
        a[i]=tmp-a[i-1];
        i++;
        coun++;
    }
    printf("!");
    for(i=1;i<=n;i++)
        printf(" %d",a[i]);
    printf("\n");
    return 0;
}

