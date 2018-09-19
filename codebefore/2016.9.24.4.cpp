#include<iostream>
#include<stdlib.h>
using namespace std;

//将结点先按权重排一下值，这样每次新插入结点一定就在原先的结点的下头
//避免了根节点的更新

typedef struct datanode
{
	int data, wight;
}datanode;
datanode input[107];
typedef struct pnode
{
	datanode x;
	struct pnode *lc, *rc;
}pnode,*pnodep;

bool Ptree_Find(datanode key, pnodep Root, pnodep &markp)
{
	pnodep p = Root,Lp=NULL;
	while (p)
	{
		if (p->x.data == key.data)
		{
			markp = p;
			return true;
		}
		else if (p->x.data < key.data)
		{
			Lp = p;
			p = p->rc;
		}
		else
		{
			Lp = p;
			p = p->lc;
		}
	}
	markp = Lp;
	return false;
}

void Ptree_Insert(datanode key, pnodep &Root)
{
	pnodep markp;
	if (!Ptree_Find(key, Root, markp))
	{
		pnodep newnode = (pnodep)malloc(sizeof(pnode));
		newnode->x = key;
		newnode->rc = newnode->lc = NULL;
		if (!markp)
		{
			Root = newnode;
		}
		else
		{
			if (markp->x.data > key.data)
			{
				markp->lc = newnode;
			}
			else
			{
				markp->rc = newnode;
			}
		}
	}
}

void Ptree_Init(pnodep &Root,int N)
{
	for (int i = 0; i < N; i++)
	{
		Ptree_Insert(input[i], Root);
	}
}

int deep(pnodep Root)
{
	if (Root)
	{
		int deepl = deep(Root->lc);
		int deepr = deep(Root->rc);
		int max = (deepl > deepr) ? deepl : deepr;
		return (1 + max);
	}
	else
		return 0;
}
template<typename T>
void mswap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}
void qsort(int left, int right)
{
	if (left < right)
	{
		int i = left, j = right;
		datanode temp = input[left];
		while (i < j)
		{
			while (i < j&&input[j].wight >= temp.wight) j--;
			while (i < j&&input[i].wight <= temp.wight) i++;
			if (i < j)
			{
				mswap(input[i], input[j]);
			}
		}
		mswap(input[left], input[i]);
		qsort(left, i - 1);
		qsort(i + 1, right);
	}
}

void Ptree_Delete(pnodep Root)
{
	if (Root)
	{
		Ptree_Delete(Root->lc);
		Ptree_Delete(Root->rc);
		free(Root);
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		pnodep Root = NULL;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> input[i].data;
		}
		for (int i = 0; i < N; i++)
		{
			cin >> input[i].wight;
		}
		qsort(0, N - 1);
		Ptree_Init(Root, N);
		cout << deep(Root)<<endl;
		Ptree_Delete(Root);
	}
	return 0;
}
