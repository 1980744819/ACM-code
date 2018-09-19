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
long long num;
bool istrue(long long a){
    long long i=2;
    while(i*i<=a){
        if(a%i==0)
            return false;
        i++;
    }
    return true;
}
int main(){
    num=3;
    while(num<=2147483648){
        if(istrue(num)){
            printf("%lld,",num);
        }
        num++;
    }
    return 0;
}

