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
int Map[8][6];
int Map_t[8][6];
int judge(){
    int i,j;
    int flag;
    int t;
    for(i=0;i<6;i++){
        flag=0;
        switch(i){
            case 0:{
                t=Map_t[0][0];
                if(t!=Map_t[0][1]||t!=Map_t[1][0]||t!=Map_t[1][1])
                    flag=1;
            }break;
            case 1:{
                t=Map_t[0][2];
                if(t!=Map_t[0][3]||t!=Map_t[1][2]||t!=Map_t[1][3])
                    flag=1;
            }break;
            case 2:{
                t=Map_t[0][4];
                if(t!=Map_t[0][5]||t!=Map_t[1][4]||t!=Map_t[1][5])
                    flag=1;
            }break;
            case 3:{
                t=Map_t[2][2];
                if(t!=Map_t[2][3]||t!=Map_t[3][2]||t!=Map_t[3][3])
                    flag=1;
            }break;
            case 4:{
                t=Map_t[4][2];
                if(t!=Map_t[4][3]||t!=Map_t[5][2]||t!=Map_t[5][3])
                    flag=1;
            }break;
            case 5:{
                t=Map_t[6][2];
                if(t!=Map_t[6][3]||t!=Map_t[7][2]||t!=Map_t[7][3])
                    flag=1;
            }break;
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
    for(i=0;i<8;i++){
        for(j=0;j<6;j++){
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
        scanf("%d %d %d %d",&Map[0][2],&Map[0][3],&Map[1][2],&Map[1][3]);
        scanf("%d %d %d %d",&Map[2][2],&Map[2][3],&Map[3][2],&Map[3][3]);
        scanf("%d %d %d %d",&Map[4][2],&Map[4][3],&Map[5][2],&Map[5][3]);
        scanf("%d %d %d %d",&Map[6][2],&Map[6][3],&Map[7][2],&Map[7][3]);
        scanf("%d %d %d %d",&Map[0][0],&Map[0][1],&Map[1][0],&Map[1][1]);
        scanf("%d %d %d %d",&Map[0][4],&Map[0][5],&Map[1][4],&Map[1][5]);
        /*for(i=0;i<8;i++){
            for(j=0;j<6;j++){
                printf("%d",Map[i][j]);
            }
            printf("\n");
        }*/
        Copy();
        if(judge()){
            printf("YES\n");
            continue;
        }
        for(i=0;i<12;i++){
            Copy();
            flag=0;
            switch(i){
                case 0:{
                    t1=Map_t[0][0];
                    t2=Map_t[0][1];
                    Map_t[0][0]=Map_t[0][2];
                    Map_t[0][1]=Map_t[0][3];
                    Map_t[0][2]=Map_t[0][4];
                    Map_t[0][3]=Map_t[0][5];
                    Map_t[0][4]=Map_t[5][3];
                    Map_t[0][5]=Map_t[5][2];
                    Map_t[5][3]=t1;
                    Map_t[5][2]=t2;
                    flag=judge();
                }break;
                case 1:{
                    t1=Map_t[0][0];
                    t2=Map_t[0][1];
                    Map_t[0][0]=Map_t[5][3];
                    Map_t[0][1]=Map_t[5][2];
                    Map_t[5][3]=Map_t[0][4];
                    Map_t[5][2]=Map_t[0][5];
                    Map_t[0][4]=Map_t[0][2];
                    Map_t[0][5]=Map_t[0][3];
                    Map_t[0][2]=t1;
                    Map_t[0][3]=t2;
                    flag=judge();
                }break;
                case 2:{
                    t1=Map_t[1][0];
                    t2=Map_t[1][1];
                    Map_t[1][0]=Map_t[1][2];
                    Map_t[1][1]=Map_t[1][3];
                    Map_t[1][2]=Map_t[1][4];
                    Map_t[1][3]=Map_t[1][5];
                    Map_t[1][4]=Map_t[4][3];
                    Map_t[1][5]=Map_t[4][2];
                    Map_t[4][3]=t1;
                    Map_t[4][2]=t2;
                    flag=judge();
                }break;
                case 3:{
                    t1=Map_t[1][0];
                    t2=Map_t[1][1];
                    Map_t[1][0]=Map_t[4][3];
                    Map_t[1][1]=Map_t[4][2];
                    Map_t[4][3]=Map_t[1][4];
                    Map_t[4][2]=Map_t[1][5];
                    Map_t[1][4]=Map_t[1][2];
                    Map_t[1][5]=Map_t[1][3];
                    Map_t[1][2]=t1;
                    Map_t[1][3]=t2;
                    flag=judge();
                }break;
                case 4:{
                    t1=Map_t[0][2];
                    t2=Map_t[1][2];
                    Map_t[0][2]=Map_t[2][2];
                    Map_t[1][2]=Map_t[3][2];
                    Map_t[2][2]=Map_t[4][2];
                    Map_t[3][2]=Map_t[5][2];
                    Map_t[4][2]=Map_t[6][2];
                    Map_t[5][2]=Map_t[7][2];
                    Map_t[6][2]=t1;
                    Map_t[7][2]=t2;
                    flag=judge();
                }break;
                case 5:{
                    t1=Map_t[0][2];
                    t2=Map_t[1][2];
                    Map_t[0][2]=Map_t[6][2];
                    Map_t[1][2]=Map_t[7][2];
                    Map_t[6][2]=Map_t[4][2];
                    Map_t[7][2]=Map_t[5][2];
                    Map_t[4][2]=Map_t[2][2];
                    Map_t[5][2]=Map_t[3][2];
                    Map_t[2][2]=t1;
                    Map_t[3][2]=t2;
                    flag=judge();
                }break;
                case 6:{
                    t1=Map_t[0][3];
                    t2=Map_t[1][3];
                    Map_t[0][3]=Map_t[2][3];
                    Map_t[1][3]=Map_t[3][3];
                    Map_t[2][3]=Map_t[4][3];
                    Map_t[3][3]=Map_t[5][3];
                    Map_t[4][3]=Map_t[6][3];
                    Map_t[5][3]=Map_t[7][3];
                    Map_t[6][3]=t1;
                    Map_t[7][3]=t2;
                    flag=judge();
                }break;
                case 7:{
                    t1=Map_t[0][3];
                    t2=Map_t[1][3];
                    Map_t[0][3]=Map_t[6][3];
                    Map_t[1][3]=Map_t[7][3];
                    Map_t[6][3]=Map_t[4][3];
                    Map_t[7][3]=Map_t[5][3];
                    Map_t[4][3]=Map_t[2][3];
                    Map_t[5][3]=Map_t[3][3];
                    Map_t[2][3]=t1;
                    Map_t[3][3]=t2;
                    flag=judge();
                }break;
                case 8:{
                    t1=Map_t[2][2];
                    t2=Map_t[2][3];
                    Map_t[2][2]=Map_t[1][4];
                    Map_t[2][3]=Map_t[0][4];
                    Map_t[1][4]=Map_t[7][3];
                    Map_t[0][4]=Map_t[7][2];
                    Map_t[7][3]=Map_t[0][1];
                    Map_t[7][2]=Map_t[1][1];
                    Map_t[0][1]=t1;
                    Map_t[1][1]=t2;
                    flag=judge();
                }
                break;
                case 9:{
                    t1=Map_t[2][2];
                    t2=Map_t[2][3];
                    Map_t[2][2]=Map_t[0][1];
                    Map_t[2][3]=Map_t[1][1];
                    Map_t[0][1]=Map_t[7][3];
                    Map_t[1][1]=Map_t[7][2];
                    Map_t[7][3]=Map_t[1][4];
                    Map_t[7][2]=Map_t[0][4];
                    Map_t[1][4]=t1;
                    Map_t[0][4]=t2;
                    flag=judge();
                }
                break;
                case 10:{
                    t1=Map_t[3][2];
                    t2=Map_t[3][3];
                    Map_t[3][2]=Map_t[1][5];
                    Map_t[3][3]=Map_t[0][5];
                    Map_t[1][5]=Map_t[6][3];
                    Map_t[0][5]=Map_t[6][2];
                    Map_t[6][3]=Map_t[0][0];
                    Map_t[6][2]=Map_t[1][0];
                    Map_t[0][0]=t1;
                    Map_t[1][0]=t2;
                    flag=judge();
                }
                break;
                case 11:{
                    t1=Map_t[3][2];
                    t2=Map_t[3][3];
                    Map_t[3][2]=Map_t[0][0];
                    Map_t[3][3]=Map_t[1][0];
                    Map_t[0][0]=Map_t[6][3];
                    Map_t[1][0]=Map_t[6][2];
                    Map_t[6][3]=Map_t[1][5];
                    Map_t[6][2]=Map_t[0][5];
                    Map_t[1][5]=t1;
                    Map_t[0][5]=t2;
                    flag=judge();
                }
                break;
            }
            if(flag){
                printf("YES\n");
                break;
            }
        }
        if(!flag)
            printf("NO\n");
        memset(Map_t,0,sizeof(Map_t));
        memset(Map,0,sizeof(Map));
    }
    return 0;
}



