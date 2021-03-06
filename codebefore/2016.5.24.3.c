#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
typedef struct{
    //char data;
    int weight;
    int lchild;
    int rchild;
    int parent;
}htnode;
typedef struct{
    char code[15];
    int start;
}hcode;
htnode ht[200];
hcode hcd[100];
void createht(htnode ht[],int n){
    int m=2*n-1;
    int i,j;
    for(i=0;i<m;i++){
        ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
    }
    int min1,min2;
    int lnode,rnode;
    for(i=n;i<m;i++){
        min1=min2=99999;
        lnode=rnode=-1;
        for(j=0;j<i;j++){
            if(ht[j].weight<min1&&ht[j].parent==-1){
                min1=ht[j].weight;
                lnode=j;
            }
        }
        ht[lnode].parent=i;
        for(j=0;j<i;j++){
            if(ht[j].weight<min2&&ht[j].parent==-1){
                min2=ht[j].weight;
                rnode=j;
            }
        }
        ht[rnode].parent=i;
        if(lnode>rnode){
            int node,min;
            min=min1;min1=min2;min2=min;
            node=lnode;lnode=rnode;rnode=node;
        }
        ht[i].lchild=lnode;
        ht[i].rchild=rnode;
        ht[i].weight=min1+min2;
        //ht[lnode].parent=i;
        //ht[rnode].parent=i;
        //ht[i].weight=ht[lnode].weight+ht[rnode].weight;
    }
}
void createhcd(htnode ht[],hcode hcd[],int n){
    int i,j,k;
    char s[15];
    int top=0;
    int lnode,rnode;
    for(i=0;i<n;i++){
        j=i;
        lnode=j;
        while(j!=-1){
            j=ht[j].parent;
            if(ht[j].lchild==lnode) s[top]='0';
            else s[top]='1';
            top++;
            lnode=j;
        }
        k=0;
        top--;
        while(top>0){
            top--;
            hcd[i].code[k]=s[top];
            k++;
        }
        puts(hcd[i].code);
        top=0;
    }
    /*for(i=0;i<n;i++){
        j=i;
        printf("%d ",j);
        while(j!=-1){
            j=ht[j].parent;
            printf("%d ",j);
        }
        printf("\n");
    }*/
}
int main(){
    int n,i;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            //ht[i].data=i;
            scanf("%d",&ht[i].weight);
        }
        createht(ht,n);
        createhcd(ht,hcd,n);
    }
    return 0;
}

