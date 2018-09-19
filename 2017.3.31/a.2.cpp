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
char s[200005];
int main(){
    queue<int >d;
    queue<int >r;
    int n;
    int i,j;
    char c;
    while(~scanf("%d",&n)){
        scanf("%s",s);
        for(i=0;i<n;i++){
            if(s[i]=='D')
                d.push(i);
            else
                r.push(i);
        }
        while(d.size()&&r.size()){
            int a,b;
            a=d.front();
            b=r.front();
            d.pop();
            r.pop();
            if(a<b){
                d.push(a+n);
            }
            else{
                r.push(b+n);
            }
        }
        if(d.size()){
            printf("D\n");
        }
        else
            printf("R\n");
    }
    return 0;
}

