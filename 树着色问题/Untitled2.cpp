#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1005;

struct node
{
    int num_node;  //�˼����а�������
    int father;    //����
    int sumc;       //��Ȩֵ
    int ans;        //���������ӽڵ����û���
    int flag;       //��ʾ���ѷ��ʹ�
} Tree[N];

int Find (int p)//���鼯�ϲ��ڵ�
{
    if (p != Tree[p].father && Tree[Tree[p].father].flag){ //Tree[p].father������Ǹ��ڵ���Tree[p].father�ѷ�ˢ���ܼ���������
        Tree[p].father = Find(Tree[p].father);   //���ĸ��ױ�ɸ��׵�����
    }
    return Tree[p].father;  //�����������ġ����׵ı�ţ���һ���Ǹ��ڵ�
}
int main()
{
    int r,n,a,b,indexn,father,k;
    double maxv;
    while(scanf("%d%d",&n,&r), n || r ){
        memset(Tree,0,sizeof(Tree));
        for(int i=1; i<=n; i++){
            scanf("%d",&Tree[i].sumc); //Ȩֵ
            Tree[i].ans = Tree[i].sumc;
            Tree[i].num_node = 1;
        }
        for(int i=1; i<n; i++){
            scanf("%d %d",&a,&b);
            Tree[b].father = a;
        }
        Tree[r].father = r;
        //printf("tree1:%d\n", Tree[1].flag);
        for(int i=1; i<n; i++){ //ѭ��n-1�ΰ�ÿ���㰴˳��ϲ���ע���ⲻ�Ƿ�ˢ˳��
            maxv = 0;
            for(int j=1; j<=n; j++){
                if(!Tree[j].flag && maxv < Tree[j].sumc*1.0/Tree[j].num_node && j != r){
                    indexn = j;
                    maxv = Tree[j].sumc*1.0/Tree[j].num_node;
                }
            }
            Tree[indexn].flag = 1;   //��ʾ�Ѻϲ�
            father = Find(indexn);   //�����ҵ���߳�������һ���Ǹ��ڵ�
            //printf("\n%d %d %d %d %d\n",indexn, father, Tree[indexn].num_node, Tree[indexn].sumc, Tree[indexn].ans);//����Ϊ�ֻ�����ʽ
            Tree[father].ans += Tree[indexn].ans + Tree[indexn].sumc * Tree[father].num_node;
            //��Ҫ�����׵��ܻ���=�����ܻ���+������Ȩֵ*���׵�˳��ֵ
            Tree[father].sumc += Tree[indexn].sumc; //���׵���Ȩֵ�ü��Ϻ��ӵ���Ȩֵ
            Tree[father].num_node += Tree[indexn].num_node;//���׵�˳��ֵҪ���Ϻ��ӵ�˳��ֵ��ע����Ҫ�����길���ܻ��Ѻ�
        }
        printf("%d\n\n",Tree[r].ans);
    }
    return 0;
}
