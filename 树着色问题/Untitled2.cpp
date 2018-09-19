#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1005;

struct node
{
    int num_node;  //此集合中包含点数
    int father;    //父亲
    int sumc;       //总权值
    int ans;        //它和它的子节点所用花费
    int flag;       //表示它已访问过
} Tree[N];

int Find (int p)//并查集合并节点
{
    if (p != Tree[p].father && Tree[Tree[p].father].flag){ //Tree[p].father如果不是根节点且Tree[p].father已粉刷就能继续往下找
        Tree[p].father = Find(Tree[p].father);   //它的父亲变成父亲的祖先
    }
    return Tree[p].father;  //返回它“最后的”父亲的编号，不一定是根节点
}
int main()
{
    int r,n,a,b,indexn,father,k;
    double maxv;
    while(scanf("%d%d",&n,&r), n || r ){
        memset(Tree,0,sizeof(Tree));
        for(int i=1; i<=n; i++){
            scanf("%d",&Tree[i].sumc); //权值
            Tree[i].ans = Tree[i].sumc;
            Tree[i].num_node = 1;
        }
        for(int i=1; i<n; i++){
            scanf("%d %d",&a,&b);
            Tree[b].father = a;
        }
        Tree[r].father = r;
        //printf("tree1:%d\n", Tree[1].flag);
        for(int i=1; i<n; i++){ //循环n-1次把每个点按顺序合并，注意这不是粉刷顺序
            maxv = 0;
            for(int j=1; j<=n; j++){
                if(!Tree[j].flag && maxv < Tree[j].sumc*1.0/Tree[j].num_node && j != r){
                    indexn = j;
                    maxv = Tree[j].sumc*1.0/Tree[j].num_node;
                }
            }
            Tree[indexn].flag = 1;   //表示已合并
            father = Find(indexn);   //找能找到最高长辈，不一定是根节点
            //printf("\n%d %d %d %d %d\n",indexn, father, Tree[indexn].num_node, Tree[indexn].sumc, Tree[indexn].ans);//以下为轮换不等式
            Tree[father].ans += Tree[indexn].ans + Tree[indexn].sumc * Tree[father].num_node;
            //重要：父亲的总花费=孩子总花费+孩子总权值*父亲的顺序值
            Tree[father].sumc += Tree[indexn].sumc; //父亲的总权值得加上孩子的总权值
            Tree[father].num_node += Tree[indexn].num_node;//父亲的顺序值要加上孩子的顺序值，注意这要在算完父亲总花费后
        }
        printf("%d\n\n",Tree[r].ans);
    }
    return 0;
}
