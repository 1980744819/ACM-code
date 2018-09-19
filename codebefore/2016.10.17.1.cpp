#include<stdio.h>
#include<stdlib.h>
#define ERROR 0;
#define OK 1;
typedef struct BiNode{
	int data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode,*BiTree;

int Search(BiTree T,int key,BiTree f,BiTree *p){//f是当前结点的父节点
	if(T==NULL){
		*p=f;//查找失败p返回父节点
		return 0;
	}
	else if(key==T->data){
		*p=T;//查找成功，p为当前结点
		return 1;
	}
	else if(key<T->data)
	    return Search(T->lchild,key,T,p);
	else
		return Search(T->rchild,key,T,p);
}

int InSert(BiTree *T,int key){
	BiTree p,s;
	if(!Search(*T,key,NULL,&p)){//是否存在该结点
		s=(BiTree)malloc(sizeof(BiNode));
		s->data =key;
		s->lchild =s->rchild=NULL;//叶子结点孩子为空
		if(!p)
			*T=s;//该结点为根结点
		else if(key<p->data)
			p->lchild=s;
		else
			p->rchild=s;
		return true;
	}
	else
	return false;
}
void pre(BiTree T){
    if(T==NULL){
        printf("#");
        return;
    }
    printf("%d ",T->data);
    pre(T->lchild);
    pre(T->rchild);
}
int main(){
	BiTree T=NULL,q=NULL;
	int n,k,i,x,b;
	int a[100];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		InSert(&T,a[i]);
	}
	//pre(T);
	for(i=0;i<k;i++){
		scanf("%d",&b);
		x=Search(T,b,NULL,&q);
		if(x==0)
			printf("0 ");
		else
			printf("1 ");
	}
	return 0;
}


]\
