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
int main(){
    int n;
    int i,j;
    int a[10];
    int coun;
    int num;
    int tmp;
    while(~scanf("%d",&n)){
        num=10000;
        while(num<=999999){
            a[0]=num%10;
            a[1]=num%100/10;
            a[2]=num%1000/100;
            a[3]=num%10000/1000;
            a[4]=num%100000/10000;
            coun=0;
            if(num<=99999){
                for(i=0;i<5;i++){
                    coun+=a[i];
                }
                if(coun==n){
                    tmp=a[0]*10000+a[1]*1000+a[2]*100+a[3]*10+a[4];
                    if(num==tmp){
                        printf("%d\n",num);
                    }
                }
            }
            else{
                a[5]=num%1000000/100000;
                for(i=0;i<=5;i++){
                    coun+=a[i];
                }
                if(coun==n){
                    tmp=a[0]*100000+a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];
                    if(num==tmp){
                        printf("%d\n",num);
                    }
                }
            }
            num++;
        }
    }
    return 0;
}

