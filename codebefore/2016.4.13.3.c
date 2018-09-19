#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int cou=0;
int a[14];
int n;

void print(){
    cou++;
    if(cou<=3){
        for(i=1;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");
    }
}
void can(int col,int row){
    int j;
    for(j=0;j<col;j++){
        if(a[j]==row){
            return 0;
        if((col-j)==abs(a[j]-row))
            return 0;
        }
    }
    return 1;
}
void que(int col){
    int i;
    if(col==n)
        print();
    else{
        for(i=0;i<n;++i){
            if(can(col,i)){
                place(col,i);
                que(col+1);
            }
        }
    }
}
void place(int col,int row){
    a[col]=row;
}
int main(){
    scanf("%d",&n);
    return 0;
}

