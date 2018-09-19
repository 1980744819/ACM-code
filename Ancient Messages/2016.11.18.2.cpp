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
char code[16][4]={"0000","0001","0010","0011","0100","0101","0110","0111",
"1000","1001","1010","1011","1100","1101","1110","1111"};
char Map[205][205];
int h,w;
struct stu{
    int x,y;
}node,store;
int nextx[8]={-1,-1,0,1,1,1,0,-1};
int nexty[8]={0,1,1,1,0,-1,-1,-1};
void bfs(int a,int b){
    queue<struct stu>que;
    node.x=a;
    node.y=b;
    int i,j,k;
    que.push(node);
    while(!que.empty()){
        node=que.front();
        for(i=0;i<8;i++){
            a=node.x+nextx[i];
            b=node.y+nexty[i];
            if(a<0||a>4*w+1||b<0||b>h+1)
                continue;
            if(Map[a][b]!='0')
                break;
            Map[a][b]='1';
            store.x=a;
            store.y=b;
            que.push(store);
        }
        que.pop();
    }
}
int main(){
    int i,j,k;
    char c;
    int num;
    int ans;
    map<char,int>ctn;
    ctn['0']=0;ctn['1']=1;ctn['2']=2;ctn['3']=3;ctn['4']=4;ctn['5']=5;
    ctn['6']=6;ctn['7']=7;ctn['8']=8;ctn['9']=9;
    ctn['a']=10;ctn['b']=11;ctn['c']=12;ctn['d']=13;ctn['e']=14;ctn['f']=15;
    while(~scanf("%d %d",&h,&w)){
        for(i=0;i<=4*w+1;i++){
            Map[0][i]='0';
            Map[h+1][i]='0';
        }
        for(i=0;i<=h+1;i++){
            Map[i][0]='0';
            Map[i][4*w+1]='0';
        }
        for(i=1;i<=h;i++){
            k=0;
            for(j=0;j<w;j++){
                scanf("%c",&c);
                num=ctn[c];
                k++;
                Map[i][k]=code[num][0];
                k++;
                Map[i][k]=code[num][1];
                k++;
                Map[i][k]=code[num][2];
                k++;
                Map[i][k]=code[num][3];
            }
        }
        ans=0;
        for(i=0;i<=h+1;i++){
            for(j=0;j<=4*w+1;j++){
                if(Map[i][j]=='0'){
                    ans++;
                    bfs(i,j);
                }
            }
        }
    }
    return 0;
}

