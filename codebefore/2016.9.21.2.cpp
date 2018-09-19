#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
using namespace::std;
typedef struct BiTNode{
    char data;
    int bf;
    //int ldeepth,rdeepth;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
int flag;
int len,start;
char s[20000];
void CreatBiTree(BiTree *T){
    BiTree L=(*T);
    char c;
    c=s[start++];
    if(c=='#'){
        (*T)==NULL;
        return;
    }
    else{
        (*T)=(BiTree)malloc(sizeof(BiTNode));
       // cout<<2;
        if(!*T)
            exit(0);
        (*T)->data=c;
        CreatBiTree(&(*T)->lchild);
        CreatBiTree(&(*T)->rchild);
    }
    //start++;

}
int Max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int Deepth(BiTree *T){
    BiTree L=*T;
        if(L==NULL)
            return 0;
        else if(L==NULL)
            return 0;
        else return 1+Max(Deepth(&L->lchild),Deepth(&L->rchild));
}
void ChargeBalance(BiTree *T){//可以用遍历；
    BiTree L=*T;
    if(L==NULL){
            //cout<<1;
            return;
    }
    L->bf=Deepth(&L->lchild)-Deepth(&L->rchild);
    //cout<<Deepth(&L->lchild)<<" "<<Deepth(&L->rchild)<<" ";
    //cout<<L->data<<" "<<L->bf<<endl;
    if(L->bf<=-2||L->bf>=2){
        flag=1;
        return;
    }
    ChargeBalance(&L->lchild);
    ChargeBalance(&L->rchild);
}

int main(){
    while(~scanf("%s",s)){
        len=strlen(s);
        start=0;
        BiTree T;
        T=NULL;
        //BiTree BT=T
        CreatBiTree(&T);
        flag=0;
        ChargeBalance(&T);
        if(flag)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
        //memset(s,'\0'.sizeof(s));
    }
    return 0;
}
