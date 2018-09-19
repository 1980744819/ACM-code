#include<stdio.h>
#include<string.h>
#include <iostream>
#define ll long long
#define bababaa printf("!!!!!\n")
using namespace std;
ll mod=2147493647;
int aa,bb,n;
struct Matrix
{
    ll m[7][7];
};
Matrix Mul(Matrix a,Matrix b)
{
    Matrix c;
    memset(c.m,0,sizeof(c.m));
    for(int i=0; i<7; i++)
        for(int j=0; j<7; j++)
            for(int k=0; k<7; k++)
            {
                c.m[i][j] =c.m[i][j]+((a.m[i][k]%mod)*(b.m[k][j]%mod)%mod);
            }
    return c;
}
Matrix fastm(Matrix a,int n)
{
    Matrix res;
    memset(res.m,0,sizeof(res.m));
    res.m[0][0]=bb,res.m[1][0]=aa,res.m[2][0]=16,res.m[3][0]=8,res.m[4][0]=4,res.m[5][0]=2,res.m[6][0]=1;
    while(n)
    {
        if(n&1)
            res = Mul(a,res);
        n>>=1;
        a = Mul(a,a);
    }
    return res;
}
Matrix init()
{
    Matrix pp;
    memset(pp.m,0,sizeof(pp.m));
    pp.m[0][0] = 1, pp.m[0][1] = 2, pp.m[0][2] = 1, pp.m[0][3] = 4, pp.m[0][4] = 6, pp.m[0][5] = 4, pp.m[0][6] = 1;
    pp.m[1][0] = 1, pp.m[1][1] = 0, pp.m[1][2] = 0, pp.m[1][3] = 0, pp.m[1][4] = 0, pp.m[1][5] = 0, pp.m[1][6] = 0;
    pp.m[2][0] = 0, pp.m[2][1] = 0, pp.m[2][2] = 1, pp.m[2][3] = 4, pp.m[2][4] = 6, pp.m[2][5] = 4, pp.m[2][6] = 1;
    pp.m[3][0] = 0, pp.m[3][1] = 0, pp.m[3][2] = 0, pp.m[3][3] = 1, pp.m[3][4] = 3, pp.m[3][5] = 3, pp.m[3][6] = 1;
    pp.m[4][0] = 0, pp.m[4][1] = 0, pp.m[4][2] = 0, pp.m[4][3] = 0, pp.m[4][4] = 1, pp.m[4][5] = 2, pp.m[4][6] = 1;
    pp.m[5][0] = 0, pp.m[5][1] = 0, pp.m[5][2] = 0, pp.m[5][3] = 0, pp.m[5][4] = 0, pp.m[5][5] = 1, pp.m[5][6] = 1;
    pp.m[6][0] = 0, pp.m[6][1] = 0, pp.m[6][2] = 0, pp.m[6][3] = 0, pp.m[6][4] = 0, pp.m[6][5] = 0, pp.m[6][6] = 1;
    return pp;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&aa,&bb);
        if(n==1)
            printf("%d\n",aa%mod);
        else if(n==2)
            printf("%d\n",bb%mod);
        else
        {
            Matrix p;
            p=fastm(init(),n-2);
            printf("%d\n",p.m[0][0]%mod);
        }
    }
}
