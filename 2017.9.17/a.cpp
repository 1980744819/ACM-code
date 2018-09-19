#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=10000;
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		string s1,s2;
		//scanf("%s %s",s1,s2);
		cin>>s1>>s2;
		int a,b;
		if(s1=="rat"){
			a=1;
		}
		else if(s1=="ox"){
			a=2;
		}
		else if(s1=="tiger"){
			a=3;
		}
		else if(s1=="rabbit"){
			a=4;
		}
		else if(s1=="dragon"){
			a=5;
		}
		else if(s1=="snake"){
			a=6;
		}
		else if(s1=="horse"){
			a=7;
		}
		else if(s1=="sheep"){
			a=8;
		}
		else if(s1=="monkey"){
			a=9;
		}
		else if(s1=="rooster"){
			a=10;
		}
		else if(s1=="dog"){
			a=11;
		}
		else if(s1=="pig"){
			a=12;
		}


		if(s2=="rat"){
			b=1;
		}
		else if(s2=="ox"){
			b=2;
		}
		else if(s2=="tiger"){
			b=3;
		}
		else if(s2=="rabbit"){
			b=4;
		}
		else if(s2=="dragon"){
			b=5;
		}
		else if(s2=="snake"){
			b=6;
		}
		else if(s2=="horse"){
			b=7;
		}
		else if(s2=="sheep"){
			b=8;
		}
		else if(s2=="monkey"){
			b=9;
		}
		else if(s2=="rooster"){
			b=10;
		}
		else if(s2=="dog"){
			b=11;
		}
		else if(s2=="pig"){
			b=12;
		}
		int ans=b-a;
		if(ans<=0)
			ans+=12;
		printf("%d\n",ans);

	}
    return 0;
}
