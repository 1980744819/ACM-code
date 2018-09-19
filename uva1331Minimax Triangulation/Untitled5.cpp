#include<cstdio>
#include<cstdlib>
#define INF 0xfffffff

const int Maxm=50+5;

int m;
int x[Maxm],y[Maxm];
double d[Maxm][Maxm];

double area(int a,int b,int c)
{
    double s=(double)(1.0/2)*(x[a]*y[b]+x[b]*y[c]+x[c]*y[a]-x[a]*y[c]-x[b]*y[a]-x[c]*y[b]);
    if(s<0) return -s;
    return s;
}

double mymin(double a,double b) {return a<b?a:b;}

double mymax(double a,double b) {return a>b?a:b;}

bool check(int a,int b,int c)
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(i==a||i==b||i==c) continue;
        double d=area(a,b,i)+area(a,c,i)+area(b,c,i)-area(a,b,c);
        if(d<0) d=-d;
        if(d<=0.01) return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int i,j,k;
        scanf("%d",&m);
        for(i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]);
        for(i=m;i>=1;i--)
        {
            d[i][i+1]=0.0;
            for(j=i+2;j<=m;j++)
            {
                d[i][j]=INF;
                for(k=i+1;k<j;k++)
                {
                    if(check(i,j,k))
                    d[i][j]=mymin(d[i][j],mymax(mymax(area(i,j,k),d[i][k]),d[k][j]));
                }
            }

        }
        printf("%.1lf\n",d[1][m]);
    }
}
