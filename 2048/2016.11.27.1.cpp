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
int a[4][4];
void up(int col){
    int i,j;
    i=0;
    int num[4];
    memset(num,0,sizeof(num));
    j=0;
    for(i=0;i<4;i++){
        if(a[i][col]!=0){
            num[j]=a[i][col];
            j++;
        }
    }
    for(i=0;num[i]!=0,i<3;i++){
        if(num[i]==num[i+1]){
            num[i]+=num[i+1];
            for(j=i+1;j<3;j++){
                num[j]=num[j+1];
            }
            num[3]=0;
        }
    }
    for(i=0;i<4;i++)
        a[i][col]=num[i];
}
void down(int col){
    int i,j;
    i=0;
    int num[4];
    memset(num,0,sizeof(num));
    j=3;
    for(i=3;i>=0;i--){
        if(a[i][col]!=0){
            num[j]=a[i][col];
            j--;
        }
    }
    for(i=3;num[i]!=0,i>0;i--){
        if(num[i]==num[i-1]){
            num[i]+=num[i-1];
            for(j=i-1;j>0;j--){
                num[j]=num[j-1];
            }
            num[0]=0;
        }
    }
    for(i=0;i<=3;i++)
        a[i][col]=num[i];
}
void left(int row){
    int num[4];
    memset(num,0,sizeof(num));
    int i,j;
    j=0;
    for(i=0;i<4;i++){
        if(a[row][i]!=0){
            num[j]=a[row][i];
            j++;
        }
    }
    for(i=0;num[i]!=0,i<3;i++){
        if(num[i]==num[i+1]){
            num[i]+=num[i+1];
            for(j=i+1;j<3;j++){
                num[j]=num[j+1];
            }
            num[3]=0;
        }
    }
    for(i=0;i<4;i++)
        a[row][i]=num[i];
}
void right(int row){
    int num[4];
    memset(num,0,sizeof(num));
    int i,j;
    j=3;
    for(i=3;i>=0;i--){
        if(a[row][i]!=0){
            num[j]=a[row][i];
            j--;
        }
    }
    for(i=3;num[i]!=0,i>0;i--){
        if(num[i]==num[i-1]){
            num[i]+=num[i-1];
            for(j=i-1;j>0;j--){
                num[j]=num[j-1];
            }
            num[0]=0;
        }
    }
    for(i=0;i<4;i++)
        a[row][i]=num[i];
}
int main(){
    int t;
    scanf("%d",&t);
    int i,j;
    int com,n;
    while(t--){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                scanf("%d",&a[i][j]);
            }
        }
        //for(i=0;i<4;i++)
            //right(i);
        scanf("%d",&n);
        while(n--){
            scanf("%d",&com);
            switch(com){
                case 1:{
                    for(i=0;i<4;i++)
                        up(i);
                }
                    break;
                case 2:{
                    for(i=0;i<4;i++)
                        down(i);
                }
                    break;
                case 3:{
                    for(i=0;i<4;i++)
                        left(i);
                }
                    break;
                case 4:{
                    for(i=0;i<4;i++)
                        right(i);
                }
                    break;
                default:break;
            }
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    printf("%5d",a[i][j]);
                    if(j!=3)
                        printf(" ");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
