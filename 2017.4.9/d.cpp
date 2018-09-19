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
    map<int,int>mp;
    int t;
    int i,j;
    char c,s[30];
    scanf("%d",&t);
    int num,tmp;
    while(t--){
        getchar();
        scanf("%c %s",&c,s);
        //printf("%c %s\n",c,s);
        num=0;
        for(i=0;s[i]!='\0';i++){
            tmp=s[i]-'0';
            num*=10;
            if(tmp%2==0){
                num+=0;
            }
            else{
                num+=1;
            }
        }
        //printf("%d\n",num);
        if(c=='+'){
            mp[num]++;
        }
        else if(c=='-'){
            mp[num]--;
        }
        else if(c=='?'){
            printf("%d\n",mp[num]);
        }
    }
    return 0;
}

