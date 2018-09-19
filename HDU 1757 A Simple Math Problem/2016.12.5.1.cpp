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
struct stu{
    int mtr[10][10];
}a,b,c;
int m;
int n;
struct stu mult(struct stu a1,struct stu a2){
    struct stu temp;
    int i,j,k;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            temp.mtr[i][j]=0;
            for(k=0;k<10;k++){
                temp.mtr[i][j]+=(a1.mtr[i][k]*a2.mtr[k][j])%m;
            }
            temp.mtr[i][j]%=m;
        }
    }
    return temp;
};
struct stu bin(int cnt){
    struct stu tmp;
    if(cnt==1)
        return a;
    if(cnt%2==0){
        tmp=bin(cnt/2);return mult(tmp,tmp);
    }
    else{
        tmp=bin((cnt-1)/2);
        tmp=mult(tmp,tmp);
        return mult(tmp,a);
    }
};
int main(){
    int i,j,k;
    while(~scanf("%d %d",&n,&m)){
        memset(a.mtr,0,sizeof(a.mtr));
        for(i=1;i<10;i++)
            a.mtr[i][i-1]=1;
        for(i=0;i<10;i++)
            scanf("%d",&a.mtr[0][i]);
        if(n<10){
            printf("%d\n",n%m);
            continue;
        }
        n-=9;
        c=bin(n);
        int ans=0;
        for(i=0;i<10;i++)
            ans+=(c.mtr[0][i]*(9-i))%m;
        printf("%d\n",ans%m);
    }
    return 0;
}

