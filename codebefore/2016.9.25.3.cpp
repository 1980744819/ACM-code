#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<cmath>
#include<algorithm>
using namespace::std;
int m;
int n;
struct stu{
    char c[55];
    int num;
}s[1005];
bool comp(stu a,stu b){
    return a.num<b.num;
}
int main(){
    while(~scanf("%d %d",&n,&m)){
        int i,j,k;
        for(i=0;i<m;i++){
            scanf("%s",s[i].c);
            s[i].num=0;
            for(j=0;j<n-1;j++){
                k=j+1;
                while(k<=n){
                    if(s[i].c[j]>s[i].c[k])
                        s[i].num++;
                    k++;
                }
            }
            //cout<<s[i].num<<endl;
        }
        sort(s,s+m,comp);
        for(i=0;i<m;i++)
            printf("%s\n",s[i].c);
    }
    return 0;
}



