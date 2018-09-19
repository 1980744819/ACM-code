#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int op[50005][2];
bool role[50005],book[50005];
void operat_1(int opi,int num){
    if(role[num]==true){
        book[opi]=false;
    }
    else{
        role[num]=true;
        book[opi]=true;
    }
}
void operat_2(int opi,int num){
    if(role[num]==false){
        book[opi]=false;
    }
    else{
        role[num]=false;
        book[opi]=true;
    }
}
void operat_3(int opi,int num){
    num=op[num][1];
    while(op[num][0]==3&&op){
        num=op[num][1];
    }
}
int main(){
    int t;
    int n;
    int m;
    int i,j,k;
    int a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d %d",&op[i][0],&op[i][1]);
        }
        for(i=0;i<m;i++){
            if(op[i][0]==1){

            }
            else if(op[i][0]==2){

            }
            else{

            }
        }
    }
    return 0;
}

