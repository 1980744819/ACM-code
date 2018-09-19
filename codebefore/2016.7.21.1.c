#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char  chess[40][40];
int return_y(char ch){
    switch(ch){
        case 'a':return 0;
        case 'b':return 1;
        case 'c':return 2;
        case 'd':return 3;
        case 'e':return 4;
        case 'f':return 5;
        case 'g':return 6;
        case 'h':return 7;
    }
}
int return_x(char ch){
    switch(ch){
        case '1' :return 1;
        case '2' :return 2;
        case '3' :return 3;
        case '4' :return 4;
        case '5' :return 5;
        case '6' :return 6;
        case '7' :return 7;
        case '8' :return 8;
    }
}
int main(){
    char a[40]="+---+---+---+---+---+---+---+---+";
    char b[40]="|...|:::|...|:::|...|:::|...|:::|";
    char c[40]="|:::|...|:::|...|:::|...|:::|...|";
    char black[400];
    char white[400];
    int i,j;
    j=0;
    for(i=0.;i<17;i++){
        if(i%2!=0){
            if(j%2==0)
                strcpy(chess[i],b);
            else
                strcpy(chess[i],c);
            j++;
        }
        else
            strcpy(chess[i],a);
    }
    //printf("%d %d %d %d",'A','Z','a','z');
    gets(white);
    gets(black);
    int len;
    len=strlen(white);
    i=6;
    int x,y;
    while(i<len){
        if(white[i]==' '||white[i]==','){
            if(white[i+1]>=65&&white[i+1]<=90){
                y=return_y(white[i+2])*4+2;
                x=(8-return_x(white[i+3]))*2+1;
                chess[x][y]=white[i+1];
                i+=4;
            }
            else{
                y=return_y(white[i+1])*4+2;
                x=(8-return_x(white[i+2]))*2+1;
                chess[x][y]='P';
                i+=3;
            }
        }
    }
    i=6;
    while(i<len){
        if(black[i]==' '||black[i]==','){
            if(black[i+1]>=65&&black[i+1]<=90){
                y=return_y(black[i+2])*4+2;
                x=(8-return_x(black[i+3]))*2+1;
                chess[x][y]=black[i+1]+32;
                i+=4;
            }
            else{
                y=return_y(black[i+1])*4+2;
                x=(8-return_x(black[i+2]))*2+1;
                chess[x][y]='p';
                i+=3;
            }
        }
    }
    for(i=0;i<17;i++)
        puts(chess[i]);
    return 0;
}

