#include<iostream>
using namespace std;

long long  Mod = 1e9 + 7;
int t;
long long Dp[2000010];
int Max;

int main()
{
	Dp[0] = 1;
	Dp[1] = 1;
	Dp[2] = 1;
	Dp[3] = 3;
	Dp[4] = 11;
	Max = 4;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n > Max)
		{
			for (long long i = Max + 1;i <= n;i++)
				Dp[i] = (((i - 1)*Dp[i - 1]) % Mod + ((i - 2)*Dp[i - 2]) % Mod) % Mod;
			Max = n;
		}
		cout << Dp[n] << endl;
	}
	return 0;
}
