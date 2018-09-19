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
bool is(int num){
    int i;
    for(i=2;i*i<=num;i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}
int main(){
    int i;
    for(i=2;i*i<=100000000;i++){
        if(is(i))
            printf("%d,",i);
    }
    return 0;
}
