	#include<cstdio>
	#include<string>
	#include<cstring>
	#include<cstdlib>
	#include<cmath>
	#include<iostream>
	#include<algorithm>
	#include<vector>
	#include<queue>
	#include<map>
	#include<set>
	#include<stack>
	using namespace std;

	int main(){
		//freopen("test.txt","r",stdin);
		int t;
		scanf("%d",&t);
		int maxn;
		while(t--)
		{
			int n;
			scanf("%d",&n);
			int a,b,c,ab,bc,ac,abc;
			int maxans = 0;
			for(int i=0;i<n;i++)
			{
				scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
				bool flag = true;
				if(ab-abc<0||bc-abc<0||ac-abc<0)
				{
					flag = false;
				}

				if(a-ab-ac+abc<0||b-ab-bc+abc<0||c-bc-ac+abc<0)
				{
					flag=false;
				}

				if(flag)
					maxans = max(maxans,a+b+c-ab-ac-bc+abc);
			}
			cout<<maxans<<endl;
		}
		return 0;
	}