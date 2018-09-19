#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char s[5][5];
int book[5][5];
int count[5][5];
void handle(int i,int j){
    int k;
    for(k=0;k<4;k++)
        count[i][k]++;
    for(k=0;k<4;k++)
        if(k!=i)
        count[k][j]++;
}
int main(){
    int i,j;
    int sum=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%c",&s[i][j]);
            if(s[i][j]=='+')
                handle(i,j);
        }
        getchar();
    }
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(count[i][j]%2!=0)
                sum++;
    printf("%d\n",sum);
    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
            if(count[i][j]%2!=0)
                printf("%d %d\n",i+1,j+1);
    }
    return 0;
}

