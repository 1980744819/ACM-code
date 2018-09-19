#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
char Map[205][205];
int w,h;
int cur;
char code[17][5]={"0000","0001","0010","0011","0100","0101","0110","0111",
"1000","1001","1010","1011","1100","1101","1110","1111"};
int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
bool range(int x,int y){
    return x>=0&&x<=h&&y>=0&&y<=w;
}
void dfs1(int x,int y){
    if(!range(x,y)||Map[x][y]!='0')
        return;
    Map[x][y]='#';
    int i;
    for(i=0;i<4;i++){
        dfs1(x+dirx[i],y+diry[i]);
    }
}
void dfs2(int x,int y){
    if(!range(x,y)||Map[x][y]!='1')
        return;
    Map[x][y]='#';
    int i;
    int a,b;
    for(i=0;i<4;i++){
        a=x+dirx[i];
        b=y+diry[i];
        if(range(a,b)){
            if(Map[a][b]=='0'){
                cur++;
                dfs1(a,b);
            }
            else if(Map[a][b]=='1'){
                dfs2(a,b);
            }
        }
    }
}
int qu[7];
int main(){
    map<char,int>ctn;
    map<char,int>M;
    //int point[7]={5,0,3,2,4,1};
    char str[7]="WAKJSD";
    M['A']=0;M['D']=1;M['J']=2;M['K']=3;M['S']=4;M['W']=5;
    ctn['0']=0;ctn['1']=1;ctn['2']=2;ctn['3']=3;ctn['4']=4;ctn['5']=5;
    ctn['6']=6;ctn['7']=7;ctn['8']=8;ctn['9']=9;
    ctn['a']=10;ctn['b']=11;ctn['c']=12;ctn['d']=13;ctn['e']=14;ctn['f']=15;
    char s[55];
    int i,j,k;
    int num;
    int kase=1;
    while(~scanf("%d %d",&h,&w),h||w){
        w*=4;
        for(i=0;i<=w;i++){
            Map[0][i]='0';
            Map[h+1][i]='0';
        }
        for(i=0;i<=h+1;i++){
            Map[i][0]='0';
            Map[i][w+1]='0';
        }
        for(i=1;i<=h;i++){
            scanf("%s",s);
            k=1;
            for(j=0;s[j]!='\0';j++){
                num=ctn[s[j]];
                //printf("%d",num);
                Map[i][k]=code[num][0];
                k++;
                Map[i][k]=code[num][1];
                k++;
                Map[i][k]=code[num][2];
                k++;
                Map[i][k]=code[num][3];
                k++;
            }
        }
        w++;h++;
        dfs1(0,0);
        for(i=0;i<=h;i++){
            for(j=0;j<=w;j++){
                if(Map[i][j]=='1'){
                    cur=0;
                    dfs2(i,j);
                    qu[cur]++;
                    //printf("%d\n",cur);
                }
            }
        }
        printf("Case %d: ",kase);
        kase++;
        for(i=0;i<qu[1];i++)
            printf("A");
        for(i=0;i<qu[5];i++)
            printf("D");
        for(i=0;i<qu[3];i++)
            printf("J");
        for(i=0;i<qu[2];i++)
            printf("K");
        for(i=0;i<qu[4];i++)
            printf("S");
        for(i=0;i<qu[0];i++)
            printf("W");
        printf("\n");
        memset(qu,0,sizeof(qu));
        /*for(i=0;i<=h;i++){
            for(j=0;j<=w;j++){
                printf("%c",Map[i][j]);
            }
            printf("\n");
        }*/
    }
    return 0;
}
