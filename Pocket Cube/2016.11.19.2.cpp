#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int Map[6][4];
int Map_t[6][4];
int judge(){
    int i,j;
    int t,flag=0;
    for(i=0;i<6;i++){
            t=Map_t[i][0];
            for(j=0;j<4;j++){
                if(Map_t[i][j]!=t){
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
    }
    if(flag)
        return 0;
    else
        return 1;
}
void Copy(){
    int i,j;
    for(i=0;i<6;i++){
        for(j=0;j<4;j++){
            Map_t[i][j]=Map[i][j];
        }
    }
}
int main(){
    int i,j,k;
    int n;
    scanf("%d",&n);
    int flag;
    int t1,t2;
    while(n--){
        for(i=0;i<6;i++){
            for(j=0;j<4;j++){
                scanf("%d",&Map[i][j]);
            }
        }
        Copy();
        if(judge()){
            printf("YES\n");
            continue;
        }
        for(i=0;i<8;i++){
            flag=0;
            Copy();
            switch(i){
                case 0:{
                    t1=Map_t[0][0];
                    t2=Map_t[0][1];
                    Map_t[0][0]=Map_t[5][0];
                    Map_t[0][1]=Map_t[5][1];
                    Map_t[5][0]=Map_t[2][3];
                    Map_t[5][2]=Map_t[2][2];
                    Map_t[2][3]=Map_t[4][0];
                    Map_t[2][2]=Map_t[4][1];
                    Map_t[4][0]=t1;
                    Map_t[4][1]=t2;
                    flag=judge();
                }break;
                case 1:{
                    t1=Map_t[0][0];
                    t2=Map_t[0][1];
                    Map_t[0][0]=Map_t[4][0];
                    Map_t[0][1]=Map_t[4][1];
                    Map_t[4][0]=Map_t[2][3];
                    Map_t[4][1]=Map_t[2][2];
                    Map_t[2][3]=Map_t[5][0];
                    Map_t[2][2]=Map_t[5][1];
                    Map_t[5][0]=t1;
                    Map_t[5][1]=t2;
                    flag=judge();
                }break;
                case 2:{
                    t1=Map_t[0][2];
                    t2=Map_t[0][3];
                    Map_t[0][2]=Map_t[5][2];
                    Map_t[0][3]=Map_t[5][3];
                    Map_t[5][2]=Map_t[2][1];
                    Map_t[5][3]=Map_t[2][0];
                    Map_t[2][1]=Map_t[4][2];
                    Map_t[2][0]=Map_t[4][3];
                    flag=judge();
                }break;
                case 3:{
                    t1=Map_t[0][2];
                    t2=Map_t[0][3];
                    Map_t[0][2]=Map_t[4][2];
                    Map_t[0][3]=Map_t[4][3];
                    Map_t[4][2]=Map_t[2][1];
                    Map_t[4][3]=Map_t[2][0];
                    Map_t[2][1]=Map_t[5][2];
                    Map_t[2][0]=Map_t[5][3];
                    Map_t[5][2]=t1;
                    Map_t[5][1]=t2;
                    flag=judge();
                }break;
                case 4:{
                    t1=Map_t[1][0];
                    t2=Map_t[1][2];
                    Map_t[1][0]=Map_t[0][0];
                    Map_t[1][2]=Map_t[0][2];
                    Map_t[0][0]=Map_t[3][0];
                    Map_t[0][2]=Map_t[3][2];
                    Map_t[3][0]=Map_t[2][0];
                    Map_t[3][2]=Map_t[2][2];
                    Map_t[2][0]=t1;
                    Map_t[2][2]=t2;
                    flag=judge();
                }break;
                case 5:{
                    t1=Map_t[1][0];
                    t2=Map_t[1][2];
                    Map_t[1][0]=Map_t[2][0];
                    Map_t[1][2]=Map_t[2][2];
                    Map_t[2][0]=Map_t[3][0];
                    Map_t[2][2]=Map_t[3][2];
                    Map_t[3][0]=Map_t[0][0];
                    Map_t[3][2]=Map_t[0][2];
                    Map_t[0][0]=t1;
                    Map_t[0][2]=t2;
                    flag=judge();
                }break;
                case 6:{
                    t1=Map_t[1][1];
                    t2=Map_t[1][3];
                    Map_t[1][1]=Map_t[0][1];
                    Map_t[1][3]=Map_t[0][3];
                    Map_t[0][1]=Map_t[3][1];
                    Map_t[0][3]=Map_t[3][3];
                    Map_t[3][1]=Map_t[2][1];
                    Map_t[3][3]=Map_t[2][3];
                    Map_t[2][1]=t1;
                    Map_t[2][3]=t2;
                    flag=judge();
                }break;
                case 7:{
                    t1=Map_t[1][1];
                    t2=Map_t[1][3];
                    Map_t[1][1]=Map_t[2][1];
                    Map_t[1][3]=Map_t[2][3];
                    Map_t[2][1]=Map_t[3][1];
                    Map_t[2][3]=Map_t[3][3];
                    Map_t[3][1]=Map_t[0][1];
                    Map_t[3][3]=Map_t[0][3];
                    Map_t[0][1]=t1;
                    Map_t[0][3]=t2;
                    flag=judge();
                }break;
            }
            if(flag){
                printf("YES\n");
                break;
            }
        }
        if(!flag)
            printf("NO\n");
    }
    return 0;
}


