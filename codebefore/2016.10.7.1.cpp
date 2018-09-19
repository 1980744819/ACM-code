#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
    char s[105];
    int len,i,j;
    while(~scanf("%s",s)){
        len=strlen(s);
        int ans=0;
        int score=1;
        for(i=0;i<len;i++){
            if(i==0){
                if(s[i]=='B')
                    score=1;
                else
                    score=0;
            }
            else{
                if(s[i]=='B'){
                    if(s[i-1]=='A'){
                        score=1;
                    }
                    else{
                        score++;
                    }
                }
                else{
                    score=0;
                }
            }
            ans+=score;
        }
        printf("%d\n",ans);
    }
    return 0;
}

