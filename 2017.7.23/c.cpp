#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream> 
using namespace std;

int N;

struct matrix
{
       int a[2][2];
}origin,res;


matrix multiply(matrix x,matrix y)
{
       matrix temp;
       memset(temp.a,0,sizeof(temp.a));
       for(int i=0;i<2;i++)
       {
               for(int j=0;j<2;j++)
               {
                       for(int k=0;k<2;k++)
                       {
                               temp.a[i][j]+=(x.a[i][k]%10000)*(y.a[k][j]%10000);
                               temp.a[i][j]%=10000;
                       }
               }
       }
       return temp;
}

void init()
{
     origin.a[0][0]=1;
     origin.a[0][1]=1;
     origin.a[1][0]=1;
     origin.a[1][1]=0;
     // for(int i=0;i<2;i++){
     //  for(int j=0;j<2;j++){
     //    printf("%8d ",origin.a[i][j]);
     //  }
     //  printf("\n");
     // }
     memset(res.a,0,sizeof(res.a));
     res.a[0][0]=res.a[1][1]=1;                  //将res.a初始化为单位矩阵 
}

void calc(int n)
{
    // printf("%d次幂结果如下：\n",n);
     while(n)
     {
             if(n&1)
                    res=multiply(res,origin);
             n>>=1;
             origin=multiply(origin,origin);
     }
     
     // for(int i=0;i<2;i++)
     // {
     //         for(int j=0;j<2;j++)
     //                 printf("%8d",res.a[i][j]);
     //         printf("\n");
     // }
     // printf("\n");
     printf("%d\n",res.a[1][0]);
}
int main()
{
    freopen("test.txt","r",stdin);
    while(~scanf("%d",&N)&&N!=-1)
    {
            //printf("%d\n",N);
            if(N==0){
              printf("0\n");
              continue;
            }
            init();
            calc(N);
    }
    return 0;
}