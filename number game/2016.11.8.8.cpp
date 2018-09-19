#include<stdio.h>
#include<string.h>

int dp[1<<20];
int info[21];
int n; // ÿ��ĸ���

int solve(int a,int b)
{
    int i,j,c,d;
    if( a == 0 )
        return 0;
    if( dp[a] != -1 ) //�����Ѿ��жϹ��ˡ�  ֱ�ӷ��ؽ��
        return dp[a];
    for( i = 0; i < n; i ++ ){
        c = a;
        d = b;
        if( (1 << i) & c ){  //Ѱ�Ҹ�״̬�¿�ѡ��������������
            for( j = 0; j + info[i] < 21; j ++ ){  //����ܸ���Ӱ�����
                if( (1 << j) & d ){
                    d = d | (1 << (info[i] + j) );
                }
            }
            for( j = 0; j < n; j ++ ){  //ɾ����Ӱ�����
                if( ( (1 << j ) & c ) && ( (1 << info[j]) & d ) ){
                    c = c^(1 << j);
                }
            }
            if( !solve(c,d) )
                return dp[a] = 1;
        }
    }
    return dp[a] = 0;
}

int main()
{
    int i, j, k;
    int a,b;   //a��ʾ״̬����ʼȫΪ1  b��ʾ����ɾ����״����1��ʾ���ڣ�0��ʾ��
    int item;  // �ܵ����С�  0��ʾ���ڣ�1��ʾ����
    int res[21];
    int case_ = 1;  //��¼��������
    while(scanf("%d",&n) != EOF && n!= 0)
    {
        item = (1<<22) - 3;       //��1������У�1ʼ���ǿ�ѡ���ֲ���ѡ�����������б�� 11 1111 1111 1111 1111 1101  0ָ��������0���ڡ�
        for( i = 0 ; i < n; i ++ ){
            scanf("%d", &info[i]);
            item ^= (1 << info[i]); //^��������,λֵ��ͬΪ0,��ͬΪ1���������е�����item�б�ǣ���Ӧλ�ö�Ϊ0��������ɾ������
        }
        for( i = 0; i < n; i ++ ){ //ð������
            for( j = 0; j < n - i - 1; j ++ ){
                if( info[j] > info[j + 1] ) {
                    info[j] = info[j] ^ info[j + 1];
                    info[j + 1] = info[j] ^ info[j + 1];
                    info[j] = info[j] ^ info[j + 1];
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        for(k = i = 0; i < n;i ++ ){  //ö�ٵ�һ����ѡ����
            a = (1<<n) - 1;   //a��ʾ״̬����ʼȫΪ1
            b = item;   //b��ʾ����ɾ����״����1��ʾ���ڣ�0��ʾ��
            for( j = 0; j + info[i] < 21; j ++ ){
                if( (1<<j) & b ){  //���j���ڿ�ѡ���У���ôj + info[i] ����info[i]��ɾ����ɾ��
                    b = b | ( 1 << (j + info[i]) );  //��������Ӧλ����1
                }
            }
            for( j = 0; j < n; j ++ ){  //�ж��ĸ�����ɾ����
                if( (1 << info[j]) & b ){
                    a = a ^ (1 << j);  //������ɾ����Ϊ0
                }
            }
            if( !solve(a,b) )
                res[k ++] = info[i];
        }
        printf("Test Case #%d\n",case_ ++);
        if( k ) {
            printf("The winning moves are:");
            for( i = 0; i < k; i ++ ){
                printf(" %d",res[i]);
            }
            puts("");
        }
        else puts("There's no winning move.");
        puts("");
    }
    return 0;
}
