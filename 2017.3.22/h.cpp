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
char a[10005],b[10005];
bool vis[10005];
int main(){
    int i,j;
    gets(a);
    gets(b);
    int lena=strlen(a);
    int lenb=strlen(b);
    for(i=0;i<lenb;i++){
        char c=b[i];
        for(j=0;j<lena;j++){
            if(c==a[j]){
                vis[j]=true;
            }
        }
    }
    for(i=0;i<lena;i++){
        if(!vis[i]){
            printf("%c",a[i]);
        }
    }
    printf("\n");
    return 0;
}
