#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char s[10][62];
char p[62];
int next[62];
int plen;
int n;
int ma;
int ans;
char result[62];
void getnext(){
    int j=0;
    int k=-1;
    next[0]=-1;
    while(j<plen-1){
        if(k==-1||p[j]==p[k]){
            ++k;
            ++j;
            if(p[j]!=p[k]){
                next[j]=k;
            }
            else
                next[j]=next[k];
        }
        else{
            k=next[k];
        }
    }
}
void kmp(){
    getnext();
    ma=100;
    int i,j,m;
    int k;
    for(k=1;k<n;k++){
        i=0;j=0;m=0;
        while(i<60&&j<plen){
            if(j==-1||s[k][i]==p[j]){
                i++;
                j++;
            }
            else{
                j=next[j];
            }
            if(j>m)m=j;
        }
        if(ma>m)ma=m;
    }
}
int main(){
    int kase;
    scanf("%d",&kase);
    int i;
    while(kase--){
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",s[i]);
        }
        for(i=0;i<57;i++){
            strcpy(p,s[0]+i);
            plen=60-i;
            kmp();
            if(ans<ma){
                ans=ma;
                strncpy(result,s[0]+i,ans);
                result[ans]='\0';
            }
            else if(ans==ma){
                char tm[62];
                strncpy(tm,s[0]+i,ans);
                tm[ans]='\0';
                if(strcmp(tm,result)<0)
                    strcpy(result,tm);
            }
        }
        if(ans>=3){
            printf("%s\n",result);
        }
        else{
            printf("no significant commonalities\n");
        }
    }
    return 0;
}
