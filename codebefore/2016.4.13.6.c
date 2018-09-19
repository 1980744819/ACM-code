#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char s[10][10];
int a[100];
int b[100];
int top=0;
int stx,sty;
int enx,eny;
int flag=0;
void ge(int i,int j){
    while(i!=enx||j!=eny){
        switch( pan(i,j) ){
        case 1:j++;s[i][j]='*';top++;a[top]=i;b[top]=j;break;
        case 2:i++;s[i][j]='*';top++;a[top]=i;b[top]=j;break;
        case 3:j--;s[i][j]='*';top++;a[top]=i;b[top]=j;break;
        case 4:i--;s[i][j]='*';top++;a[top]=i;b[top]=j;break;
        default:
            s[a[top]][b[top]]='!';
            top--;
            if(top>=0){
                i=a[top];
                j=b[top];
            }
            else
                flag=1;
            break;
        }
        if(flag==1)
            break;
    }
}
int pan(int i,int j){
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int k;
    int tx,ty;
    for(k=0;k<4;k++){
        tx=i+next[k][0];
        ty=j+next[k][1];
        if(s[tx][ty]==' '||s[tx][ty]=='E'){
            return k+1;
        }
    }
    return -1;
}
int cho(int i,int j){

}
int main(){
    int i,j;
    for(i=0;i<10;i++){
        gets(s[i]);
    }
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(s[i][j]=='S'){
                stx=i;
                sty=j;
            }
            else if(s[i][j]=='E'){
                enx=i;
                eny=j;
            }
        }
    }
    a[top]=stx;
    b[top]=sty;
    s[a[top]][b[top]]='*';
    ge(stx,sty);
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%c",s[i][j]);
        };
        printf("\n");
    }
    return 0;
}

