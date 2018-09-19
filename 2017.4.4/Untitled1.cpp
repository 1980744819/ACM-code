#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//    ���������еĽڵ�
typedef struct LinkedList
{
    int member;                //    �ڵ��еĳ�Ա
    struct LinkedList* Next;        //    ָ����һ���ڵ��ָ��
} LinkListed,*Linked;
//    ��������
Linked CreateList(int);                 //  ����������
void print(Linked);            //  ��ӡ����
void qiancha(Linked,int);  //��һ��������ͷ�ڵ㣬�ڶ�����ʾ����ֵ
void turn(Linked);
int GetLength(Linked );
void JudgeNULL(Linked Head);

int main()
{
    Linked Head = NULL;                //  �����ʼ��ͷ�ڵ㣬�ȼ��� struct LinkedList *Linked== NULL
    int value,n;
	int i;
    while(~scanf("%d",&n)){
        if(n!=0){
            Head=CreateList(n);
            print(Head);//  ���ô�ӡ����
            turn(Head);
            print(Head);
        }
        else{
            printf("list is empty\n");
        }
    }
    return 0;
}
//    ����������
Linked CreateList(int n)
{
    int i;                                            //    ��������ѭ��
    int value;                                        //    ������ʱ����û����������
    Linked Head = (Linked)malloc(sizeof(Linked));        //  ����һ���������Ч���ݵ�ͷ���
    Linked Tail = Head;                            //    ��������һ���ڵ�
    Tail->Next = NULL;                            //    ���һ���ڵ��ָ����Ϊ��
    for(i = 0; i < n; i++)
    {

        scanf("%d",&value);
        Linked Newnum = (Linked)malloc(sizeof(Linked));    //    Ϊ�ڵ����ռ�
        Newnum->member =value;                            //���û���������ݸ����ڵ�ĳ�Ա
        Tail->Next = Newnum;                        //�����һ���ڵ��ָ��ָ����һ���µĽڵ�
        Newnum->Next =NULL;                            //���½ڵ��е�ָ����Ϊ��
        Tail =Newnum;
	}                               //���½ڵ㸳������һ���ڵ�
    return Head;                                    //����ͷ�ڵ�
}

//    ����������
void print(Linked Head)
{
    Linked p=Head->Next;                            //��ͷ�ڵ��ָ�������ʱ�ڵ�p
    while(p!=NULL)                                //�ڵ�p��Ϊ�գ�ѭ��
    {
        printf("%d ",p->member);
        p = p->Next;
    }
    printf("\n");
    return ;
}

void qiancha(Linked Head,int data)
{
	int before,after;
	before=GetLength(Head);
	Linked newnum=(Linked )malloc(sizeof(Linked));
	newnum->member=data;
	newnum->Next=Head->Next;
	Head->Next=newnum;
	after=GetLength(Head);
	if(before!=after-1)
	{
		;
	}
}

int GetLength(Linked Head)
{
	int j=0;
	Linked p=Head;
	while (p!=NULL)
	{
		p=p->Next;
		j++;
	}
	return j;
}
void turn(Linked Head)
{
	int length,i;
	Linked p=Head->Next;
	Head->Next=NULL;
	length=GetLength(p);
	for(i=0;i<length;i++)
	{
		qiancha(Head,p->member);
		p=p->Next;
	}
}

void JudgeNULL(Linked Head)
{
	if(Head->Next==NULL)
		printf("list is empty\n");
}

