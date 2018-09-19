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
    int i;
    int j;
    int col,row;
    char c;
    while(~scanf("%d %c",&n,&c)){
        col=n/2;
        if(n%2!=0)
            col++;
        for(i=0;i<col;i++){
            for(j=0;j<n;j++){
                printf("%c",c);
            }
            printf("\n");
        }
    }
    return 0;
}
