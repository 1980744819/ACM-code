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
int a[3005],b[3005];
int main(){
    int n,m;
    int i,j;
    int ans;
    int coun;
    bool flag;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=m)
            b[a[i]]++;
    }
    coun=n/m;
    ans=0;
    //int ans=0;
    //printf("%d\n",m);
    for(i=1;i<=n;i++){
        if(a[i]>m){
            //printf("%d %d\n",i,a[i]);
            for(j=1;j<=m;j++){
                //printf("???");
                if(b[j]<coun){
                    b[j]++;
                    a[i]=j;
                    ans++;
                    break;
                }
            }
        }
    }
    flag=true;
    for(i=1;i<=n;i++){
        if(a[i]>m){
            flag=false;
            break;
        }
    }
    if(flag){
        for(i=1;i<=n;i++){
            if(b[a[i]]>coun){
                for(j=1;j<=m;j++){
                    if(b[j]<coun){
                        b[j]++;
                        b[a[i]]--;
                        a[i]=j;
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    printf("%d %d\n",coun,ans);
    for(i=1;i<=n;i++){
        printf("%d",a[i]);
        if(i!=n)
            printf(" ");
    }
    printf("\n");
    return 0;
}

