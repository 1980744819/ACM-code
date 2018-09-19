#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <int> stk;

bool isvariable(char c, int pp, int qq, int rr, int ss, int tt)
{
	switch (c)
	{
	case 'p': stk.push(pp); return true;
	case 'q': stk.push(qq); return true;
	case 'r': stk.push(rr); return true;
	case 's': stk.push(ss); return true;
	case 't': stk.push(tt); return true;
	}
	return false;
}

void operand(char op)
{
	switch (op)
	{
	case 'K':
		{
			int x = stk.top();
			stk.pop();
			int y = stk.top();
			stk.pop();
			stk.push(x && y);
			break;
		}
	case 'A':
		{
			int x = stk.top();
			stk.pop();
			int y = stk.top();
			stk.pop();
			stk.push(x || y);
			break;
		}
	case 'C':
		{
			int x = stk.top();
			stk.pop();
			int y = stk.top();
			stk.pop();
			stk.push((!x) || y);
			break;
		}
	case 'E':
		{
			int x = stk.top();
			stk.pop();
			int y = stk.top();
			stk.pop();
			stk.push(x == y);
			break;
		}
	case 'N':
		{
			int x = stk.top();
			stk.pop();
			stk.push(!x);
			break;
		}
	}
	return;
}

int main()
{
	string s;
	while (cin >> s && s != "0")
	{
		bool flag = true;
		for (int pp = 0; pp <= 1; ++pp)
		{
			for (int qq = 0; qq <= 1; ++qq)
			{
				for (int rr = 0; rr <= 1; ++rr)
				{
					for (int ss = 0; ss <= 1; ++ss)
					{
						for (int tt = 0; tt <= 1; ++tt)
						{
							for (int i = s.size() - 1; i >= 0; i--)
							{
								if (!isvariable(s[i], pp, qq, rr, ss, tt))
									operand(s[i]);
							}
							int ans = stk.top();
							stk.pop();
							if (!ans)
							{
								flag = false;
								break;
							}
						}
						if (!flag)
							break;
					}
					if (!flag)
						break;
				}
				if (!flag)
					break;
			}
			if (!flag)
				break;
		}
		if (flag)
		{
			cout << "tautology" << endl;
		}
		else cout << "not" << endl;

		while (!stk.empty())
		{
			stk.pop();
		}
	}
}
