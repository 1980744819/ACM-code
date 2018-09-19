#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char s[11][70];
int lens[11];
int m;
int max;
char ch[70];
int lench;
int next[70];
char ans[22][70];
int lenans;
int ansi;
void getnext(){
    next[0]=-1;
    int k=-1;
    int j=0;
    while(j<lench-1){
        if(k==-1||ch[j]==ch[k]){
            ++j;
            ++k;
            if(ch[j]!=ch[k])
                next[j]=k;
            else
                next[j]=next[k];
        }
        else{
            k=next[k];
        }
    }
}
void copy(int i,int j){
    int k;
    lench=j-i+1;
    for(k=i;k<=j;k++){
        ch[k-i]=s[0][k];
    }
}
int kmpsearch(int k){
    int i=0;
    int j=0;
    while(i<lens[k]&&j<lench){
        if(j==-1||s[i]==ch[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if(j==lench)
        return 1;
    else
        return 0;
}
void anscopy(int i){
    int j;
    for(j=0;j<70;j++){
        ans[i][j]='\0';
    }
    for(j=0;j<lench;j++){
        ans[i][j]=ch[j];
    }
}
void sort(){
    int i,j;
    for(i=0;i<=ansi;i++){
        for(j=i+1;j<=ansi;j++){
            if(strcmp(ans[i],ans[j])>0){
                char c[70];
                memset(c,'0',sizeof(c));
                strcpy(c,ans[i]);
                strcpy(ans[i],ans[j]);
                strcpy(ans[j],c);
            }
        }
    }
}
int main(){
    int kase;
    scanf("%d",&kase);
    int i,j,k;
    while(kase--){
        int flag=0;
        max=0;
        ansi=0;
        lenans=0;
        scanf("%d",&m);
        for(i=0;i<m;i++){
            memset(s[i],'\0',sizeof(s[i]));
            scanf("%s",s[i]);
            lens[i]=strlen(s[i]);
        }
        for(i=0;i<lens[0]-3;i++){
            for(j=i+2;j<lens[0];j++){
                copy(i,j);
                getnext();
                for(k=1;k<m;k++){
                    if(kmpsearch(k)){
                        flag=1;
                        if(lench>max){
                            max=lench;
                            ansi=0;
                            anscopy(ansi);
                        }
                        else if(lench==max){
                            ansi++;
                            anscopy(ansi);
                        }
                    }
                }
            }
        }
        if(flag){//≈≈–Ú
            sort();
            for(i=0;i<=ansi;i++){
                printf("%s",ans[i]);
                if(i!=ansi)
                    printf(" ");
            }
            printf("\n");
        }
        else{
            printf("no significant commonalities\n");
        }
    }
    return 0;
}
