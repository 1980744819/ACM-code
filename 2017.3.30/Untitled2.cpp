#include<stdio.h>
#include<string.h>
#include<iostream>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500010;
int F[MAXN];
const int MAX=26;
int degree[MAXN];//����
int color;//��ɫ��ţ���0��ʼ����������ɫ����
int find(int x)
{
    if(F[x]==-1)return x;
    return F[x]=find(F[x]);
}
void bing(int a,int b)
{
    int t1=find(a);
    int t2=find(b);
    if(t1!=t2) F[t1]=t2;
}
typedef struct Trie_Node
{
    bool isWord;
    struct Trie_Node *next[MAX];
    int id;
}Trie;
int insert(Trie *root,char *word)//������ɫ���
{
    Trie *p=root;
    int i=0;
    while(word[i]!='\0')
    {
        if(p->next[word[i]-'a']==NULL)
        {
            Trie *temp=new Trie;
            temp->isWord=false;
            for(int j=0;j<MAX;j++)
              temp->next[j]=NULL;
            temp->isWord=false;
            temp->id=0;
            p->next[word[i]-'a']=temp;
        }
        p=p->next[word[i]-'a'];
        i++;
    }
    if(p->isWord)
    {
        return p->id;
    }
    else
    {
        p->isWord=true;
        p->id=color++;
        return p->id;
    }
}
void del(Trie *root)
{
    for(int i=0;i<MAX;i++)
    {
        if(root->next[i]!=NULL)
         del(root->next[i]);

    }
    free(root);
}
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    char str1[20],str2[20];
    Trie *root=new Trie;
    for(int i=0;i<MAX;i++)
      root->next[i]=NULL;
    root->isWord=false;
    root->id=0;
    color=0;
    memset(F,-1,sizeof(F));
    memset(degree,0,sizeof(degree));
    while(scanf("%s%s",&str1,&str2)!=EOF)
    {
        int t1=insert(root,str1);
        int t2=insert(root,str2);
     //   printf("%d %d\n",t1,t2);
        degree[t1]++;
        degree[t2]++;
        bing(t1,t2);

    }
//***********************************************
//����Ǹ���F�������-1���Ҹ����
    int cnt1=0,cnt2=0;
    for(int i=0;i<color;i++)
    {
        if(F[i]==-1)cnt1++;
        if(degree[i]%2==1)cnt2++;
        if(cnt1>1)break;
        if(cnt2>2)break;
    }
    //���ݱȽϿ��ˣ�����0��ľ�����������ʱcnt1==0
    if((cnt1==0||cnt1==1)&&(cnt2==0||cnt2==2))
      printf("Possible\n");
    else printf("Impossible\n");
    //del(root);//����������Բ��ͷſռ䣬���Խ�ʡʱ��
    return 0;

/*
    //********************************
    //��������Ѱ����㣬������ڵ����ж��ǲ�����ͨ
    bool flag=true;
    int tt1=find(0);
    int cnt=0;//ͳ�ƶ���Ϊ�����Ľ�����
    for(int i=0;i<color;i++)
    {
        if(find(i)!=tt1)flag=false;//����ͨҲ����ŷ����·
        if(!flag)break;
        if(degree[i]%2==1) cnt++;
        if(cnt>2) flag=false;//����Ϊ��Ľ�����>2���϶�����ŷ����·��
    }
    if(cnt==1)flag=false;
    if(flag) printf("Possible\n");
    else printf("Impossible\n");
    del(root);//����������Բ��ͷſռ䣬���Խ�ʡʱ��
    return 0;
    //******************************************
    */
}
