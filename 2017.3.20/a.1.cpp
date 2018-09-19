#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<memory.h>
#include<string>
#include<string.h>
#include<vector>
#include<map>
#include<set>
using namespace std;
//typedef long long int;


int n;
int a, b;

long long res[100010];
int data1[100010];


int main()
{


	while (scanf("%d %d %d", &n, &a, &b) != EOF)
	{

		//memset(res, 0, sizeof(res));

		long long sum = 0;
		int deold;
		int denew;
		deold = 1000000;


	//	long long sum = 0;

		for (int i = 0;i < n;i++)
		{


			scanf("%d", &data1[i]);

			if (i == 0)
			{

				res[i] = 1;
				sum += res[i];
				continue;
			}


			denew = data1[i] - data1[i - 1];

			if (deold == a&&denew == a || denew == b&&deold == a || denew == b&&deold == b)
				res[i] = res[i - 1] + 1;
			else
				if (denew == a || denew == b)
					res[i] = 2;
				else
					res[i] = 1;

			deold = denew;
			sum += res[i];
		}

		cout << sum << endl;
	}


	return 0;
}
