#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define MAXSIZE 11
typedef char ElemType[1024];
typedef struct{
    ElemType data;
    int cur;
}NodeType;
NodeType space[MAXSIZE];
typedef struct{
    int elem;
    int lenth;
    int listSize;
}SLinkList;
void InitSpace(){
    memset(space,0,sizeof(space));
    for(int i=0;i<MAXSIZE-1;++i){
        space[i].cur=i+1;
        space[MAXSIZE-1].cur=0;
    }
}
int LocalElem(SLinkList &s,ElemType e){
    int i;
    i=S.elem;
    while(i&&strcmp(space[i].data,e))
        i=space[i].cur;
    return i;
}
int Malloc(){
    int i=space[0].cur;
    if(space[0].cur)
        space[0].cur=space[space[0].cur].cur;
    return i;
}
void Free(int k){
    space[k].cur=space[0].cur;
    space[0].cur=k;
}
int Insert(SLinkList &s,int i,ElemType e){
    int cur=S.elem;
    int j=0;
    int newNodeIndex;
    while(j<i-1){
        cur=space[cur].cur;
        ++j;
    }
    newNodeIndex=Malloc();
    strcpy(space[newNodeIndex].data,e);
    space[cur].cur=newNodeIndex;
    S.length++;
}
void Delete(SLinkList &S,int I){
    int cur=S.elem;
    int j=0;
    int delCur;
    while(j<i-1){
        cur=space[cur].cur;
        ++j;
    }
    delCur=sapce[cur].cur;
    space[cur].cur=space[delCur].cur;
    Free(delCur);
    S.length--;
}
void CreateList(SLinkList &S){
    S.elem=Malloc();
    space[S.elem].cur=0;
    S.length=0;
    S.listSize=9;
}
void Show(){
    int i;
    for(i=0;i<MAXSIZE;i++){
        printf("%-8s%2d\n",space[i].data,space[i].cur);
    }
}
int main(){
    SLinkList S;
    char operate[1024];
    int n;
    ElemType e;
    InitSpace();
    CreateList(S);
    while(~scanf("%s",operate)){
        if(!strcmp("show",operate)){
            Show();
            printf("********************\n");
        }
        else if(!strcmp("insert",operate)){
            scanf("%d",&n);
            scanf("%s",e);
            Insert(S,n,e);
        }
        else if(!strcmp("search",operate)){
            scanf("%s",e);
            int number=LocalElem(S,e);
            if(number>9)
                printf("%d\n",number);
            else
                printf(" %d",number);
            printf("********************\n");
        }
        else{
            scanf("%d",&n);
            Delete(S,n);
        }
    }
    return 0;
}

