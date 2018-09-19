#include<stdio.h>
#include<string.h>
#include<iostream>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500010;
int F[MAXN];
const int MAX=26;
int degree[MAXN];//度数
int color;//颜色编号，从0开始，最后就是颜色总数
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
int insert(Trie *root,char *word)//返回颜色编号
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
//这个是根据F数组等于-1来找根结点
    int cnt1=0,cnt2=0;
    for(int i=0;i<color;i++)
    {
        if(F[i]==-1)cnt1++;
        if(degree[i]%2==1)cnt2++;
        if(cnt1>1)break;
        if(cnt2>2)break;
    }
    //数据比较坑人，存在0根木棒的情况，此时cnt1==0
    if((cnt1==0||cnt1==1)&&(cnt2==0||cnt2==2))
      printf("Possible\n");
    else printf("Impossible\n");
    //del(root);//单组输入可以不释放空间，可以节省时间
    return 0;

/*
    //********************************
    //这种是找寻根结点，多个根节点来判断是不是连通
    bool flag=true;
    int tt1=find(0);
    int cnt=0;//统计度数为奇数的结点个数
    for(int i=0;i<color;i++)
    {
        if(find(i)!=tt1)flag=false;//不连通也不是欧拉回路
        if(!flag)break;
        if(degree[i]%2==1) cnt++;
        if(cnt>2) flag=false;//度数为奇的结点个数>2，肯定不是欧拉回路了
    }
    if(cnt==1)flag=false;
    if(flag) printf("Possible\n");
    else printf("Impossible\n");
    del(root);//单组输入可以不释放空间，可以节省时间
    return 0;
    //******************************************
    */
}
