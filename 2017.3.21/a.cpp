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
char s[50005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        if(len>=3&&s[0]==s[len-1]){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}

