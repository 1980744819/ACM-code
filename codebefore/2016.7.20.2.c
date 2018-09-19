#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char map[10][10];
char input[40];
struct white{
    char c;
    int d;
}white[6][64];
struct black{
    char c;
    int d;
}black[6][64];
int bl[6];
int wh[6];
int firstinput_white(char ch){
    switch(ch){
        case 'K': return 0;
        case 'Q': return 1;
        case 'R': return 2;
        case 'B': return 3;
        case 'N': return 4;
        case 'P': return 5;
    }
}
int firstinput_black(char ch){
    switch(ch){
        case 'k': return 0;
        case 'q': return 1;
        case 'r': return 2;
        case 'b': return 3;
        case 'n': return 4;
        case 'p': return 5;
    }
}
char return_al(int y){
    switch(y){
        case 0:return 'a';
        case 1:return 'b';
        case 2:return 'c';
        case 3:return 'd';
        case 4:return 'e';
        case 5:return 'f';
        case 6:return 'g';
        case 7:return 'h';
    }
}
char out(int i){
    switch(i){
        case 0:return 'K';
        case 1:return 'Q';
        case 2:return 'R';
        case 3:return 'B';
        case 4:return 'N';
        case 5:return '\0';
    }
}
void init(){
    int i,j;
    for(i=0;i<64;i++){
        bl[i]=-1;
        wh[i]=-1;
    }
}
int main(){
    int i,j;
    int len;
    int x=0,y=0;
    int a;
    int blsum=0,whsum=0;
    for(i=1;i<=17;i++){
        scanf("%s",input);
        if(i%2==0){
            j=0;
            //len=strlen(input);
            //printf("%d\n",len);
            y=0;
            while(j<31){
                if(input[j+2]==':'||input[j+2]=='.'){
                    map[x][y]=' ';
                }
                else{
                    map[x][y]=input[j+2];
                    if(input[j+2]=='k'||input[j+2]=='q'||input[j+2]=='r'||input[j+2]=='b'||input[j+2]=='n'||input[j+2]=='p'){
                        a=firstinput_black(map[x][y]);
                        black[a][bl[a]].c=return_al(y);
                        black[a][bl[a]].d=8-x;
                        //printf("%d %c %d\n",a,black[a][bl[a]].c,black[a][bl[a]].d);
                        blsum++;
                        bl[a]++;
                    }
                }
                j+=4;
                y++;
            }
            x++;
        }
    }
    char ch;
    int count=0;
    for(i=7;i>=0;i--){
        for(j=0;j<8;j++){
            if(map[i][j]=='K'||map[i][j]=='Q'||map[i][j]=='R'||map[i][j]=='B'||map[i][j]=='N'||map[i][j]=='P'){
                a=firstinput_white(map[i][j]);
                white[a][wh[a]].c=return_al(j);
                white[a][wh[a]].d=8-i;
                whsum++;
                wh[a]++;
            }
        }
    }
    printf("White: ");
    for(i=0;i<6;i++){
            ch=out(i);
            j=0;
            while(j<wh[i]){
                if(ch!='\0')
                printf("%c",ch);
                printf("%c%d",white[i][j].c,white[i][j].d);
                if(count<whsum-1)
                    printf(",");
                count++;
                j++;
            }
    }
    printf("\n");
    count=0;
    printf("Black: ");
    for(i=0;i<6;i++){
            ch=out(i);
            j=0;
            while(j<bl[i]){
                if(ch!='\0')
                printf("%c",ch);
                printf("%c%d",black[i][j].c,black[i][j].d);
                if(count<blsum-1)
                    printf(",");
                count++;
                j++;
            }
    }
    printf("\n");
    /*for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}
