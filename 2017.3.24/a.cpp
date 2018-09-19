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
    int i,j;
    for(i=0;i<40;i++){
        j=823-i*23;
        if(j%19==0){
            j/=19;
            if(j>i){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}

