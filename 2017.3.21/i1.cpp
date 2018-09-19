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
    int t;
    long long n,p;
    long long i,j;
    long long coun=0;
    scanf("%d",&t);
    while(t--){
            scanf("%lld %lld",&n,&p);
            coun=0;
            for(i=1;i*i<=n;i++){
                if(n%i==0){
                    if(n/i!=i){
                        coun+=2;
                    }
                    else{
                        coun+=1;
                    }
                }
            }
            if(coun==p)
                printf("YES\n");
            else
                printf("NO\n");
    }
    return 0;
}

