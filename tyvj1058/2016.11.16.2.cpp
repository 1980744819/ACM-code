#include <stdio.h>
#include <string.h>
int train[361];
int machine[19][19];
int time[19][19];
int used[19];
int finished[19];
char cpu[19][361];
int main(void)
{
    int i,j,k;
    int m,n;
    int t;
    int ans;
    scanf("%d%d",&m,&n);
    for(i=0;i<m*n;i++)
    {
        scanf("%d",&train[i]);
        train[i]--;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
    {
            scanf("%d",&machine[i][j]);
            machine[i][j]--;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
    {
            scanf("%d",&time[i][j]);
        }
    }
    ans = 0;
    for(i=0;i<m*n;i++)
    {
        t=train[i];
        j=finished[t]-1;        //������Ϊ������ʧ��ʱ��j��ֵ��Ҫ��ǰ��һ��
        do{                //�����ڸ�ֵ��ʱ��ͼ���һ��Ȼ����do-while
            j++;            //����ʽ��һ�����Ͷ�j������
            for(k=0;k<time[t][used[t]];k++)
               {
                if(cpu[machine[t][used[t]]][j+k]){
                    j=k+j;    //�������ʼ�Ҿʹ������д���j = k + j
                    break;        //��λ���ϣ��Ұ�λ�÷���while(..)�����棬
                }            //Ҳ�͵���������ʱ��ѡ���˴������µ�λ��
            }                //ʱ�ڵ��µ�memset���ܹ�������������Ϊ��
                            //��ʹ�õ�finished������j������ѡ����λ��
                            //֮��ᵼ��һЩԤ�벻�������⡣
        }while(cpu[machine[t][used[t]]][j]);
        memset(cpu[machine[t][used[t]]]+j,t+1,time[t][used[t]]);
        if(ans<j+time[t][used[t]])
         {
            ans=j+time[t][used[t]];
        }
        finished[t]=j+k;
        used[t]++;
    }
                            //���������һ��ע�ͣ��Ұ���ans����
                            //������ѭ�����棬������һЩ�ɶ��ԣ���
                            //��λ����˵��Sorry..
    printf("%d\n",ans);
    return 0;
}
