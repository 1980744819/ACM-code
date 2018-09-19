#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a[27];
int n;
bool flag;
void fun(int cen);
bool chack(int cen,int i);
int main()
{
	while(scanf("%d",&n)&&n)
	{
		flag=false;
		fun(0);
		if(!flag)
		{
			printf("No answer.\n");
		}
		printf("\n");
	}
return 0;
}
void fun(int cen)
{
	if(flag)
	return ;
	if(cen==n)
	{
		flag=true;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j==a[i])
				{
					printf("Q ");
				}
				else
				printf(". ");
			}
			printf("\n");
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(chack(cen,i))
			{
				a[cen]=i;
				fun(cen+1);
			}
		}
	}
}
bool chack(int cen,int i)
{
	bool ret=true;
	for(int j=0;j<cen;j++)
	{
		if(a[j]==i||abs(j-cen)==abs(i-a[j]))
		{
			ret=false;
			break;
		}
	}
	return ret;
}
