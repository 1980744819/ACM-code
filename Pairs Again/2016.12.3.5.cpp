#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;
map<int, vector<int> > M;
int main()
{
	int N, K;
	while (~scanf("%d %d",&N,&K))
	{
		M . clear();
		for (int i = 0; i < N; i++)
		{
			int x;
			scanf("%d",&x);
			int a = x%K;
			int b = x / K;
			M[a].push_back(b);
		}
		long long ans = 0;
		for (int i = 0; i < M.size(); i++)
		{
			sort(M[i].begin(), M[i].end());
			long long tans = 0;
			for (int j = 0; j < M[i].size(); j++)
			{
				if (j > 0 && M[i][j] == M[i][j - 1])
				{
					ans += tans;
					continue;
				}
				tans = 0;
				int w = j + 1;
				while (w < M[i].size() && M[i][w] <=M[i][j] + 1)
				{
					if (M[i][w] == M[i][j] + 1)
					{
						ans++;
						tans++;
					}
					w++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

