#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<malloc.h>
#include<cmath>
using namespace std;
int num[7];
int main(){
    int a[7]={1,2,5,10,20,50,100};
    int t;
    int i;
    while(~scanf("%d",&t)){
        while(t--){
            int money;
            scanf("%d",&money);
            for(i=6;i>=0;i--){
                num[i]=money/a[i];
                money%=a[i];
            }
            for(i=0;i<7;i++){
                printf("%d ",num[i]);
            }
            cout<<endl;
        }
    }
    return 0;
}
