#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cstring>
using namespace std;
int main(void)
{
    int a[26],cas,i,j;
    cin>>cas;
    while(cas--)
    {
        bool ok=false;
        for(i=1;i<=24;i++)
        {
            scanf("%d",&a[i]);
        }
        bool nomove=true;
        for(i=1;i<=21;i+=4)
        {
            for(j=i;j<=i+2;j++)
            {
                if(a[j]!=a[j+1])
                {
                    nomove=false;
                }
            }
        }
        if(nomove)
        {
            printf("YES\n");
            continue;
        }
        if(a[17]==a[18]&&a[18]==a[19]&&a[19]==a[20]&&a[21]==a[22]&&a[22]==a[23]&&a[23]==a[24])
        {
            //1
            if(a[15]==a[13]&&a[13]==a[2]&&a[2]==a[4])
            {
                if(a[1]==a[3]&&a[3]==a[6]&&a[6]==a[8])
                {
                    if(a[7]==a[5]&&a[5]==a[10]&&a[10]==a[12])
                    {
                        if(a[11]==a[9]&&a[9]==a[14]&&a[14]==a[16])
                        {
                            ok=true;
                        }
                    }
                }
            }
            //2
            if(a[2]==a[4]&&a[4]==a[5]&&a[5]==a[7])
            {
                if(a[6]==a[8]&&a[9]==a[8]&&a[9]==a[11])
                {
                    if(a[10]==a[12]&&a[12]==a[13]&&a[13]==a[15])
                    {
                        if(a[1]==a[3]&&a[3]==a[14]&&a[14]==a[16])
                        {
                            ok=true;
                        }
                    }
                }
            }
        }
        if(a[13]==a[14]&&a[14]==a[15]&&a[15]==a[16]&&a[5]==a[6]&&a[6]==a[7]&&a[7]==a[8])
        {
            //3
            if(a[17]==a[18]&&a[18]==a[10]&&a[10]==a[9])
            {
                if(a[21]==a[22]&&a[22]==a[3]&&a[3]==a[4])
                {
                    if(a[1]==a[2]&&a[2]==a[19]&&a[19]==a[20])
                    {
                        if(a[24]==a[23]&&a[23]==a[11]&&a[11]==a[12])
                        {
                            ok=true;
                        }
                    }
                }
            }
            //4
            if(a[17]==a[18]&&a[18]==a[3]&&a[3]==a[4])
            {
                if(a[21]==a[22]&&a[22]==a[9]&&a[9]==a[10])
                {
                    if(a[1]==a[2]&&a[2]==a[23]&&a[23]==a[24])
                    {
                        if(a[19]==a[20]&&a[20]==a[11]&&a[11]==a[12])
                        {
                            ok=true;
                        }
                    }
                }
            }
        }
        if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[9]==a[10]&&a[10]==a[11]&&a[11]==a[12])
        {
            //5
            if(a[17]==a[5]&&a[5]==a[6]&&a[6]==a[19])
            {
                if(a[15]==a[22]&&a[22]==a[16]&&a[16]==a[24])
                {
                    if(a[23]==a[21]&&a[21]==a[7]&&a[7]==a[8])
                    {
                        if(a[13]==a[14]&&a[14]==a[20]&&a[20]==a[18])
                        {
                            ok=true;
                        }
                    }
                }
            }
            //6
            if(a[17]==a[15]&&a[15]==a[19]&&a[19]==a[16])
            {
                if(a[5]==a[6]&&a[6]==a[22]&&a[22]==a[24])
                {
                    if(a[20]==a[18]&&a[18]==a[7]&&a[7]==a[8])
                    {
                        if(a[13]==a[14]&&a[21]==a[14]&&a[21]==a[23])
                        {
                            ok=true;
                        }
                    }
                }
            }
        }
        if(ok==true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
