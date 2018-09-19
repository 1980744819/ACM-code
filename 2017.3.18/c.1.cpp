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
int s[300009],p[300009];
void manacher(int len){
    int i;
    int mx=0;
    int id=0;
    for(i=0;i<=len;i++){
        if(mx>i){
            p[i]=min(p[2*id-i],mx-i);
        }
        else{
            p[i]=1;
        }
        while(s[i+p[i]]==s[i-p[i]]){
            p[i]++;
        }
        if(p[i]+i>mx){
            mx=p[i]+i;
            id=i;
        }
    }
    /*
    for(i=0;i<=len;i++){
        printf("%2d  ",s[i]);
    }
    printf("\n");
    for(i=0;i<=len;i++){
        printf("%2d  ",p[i]);
    }
    printf("\n");*/
}
int main(){
    int t;
    int kase=1;
    scanf("%d",&t);
    int i,j;
    int len;
    int n;
    while(t--){
        scanf("%d",&n);
        len=0;
        s[len++]=-1;
        for(i=0;i<=2*n+1;i++){
            p[i]=0;
        }
        for(i=1;i<=n;i++){
            scanf("%d",&s[len++]);
            s[len++]=-1;
        }
        len--;
        int ans=1;
        manacher(len);
        for(i=2;i<=len;i+=2){
            for(j=ans;j<=p[i];j+=2){
                if(p[i+j-1]>=j){
                    ans=j;
                }
            }
        }
        printf("Case #%d: ",kase++);
        printf("%d\n",ans/2*3);
    }
    return 0;
}

