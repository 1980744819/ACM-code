#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    char s[1000];
    int n;
    scanf("%d",&n);
    int i,j;
    int ans;
    while(n--){
        scanf("%s",s);
        ans=0;
        for(i=0;s[i]!='\0';i++){
            if(s[i]=='H'){
                ans+=1;
            }
            else if(s[i]=='C'){
                ans+=12;
            }
            else if(s[i]=='O'){
                ans+=16;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}




