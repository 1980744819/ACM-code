#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF=(1<<20)-1;
int f[81][1<<9][21]={0};//��i��״̬Ϊs[j],ǰi�з�k�����ӵķ�������
int s[1<<9];//����״̬
int c[1<<9];//ÿ��״̬��Ӧ��1�ĸ���
int n,m,maxn=0,count1=0,num=0;//n�У�m��

void dfs(int state,int p,int count1)//��ǰ״̬��λ�ã�1�ĸ���
{
    if(p>m)//�д������������ˣ���ÿһ�ж�����Ӧ�ķ����ˣ�
    {
        num++;
        s[num]=state;
        c[num]=count1;
        return ;//������һ��λ��ִ����һ�ַ�����
    }
    dfs(state,p+1,count1);//��ǰλ�ò���
    dfs(state+(1<<(p-1)),p+2,count1+1);//��ǰλ�÷ţ�����֮����һ��λ�þͲ��ܷ��ˡ�
}

int main()
{
    int i,j,k,t;
    while(~scanf("%d%d%d",&n,&m,&maxn)){
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        memset(c,0,sizeof(c));
        if(m>n) swap(n,m);//���г�ΪС���Ǹ�
        dfs(0,1,0);//ȫ���ţ��ӵ�һ�п�ʼ��1�ĸ�����0
        for(i=1;i<=num;++i)
            f[1][s[i]][c[i]]=1;//��һ��ʹ��״̬s[i]������count[i]�����ӡ���һ�ַ���

        for(i=2;i<=n;++i)//ǰ2-n��
        {
            for(j=1;j<=num;++j)//��ǰ�е�״̬
            {
                for(k=1;k<=num;++k)//��һ��״̬
                {
                    if((s[j]&s[k])||((s[j]>>1)&s[k])||((s[j]<<1)&s[k]))continue;
                        for(t=0;t<=maxn;++t)//ǰi�з��˼�������
                        {
                            if(t>=c[j])//����ǰ��Ϊֹ�ŵ���������Ҫ��С��ѡ��ǰ״̬�Ż���ӵ���������
                                f[i][s[j]][t] += f[i-1][s[k]][t-c[j]];
                        }
                }
            }
        }
        long long ans=0;
        for(i=1;i<=num;++i){
            ans+=f[n][s[i]][maxn];
        }//ǰn�з�k�����ӣ���n��ѡ��״̬s[i]�ķ��������
        ans%=200640345;
        printf("%lld\n",ans);
    }
    return 0;
}
