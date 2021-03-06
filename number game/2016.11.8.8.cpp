#include<stdio.h>
#include<string.h>

int dp[1<<20];
int info[21];
int n; // 每组的个数

int solve(int a,int b)
{
    int i,j,c,d;
    if( a == 0 )
        return 0;
    if( dp[a] != -1 ) //表明已经判断过了。  直接返回结果
        return dp[a];
    for( i = 0; i < n; i ++ ){
        c = a;
        d = b;
        if( (1 << i) & c ){  //寻找该状态下可选的数，继续搜索
            for( j = 0; j + info[i] < 21; j ++ ){  //标记受该数影响的数
                if( (1 << j) & d ){
                    d = d | (1 << (info[i] + j) );
                }
            }
            for( j = 0; j < n; j ++ ){  //删除受影响的数
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
    int a,b;   //a表示状态，初始全为1  b表示序列删除的状况，1表示不在，0表示在
    int item;  // 总的序列。  0表示存在，1表示不在
    int res[21];
    int case_ = 1;  //记录测试组数
    while(scanf("%d",&n) != EOF && n!= 0)
    {
        item = (1<<22) - 3;       //将1添进序列，1始终是可选但又不能选的数。总序列变成 11 1111 1111 1111 1111 1101  0指该序列中0存在。
        for( i = 0 ; i < n; i ++ ){
            scanf("%d", &info[i]);
            item ^= (1 << info[i]); //^异或运算符,位值相同为0,不同为1。将序列中的数在item中标记，相应位置都为0，这样做删除方便
        }
        for( i = 0; i < n; i ++ ){ //冒泡排序
            for( j = 0; j < n - i - 1; j ++ ){
                if( info[j] > info[j + 1] ) {
                    info[j] = info[j] ^ info[j + 1];
                    info[j + 1] = info[j] ^ info[j + 1];
                    info[j] = info[j] ^ info[j + 1];
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        for(k = i = 0; i < n;i ++ ){  //枚举第一个被选的数
            a = (1<<n) - 1;   //a表示状态，初始全为1
            b = item;   //b表示序列删除的状况，1表示不在，0表示在
            for( j = 0; j + info[i] < 21; j ++ ){
                if( (1<<j) & b ){  //如果j不在可选序列，那么j + info[i] 会因info[i]的删除而删除
                    b = b | ( 1 << (j + info[i]) );  //将该数相应位置置1
                }
            }
            for( j = 0; j < n; j ++ ){  //判断哪个数被删除了
                if( (1 << info[j]) & b ){
                    a = a ^ (1 << j);  //将该数删除置为0
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
