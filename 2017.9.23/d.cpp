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
	freopen("test.txt","w",stdout);
	for(int i=0;i<20;i++){
		int n,m;
		n=rand()%1000;
		m=rand()%1000;
		if(n<=1){
			n+=2;
		}
		if(m<=1){
			m+=2;
		}
		printf("%d %d\n",n,m);
	}
    return 0;
}
