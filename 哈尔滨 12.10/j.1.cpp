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
int a[100];
bool judge(long long num){
    long long i;
    for(i=2;i*i<=num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}
int main(){
    int coun;
    int i,j,k;
    long long num;
    long long mnum;
    long long tmp;
    a[0]=1;
    a[1]=2;
    coun=0;
    while(coun<1005){
        a[1]++;
        if(a[1]>=10){
            for(i=1;i<=a[0];i++){
                if(a[i]>=10){
                    a[i]-=10;
                    a[i+1]++;
                    if(i==a[0])
                        a[0]++;
                }
            }
        }
        num=0;
        mnum=0;
        tmp=1;
        for(i=1;i<=a[0];i++){
            num+=a[i]*tmp;
            tmp*=10;
        }
        tmp=1;
        for(i=a[0];i>=1;i--){
            mnum+=a[i]*tmp;
            tmp*=10;
        }
        if(judge(num)&&judge(mnum)&&num!=mnum){
            coun++;
            printf("%lld,",num);
        }
    }
    return 0;
}

