#include<cstdio>
#include<iostream>
#include<malloc.h>
#define LH +1
#define EH 0
#define RH -1
#define NULL 0
using namespace::std;
typedef struct BiTNode{
    int data;//数据
    int bf;//平衡因子
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void R_Rotate(BiTree *p){
    BiTree L;
    L=(*p)->lchild;
    (*p)->lchild=L->rchild;
    L->rchild=(*p);
    *p=L;
}
void L_Rotate(BiTree *p){
    BiTree R;
    R=(*p)->rchild;
    (*p)->rchild=R->lchild;
    R->lchild=(*p);
    *p=R;
}
void LeftBalance(BiTree *T){
    BiTree L,Lr;
    L=(*T)->lchild;
    switch(L->bf){
    case LH:
            (*T)->bf=L->bf=EH;
            R_Rotate(T);
            break;
        case RH:
            Lr=L->rchild;
            switch(Lr->bf){
                case LH:
                    (*T)->bf=RH;
                    L->bf=EH;
                    break;
                case EH:
                    (*T)->bf=L->bf=EH;
                    break;
                case RH:
                    (*T)->bf=EH;
                    L->bf=LH;
                    break;
            }
            Lr->bf=EH;
            L_Rotate(&(*T)->lchild);
            R_Rotate(T);
            break;
    }
}
void RightBalance(BiTree *T){
    BiTree R,Rl;
    R=(*T)->rchild;
    switch(R->bf){
        case RH:
            (*T)->bf=R->bf=EH;
            L_Rotate(T);
            break;
        case LH:
            Rl=R->lchild;
            switch(Rl->bf){
            case RH:
                (*T)->bf=LH;
                R->bf=EH;
                break;
            case EH:
                (*T)->bf=R->bf=EH;
                break;
            case LH:
                (*T)->bf=EH;
                R->bf=RH;
                break;
            }
            Rl->bf=EH;
            R_Rotate(&(*T)->lchild);
            L_Rotate(T);
    }
}
int InsertAVL(BiTree *T,int e,int *taller){
    if(!*T){
        *T=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=e;
        (*T)->lchild=(*T)->rchild=NULL;
        (*T)->bf=EH;
        *taller=1;
    }
    else{
        if(e==(*T)->data){
            *taller=0;
            return 0;
        }
        if(e<(*T)->data){
            if(!InsertAVL(&(*T)->lchild,e,taller))
                return 0;
            if(taller){
                switch((*T)->bf){
                    case LH:
                        LeftBalance(T);
                        *taller=0;
                        break;
                    case EH:
                        (*T)->bf=LH;
                        *taller=1;
                        break;
                    case RH:
                        (*T)->bf=LH;
                        *taller=0;
                        break;
                }
            }
        }
        else{
            if(!InsertAVL(&(*T)->rchild,e,taller))
                return 0;
            if(taller){
                switch((*T)->bf){
                case LH:
                    (*T)->bf=EH;
                    *taller=0;
                    break;
                case EH:
                    (*T)->bf=RH;
                    *taller=1;
                    break;
                case RH:
                    RightBalance(T);
                    *taller=0;
                    break;
                }
            }
        }
    }
    return 0;
}
int SearchBT(BiTree *T,int e){
    if(e==(*T)->data)
        return 1;
    else if(e<(*T)->data){
        if((*T)->lchild!=NULL)
        SearchBT(&(*T)->lchild,e);
        else return 0;
    }
    else if(e>(*T)->data){
        if((*T)->rchild!=NULL)
        SearchBT(&(*T)->rchild,e);
        else return 0;
    }
}
int main(){
    int n,k;
    int i,j;
    while(~scanf("%d%d",&n,&k)){
        BiTree T=NULL;
        int taller=0;
        int e;
        while(n--){
            scanf("%d",&e);
            InsertAVL(&T,e,&taller);
        }
        while(k--){
            scanf("%d",&e);
            if(SearchBT(&T,e))
                cout<<1<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}
