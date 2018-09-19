#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a=='S')
	{
		if(b=='S')
		   printf("DECUE");
		else
		{
			if(b=='J')
			   printf("FIRST");
			else
			   printf("SECOND");
		}
	}
	else
	{
		if(a=='J')
		{
			if(b=='S')
			   printf("SECOND");
			else
			{
				if(b=='J')
				   printf("DECUE");
				else
				   printf("FIRST");
			}
		}
		else
		{
			if(b=='S')
			   printf("FIRST");
			else
			{
				if(b=='J')
				   printf("SECOND");
				else
				   printf("DECUE");
			}
		}
	}
	return 0;
}
