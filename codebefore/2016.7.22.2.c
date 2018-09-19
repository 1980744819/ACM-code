#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char dictionary[10005][20];
char check_words[55][20];
int lend[10005];
int lenc[55];
int m,n;
void check(int num){
    int flag=0;
    int i,j;
    printf("%s",check_words[num]);
    for(i=0;i<m;i++){
        if(strcmp(check_words[num],dictionary[i])==0){
            printf(" is correct\n");
            return;
        }
    }
    printf(":");
    int sum;
    int time=0;

    int k;
    char ch[20];
    int a;
    int f;
    for(i=0;i<m;i++){
        if(lend[i]==lenc[num]-1){
            for(j=0;j<lenc[num];j++){
                    f=0;
                for(k=0;k<j;k++){
                    ch[k]=check_words[num][k];
                }
                for(k=j+1;k<lenc[num];k++){
                    ch[k-1]=check_words[num][k];
                }
                for(k=0;k<lenc[num]-1;k++){
                    if(ch[k]!=dictionary[i][k]){
                        f=1;
                        break;
                    }
                }
                if(!f){
                    printf(" %s",dictionary[i]);
                    break;
                }
            }
        }
    }
    for(i=0;i<m;i++){
        if(lenc[num]==lend[i]){
            sum=0;
            for(j=0;j<lenc[num];j++){
                if(check_words[num][j]!=dictionary[i][j]){
                    sum++;
                }
            }
            if(sum==1){
                printf(" %s",dictionary[i]);
            }
        }
    }

    for(i=0;i<m;i++){
        if(lenc[num]==lend[i]-1){
            for(j=0;j<lend[i];j++){
                    f=0;
            for(k=0;k<j;k++){
                ch[k]=dictionary[i][k];
            }
            for(k=j+1;k<lend[i];k++){
                ch[k-1]=dictionary[i][k];
            }
            for(k=0;k<lend[i]-1;k++){
                if(ch[k]!=check_words[num][k]){
                    f=1;
                    break;
                }
            }
            if(!f){
                printf(" %s",dictionary[i]);
                break;
                }
            }
        }
    }
        printf("\n");
}
int main(){
    int i,j;
    char ch[20];
    m=0;
    while(scanf("%s",dictionary[m])){
        lend[m]=strlen(dictionary[m]);
        if(dictionary[m][0]=='#')
            break;
        m++;
    }
    n=0;
    while(scanf("%s",check_words[n])){
        lenc[n]=strlen(check_words[n]);
        if(check_words[n][0]=='#')
            break;
        n++;
    }
    for(i=0;i<n;i++){
        check(i);
    }
    return 0;
}

