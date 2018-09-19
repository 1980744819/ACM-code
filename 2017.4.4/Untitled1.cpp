#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//    定义链表中的节点
typedef struct LinkedList
{
    int member;                //    节点中的成员
    struct LinkedList* Next;        //    指向下一个节点的指针
} LinkListed,*Linked;
//    函数声明
Linked CreateList(int);                 //  创建链表函数
void print(Linked);            //  打印数据
void qiancha(Linked,int);  //第一个参数是头节点，第二个表示数据值
void turn(Linked);
int GetLength(Linked );
void JudgeNULL(Linked Head);

int main()
{
    Linked Head = NULL;                //  定义初始化头节点，等价于 struct LinkedList *Linked== NULL
    int value,n;
	int i;
    while(~scanf("%d",&n)){
        if(n!=0){
            Head=CreateList(n);
            print(Head);//  调用打印函数
            turn(Head);
            print(Head);
        }
        else{
            printf("list is empty\n");
        }
    }
    return 0;
}
//    创建链表函数
Linked CreateList(int n)
{
    int i;                                            //    用于下面循环
    int value;                                        //    用于临时存放用户输入的数据
    Linked Head = (Linked)malloc(sizeof(Linked));        //  分配一个不存放有效数据的头结点
    Linked Tail = Head;                            //    链表的最后一个节点
    Tail->Next = NULL;                            //    最后一个节点的指针置为空
    for(i = 0; i < n; i++)
    {

        scanf("%d",&value);
        Linked Newnum = (Linked)malloc(sizeof(Linked));    //    为节点分配空间
        Newnum->member =value;                            //将用户输入的数据赋给节点的成员
        Tail->Next = Newnum;                        //将最后一个节点的指针指向下一个新的节点
        Newnum->Next =NULL;                            //将新节点中的指针置为空
        Tail =Newnum;
	}                               //将新节点赋给最后的一个节点
    return Head;                                    //返回头节点
}

//    遍历链表函数
void print(Linked Head)
{
    Linked p=Head->Next;                            //将头节点的指针给予临时节点p
    while(p!=NULL)                                //节点p不为空，循环
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

