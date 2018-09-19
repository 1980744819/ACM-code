#include <cstdio>
int main(int argc, char const *argv[])
{
	int r, c, input;
	while(~scanf("%d%d", &r, &c))
	{
		int maxa = 0, maxb = 0;
		int numa = 0, numb = 0;
		int suma = 0, sumb = 0;
		for (int i = 0; i < r; ++i)
		{
			scanf("%d", &input);
			if (input > maxa)
				maxa = input;
			if (input)
				++numa;
			suma += input;
		}
		for (int i = 0; i < c; ++i)
		{
			scanf("%d", &input);
			if (input > maxb)
				maxb = input;
			if (input)
				++numb;
			sumb += input;
		}
		if (maxa > numb || maxb > numa || suma != sumb)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}
