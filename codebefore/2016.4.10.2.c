#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char a[11][11];
char b[11][11];
int c[11][11]={0};
int n;
void df(int x,int y){
    int next[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    int k;
    int tx,ty;
    for(k=0;k<8;k++){
        tx=x+next[k][0];
        ty=y+next[k][1];
        if(tx<0||tx>=n||ty<0||ty>=n||a[tx][ty]!='.')
            continue;
        c[tx][ty]+=1;
    }
}
int main(){
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
            scanf("%s",a[i]);
    }
    for(i=0;i<n;i++){
            scanf("%s",b[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                if(a[i][j]=='*'){
                        //printf("%d %d\n",i,j);
                    df(i,j);
            }
        }
    }
    int flag=0;
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                if(b[i][j]=='x'&&a[i][j]=='*'){
                    flag=1;
                    break;
                }
        }
     }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                if(b[i][j]=='x'){
                        if(a[i][j]=='*'){
                            printf("*");
                        }
                        else
                            printf("%d",c[i][j]);
                }
                else if(b[i][j]=='.'){
                        if(flag==1&&a[i][j]=='*')
                            printf("*");
                        else
                            printf(".");
                }
        }
        printf("\n");
    }
    return 0;
}

