#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct stu{
    int a;
    int b;
}stu[1001];
bool cmp(struct stu m,struct stu n){
    return m.b<n.b;
}
int num[1010][5500];
int num_add[4][5500];
/*int com(){
    int mi=1;
    if(num_add[mi][0]>num[2][0])
        mi=2;
    else if(num_add[mi][0]==num[2][0]){
            int t=num_add[mi][0];
            int k=num_add[2][0];
        if(num_add[mi][t]>num[2][k])
            mi=2;
    }
    if(num_add[mi][0]>num[3][0])
        mi=3;
    else if(num_add[mi][0]==num[3][0]){
            int t=num_add[mi][0];
            int k=num_add[3][0];
        if(num_add[mi][t]>num[3][k])
            mi=3;
    }
    return mi;
}*/
int main(){
    int n;
    int i,j;
    i=0;
    int na;
    while(~scanf("%d",&n)&&n!=0){
        stu[i].a=i;
        stu[i].b=n;
        i++;
    }
    sort(stu,stu+i,cmp);
    /*for(j=0;j<i;j++){
        printf("%d %d\n",stu[j].a,stu[j].b);
    }*/
    n=i;
    int m;
    m=1;
    int stu_i=0;
    num_add[m][0]=1;
    num_add[m][1]=1;
    while(m==stu[stu_i].b&&stu_i<n){
        //printf("%d\n",m);
        num[stu[stu_i].a][0]=1;
        num[stu[stu_i].a][1]=1;
        stu_i++;
    }
    m++;
    num_add[m][0]=1;
    num_add[m][1]=1;
    while(m==stu[stu_i].b&&stu_i<n){
        //printf("%d\n",m);
        num[stu[stu_i].a][0]=1;
        num[stu[stu_i].a][1]=1;
        stu_i++;
    }
    int t=stu[n-1].b;
    //printf("%d\n",t);
    int mi;
    int numn;
    while(m<=t){
        m++;
        //memset(num_add[3],0,sizeof(num_add[3]));
        num_add[3][0]=num_add[2][0];
        numn=num_add[2][0];
        num_add[3][1]=0;
        for(i=1;i<=numn;i++){
            num_add[3][i+1]=0;
            num_add[3][i]+=num_add[2][i]+num_add[1][i];
            if(num_add[3][i]>=10000){
                num_add[3][i]-=10000;
                num_add[3][i+1]++;
                if(i==numn){
                    num_add[3][0]++;
                }
            }
        }
        /*for(j=num_add[3][0];j>=1;j--){
            printf("%lld",num_add[3][j]);
        }
        printf("\n");
        Sleep(1000);*/
        while(m==stu[stu_i].b&&stu_i<n){
            na=stu[stu_i].a;
            for(i=0;i<=num_add[3][0];i++){
                num[na][i]=num_add[3][i];
            }
            stu_i++;
        }


        m++;
        //memset(num_add[3],0,sizeof(num_add[3]));
        num_add[1][0]=num_add[3][0];
        numn=num_add[3][0];
        num_add[1][1]=0;
        for(i=1;i<=numn;i++){
            num_add[1][i+1]=0;
            num_add[1][i]+=num_add[2][i]+num_add[3][i];
            if(num_add[1][i]>=10000){
                num_add[1][i]-=10000;
                num_add[1][i+1]++;
                if(i==numn){
                    num_add[1][0]++;
                }
            }
        }
        /*for(j=num_add[1][0];j>=1;j--){
            printf("%lld",num_add[1][j]);
        }
        printf("\n");
        Sleep(1000);*/
        while(m==stu[stu_i].b&&stu_i<n){
            na=stu[stu_i].a;
            for(i=0;i<=num_add[1][0];i++){
                num[na][i]=num_add[1][i];
            }
            stu_i++;
        }


        m++;
        //memset(num_add[3],0,sizeof(num_add[3]));
        num_add[2][0]=num_add[1][0];
        numn=num_add[1][0];
        num_add[2][1]=0;
        for(i=1;i<=numn;i++){
            num_add[2][i+1]=0;
            num_add[2][i]+=num_add[3][i]+num_add[1][i];
            if(num_add[2][i]>=10000){
                num_add[2][i]-=10000;
                num_add[2][i+1]++;
                if(i==numn){
                    num_add[2][0]++;
                }
            }
        }
        /*for(j=num_add[2][0];j>=1;j--){
            printf("%lld",num_add[2][j]);
        }
        printf("\n");
        Sleep(1000);*/
        while(m==stu[stu_i].b&&stu_i<n){
            na=stu[stu_i].a;
            for(i=0;i<=num_add[2][0];i++){
                num[na][i]=num_add[2][i];
            }
            stu_i++;
        }
    }
    int ta;
    for(i=0;i<n;i++){
        for(j=num[i][0];j>=1;j--){
            if(num[i][j]>=1000)
                printf("%d",num[i][j]);
            else{
                if(j!=num[i][0]){
                    ta=num[i][j];
                    printf("%d",ta/1000);
                    ta%=1000;
                    printf("%d",ta/100);
                    ta%=100;
                    printf("%d",ta/10);
                    ta%=10;
                    printf("%d",ta);
                }
                else{
                    printf("%d",num[i][j]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
