#include <stdio.h>
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
        for( int i=1;i<=n;i++)
		  printf("%3d",i);
		printf("\n");
		for(int i=2;i<=n-1;i++)
		{
			printf("%3d",4*n-2-i);
			for(int j=1;j<=n*3-6;j++)
				printf(" ");
			printf("%3d",n+i-1);
			printf("\n");
		}
		if(n>1)
		{
		for(int i=3*n-2;i>=2*n-1;i--)
			printf("%3d",i);
		printf("\n");
		}
	}
	return 0;
}
