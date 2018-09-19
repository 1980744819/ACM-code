#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int map[105][105];
int direc[105];
int a,b;
struct robnum{
    int xi,yi;
}robnum[105];
void setpos(int i,int x,int y,char ch){
    switch(ch){
        case 'E':direc[i]=0;break;
        case 'N':direc[i]=90;break;
        case 'W':direc[i]=180;break;
        case 'S':direc[i]=270;break;
        default:break;
    }
    robnum[i].xi=b-y+1;
    robnum[i].yi=x;
    map[b-y+1][x]=i;
    /*int j;
    for(i=1;i<=b;i++){
        for(j=1;j<=a;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }*/
}
int action(int num,char act,int rep){
    int i,j;
    switch(act){
        case 'L':{
            direc[num]+=90*rep;
            direc[num]%=360;
            return 1;
        }
        case 'R':{
            direc[num]-=90*rep;
            direc[num]%=360;
            return 1;
        }
        case 'F':{
            //printf("0000000\n");
            switch(direc[num]){
                case  0 :{
                    //printf("1\n");
                    for(i=0;i<rep;i++){
                        if(robnum[num].yi+1>a){
                            printf("Robot %d crashes into the wall\n",num);
                            return 0;
                        }
                        else if(map[robnum[num].xi][robnum[num].yi+1]!=0){
                            printf("Robot %d crashes into robot %d\n",num,map[robnum[num].xi][robnum[num].yi+1]);
                            return 0;
                        }
                        else{
                            robnum[num].yi+=1;
                            map[robnum[num].xi][robnum[num].yi]=num;
                            map[robnum[num].xi][robnum[num].yi-1]=0;
                        }
                    }
                    return 1;
                }
                case 90:{
                    for(i=0;i<rep;i++){
                        if(robnum[num].xi-1<=0){
                            printf("Robot %d crashes into the wall\n",num);
                            return 0;
                        }
                        else if(map[robnum[num].xi-1][robnum[num].yi]!=0){
                            printf("Robot %d crashes into robot %d\n",num,map[robnum[num].xi-1][robnum[num].yi]);
                            return 0;
                        }
                        else{
                            robnum[num].xi-=1;
                            map[robnum[num].xi][robnum[num].yi]=num;
                            map[robnum[num].xi+1][robnum[num].yi]=0;
                        }
                    }
                    return 1;
                }
                case -270:{
                    for(i=0;i<rep;i++){
                        if(robnum[num].xi-1<=0){
                            printf("Robot %d crashes into the wall\n",num);
                            return 0;
                        }
                        else if(map[robnum[num].xi-1][robnum[num].yi]!=0){
                            printf("Robot %d crashes into robot %d\n",num,map[robnum[num].xi-1][robnum[num].yi]);
                            return 0;
                        }
                        else{
                            robnum[num].xi-=1;
                            map[robnum[num].xi][robnum[num].yi]=num;
                            map[robnum[num].xi+1][robnum[num].yi]=0;
                        }
                    }
                    return 1;
                }
                case -180:{
                    for(i=0;i<rep;i++){
                        if(robnum[num].yi-1<=0){
                            printf("Robot %d crashes into the wall\n",num);
                            return 0;
                        }
                        else if(map[robnum[num].xi][robnum[num].yi-1]!=0){
                            printf("Robot %d crashes into robot %d\n",num,map[robnum[num].xi][robnum[num].yi-1]);
                            return 0;
                        }
                        else{
                            robnum[num].yi-=1;
                            map[robnum[num].xi][robnum[num].yi]=num;
                            map[robnum[num].xi][robnum[num].yi+1]=0;
                        }
                    }
                    return 1;
                }
                case 180:{
                    for(i=0;i<rep;i++){
                        if(robnum[num].yi-1<=0){
                            printf("Robot %d crashes into the wall\n",num);
                            return 0;
                        }
                        else if(map[robnum[num].xi][robnum[num].yi-1]!=0){
                            printf("Robot %d crashes into robot %d\n",num,map[robnum[num].xi][robnum[num].yi-1]);
                            return 0;
                        }
                        else{
                            robnum[num].yi-=1;
                            map[robnum[num].xi][robnum[num].yi]=num;
                            map[robnum[num].xi][robnum[num].yi+1]=0;
                        }
                    }
                    return 1;
                }
                case 270:{
                    for(i=0;i<rep;i++){
                        if(robnum[num].xi+1>b){
                            printf("Robot %d crashes into the wall\n",num);
                            return 0;
                        }
                        else if(map[robnum[num].xi+1][robnum[num].yi]!=0){
                            printf("Robot %d crashes into robot %d\n",num,map[robnum[num].xi+1][robnum[num].yi]);
                            return 0;
                        }
                        else{
                            robnum[num].xi+=1;
                            map[robnum[num].xi][robnum[num].yi]=num;
                            map[robnum[num].xi-1][robnum[num].yi]=0;
                        }
                    }
                    return 1;
                }
                case -90:{
                    for(i=0;i<rep;i++){
                        if(robnum[num].xi+1>b){
                            printf("Robot %d crashes into the wall\n",num);
                            return 0;
                        }
                        else if(map[robnum[num].xi+1][robnum[num].yi]!=0){
                            printf("Robot %d crashes into robot %d\n",num,map[robnum[num].xi+1][robnum[num].yi]);
                            return 0;
                        }
                        else{
                            robnum[num].xi+=1;
                            map[robnum[num].xi][robnum[num].yi]=num;
                            map[robnum[num].xi-1][robnum[num].yi]=0;
                        }
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    int k,n,m;
    int x,y;
    int i,j;
    scanf("%d",&k);
    int flag;
    while(k--){
        flag=1;
        scanf("%d %d",&a,&b);
        char ch;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d %d %c",&x,&y,&ch);
            setpos(i,x,y,ch);
        }
        int num[105];
        char act[105];
        int rep[105];
        for(i=1;i<=m;i++){
            scanf("%d %c %d",&num[i],&act[i],&rep[i]);
        }
        for(i=1;i<=m;i++){
            if(!action(num[i],act[i],rep[i])){
                flag=0;
                break;
            }
        }
        if(flag)
            printf("OK\n");
        for(i=0;i<105;i++){
            for(j=0;j<105;j++){
                map[i][j]=0;
            }
            direc[i]=0;
        }
    }
    return 0;
}

