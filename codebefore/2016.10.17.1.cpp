#include<stdio.h>
#include<stdlib.h>
#define ERROR 0;
#define OK 1;
typedef struct BiNode{
	int data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode,*BiTree;

int Search(BiTree T,int key,BiTree f,BiTree *p){//f�ǵ�ǰ���ĸ��ڵ�
	if(T==NULL){
		*p=f;//����ʧ��p���ظ��ڵ�
		return 0;
	}
	else if(key==T->data){
		*p=T;//���ҳɹ���pΪ��ǰ���
		return 1;
	}
	else if(key<T->data)
	    return Search(T->lchild,key,T,p);
	else
		return Search(T->rchild,key,T,p);
}

int InSert(BiTree *T,int key){
	BiTree p,s;
	if(!Search(*T,key,NULL,&p)){//�Ƿ���ڸý��
		s=(BiTree)malloc(sizeof(BiNode));
		s->data =key;
		s->lchild =s->rchild=NULL;//Ҷ�ӽ�㺢��Ϊ��
		if(!p)
			*T=s;//�ý��Ϊ�����
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
